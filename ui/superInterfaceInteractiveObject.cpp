//
//  superInterfaceInteractiveObject.cpp
//  superInterface
//
//  Created by Martial Geoffre-Rouland on 04/08/2011.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#include "superInterfaceInteractiveObject.h"
#include "ofxSuperInterface.h"

superInterfaceInteractiveObject::superInterfaceInteractiveObject() {
    
    superInterfaceObject::superInterfaceObject();
    
    
    isRollOver = false;
    isMouseDown = false;
    
   
   
    //ofRegisterTouchEvents(this); 
    //ofxiPhoneAlerts.addListener(this);

}

void superInterfaceInteractiveObject::setup (ofxSuperInterface   * mom) {
    
    superInterfaceObject::setup(mom);
    
}



/*
 
 EVENTS
 
 */



bool superInterfaceInteractiveObject::hitTest(ofPoint tPos) {
        return ((tPos.x > pos.x) && (tPos.x < pos.x + width) && (tPos.y > pos.y) && (tPos.y < pos.y + height));
}


 #if !defined( TARGET_OF_IPHONE ) 

void superInterfaceInteractiveObject::mousePressed(ofMouseEventArgs &e) { onDownHandler(e.x, e.y) }
void superInterfaceInteractiveObject::mouseReleased(ofMouseEventArgs &e) {onUpHandler() }
void superInterfaceInteractiveObject::mouseMoved(ofMouseEventArgs &e) {onMovedHandler(e.x, e.y) }

#else 


void superInterfaceInteractiveObject::touchDown(ofTouchEventArgs &touch) { onDownHandler(touch.x, touch.y, touch.id);}
void superInterfaceInteractiveObject::touchUp(ofTouchEventArgs &touch) { onUpHandler(touch.id);}
void superInterfaceInteractiveObject::touchMoved(ofTouchEventArgs &touch) { onMovedHandler(touch.x, touch.y, touch.id);}

#endif



void superInterfaceInteractiveObject::onDownHandler(int x, int y, int id) {
    
    
    ofPoint mousePos;
    mousePos.set(x, y);
    
    if ( hitTest(mousePos) ) {
        onMousePressed();
        assignedId = id;
        isMouseDown = true;
        ofNotifyEvent(eventMouseDown, eventsArgs, this );
    }

}

void superInterfaceInteractiveObject::onUpHandler(int id) {
    if ( assignedId == id ) {
        onMouseReleased();
        isMouseDown = false;
    }
}

void superInterfaceInteractiveObject::onMovedHandler(int x, int y, int id) {

    
    ofPoint mousePos;
    mousePos.set(x, y);
    bool isMouseOver =  hitTest(mousePos);
    
    
    if ( isMouseDown && mom->bPositionMode && !bIsFixed) {
        setPosition(x, y, true);
    }
       
    if(!bEnabled) return;
    
      
    
    
    if ( isMouseDown && assignedId == id) {
        
        if ( bEnabled ) {
        onMouseDragged(x, y);
        if (!isRollOver ) onRollOver();
        }
        
    } else {
        
        if (isRollOver ) onRollOut();
    }
    
    isRollOver = isMouseOver;

    
}

void superInterfaceInteractiveObject::setPosition(int x, int y, bool bSnapToGrid) {
    
    x -= width*.5; 
    y -= height*.5;
    pos.x = (bSnapToGrid) ? roundToNumber(x, mom->settings.grid.x) : x;
    pos.y = (bSnapToGrid) ? roundToNumber(y, mom->settings.grid.y) : y;
    
    
}

int superInterfaceInteractiveObject::roundToNumber(int val, int roundTo) {
    
    if (roundTo == 0) return 0;
    return ((val + roundTo - 1) / roundTo) * roundTo;
    
}



void superInterfaceInteractiveObject::update() {
    
    superInterfaceObject::update();
  
    
}

void superInterfaceInteractiveObject::draw() {
    
    superInterfaceObject::draw();
    
 
    ofSetColor((!bEnabled) ? this->mom->settings.disabledColor : (!isMouseDown) ? this->settings->bgColor : this->settings->bgColorRoll);
    

    ofRect(pos.x, pos.y, width, height);
    
    if ( mom->bPositionMode ) {
        
       // ofSetColor(255, 0, 0);
       // ofDrawBitmapString(this->settings->label, pos.x, pos.y);
        
    }
    
   // onMousePressed();
    
}


