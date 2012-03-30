/*
 *  ofxSIVSlider.h
 *  ofxSI
 *
 *  Created by Martial on 07/09/2011.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef SUPINTVSLIDER
#define SUPINTVSLIDER

#include "ofMain.h"
#include "ofxSIComponent.h"

class ofxSIVSlider : public ofxSIComponent { 
    
    
public:
    
    ofxSIVSlider();
    void setup(ofxSuperInterface   * mom, float * value, int xGridPos, int yGridPos, int wGridSize, int hGridSize, float minVal = 0.0, float maxVal = 1.0, string label = "slider" );
	void setup(ofxSuperInterface   * mom, int xGridPos, int yGridPos, int wGridSize, int hGridSize, float minVal = 0.0, float maxVal = 1.0, string label = "slider" );
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
    
    
    
    
};


#endif
