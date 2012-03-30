//
//  superInterfaceSimpleButton.cpp
//  superInterface
//
//  Created by Martial Geoffre-Rouland on 04/08/2011.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#include "superInterfaceSimpleButton.h"
#include "ofxSuperInterface.h"


superInterfaceSimpleButton::superInterfaceSimpleButton () {

}

void superInterfaceSimpleButton::setup(ofxSuperInterface   * mom, bool &value, string label,  int xGridPos, int yGridPos, int wGridSize, int hGridSize) {
    
    this->gridPos.set(xGridPos, yGridPos);
    this->wGridSize = wGridSize;
    this->hGridSize = hGridSize;
    this->settings->label = label;
    
    superInterfaceSwitch::setup(mom, label, value);
  
}

void superInterfaceSimpleButton::setup(ofxSuperInterface   * mom,  string label,  int xGridPos, int yGridPos, int wGridSize, int hGridSize) {
    
    this->gridPos.set(xGridPos, yGridPos);
    this->wGridSize = wGridSize;
    this->hGridSize = hGridSize;
    this->settings->label = label;
    
    superInterfaceSwitch::setup(mom, label);
    
}



void superInterfaceSimpleButton::update() {
    
    superInterfaceSwitch::update();
}

void superInterfaceSimpleButton::draw() {
    
    superInterfaceSwitch::draw();
    
   
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

void superInterfaceSimpleButton::setTemporary(bool b) {
    superInterfaceSwitch::setTemporary(b);
}