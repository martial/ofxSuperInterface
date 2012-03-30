//
//  superInterfaceSimpleButton.h
//  superInterface
//
//  Created by Martial Geoffre-Rouland on 04/08/2011.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#ifndef SUPINTSMPLBTN
#define SUPINTSMPLBTN
    
#include "ofMain.h"
#include "superInterfaceSwitch.h"

class superInterfaceSimpleButton : public superInterfaceSwitch {
        
    public :
    
    superInterfaceSimpleButton();
    void setup(ofxSuperInterface   * mom, bool &value, string label = "button",  int xGridPos = 0, int yGridPos = 0, int wGridSize = 0, int hGridSize = 0);
    void setup(ofxSuperInterface   * mom, string label = "button",  int xGridPos = 0, int yGridPos = 0, int wGridSize = 0, int hGridSize = 0);
    void update();
    void draw();
    void setTemporary(bool b);
    
    
    
};


#endif