//
//  superInterfacePage.cpp
//  emptyExample
//
//  Created by Martial Geoffre-Rouland on 08/08/2011.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#include "superInterfacePage.h"


superInterfacePage::superInterfacePage(){
     enabled = true;
}
void superInterfacePage::setup(ofxSuperInterface * mom, int pageNumber){
    this->mom = mom;
    this->pageNumber = pageNumber;
    
    bgColor.set(0,0,0);
   
    
}
void superInterfacePage::update(){
    
    for ( int i = 0; i<components.size(); i++) {
        if( !components[i]->bAutoUpdate ) components[i]->update();
    }
    
}
void superInterfacePage::draw(){
    
  
    for ( int i = 0; i<components.size(); i++) {
        components[i]->draw();
    }
    
}

void superInterfacePage::addComponent(superInterfaceComponent * component){
    components.push_back(component);
}
void superInterfacePage::removeComponentByLabel(string label){
    
    for ( int i = components.size()-1; i>= 0; i--) {
        superInterfaceComponent * comp = components[i];
        if ( comp->settings->label == label ){
            components.erase (components.begin() + i);
        }
    }
    
    
}





/* events */


#if !defined( TARGET_OF_IPHONE ) 

void superInterfacePage::mouseMoved(ofMouseEventArgs &e){
    
}
void superInterfacePage::mouseDragged(ofMouseEventArgs &e){
	
    for ( int i = 0; i<components.size(); i++) {
        components[i]->mouseMoved(e);
    }
}

void superInterfacePage::mousePressed(ofMouseEventArgs &e){
    
    
    for ( int i = 0; i<components.size(); i++) {
        components[i]->mousePressed(e);
    }
    
}

void superInterfacePage::mouseReleased(ofMouseEventArgs &e){
    
    for ( int i = 0; i<components.size(); i++) {
        components[i]->mouseReleased(e);
    }
    
}


#else

void superInterfacePage::touchDown(ofTouchEventArgs &touch){
    
    if(!enabled ) return;
    for ( int i = 0; i<components.size(); i++) {
        components[i]->touchDown(touch);
    }    
}

void superInterfacePage::touchMoved(ofTouchEventArgs &touch){
    if(!enabled ) return;
    
    
    for ( int i = 0; i<components.size(); i++) {
        components[i]->touchMoved(touch);
    }
    
    
    
}

void superInterfacePage::touchUp(ofTouchEventArgs &touch){
    
     if(!enabled ) return;
    for ( int i = 0; i<components.size(); i++) {
        components[i]->touchUp(touch);
    }
    
}

void superInterfacePage::touchDoubleTap(ofTouchEventArgs &touch){
     if(!enabled ) return;
}

void superInterfacePage::touchCancelled(ofTouchEventArgs &touch){
     if(!enabled ) return;
}


#endif
