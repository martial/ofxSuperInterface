//
//  ofxSIPage.h
//  emptyExample
//
//  Created by Martial Geoffre-Rouland on 08/08/2011.
 
 


//

#ifndef SUPINTPAGE
#define SUPINTPAGE

#include "ofMain.h"
#include "ofxSIComponent.h"

class ofxSuperInterface;

class ofxSIPage {
        
public:
    
    
    ofxSIPage();
    virtual void setup(ofxSuperInterface * mom, int pageNumber);
    virtual void update();
    virtual void draw();
    
    void addComponent(ofxSIComponent * component);
    void removeComponentByLabel(string label);
    
    void alignAll();
    
    
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
    ofxSuperInterface                 * mom;
    
    vector<ofxSIComponent*> components;
    
    bool enabled;
    int pageNumber;
    string xmlPath;

    
private:
    
    
      
};


#endif
