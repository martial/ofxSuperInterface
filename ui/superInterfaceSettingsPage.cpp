//
//  superInterfaceSettingsPage.cpp
//  emptyExample
//
//  Created by Martial Geoffre-Rouland on 08/08/2011.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#include "superInterfaceSettingsPage.h"
#include "ofxSuperInterface.h"

superInterfaceSettingsPage::superInterfaceSettingsPage () {
     enabled = true;
}

void superInterfaceSettingsPage::setup (ofxSuperInterface * mom)

{
    
    superInterfacePage::setup(mom, -1);

    
    label.setup(this->mom, 2,0, "Settings");
    
    xUnitSlider.setup(this->mom, &this->mom->settings.grid.x, 2, label.hGridSize + 2, 40, 4, 10.0, 80.0, "Grille X");
    yUnitSlider.setup(this->mom, &this->mom->settings.grid.y, 44, label.hGridSize+ 2, 40, 4, 10.0, 80.0, "Grille Y" );
    
	gridBtn.setup(mom, mom->bShowGrid, "Show Grid", 0, 0, 10, 10);
	
	positionBtn.setup(mom, mom->bPositionMode, "Position Mode", 0, 0, 10, 10);
	
	saveBtn.setup(mom, "Save settings", 0,0, 10,10);
    saveBtn.setTemporary(true);
	
    
    xUnitSlider.roundValues(true);
    yUnitSlider.roundValues(true);
    
    addComponent(&label);
    addComponent(&xUnitSlider);
    addComponent(&yUnitSlider);
	addComponent(&gridBtn);
	addComponent(&positionBtn);

    addComponent(&saveBtn);
    
    
    bgColor.set(0,0,0,126);
    
  
    
    
}

void superInterfaceSettingsPage::update () {
    
    superInterfacePage::update();
    
    label.setFixed(false, 20);
    xUnitSlider.setFixed(false, 20,  (label.height ) + 40 + this->mom->settings.grid.y, 400.0, 30.0);
    yUnitSlider.setFixed(false, 420 + 20, label.height + 40  + this->mom->settings.grid.y, 400.0, 30.0);
	
	gridBtn.setFixed(false, 20, yUnitSlider.pos.y + yUnitSlider.height, 100,50);
	positionBtn.setFixed(false, 140, yUnitSlider.pos.y + yUnitSlider.height, 100,50);
    saveBtn.setFixed(false, 20, gridBtn.pos.y + gridBtn.height, 100,50);
}

void superInterfaceSettingsPage::draw() {
    
    ofEnableAlphaBlending();
    ofSetColor(bgColor);
    ofRect(0,0,ofGetWidth(), ofGetHeight());
    ofDisableAlphaBlending();
    
    superInterfacePage::draw();
    
    
}