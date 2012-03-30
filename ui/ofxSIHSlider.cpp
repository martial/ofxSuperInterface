//
//  ofxSIHSlider.cpp
//  emptyExample
//
//  Created by Martial Geoffre-Rouland on 05/08/2011.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#include "ofxSIHSlider.h"



ofxSIHSlider::ofxSIHSlider() {
    
    
}
void ofxSIHSlider::setup(ofxSuperInterface   * mom, float * value, int xGridPos, int yGridPos, int wGridSize, int hGridSize, float minVal, float maxVal, string label ) {
    
    this->gridPos.set(xGridPos, yGridPos);
    
    
    
    this->wGridSize = wGridSize;
    this->hGridSize = hGridSize;
    this->minVal = minVal;
    this->maxVal = maxVal;
 
    
    ofxSIComponent::setup(mom, label);
    
    
    minVal = 10;
    maxVal = 100;
    
    bRounded = false;
    
    this->value = value;
    this->targetValue = *value;
    
    // get width/height
    ofxSIComponent::update();
    
    pct = *value /  (minVal + (maxVal-minVal)); 
    
    txtLabel.setup(mom, pos.x, pos.y + height, label);
	
	
	eventsArgs.floatVals.push_back(&pct);
    eventsArgs.floatVals.push_back(value);
	
}

void ofxSIHSlider::roundValues(bool bActive) {
    bRounded = bActive;
}

void ofxSIHSlider::update() {
     ofxSIComponent::update();
    
     pct = *value /  (minVal + (maxVal-minVal)); 
	 this->targetValue = (bRounded) ? int(minVal + (maxVal-minVal) * pct) : (minVal + (maxVal-minVal) * pct);
}

void ofxSIHSlider::onMouseDragged (int x, int y, int id ) {
     
	
	
     pct = ( ((float)x - pos.x) / this->width );
     pct = ofClamp(pct, 0.0, 1.0);
     this->targetValue = (bRounded) ? int(minVal + (maxVal-minVal) * pct) : (minVal + (maxVal-minVal) * pct);
     *value = targetValue;    
    
	
	 ofNotifyEvent(eventUpdateValues, eventsArgs, this);
}


void ofxSIHSlider::draw() {
    
    ofxSIComponent::draw();
    
    if ( isMouseDown ) {
        ofSetColor(  this->settings->bgColorRoll );
    } else {
        ofSetColor(  this->settings->bgColor );
    }
    
    roundedRect(pos.x, pos.y, width, height, 4);
    
    ofSetColor( this->settings->onColor  );
    roundedRect(pos.x, pos.y, (bRounded) ? int(width*pct) : width*pct, height, 4);
    
    
    //txtLabel.settings->label = this->settings->label + " | " + ofToString(targetValue) + " " + extraText:
    
    txtLabel.pos.x = pos.x + 3;
    txtLabel.pos.y = pos.y + height + txtLabel.getBoundingBox().height +5;
    txtLabel.draw();
    
}




