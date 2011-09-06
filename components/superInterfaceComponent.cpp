//
//  superInterfaceComponent.cpp
//  emptyExample
//
//  Created by Martial Geoffre-Rouland on 05/08/2011.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#include "superInterfaceComponent.h"


superInterfaceComponent::superInterfaceComponent(){
    
}
void superInterfaceComponent::setup(ofxSuperInterface   * mom, string label){
     superInterfaceInteractiveObject::setup(mom, label);
}


void superInterfaceComponent::update(){
    superInterfaceInteractiveObject::update();
}
void superInterfaceComponent::draw(){
    superInterfaceInteractiveObject::draw();
    
    ///if(!assets) ofLog(0, "Warning - no assets detected");
    
}

void superInterfaceComponent::onMousePressed(){
    
}
void superInterfaceComponent::onMouseDragged(int x, int y){
    
}
void superInterfaceComponent::onMouseMoved(){
    
}
void superInterfaceComponent::onMouseReleased(){
    
}