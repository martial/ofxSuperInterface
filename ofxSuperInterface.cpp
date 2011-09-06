//
//  ofxSuperInterface.cpp
//  emptyExample
//
//  Created by Martial Geoffre-Rouland on 05/08/2011.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#include "ofxSuperInterface.h"

ofxSuperInterface::ofxSuperInterface() {
    
}

void ofxSuperInterface::setup(string initialDirectory) {
    
    
    // first check is folder structure exists
    initialDirectory = initialDirectory;
    
    
    ofDirectory dir;
    dir.open(initialDirectory + "superInterface");
    if (!dir.exists()) dir.create();
    dir.open(initialDirectory+"superInterface/layouts");
    if (!dir.exists()) dir.create();
    
    
    
    #if !defined( TARGET_OF_IPHONE ) 
    ofRegisterMouseEvents(this);
    #else 
    ofRegisterTouchEvents(this);
    #endif
    
    dataManager.setup(&settings, &settingsPage);
    dataManager.loadSettings(initialDirectory);
    
    //settings.setupDefaults();
    assets.setup(&settings);
    
    addSettingsPage();
    
    bShowGrid = true;
   
    bPositionMode = false;
    
    showPage(0);
    
    
    
    //menuPage.settingsBtn.value = &bShowSettings;
    
}




void ofxSuperInterface::setupFromXml(string xmlPath){
    
}

void ofxSuperInterface::addSettingsPage () {
    
    // settings will be our page 0
    settingsPage.setup(this);
    menuPage.setup(this);
    //pages.push_back(&settingsPage);
    
    // then we always create an empty page;
    
    //addPage();
    
}

void ofxSuperInterface::showSettings(bool b) {
    bShowSettings = b;
}

void ofxSuperInterface::toggleSettings() {
    bShowSettings = !bShowSettings;
}

void ofxSuperInterface::update(){
    
    if ( bShowSettings ) settingsPage.update();
    menuPage.update();
    superInterfacePage * currentP = getCurrentPage();
    currentP->update();
    
}
void ofxSuperInterface::draw(){
    
    if ( bShowGrid ) {
        
        
            ofSetColor(125, 125, 125);
        
            int xGrid = settings.grid.x;
            int yGrid = settings.grid.y;
                        
            int numOfHPoint = (int)((float)ofGetWidth() / (float)xGrid) +1;
            int numOfVPoint = (int)((float)ofGetHeight() / (float)yGrid) +1;
            int totalPoints = (numOfHPoint * numOfVPoint);
            
            int numOfVertices = totalPoints*2;
            float vertices[numOfVertices];
            int vNum = 0;
            for (int i = 0; i <totalPoints; i++)
            {            
                int row = (int)(i % numOfVPoint);
                int col = floor(i / numOfVPoint);
                
                vertices[vNum++] = (GLfloat)(col*xGrid);
                vertices[vNum++] = (GLfloat)(row*yGrid);
                
        }
        
        
      
        
        
        //draw it!

        glEnableClientState(GL_VERTEX_ARRAY);
        glVertexPointer(2, GL_FLOAT, 0, vertices);        
        glDrawArrays(GL_POINTS, 0, totalPoints);
        glDisableClientState(GL_VERTEX_ARRAY);
        
        
    }
    
  
    
    
    getCurrentPage()->draw();
    if ( bShowSettings ) settingsPage.draw();
    
    menuPage.draw();
    
}

void ofxSuperInterface::addComponent(superInterfaceComponent * component, int numPage){

    //components.push_back(component);
    
    if ( numPage >= pages.size() ) {
        
        int diff = numPage - pages.size()+1;
        for ( int i=0; i< diff; i++) {
            addPage();
            //ofLog(OF_LOG_NOTICE, "Page %d does not exist - creating  page %d", numPage, i);
        }
        
        
    }
    //ofLog(OF_LOG_NOTICE, "add component to page %d", numPage);
    pages[numPage]->addComponent(component);    
    
}
void ofxSuperInterface::removeComponent(){
    
}

void ofxSuperInterface::addPage() {
    superInterfacePage * page =  new superInterfacePage();
    page->setup(this);
    pages.push_back(page);
    menuPage.setNumOfPages(pages.size());
}

void ofxSuperInterface::showPage(int id) {
    currentPage = id;
}

void ofxSuperInterface::showGrid(bool bActive) {
    bShowGrid = bActive;
}

void ofxSuperInterface::enablePositionMode(bool bActive) {
    bPositionMode = bActive;
    //showGrid(bActive);
    for ( int i = 0; i<components.size(); i++) {
        components[i]->bEnabled = !bActive;
    }
    
}


superInterfacePage * ofxSuperInterface::getCurrentPage() {
    if ( currentPage > pages.size()-1) {
        ofLog(OF_LOG_ERROR, "oh nor!! %d", currentPage);
    }
    
    return pages[currentPage];
    
}









