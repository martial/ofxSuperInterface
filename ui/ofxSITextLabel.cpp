//
//  ofxSIHTextLabel.cpp
//  emptyExample
//
//  Created by Martial Geoffre-Rouland on 09/08/2011.
//   
 
 
//

#include "ofxSITextLabel.h"
#include "ofxSuperInterface.h"

ofxSITextLabel::ofxSITextLabel() {
    
}
void ofxSITextLabel::setup(ofxSuperInterface   * mom, int xGridPos, int yGridPos, string label) {
    
    ofxSIComponent::setup(mom, label);
    
    this->gridPos.set(xGridPos, xGridPos);
    extraText = "";
   
    
}
void ofxSITextLabel::update(){
    
    // have to find how many units it is!
    
    getBoundingBox();
    
    calculatePos();
    
    wGridSize = (int)(boundingBox.width / this->mom->settings.grid.x);
    hGridSize = (int)(boundingBox.height / this->mom->settings.grid.y);
    
    // don't update size here
    //ofxSIComponent::update(); 
    
    
}
void ofxSITextLabel::draw() {
    
    ofxSIComponent::draw(); 
    
    ofSetColor(255,0,0);
    //ofRect(pos.x, pos.y, boundingBox.width, boundingBox.height);
    
    ofSetColor(this->settings->labelOffColor);
    //float txtWidth = this->mom->assets.labelFont.stringWidth(this->settings->label.c_str());
	string txt = this->settings->label  + " " + extraText;
    this->mom->assets.labelFont.drawString(txt, pos.x, pos.y + height);
    
    //ofSetColor(45, 45, 45);
    //ofLine(pos.x , pos.y + boundingBox.height, pos.x + boundingBox.width, pos.y + boundingBox.height);
    
    
}

ofRectangle ofxSITextLabel::getBoundingBox() {
    
    boundingBox = this->mom->assets.labelFont.getStringBoundingBox(this->settings->label.c_str(), pos.x, pos.y);
    return boundingBox;
    
}