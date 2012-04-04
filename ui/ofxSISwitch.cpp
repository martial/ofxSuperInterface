//
//  ofxSISwitch.cpp
//  ofxSI
//
//  Created by Martial Geoffre-Rouland on 04/08/2011.
//   
 
 
//

#include "ofxSISwitch.h"


ofxSISwitch::ofxSISwitch () {
    
    ofxSIInteractiveObject::ofxSIInteractiveObject();
    inherentValue = false;
    bTemporary = false;
    value = NULL;
	
	
	
}

void ofxSISwitch::setup(ofxSuperInterface   * mom, string label, bool &value ) {
    this->value = &value;
    ofxSIInteractiveObject::setup(mom, label);
	
	;
}

void ofxSISwitch::setup(ofxSuperInterface   * mom, string label) {
    this->value = &inherentValue;
    ofxSIInteractiveObject::setup(mom, label);
}

void ofxSISwitch::update() {
    ofxSIInteractiveObject::update();
}

void ofxSISwitch::draw() {
    ofxSIInteractiveObject::draw();
    
}

void ofxSISwitch::setTemporary(bool b) {
    bTemporary = b;
}

void ofxSISwitch::isEnabled(bool b) {
     *value = b;
	eventsArgs.intVals.clear();
	int val = (*value == true) ? 1 : 0;
	eventsArgs.intVals.push_back( &val);
	ofNotifyEvent(eventUpdateValues, eventsArgs, this);
}

void ofxSISwitch::toggle () {
		
	*value=! *value;
	eventsArgs.intVals.clear();
	int val = (*value == true) ? 1 : 0;
	eventsArgs.intVals.push_back( &val);
	ofNotifyEvent(eventUpdateValues, eventsArgs, this);
}

void ofxSISwitch::onMousePressed(int x, int y, int id) {
    
    
    if ( bTemporary ){ 
        
        isEnabled(true);
        
    } else {
        
        toggle();
        
    }
}

void ofxSISwitch::onMouseReleased (int id) {
    if ( bTemporary ) isEnabled(false);
    
}
