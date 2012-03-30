//
//  ofxSISettingsPage.h
//  emptyExample
//
//  Created by Martial Geoffre-Rouland on 08/08/2011.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#ifndef SUPINTSETTPG
#define SUPINTSETTPG

#include "ofMain.h"
#include "ofxSIPage.h"
#include "ofxSIHSlider.h"
#include "ofxSISimpleButton.h"
#include "ofxSIHTextLabel.h"

class ofxSuperInterface;

class ofxSISettingsPage : public ofxSIPage {
    
public:
    
    ofxSISettingsPage();
    
    void setup(ofxSuperInterface * mom);    
    void update();
    void draw();
    
    ofxSIHSlider           xUnitSlider;
    ofxSIHSlider           yUnitSlider;
	ofxSISimpleButton      gridBtn;
    ofxSISimpleButton      saveBtn;
	ofxSISimpleButton      positionBtn;
    ofxSIHTextLabel        label;
    
    
};



#endif
