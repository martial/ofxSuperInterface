//
//  superInterfaceHSlider.cpp
//  emptyExample
//
//  Created by Martial Geoffre-Rouland on 05/08/2011.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#include "superInterfaceHSlider.h"



superInterfaceHSlider::superInterfaceHSlider() {
    
    
}
void superInterfaceHSlider::setup(ofxSuperInterface   * mom, float * value, int xGridPos, int yGridPos, int wGridSize, int hGridSize, float minVal, float maxVal, string label ) {
    
    this->gridPos.set(xGridPos, yGridPos);
    
    
    
    this->wGridSize = wGridSize;
    this->hGridSize = hGridSize;
    this->minVal = minVal;
    this->maxVal = maxVal;
 
    
    superInterfaceComponent::setup(mom, label);
    
    
    minVal = 10;
    maxVal = 100;
    
    bRounded = false;
    
    this->value = value;
    this->targetValue = *value;
    
    // get width/height
    superInterfaceComponent::update();
    
    pct = *value /  (minVal + (maxVal-minVal)); 
    
    txtLabel.setup(mom, pos.x, pos.y + height, label);
    
}

void superInterfaceHSlider::roundValues(bool bActive) {
    bRounded = bActive;
}

void superInterfaceHSlider::update() {
     superInterfaceComponent::update();
    
    //txtLabel.update();
}

void superInterfaceHSlider::onMouseDragged (int x, int y) {
     
	
	
     pct = ( ((float)x - pos.x) / this->width );
     pct = ofClamp(pct, 0.0, 1.0);
     this->targetValue = (bRounded) ? int(minVal + (maxVal-minVal) * pct) : (minVal + (maxVal-minVal) * pct);
     *value = targetValue;    
    
}


void superInterfaceHSlider::draw() {
    
    superInterfaceComponent::draw();
    
    if ( isMouseDown ) {
        ofSetColor(  this->settings->bgColorRoll );
    } else {
        ofSetColor(  this->settings->bgColor );
    }
    roundedRect(pos.x, pos.y, width, height, 4);
    
    ofSetColor( this->settings->onColor  );
    roundedRect(pos.x, pos.y, (bRounded) ? int(width*pct) : width*pct, height, 4);
    
    
    txtLabel.settings->label = this->settings->label + " | " + ofToString(targetValue);
    
    txtLabel.pos.x = pos.x + 3;
    txtLabel.pos.y = pos.y + height + txtLabel.getBoundingBox().height +3;
    txtLabel.draw();
    
}