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

void superInterfaceSwitch::setup(ofxSuperInterface   * mom,bool &value) {
    this->value = &value;
    superInterfaceInteractiveObject::setup(mom);
}

void superInterfaceSwitch::setup(ofxSuperInterface   * mom) {
    this->value = &inherentValue;
    superInterfaceInteractiveObject::setup(mom);
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
}

void superInterfaceSwitch::toggle () {
    
      *value=! *value;
    
}

void superInterfaceSwitch::onMousePressed() {
    
    
    if ( bTemporary ){ 
        
        isEnabled(true);
        
    } else {
        
        toggle();
        
    }
}

void superInterfaceSwitch::onMouseReleased () {
    if ( bTemporary ) isEnabled(false);
    
}
