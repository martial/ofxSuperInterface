//
//  ofxSIHTextLabel.cpp
//  emptyExample
//
//  Created by Martial Geoffre-Rouland on 09/08/2011.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#include "ofxSIHTextLabel.h"
#include "ofxSuperInterface.h"

ofxSIHTextLabel::ofxSIHTextLabel() {
    
}
void ofxSIHTextLabel::setup(ofxSuperInterface   * mom, int xGridPos, int yGridPos, string label) {
    
     ofxSIComponent::setup(mom, label);
    
    this->gridPos.set(xGridPos, yGridPos);
 
    
    // just to fix width and height on setup
   // getBox();
    update();
    
}
void ofxSIHTextLabel::update(){
    
     // have to find how many units it is!
    
    getBoundingBox();
    
    calculatePos();
    
    wGridSize = (int)(boundingBox.width / this->mom->settings.grid.x);
    hGridSize = (int)(boundingBox.height / this->mom->settings.grid.y);

    //ofxSIComponent::update(); 

    
}
void ofxSIHTextLabel::draw() {
    
    ofxSIComponent::draw(); 
    
    ofSetColor(0,0,0);
    ofRect(pos.x, pos.y, boundingBox.width, boundingBox.height);
    
    ofSetColor(this->settings->labelOffColor);
    //float txtWidth = this->mom->assets.labelFont.stringWidth(this->settings->label.c_str());
    this->mom->assets.headlineFont.drawString(this->settings->label.c_str() , pos.x, pos.y + boundingBox.height);
    
    ofSetColor(100, 100, 100);
    
    ofRect(pos.x , pos.y + boundingBox.height, boundingBox.width, 2);
    
    
}

ofRectangle ofxSIHTextLabel::getBoundingBox() {
    
    boundingBox = this->mom->assets.headlineFont.getStringBoundingBox(this->settings->label.c_str(), 0, 0);
    return boundingBox;
    
}