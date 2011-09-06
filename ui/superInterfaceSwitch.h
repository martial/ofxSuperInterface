//
//  superInterfaceSwitch.h
//  superInterface
//
//  Created by Martial Geoffre-Rouland on 04/08/2011.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#ifndef SUPINTSWITCH
#define SUPINTSWITCH

#include "ofMain.h"
#include "superInterfaceComponent.h"

class superInterfaceSwitch : public superInterfaceComponent {
    
    
    public :
    
    superInterfaceSwitch();
    void setup(ofxSuperInterface   * mom, bool &value);
    void setup(ofxSuperInterface   * mom);
    void update();
    void draw();
    
    virtual void setTemporary(bool b);
    void toggle();
    void isEnabled(bool b);
    
    
    void onMousePressed();
    void onMouseDragged();
    void onMouseMoved();
    void onMouseReleased();
    
    bool    inherentValue;
    bool    *value;
    bool    bTemporary;
    
    
};



#endif
