//
//  superInterfaceInteractiveObject.h
//  superInterface
//
//  Created by Martial Geoffre-Rouland on 04/08/2011.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#ifndef SUPINTINTOBJ
#define SUPINTINTOBJ

#include "ofMain.h"
#include "ofEvents.h"
#include "superInterfaceObject.h"
#include "superInterfaceEventArgs.h"


class superInterfaceInteractiveObject : public superInterfaceObject {
    
    public:
    superInterfaceInteractiveObject();
    void setup(ofxSuperInterface   * mom, string label);
    void update();
    void draw();
    
    virtual void onMousePressed(){};
    virtual void onMouseDragged(int x, int y){};
    virtual void onMouseDragged(int x, int y, int id){};
    //virtual void onMouseMoved(){};
    virtual void onMouseReleased(){};
    
    virtual void onRollOver(){};
    virtual void onRollOut(){};
    
    bool         isMouseDown, isRollOver;
    
	
	
    void setPosition(int x, int y, bool bSnapToGrid = false) ;
    
	
	
    
    #if !defined( TARGET_OF_IPHONE ) 
    
    void mousePressed(ofMouseEventArgs &e);
    void mouseMoved(ofMouseEventArgs &e );
    void mouseDragged(ofMouseEventArgs &e);
    void mouseReleased(ofMouseEventArgs &en);
    
    
    #else
    
    void touchDown(ofTouchEventArgs &touch);
    void touchMoved(ofTouchEventArgs &touch);  
    void touchUp(ofTouchEventArgs &touch);  
    void touchDoubleTap(ofTouchEventArgs &touch){}; 
    void touchCancelled(ofTouchEventArgs &touch){};
    #endif
    
    void onDownHandler(int x, int y, int id = -1);
    void onMovedHandler(int x, int y, int id = -1);
    void onUpHandler(int id = -1);
    
	
	
	ofEvent<superInterfaceEventArgs>   eventOscEnabled;
	ofEvent<superInterfaceEventArgs>   eventUpdateValues;
    ofEvent<superInterfaceEventArgs>   eventMouseDown;
	ofEvent<superInterfaceEventArgs>   eventChangePos;
	
	
	
	virtual void enableOSC(bool bEnabled, string oscAdress = "");
	virtual void sendOscValues ();
	
	
    
    private :
    
    int  assignedId;
    bool hitTest(ofPoint tPos);
    int  roundToNumber(int val, int roundTo);
    
	

   
   // void _onTouchDragged(ofMouseEventArgs &e);
    //void _onTouchMoved(ofMouseEventArgs &e);
    //void _onTouchReleased(ofMouseEventArgs &e);
    
    
};



#endif
