//
//  superInterfaceHTextLabel.cpp
//  emptyExample
//
//  Created by Martial Geoffre-Rouland on 09/08/2011.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#include "superInterfaceHTextLabel.h"
#include "ofxSuperInterface.h"

superInterfaceHTextLabel::superInterfaceHTextLabel() {
    
}
void superInterfaceHTextLabel::setup(ofxSuperInterface   * mom, int xGridPos, int yGridPos, string label) {
    
     superInterfaceComponent::setup(mom);
    
    this->gridPos.set(xGridPos, yGridPos);
    this->settings->label = label;
    
    // just to fix width and height on setup
   // getBox();
    update();
    
}
void superInterfaceHTextLabel::update(){
    
     // have to find how many units it is!
    
    getBoundingBox();
    
    calculatePos();
    
    wGridSize = (int)(boundingBox.width / this->mom->settings.grid.x);
    hGridSize = (int)(boundingBox.height / this->mom->settings.grid.y);

    //superInterfaceComponent::update(); 

    
}
void superInterfaceHTextLabel::draw() {
    
    superInterfaceComponent::draw(); 
    
    ofSetColor(0,0,0);
    ofRect(pos.x, pos.y, boundingBox.width, boundingBox.height);
    
    ofSetColor(this->settings->labelOffColor);
    //float txtWidth = this->mom->assets.labelFont.stringWidth(this->settings->label.c_str());
    this->mom->assets.headlineFont.drawString(this->settings->label.c_str(), pos.x, pos.y + boundingBox.height);
    
    ofSetColor(100, 100, 100);
    
    ofRect(pos.x , pos.y + boundingBox.height, boundingBox.width, 2);
    
    
}

ofRectangle superInterfaceHTextLabel::getBoundingBox() {
    
    boundingBox = this->mom->assets.headlineFont.getStringBoundingBox(this->settings->label.c_str(), 0, 0);
    return boundingBox;
    
}