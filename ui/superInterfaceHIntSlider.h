/*
 *  superInterfaceHIntSlider.h
 *  MODULAR_SHIP
 *
 *  Created by Martial on 12/09/2011.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef SUPINTHINTSLIDER
#define SUPINTHINTSLIDER

#include "ofMain.h"
#include "superInterfaceComponent.h"
#include "superInterfaceTextLabel.h"

class superInterfaceHIntSlider : public superInterfaceComponent { 
    
    
public:
    
    superInterfaceHIntSlider();
    void setup(ofxSuperInterface   * mom, int * value, int xGridPos, int yGridPos, int wGridSize, int hGridSize, float minVal = 0.0, float maxVal = 1.0, string label = "slider" );
    void update();
    void draw();
    
    void onMouseDragged (int x, int y, int id );
    void roundValues(bool bActive);
	
    
    float pct;
    int minVal, maxVal;
    int targetValue;
    int *value;
    
    int  assignedId;
    
    
    
    superInterfaceTextLabel txtLabel;
    
    
};


#endif