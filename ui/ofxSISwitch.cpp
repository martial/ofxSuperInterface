//
//  superInterfaceSwitch.cpp
//  superInterface
//
//  Created by Martial Geoffre-Rouland on 04/08/2011.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#include "superInterfaceSwitch.h"


superInterfaceSwitch::superInterfaceSwitch () {
    
    superInterfaceInteractiveObject::superInterfaceInteractiveObject();
    inherentValue = false;
    bTemporary = false;
    value = NULL;
	
	
	
}

void superInterfaceSwitch::setup(ofxSuperInterface   * mom, string label, bool &value ) {
    this->value = &value;
    superInterfaceInteractiveObject::setup(mom, label);
	
	;
}

void superInterfaceSwitch::setup(ofxSuperInterface   * mom, string label) {
    this->value = &inherentValue;
    superInterfaceInteractiveObject::setup(mom, label);
}

void superInterfaceSwitch::update() {
    superInterfaceInteractiveObject::update();
}

void superInterfaceSwitch::draw() {
    superInterfaceInteractiveObject::draw();
    
}

void superInterfaceSwitch::setTemporary(bool b) {
    bTemporary = b;
}

void superInterfaceSwitch::isEnabled(bool b) {
     *value = b;
	eventsArgs.intVals.clear();
	int val = (*value == true) ? 1 : 0;
	eventsArgs.intVals.push_back( &val);
	ofNotifyEvent(eventUpdateValues, eventsArgs, this);
}

void superInterfaceSwitch::toggle () {
		
	*value=! *value;
	eventsArgs.intVals.clear();
	int val = (*value == true) ? 1 : 0;
	eventsArgs.intVals.push_back( &val);
	ofNotifyEvent(eventUpdateValues, eventsArgs, this);
}

void superInterfaceSwitch::onMousePressed(int x, int y, int id) {
    
    
    if ( bTemporary ){ 
        
        isEnabled(true);
        
    } else {
        
        toggle();
        
    }
}

void superInterfaceSwitch::onMouseReleased (int id) {
    if ( bTemporary ) isEnabled(false);
    
}
