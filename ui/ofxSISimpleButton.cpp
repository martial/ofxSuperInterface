//
//  ofxSISimpleButton.cpp
//  ofxSI
//
//  Created by Martial Geoffre-Rouland on 04/08/2011.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#include "ofxSISimpleButton.h"
#include "ofxSuperInterface.h"


ofxSISimpleButton::ofxSISimpleButton () {

}

void ofxSISimpleButton::setup(ofxSuperInterface   * mom, bool &value, string label,  int xGridPos, int yGridPos, int wGridSize, int hGridSize) {
    
    this->gridPos.set(xGridPos, yGridPos);
    this->wGridSize = wGridSize;
    this->hGridSize = hGridSize;
    this->settings->label = label;
    
    ofxSISwitch::setup(mom, label, value);
  
}

void ofxSISimpleButton::setup(ofxSuperInterface   * mom,  string label,  int xGridPos, int yGridPos, int wGridSize, int hGridSize) {
    
    this->gridPos.set(xGridPos, yGridPos);
    this->wGridSize = wGridSize;
    this->hGridSize = hGridSize;
    this->settings->label = label;
    
    ofxSISwitch::setup(mom, label);
    
}



void ofxSISimpleButton::update() {
    
    ofxSISwitch::update();
}

void ofxSISimpleButton::draw() {
    
    ofxSISwitch::draw();
    
   
    if (!value) return;
        
    ofSetColor( 255,255,255 );
    roundedRect(pos.x, pos.y, width, height, cornerRadius);
    
   
    ofSetColor( (*value) ? this->settings->onColor : this->settings->offColor );
    roundedRect(pos.x+1, pos.y+1, width-2, height-2, cornerRadius);
   
    
    ofSetColor((*value) ? this->settings->labelOnColor : this->settings->labelOffColor);
   // float txtWidth = this->mom->assets.labelFont.stringWidth(this->settings->label.c_str());
    ofRectangle txtBox = this->mom->assets.labelFont.getStringBoundingBox(this->settings->label.c_str(),0,0);
    this->mom->assets.labelFont.drawString(this->settings->label.c_str(), (int)(pos.x + ( width * .5 - txtBox.width *.5)), (int)(pos.y + txtBox.height *.5 + height*.5));
    
}

void ofxSISimpleButton::setTemporary(bool b) {
    ofxSISwitch::setTemporary(b);
}