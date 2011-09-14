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
    if (!dir.exists()) {
        dir.create();
        ofLog(OF_LOG_NOTICE, "create layout folder");
    }
    
    
    
    #if !defined( TARGET_OF_IPHONE ) 
    ofRegisterMouseEvents(this);
    #else 
    ofRegisterTouchEvents(this);
    #endif
    settings.setupDefaults();
    dataManager.setup(this, &settings, &settingsPage);
    dataManager.loadSettings(initialDirectory);
    
    
    assets.setup(&settings);
    
    addSettingsPage();
       
    bPositionMode = false;
	bShowSettings = false;
    
    showPage(0);
    
;
    
}




void ofxSuperInterface::setupFromXml(string xmlPath){
    
}

void ofxSuperInterface::addSettingsPage () {
    
    // settings will be our page 0
    settingsPage.setup(this);
    menuPage.setup(this);
    
}



void ofxSuperInterface::update(){
	
	// for position mode 
	// TODO quit of update, put as event 
	
	for ( int i = 0; i<dataManager.components.size(); i++) {
		dataManager.components[i]->bEnabled = !bPositionMode;
	}
	
    
    if ( bShowSettings ) settingsPage.update();
    menuPage.update();
    superInterfacePage * currentP = dataManager.getPage(currentPage);
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
    
    dataManager.getPage(currentPage)->draw();
    if ( bShowSettings ) settingsPage.draw();
    
    menuPage.draw();
    
}




void ofxSuperInterface::addComponent(superInterfaceComponent * component, int pageNumber){

    
    if ( pageNumber >= dataManager.pages.size() ) {
        
        int diff = pageNumber - dataManager.pages.size()+1;
        for ( int i=0; i< diff; i++) addPage(i);
                   
    }
    
    
    dataManager.pages[pageNumber]->addComponent(component);    
    dataManager.addComponent(component, pageNumber);
    
}
void ofxSuperInterface::removeComponent(){
    
}

void ofxSuperInterface::addPage(int pageNumber) {
    
    dataManager.addPage(pageNumber);
    menuPage.setNumOfPages(dataManager.pages.size());
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
    
    
}


void ofxSuperInterface::showSettings(bool b) {
    bShowSettings = b;
}

void ofxSuperInterface::toggleSettings() {
    bShowSettings = !bShowSettings;
}










