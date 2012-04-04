//
//  ofxSIComponent.cpp
//  emptyExample
//
//  Created by Martial Geoffre-Rouland on 05/08/2011.
//   
 
 
//

#include "ofxSIComponent.h"


ofxSIComponent::ofxSIComponent(){
     
}
void ofxSIComponent::setup(ofxSuperInterface   * mom, string label){
     ofxSIInteractiveObject::setup(mom, label);
}

void ofxSIComponent::update(){
    ofxSIInteractiveObject::update();
}

void ofxSIComponent::update(ofEventArgs & e){
    ofxSIInteractiveObject::update(e);
}
void ofxSIComponent::draw(){
    ofxSIInteractiveObject::draw();    
}

void ofxSIComponent::onMousePressed(int x, int y, int id){
    
}
void ofxSIComponent::onMouseDragged(int x, int y){
    
}
void ofxSIComponent::onMouseMoved(){
    
}
void ofxSIComponent::onMouseReleased(){
    
}