//
//  superInterfacePage.h
//  emptyExample
//
//  Created by Martial Geoffre-Rouland on 08/08/2011.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#ifndef SUPINTPAGE
#define SUPINTPAGE

#include "ofMain.h"
#include "superInterfaceComponent.h"


class superInterfacePage {
        
public:
    
    
    superInterfacePage();
    virtual void setup(ofxSuperInterface * mom);
    virtual void update();
    virtual void draw();
    
    void addComponent(superInterfaceComponent * component);
    void removeComponentByLabel(string label);
    
    bool enabled;
    
#if !defined( TARGET_OF_IPHONE ) 
    
    virtual void mouseMoved(ofMouseEventArgs &e );
    virtual void mouseDragged(ofMouseEventArgs &e);
    virtual void mousePressed(ofMouseEventArgs &e);
    virtual void mouseReleased(ofMouseEventArgs &en);
    
#else
    
    virtual void touchDown(ofTouchEventArgs &touch);
    virtual void touchMoved(ofTouchEventArgs &touch);  
    virtual void touchUp(ofTouchEventArgs &touch);  
    virtual void touchDoubleTap(ofTouchEventArgs &touch); 
    virtual void touchCancelled(ofTouchEventArgs &touch);
    
#endif
    
    
    ofColor                           bgColor;
    ofxSuperInterface               * mom;
    
    vector<superInterfaceComponent*> components;

    
private:
    
    
      
};


#endif
