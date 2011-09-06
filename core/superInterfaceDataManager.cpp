//
//  superInterfaceDataManager.cpp
//  superInterface
//
//  Created by Martial Geoffre-Rouland on 11/08/2011.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#include "superInterfaceDataManager.h"
#include "ofxSuperInterface.h"


void superInterfaceDataManager::setup(ofxSuperInterface * mom, superInterfaceSettings * interfaceSettings, superInterfaceSettingsPage * settingsPage) {
	
	this->mom = mom;
    this->interfaceSettings = interfaceSettings;
    this->settingsPage = settingsPage;
    
    ofAddListener(settingsPage->saveBtn.eventMouseDown, this, &superInterfaceDataManager::saveSettings);
}


/*
 
 ----------------------------------------------------------- settings
 
 */

void superInterfaceDataManager::loadSettings(string initialDirectory) {
    
    this->initialDirectory = initialDirectory;
    this->xmlSettingsPath =  initialDirectory + "settings.xml";
    
    if( !xmlSettings.loadFile(xmlSettingsPath)  ) {
        createDefaultSettings();
        ofLog(OF_LOG_NOTICE, "no settings files found");
    } else {
        ofLog(OF_LOG_NOTICE, "settings files found");
        
    }
	    
    updateSettings();
    
   // loadLayouts();
    
}

void superInterfaceDataManager::createDefaultSettings () {
    
    ofLog(OF_LOG_NOTICE, "Create default settings");
    
    xmlSettings.addTag("settings");
    xmlSettings.pushTag("settings");
    xmlSettings.addTag("grid_size");
    xmlSettings.addAttribute("grid_size", "x", 15, 0);
    xmlSettings.addAttribute("grid_size", "y", 15  ,0);
    
	xmlSettings.addTag("showgrid");
	xmlSettings.setValue("showgrid", 1);

    xmlSettings.addTag("headlineFont");
    xmlSettings.setValue("headlineFont", "Arial.ttf");
    xmlSettings.addAttribute("headlineFont", "size", 14 ,0);
    
    xmlSettings.addTag("labelFont");
    xmlSettings.setValue("labelFont", "Arial.ttf");
    xmlSettings.addAttribute("labelFont", "size", 9, 0);
    
    
    xmlSettings.popTag();
    
    xmlSettings.saveFile(xmlSettingsPath);
    
    
}

void superInterfaceDataManager::updateSettings () {
    
    ofLog(OF_LOG_NOTICE, "Update Settings");
    
    xmlSettings.pushTag("settings");
    interfaceSettings->grid.x = xmlSettings.getAttribute("grid_size", "x", 0);
    interfaceSettings->grid.y = xmlSettings.getAttribute("grid_size", "y", 0);
    
    interfaceSettings->headLineFontPath = xmlSettings.getValue("headlineFont", "Arial.ttf");
    interfaceSettings->headLineFontSize = xmlSettings.getAttribute("headlineFont", "size", 14);

    
    interfaceSettings->labelFontPath = xmlSettings.getValue("labelFont", "Arial.ttf");
    interfaceSettings->labelFontSize = xmlSettings.getAttribute("labelFont", "size", 9);
	
	mom->bShowGrid = ( xmlSettings.getValue("showgrid", 1, 0) == 0 )?  false : true;
    
	
    xmlSettings.popTag();
}

void superInterfaceDataManager::saveSettings(superInterfaceEventArgs & e) {
    saveSettings();
}

void superInterfaceDataManager::saveSettings(){
    
    
    ofLog(OF_LOG_NOTICE, "Save Settings");
	
    xmlSettings.pushTag("settings");
    xmlSettings.setAttribute("grid_size", "x", interfaceSettings->grid.x, 0);
    xmlSettings.setAttribute("grid_size", "y", interfaceSettings->grid.y ,0);
	xmlSettings.setValue("showgrid", mom->bShowGrid);
    xmlSettings.popTag();
      
    xmlSettings.saveFile(xmlSettingsPath);
    
}


/*
 
 ------------------------------------------------------------ layouts
 
 */




void superInterfaceDataManager::loadLayouts(){
    
    // first we'll need to check if we have some layouts files in local.
    
    
    //dir.open(initialDirectory+layoutDirectory);
    //int numOfFiles = dir.listDir("superInterface/"+layoutDirectory);
    
    int numOfFiles = dir.listDir(initialDirectory+"superInterface/layouts");
    
    ofLog(OF_LOG_NOTICE, "Num of layouts : %d", numOfFiles);
    
    numOfFiles = dir.listDir("");
       ofLog(OF_LOG_NOTICE, "Num of files in root : %d", numOfFiles);
    for ( int i = 0; i<numOfFiles; i++ ) {
        
           //ofLog(OF_LOG_NOTICE, "File : "+dir.getPath(i));
        
    }

  
    
}
void superInterfaceDataManager::saveLayouts(){
            
}



/*
 
 ----------------------------------------------------------- Pages & components
 
 */



void superInterfaceDataManager::addComponent(superInterfaceComponent *component, int pageNumber) {
    
	ofAddListener(component->eventChangePos, this, &superInterfaceDataManager::updateComponentPos);
	component->pageNum = pageNumber;
	
	
	checkIfLabelExists(component);
	checkIfComponentXmlExists(pageNumber, component);
	
    components.push_back(component);
	
	
	
	// and. Finaly. Update positions.
	
	ofxXmlSettings * layoutXml = xmlLayouts[pageNumber];
	
	int layoutNode = getLayoutNodeByLabel(component->settings->label, pageNumber);
	
	ofLog(OF_LOG_NOTICE, "Test %d", layoutNode);
	ofLog(OF_LOG_NOTICE, "get layout node " + component->settings->label);
	
	
	string debug;
	layoutXml->copyXmlToString(debug);
	
	ofLog(OF_LOG_NOTICE, debug);
	
	layoutXml->pushTag("layout");
	layoutXml->pushTag("component", layoutNode);
	component->gridPos.x = layoutXml->getAttribute("pos", "x", 0, 0);
	component->gridPos.y = layoutXml->getAttribute("pos", "y", 0, 0);
	layoutXml->popTag();
	layoutXml->popTag();
}

void superInterfaceDataManager::addPage(int pageNumber) {
    
    checkIfLayoutXmlExists(pageNumber);
	
	superInterfacePage * page =  new superInterfacePage();
    page->setup(mom, pageNumber);
	pages.push_back(page);
	
}

bool superInterfaceDataManager::checkIfComponentXmlExists(int pageNumber, superInterfaceComponent * component) {
		
	ofxXmlSettings * layoutXml = xmlLayouts[pageNumber];
    
	int nodeXml = getLayoutNodeByLabel( component->settings->label, pageNumber );
	if ( nodeXml != -1 ) return true;
	
   
	/*
	 * add new component
	 */
		
	ofLog(OF_LOG_NOTICE, "adding component..");
		
	layoutXml->pushTag("layout");
	int tagNumber = layoutXml->addTag("component");
		
	layoutXml->pushTag("component", tagNumber);
		
	layoutXml->addTag("label");
	layoutXml->setValue("label", component->settings->label);

	
	layoutXml->addTag("pos");
	layoutXml->setAttribute("pos", "x", component->gridPos.x, 0 );
	layoutXml->setAttribute("pos", "y", component->gridPos.y, 0 );
	
	layoutXml->popTag();
		
	layoutXml->popTag();
		
	layoutXml->saveFile();
	
		
	return false;
	
}

string superInterfaceDataManager::checkIfLayoutXmlExists(int pageNumber) {
    
    //int numOfFiles = dir.listDir(initialDirectory+"superInterface/layouts");
    
    ofFile layoutFile;
    string path = initialDirectory + "superInterface/layouts/" + ofToString(pageNumber) + "__layout.xml";
    layoutFile.open(path);
    
    ofxXmlSettings * layoutXml = new ofxXmlSettings();
    
    if(!layoutFile.exists()) {
        
        layoutXml->addTag("layout");
        layoutXml->saveFile(path);
        //if(!layoutFile.create()) ofLog(OF_LOG_NOTICE, "error writing file");
        
    } else {
        
        if ( !layoutXml->loadFile(path) ) 
        ofLog(OF_LOG_NOTICE, "seems that file exists! but error with loading..");
        
    }
    
    layoutFile.close();
    
    xmlLayouts.push_back(layoutXml);
    
    return path;
    
}


superInterfacePage * superInterfaceDataManager::getPage(int pageNumber ) {
    if ( pageNumber > pages.size()-1) {
        ofLog(OF_LOG_ERROR, "oh no!! %d", pageNumber);
    }
    return pages[pageNumber];
    
}



void superInterfaceDataManager::checkIfLabelExists(superInterfaceComponent *component) {

	for (int i=0; i<components.size(); i++) {
		
		if ( component->settings->label == components[i]->settings->label ) {
			
			doubleLabels.push_back(component->settings->label);
			// get how many
			int labelCount = 0;
			for ( int j=0; j<doubleLabels.size(); j++ ) {
				if(doubleLabels[j] == component->settings->label ) labelCount++;
					
			}
			component->settings->label += "_" + ofToString(labelCount);
		}
		
	}
	
}

int superInterfaceDataManager::getLayoutNodeByLabel(string label, int pageNum) {
		
	ofxXmlSettings * layoutXml = xmlLayouts[pageNum];
	
	layoutXml->pushTag("layout");
	
	int numOfComponents = layoutXml->getNumTags("component");
	
	ofLog(OF_LOG_NOTICE, "numOfComponents %d", numOfComponents);
	for( int i= 0; i<numOfComponents; i++) {
		
		layoutXml->pushTag("component", i);
		
		ofLog(OF_LOG_NOTICE, "CHECK FOR " + layoutXml->getValue("label", "merde"));
		
		if ( layoutXml->getValue("label", "") == label ) {
			layoutXml->popTag();
			layoutXml->popTag();
			return i;			
		}
		layoutXml->popTag();
		
	}
	layoutXml->popTag();
	
	return -1;

}

void superInterfaceDataManager::updateComponentPos(superInterfaceEventArgs & e) {
	superInterfaceObject * comp = e.comp;
	// get layout comp
	
	ofxXmlSettings * layoutXml = xmlLayouts[comp->pageNum];
	
	layoutXml->pushTag("layout");
	
	int numOfComponents = layoutXml->getNumTags("component");
	
	
	for( int i= 0; i<numOfComponents; i++) {
	
		layoutXml->pushTag("component", i);
		if ( layoutXml->getValue("label", "") == comp->settings->label ) {
			layoutXml->setAttribute("pos", "x", comp->gridPos.x, 0);
			layoutXml->setAttribute("pos", "y", comp->gridPos.y, 0);
			
		}
		layoutXml->popTag();
		
	}
	layoutXml->popTag();
	layoutXml->saveFile();
}

