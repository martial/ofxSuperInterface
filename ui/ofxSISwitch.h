//
//  ofxSISwitch.h
//  ofxSI
//
//  Created by Martial Geoffre-Rouland on 04/08/2011.
 
 


//

#ifndef SUPINTSWITCH
#define SUPINTSWITCH

#include "ofMain.h"
#include "ofxSIComponent.h"

class ofxSISwitch : public ofxSIComponent {
    
    
    public :
    
    ofxSISwitch();
    void setup(ofxSuperInterface   * mom, string label, bool &value);
    void setup(ofxSuperInterface   * mom, string label);
    void update();
    void draw();
    
    virtual void setTemporary(bool b);
    void toggle();
    void isEnabled(bool b);
    
    
    void onMousePressed(int x, int y, int id);
    void onMouseDragged(int x, int y, int id ){};
    void onMouseMoved(){};
    void onMouseReleased(int id);
    
    bool    inherentValue;
    bool    *value;
    bool    bTemporary;
    
    
};



#endif
