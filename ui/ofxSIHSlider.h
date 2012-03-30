//
//  superInterfaceHSlider.h
//  emptyExample
//
//  Created by Martial Geoffre-Rouland on 05/08/2011.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#ifndef SUPINTHSLIDER
#define SUPINTHSLIDER

#include "ofMain.h"
#include "superInterfaceComponent.h"
#include "superInterfaceTextLabel.h"

class superInterfaceHSlider : public superInterfaceComponent { 
    
    
public:
    
    superInterfaceHSlider();
    void setup(ofxSuperInterface   * mom, float * value, int xGridPos, int yGridPos, int wGridSize, int hGridSize, float minVal = 0.0, float maxVal = 1.0, string label = "slider" );
    void update();
    void draw();
    
    void onMouseDragged (int x, int y, int id );
    void roundValues(bool bActive);
	
    
    float pct;
    float minVal, maxVal;
    float targetValue;
    float *value;
    
    int  assignedId;
    
    bool bRounded;
    
    
    superInterfaceTextLabel txtLabel;
    
    
};


#endif
