//
//  ofxSIObject.cpp
//  emptyExample
//
//  Created by Martial Geoffre-Rouland on 04/08/2011.
//   
 
 
//

#include "ofxSIObject.h"
#include "ofxSuperInterface.h"

ofxSIObject::ofxSIObject() {
    
    
    pos.x           = 0;
    pos.y           = 0;
    
    width           = 0;
    height          = 0;
    
    fixedWidth      = 0;
    fixedHeight     = 0;
    fixedXPos       = 0;
    fixedYPos       = 0;
    
    cornerRadius    = 8;
    
    
    bEnabled        = true;
    bIsFixed        = false;
    bIsFreePos      = false;
    
    settings = new ofxSICompSettings();
    settings->setupDefaults();
    
    eventsArgs.comp = this;
	
	
  
    
}

void ofxSIObject::setup (ofxSuperInterface   * mom, string label) {
    
    this->mom = mom;
	this->settings->label = label;
}

void ofxSIObject::setSettings(ofxSICompSettings * settings) {
    
    this->settings = NULL;
    this->settings = settings;
}


void ofxSIObject::setGridPosByScreenCoords(int x, int y) {
	
	float xSteps = ofGetWidth() / mom->settings.grid.x;
	float ySteps = ofGetHeight() / mom->settings.grid.y;
	gridPos.x = (int)( (x * xSteps ) / ofGetWidth()) - wGridSize * .5;
	gridPos.y = (int)( (y * ySteps ) / ofGetHeight()) - mom->settings.menuBarGridSize - hGridSize * .5;
	
}

void ofxSIObject::update(ofEventArgs & e) {
	update();
}

void ofxSIObject::update() {
    
   
    calculatePos();
    calculateSize();
   
}

void ofxSIObject::draw() {
    
   
}


void ofxSIObject::setFixed(bool b, int fixedXPos, int fixedYPos, int fixedWidth, int fixedHeight) {
    
    bIsFixed = b;
    this->fixedXPos = fixedXPos;
    this->fixedYPos = fixedYPos;
    this->fixedWidth = fixedWidth;
    this->fixedHeight = fixedHeight;
    
    
}

void ofxSIObject::calculatePos() {
    pos.x = (fixedXPos == 0 ) ? mom->settings.grid.x * gridPos.x : fixedXPos;
    pos.y = (fixedYPos == 0 ) ? mom->settings.grid.y * gridPos.y : fixedYPos;
    
    // up to bar menu ;)
    if ( !bIsFreePos ) pos.y += mom->settings.grid.y * mom->settings.menuBarGridSize;
}

void ofxSIObject::calculateSize() {
    
    if ( bIsFixed ) {
        
        width = fixedWidth;
        height = fixedHeight;
        
        
    } else {
        
        
        width = (fixedWidth == 0 ) ? mom->settings.grid.x * wGridSize : fixedWidth;
        height =  (fixedHeight == 0 ) ? mom->settings.grid.y * hGridSize : fixedHeight;
        
    }
    
    getBoundingBox();
    
}

ofRectangle ofxSIObject::getBoundingBox() {
    
    boundingBox.set(pos.x, pos.y, width, height);
    return boundingBox;
}




/*
 TODO -> put in other external lib
 utils
*/

void ofxSIObject::roundedRect(float x, float y, float w, float h, float r) {  
    
    r = 0;
    
    if(w== 0 || h==0) return;
    
    ofBeginShape();  
    ofVertex(x+r, y);  
    ofVertex(x+w-r, y);  
    quadraticBezierVertex(x+w, y, x+w, y+r, x+w-r, y);  
    ofVertex(x+w, y+h-r);  
    quadraticBezierVertex(x+w, y+h, x+w-r, y+h, x+w, y+h-r);  
    ofVertex(x+r, y+h);  
    quadraticBezierVertex(x, y+h, x, y+h-r, x+r, y+h);  
    ofVertex(x, y+r);  
    quadraticBezierVertex(x, y, x+r, y, x, y+r);  
    ofEndShape();  
    
    }  

void ofxSIObject::quadraticBezierVertex(float cpx, float cpy, float x, float y, float prevX, float prevY) {  
    float cp1x = prevX + 2.0/3.0*(cpx - prevX);  
    float cp1y = prevY + 2.0/3.0*(cpy - prevY);  
    float cp2x = cp1x + (x - prevX)/3.0;  
    float cp2y = cp1y + (y - prevY)/3.0;  
    
    // finally call cubic Bezier curve function  
    ofBezierVertex(cp1x, cp1y, cp2x, cp2y, x, y);  
};  