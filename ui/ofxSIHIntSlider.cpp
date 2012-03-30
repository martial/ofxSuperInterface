/*
 *  ofxSIHIntSlider.cpp
 *  MODULAR_SHIP
 *
 *  Created by Martial on 12/09/2011.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "ofxSIHIntSlider.h"


ofxSIHIntSlider::ofxSIHIntSlider() {
    
    
}
void ofxSIHIntSlider::setup(ofxSuperInterface   * mom, int * value, int xGridPos, int yGridPos, int wGridSize, int hGridSize, float minVal, float maxVal, string label ) {
    
    this->gridPos.set(xGridPos, yGridPos);
    
    
    
    this->wGridSize = wGridSize;
    this->hGridSize = hGridSize;
    this->minVal = minVal;
    this->maxVal = maxVal;
	
    
    ofxSIComponent::setup(mom, label);
    
    
    minVal = 10;
    maxVal = 100;
    
    
    this->value = value;
    this->targetValue = *value;
    
    // get width/height
    ofxSIComponent::update();
    
    pct = *value /  (minVal + (maxVal-minVal)); 
    
    txtLabel.setup(mom, pos.x, pos.y + height, label);
	
	
	eventsArgs.floatVals.push_back(&pct);
    eventsArgs.intVals.push_back(value);
	
}

void ofxSIHIntSlider::roundValues(bool bActive) {
}

void ofxSIHIntSlider::update() {
	ofxSIComponent::update();
    
	pct = (float)*value /  (float)(minVal + (maxVal-minVal)); 
	this->targetValue =  (int)(minVal + (maxVal-minVal) * pct);
}

void ofxSIHIntSlider::onMouseDragged (int x, int y, int id ) {
	
	
	
	pct = ( ((float)x - pos.x) / this->width );
	pct = ofClamp(pct, 0.0, 1.0);
	
	this->targetValue =  (int)(minVal + (maxVal-minVal) * pct);
	*value = targetValue;    
    
	
	ofNotifyEvent(eventUpdateValues, eventsArgs, this);
}


void ofxSIHIntSlider::draw() {
    
    ofxSIComponent::draw();
    
    if ( isMouseDown ) {
        ofSetColor(  this->settings->bgColorRoll );
    } else {
        ofSetColor(  this->settings->bgColor );
    }
    roundedRect(pos.x, pos.y, width, height, 4);
    
    ofSetColor( this->settings->onColor  );
    roundedRect(pos.x, pos.y, int(width*pct), height, 4);
    
    
    txtLabel.settings->label = this->settings->label + " | " + ofToString(targetValue);
    
    txtLabel.pos.x = pos.x + 3;
    txtLabel.pos.y = pos.y + height + txtLabel.getBoundingBox().height +5;
    txtLabel.draw();
    
}

