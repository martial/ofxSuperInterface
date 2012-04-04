//
//  ofxSIPage.cpp
//  emptyExample
//
//  Created by Martial Geoffre-Rouland on 08/08/2011.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#include "ofxSIPage.h"
#include "ofxSuperInterface.h"

ofxSIPage::ofxSIPage(){
     enabled = true;
}
void ofxSIPage::setup(ofxSuperInterface * mom, int pageNumber){
    this->mom = mom;
    this->pageNumber = pageNumber;
    
    bgColor.set(0,0,0);
   
    
}
void ofxSIPage::update(){
    
    for ( int i = 0; i<components.size(); i++) {
        if( !components[i]->bAutoUpdate ) components[i]->update();
    }
    
}
void ofxSIPage::draw(){
    
  
    for ( int i = 0; i<components.size(); i++) {
        components[i]->draw();
    }
    
}

void ofxSIPage::addComponent(ofxSIComponent * component){
    components.push_back(component);
}
void ofxSIPage::removeComponentByLabel(string label){
    
    for ( int i = components.size()-1; i>= 0; i--) {
        ofxSIComponent * comp = components[i];
        if ( comp->settings->label == label ){
            components.erase (components.begin() + i);
        }
    }
    
    
}


void ofxSIPage::alignAll () {
    
    int numOfGridX = ofGetWidth() / mom->settings.grid.x;
    
    int xGridPos = 0;
    int yGridPos = 0;
    int maxHGridSize = 0;
    for ( int i = 0; i<components.size(); i++) {
        
        components[i]->gridPos.x = xGridPos;
        components[i]->gridPos.y = yGridPos;
        components[i]->savePositionValues();
         
        xGridPos += components[i]->wGridSize + 1;
        maxHGridSize = max(components[i]->hGridSize, maxHGridSize);
        
        if ( i< components.size()-1 && xGridPos + components[i+1]->wGridSize  > numOfGridX ) {
            xGridPos = 0;
            yGridPos += maxHGridSize +1;
            maxHGridSize = 0;
            
        }
        
    }
    
}


/* events */


#if !defined( TARGET_OF_IPHONE ) 

void ofxSIPage::mouseMoved(ofMouseEventArgs &e){
    for ( int i = 0; i<components.size(); i++) {
        components[i]->mouseMoved(e);
    }
    
}
void ofxSIPage::mouseDragged(ofMouseEventArgs &e){
	
    for ( int i = 0; i<components.size(); i++) {
        components[i]->mouseDragged(e);
    }
}

void ofxSIPage::mousePressed(ofMouseEventArgs &e){
    
    
    for ( int i = 0; i<components.size(); i++) {
        components[i]->mousePressed(e);
    }
    
}

void ofxSIPage::mouseReleased(ofMouseEventArgs &e){
    
    for ( int i = 0; i<components.size(); i++) {
        components[i]->mouseReleased(e);
    }
    
}


#else

void ofxSIPage::touchDown(ofTouchEventArgs &touch){
    
    if(!enabled ) return;
    for ( int i = 0; i<components.size(); i++) {
        components[i]->touchDown(touch);
    }    
}

void ofxSIPage::touchMoved(ofTouchEventArgs &touch){
    if(!enabled ) return;
    
    
    for ( int i = 0; i<components.size(); i++) {
        components[i]->touchMoved(touch);
    }
    
    
    
}

void ofxSIPage::touchUp(ofTouchEventArgs &touch){
    
     if(!enabled ) return;
    for ( int i = 0; i<components.size(); i++) {
        components[i]->touchUp(touch);
    }
    
}

void ofxSIPage::touchDoubleTap(ofTouchEventArgs &touch){
     if(!enabled ) return;
}

void ofxSIPage::touchCancelled(ofTouchEventArgs &touch){
     if(!enabled ) return;
}


#endif
