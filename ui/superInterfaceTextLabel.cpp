//
//  superInterfaceHTextLabel.cpp
//  emptyExample
//
//  Created by Martial Geoffre-Rouland on 09/08/2011.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#include "superInterfaceTextLabel.h"
#include "ofxSuperInterface.h"

superInterfaceTextLabel::superInterfaceTextLabel() {
    
}
void superInterfaceTextLabel::setup(ofxSuperInterface   * mom, int xGridPos, int yGridPos, string label) {
    
    superInterfaceComponent::setup(mom, label);
    
    this->gridPos.set(xGridPos, xGridPos);
    extraText = "";
   
    
}
void superInterfaceTextLabel::update(){
    
    // have to find how many units it is!
    
    getBoundingBox();
    
    calculatePos();
    
    wGridSize = (int)(boundingBox.width / this->mom->settings.grid.x);
    hGridSize = (int)(boundingBox.height / this->mom->settings.grid.y);
    
    // don't update size here
    //superInterfaceComponent::update(); 
    
    
}
void superInterfaceTextLabel::draw() {
    
    superInterfaceComponent::draw(); 
    
    ofSetColor(255,0,0);
    //ofRect(pos.x, pos.y, boundingBox.width, boundingBox.height);
    
    ofSetColor(this->settings->labelOffColor);
    //float txtWidth = this->mom->assets.labelFont.stringWidth(this->settings->label.c_str());
	string txt = this->settings->label  + " " + extraText;
    this->mom->assets.labelFont.drawString(txt, pos.x, pos.y + height);
    
    //ofSetColor(45, 45, 45);
    //ofLine(pos.x , pos.y + boundingBox.height, pos.x + boundingBox.width, pos.y + boundingBox.height);
    
    
}

ofRectangle superInterfaceTextLabel::getBoundingBox() {
    
    boundingBox = this->mom->assets.labelFont.getStringBoundingBox(this->settings->label.c_str(), pos.x, pos.y);
    return boundingBox;
    
}