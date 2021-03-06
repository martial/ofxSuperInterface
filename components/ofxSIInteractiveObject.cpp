//
//  ofxSIInteractiveObject.cpp
//  ofxSI
//
//  Created by Martial Geoffre-Rouland on 04/08/2011.
//   
 
 
//

#include "ofxSIInteractiveObject.h"
#include "ofxSuperInterface.h"

ofxSIInteractiveObject::ofxSIInteractiveObject() {
    
    ofxSIObject::ofxSIObject();
    
    
    isRollOver = false;
    isMouseDown = false;
    isMultiTouch = false;
    bAutoUpdate = false;
   
    nTouches = 0;
    //ofRegisterTouchEvents(this); 
    //ofxiPhoneAlerts.addListener(this);

}

void ofxSIInteractiveObject::setup (ofxSuperInterface   * mom, string label) {
    
    ofxSIObject::setup(mom, label);
    
}



/*
 
 EVENTS
 
 */



bool ofxSIInteractiveObject::hitTest(ofPoint tPos) {
        return ((tPos.x > pos.x) && (tPos.x < pos.x + width) && (tPos.y > pos.y) && (tPos.y < pos.y + height));
}


#if !defined( TARGET_OF_IPHONE ) 

void ofxSIInteractiveObject::mousePressed(ofMouseEventArgs &e) { onDownHandler(e.x, e.y); }
void ofxSIInteractiveObject::mouseReleased(ofMouseEventArgs &e) {onUpHandler(); }
void ofxSIInteractiveObject::mouseMoved(ofMouseEventArgs &e) {onMovedHandler(e.x, e.y); }
void ofxSIInteractiveObject::mouseDragged(ofMouseEventArgs &e) {onDraggedHandler(e.x, e.y); }
#else 


void ofxSIInteractiveObject::touchDown(ofTouchEventArgs &touch) { onDownHandler(touch.x, touch.y, touch.id);}
void ofxSIInteractiveObject::touchUp(ofTouchEventArgs &touch) { onUpHandler(touch.id);}
void ofxSIInteractiveObject::touchMoved(ofTouchEventArgs &touch) { onDraggedHandler(touch.x, touch.y, touch.id); onMovedHandler(e.x, e.y);}

#endif



void ofxSIInteractiveObject::onDownHandler(int x, int y, int id) {
    
    
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

void ofxSIInteractiveObject::onUpHandler(int id) {
    
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

void ofxSIInteractiveObject::onDraggedHandler(int x, int y, int id) {
	
    
    ofPoint mousePos;
    mousePos.set(x, y);
    
      
    if ( isMouseDown && mom->bPositionMode && !bIsFixed) {
        setGridPosByScreenCoords(x, y);
		savePositionValues();        
    }
       
    if(!bEnabled) return;
    
      
    if(isMultiTouch) {
    
    if( isMouseDown) 
        onMouseDragged(x, y, id);
    
    } else {
        
    if ( isMouseDown && assignedId == id) 
        onMouseDragged(x, y, id);
    
    }
    
    

    
}

void ofxSIInteractiveObject::onMovedHandler(int x, int y, int id) {
	
    
    ofPoint mousePos;
    mousePos.set(x, y);
    bool isMouseOver =  hitTest(mousePos);
    
    
    
    if(!bEnabled) return;
    
    onMouseMoved();
      
    (!isRollOver ) ? onRollOver() : onRollOut();
        
        
    isRollOver = isMouseOver;
    
    
}

void ofxSIInteractiveObject::setPosition(int x, int y, bool bSnapToGrid) {
    
    x -= width*.5; 
    y -= height*.5;
    pos.x = (bSnapToGrid) ? roundToNumber(x, mom->settings.grid.x) : x;
    pos.y = (bSnapToGrid) ? roundToNumber(y, mom->settings.grid.y) : y;
    
    
}

int ofxSIInteractiveObject::roundToNumber(int val, int roundTo) {
    
    if (roundTo == 0) return 0;
    return ((val + roundTo - 1) / roundTo) * roundTo;
    
}


void ofxSIInteractiveObject::update(ofEventArgs & e) {
    update();    
}

void ofxSIInteractiveObject::update() {
    ofxSIObject::update();    
}

void ofxSIInteractiveObject::draw() {
    
    ofxSIObject::draw();
    
 
    ofSetColor((!bEnabled) ? this->mom->settings.disabledColor : (!isMouseDown) ? this->settings->bgColor : this->settings->bgColorRoll);
    ofRect(pos.x, pos.y, width, height);
    
    
}

void ofxSIInteractiveObject::enableAutoUpdate(bool bEnabled) {
    
    this->bAutoUpdate = bEnabled;
    ofNotifyEvent(eventAutoUpdateEnabled, eventsArgs, this);
}


void ofxSIInteractiveObject::enableOSC(bool bEnabled, string oscAdress) {
		
	this->settings->bOscEnabled = bEnabled;
	if(oscAdress != "" ) this->settings->oscAdress = oscAdress + "/" + this->settings->label;
	ofNotifyEvent(eventOscEnabled, eventsArgs, this);
}

void ofxSIInteractiveObject::sendOscValues() {
	
	//typeid(x).name();
}

void ofxSIInteractiveObject::savePositionValues() {
    ofNotifyEvent(eventChangePos, eventsArgs, this);    
}

