/*
 *  superInterfaceVSlider.cpp
 *  superInterface
 *
 *  Created by Martial on 07/09/2011.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "superInterfaceVSlider.h"



superInterfaceVSlider::superInterfaceVSlider() {
    
    value = NULL;
    
}

void superInterfaceVSlider::setup(ofxSuperInterface   * mom, float * value, int xGridPos, int yGridPos, int wGridSize, int hGridSize, float minVal, float maxVal, string label ) {
    
	setup(mom, xGridPos,yGridPos, wGridSize, hGridSize, minVal, maxVal, label);
	
    this->value = value;
    this->targetValue = *value;
    pct = *value /  (minVal + (maxVal-minVal)); 
    
   	
}

void superInterfaceVSlider::setup(ofxSuperInterface   * mom, int xGridPos, int yGridPos, int wGridSize, int hGridSize, float minVal, float maxVal, string label ) {
    
    this->gridPos.set(xGridPos, yGridPos);
    
    
    
    this->wGridSize = wGridSize;
    this->hGridSize = hGridSize;
    this->minVal = minVal;
    this->maxVal = maxVal;
	
    targetValue = 0.0;
	pct = 0.0;
	
    superInterfaceComponent::setup(mom, label);
    
    
    minVal = 10;
    maxVal = 100;
    
    bRounded = false;
    
    
    // get width/height
    superInterfaceComponent::update();
  
	
	eventsArgs.floatVals.push_back(&pct);
    eventsArgs.floatVals.push_back(value);
	
}

void superInterfaceVSlider::roundValues(bool bActive) {
    bRounded = bActive;
}

void superInterfaceVSlider::update() {
	superInterfaceComponent::update();
    if (!isMouseDown && value != NULL) pct = *value /  (minVal + (maxVal-minVal)); 
    //txtLabel.update();
}

void superInterfaceVSlider::onMouseDragged (int x, int y, int id ) {
	
	
	
	pct = ( ((float)y - pos.y) / this->height );
	pct = ofClamp(pct, 0.0, 1.0);
	this->targetValue = (bRounded) ? int(minVal + (maxVal-minVal) * pct) : (minVal + (maxVal-minVal) * pct);
	*value = targetValue;    
    
	
	ofNotifyEvent(eventUpdateValues, eventsArgs, this);
}


void superInterfaceVSlider::draw() {
    
    superInterfaceComponent::draw();
    
    if ( isMouseDown ) {
        ofSetColor(  this->settings->bgColorRoll );
    } else {
        ofSetColor(  this->settings->bgColor );
    }
    roundedRect(pos.x, pos.y, width, height, 4);
    
    ofSetColor( this->settings->onColor  );
    
    
    float barHeight = (bRounded) ? int(height*pct) : height*pct;
    float diff = height - barHeight;
    roundedRect(pos.x,  pos.y + diff,  width, barHeight, 4);
    
	
}
