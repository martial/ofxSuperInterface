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
    isMultiTouch = false;
    bAutoUpdate = false;
   
    nTouches = 0;
    //ofRegisterTouchEvents(this); 
    //ofxiPhoneAlerts.addListener(this);

}

void superInterfaceInteractiveObject::setup (ofxSuperInterface   * mom, string label) {
    
    superInterfaceObject::setup(mom, label);
    
}



/*
 
 EVENTS
 
 */



bool superInterfaceInteractiveObject::hitTest(ofPoint tPos) {
        return ((tPos.x > pos.x) && (tPos.x < pos.x + width) && (tPos.y > pos.y) && (tPos.y < pos.y + height));
}


 #if !defined( TARGET_OF_IPHONE ) 

void superInterfaceInteractiveObject::mousePressed(ofMouseEventArgs &e) { onDownHandler(e.x, e.y); }
void superInterfaceInteractiveObject::mouseReleased(ofMouseEventArgs &e) {onUpHandler(); }
void superInterfaceInteractiveObject::mouseMoved(ofMouseEventArgs &e) {onMovedHandler(e.x, e.y); }

#else 


void superInterfaceInteractiveObject::touchDown(ofTouchEventArgs &touch) { onDownHandler(touch.x, touch.y, touch.id);}
void superInterfaceInteractiveObject::touchUp(ofTouchEventArgs &touch) { onUpHandler(touch.id);}
void superInterfaceInteractiveObject::touchMoved(ofTouchEventArgs &touch) { onMovedHandler(touch.x, touch.y, touch.id);}

#endif



void superInterfaceInteractiveObject::onDownHandler(int x, int y, int id) {
    
    
    ofPoint mousePos;
    mousePos.set(x, y);
    
    if ( hitTest(mousePos) ) {
        onMousePressed(x,y, id);
        assignedId = id;
        isMouseDown = true;
        nTouches++;
        ofNotifyEvent(eventMouseDown, eventsArgs, this );
    }

}

void superInterfaceInteractiveObject::onUpHandler(int id) {
    
    if(isMultiTouch) {
        nTouches--;
        if(nTouches<0) nTouches = 0;
        onMouseReleased(id);
        
        if(nTouches==0) isMouseDown = false;
        
    } else {
    
        if ( assignedId == id ) {
            onMouseReleased(id);
            isMouseDown = false;
        }
        
    }
}

void superInterfaceInteractiveObject::onMovedHandler(int x, int y, int id) {
	
    
    ofPoint mousePos;
    mousePos.set(x, y);
    bool isMouseOver =  hitTest(mousePos);
    
    
    if ( isMouseDown && mom->bPositionMode && !bIsFixed) {
        setGridPosByScreenCoords(x, y);
		ofNotifyEvent(eventChangePos, eventsArgs, this);
    }
       
    if(!bEnabled) return;
    
      
    if(isMultiTouch) {
    
    if( isMouseDown) {
        onMouseDragged(x, y, id);
         if (!isRollOver ) onRollOver();
    } else {
        
        if (isRollOver ) onRollOut();
    }
    
    } else {
        
    if ( isMouseDown && assignedId == id) {
        
       // if ( bEnabled ) {
        onMouseDragged(x, y, id);
        if (!isRollOver ) onRollOver();
       // }
        
    } else {
        
        if (isRollOver ) onRollOut();
    }
    
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


void superInterfaceInteractiveObject::update(ofEventArgs & e) {
    update();    
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

void superInterfaceInteractiveObject::enableAutoUpdate(bool bEnabled) {
    
    this->bAutoUpdate = bEnabled;
    ofNotifyEvent(eventAutoUpdateEnabled, eventsArgs, this);
}


void superInterfaceInteractiveObject::enableOSC(bool bEnabled, string oscAdress) {
		
	this->settings->bOscEnabled = bEnabled;
	if(oscAdress != "" ) this->settings->oscAdress = oscAdress + "/" + this->settings->label;
	ofNotifyEvent(eventOscEnabled, eventsArgs, this);
}

void superInterfaceInteractiveObject::sendOscValues() {
	
	//typeid(x).name();
}


