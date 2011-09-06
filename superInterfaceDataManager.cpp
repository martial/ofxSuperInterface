//
//  superInterfaceDataManager.cpp
//  superInterface
//
//  Created by Martial Geoffre-Rouland on 11/08/2011.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#include "superInterfaceDataManager.h"



void superInterfaceDataManager::setup(superInterfaceSettings * interfaceSettings, superInterfaceSettingsPage * settingsPage) {
    this->interfaceSettings = interfaceSettings;
    this->settingsPage = settingsPage;
    
    ofAddListener(settingsPage->saveBtn.eventMouseDown, this, &superInterfaceDataManager::saveSettings);
}

void superInterfaceDataManager::loadSettings(string initialDirectory) {
    
    this->initialDirectory = initialDirectory;
    this->xmlSettingsPath =  initialDirectory + "settings.xml";
    
    if( !xmlSettings.loadFile("settings.xml")  ) {
            createDefaultSettings();
    } 
	    
    updateSettings();
    
    loadLayouts();
    
}

void superInterfaceDataManager::createDefaultSettings () {
    
    ofLog(OF_LOG_NOTICE, "Create default settings");
    
    xmlSettings.addTag("settings");
    xmlSettings.pushTag("settings");
    xmlSettings.addTag("grid_size");
    xmlSettings.addAttribute("grid_size", "x", 15, 0);
    xmlSettings.addAttribute("grid_size", "y", 15  ,0);
    
    
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
    xmlSettings.popTag();
    
    ofLog(OF_LOG_NOTICE, "with Settings x %f", interfaceSettings->grid.x);
    ofLog(OF_LOG_NOTICE, "with Settings y %f", interfaceSettings->grid.y);
    
    
    string debugStr;
    xmlSettings.copyXmlToString(debugStr);
    
    ofLog(OF_LOG_NOTICE, debugStr);
    
    xmlSettings.saveFile(xmlSettingsPath);
    
}

void superInterfaceDataManager::loadLayouts(){
    
    // first we'll need to check if we have some layouts files in local.
    
    
    //dir.open(initialDirectory+layoutDirectory);
    //int numOfFiles = dir.listDir("superInterface/"+layoutDirectory);
    
    int numOfFiles = dir.listDir(initialDirectory+"superInterface/layouts");
    
    ofLog(OF_LOG_NOTICE, "Num of layouts : %d", numOfFiles);
    
    numOfFiles = dir.listDir("");
       ofLog(OF_LOG_NOTICE, "Num of layouts : %d", numOfFiles);
    for ( int i = 0; i<numOfFiles; i++ ) {
        
           ofLog(OF_LOG_NOTICE, "File : "+dir.getPath(i));
        
    }

  
    
}
void superInterfaceDataManager::saveLayouts(){
    
}