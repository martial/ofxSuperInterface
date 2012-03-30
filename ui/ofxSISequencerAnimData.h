/*
 *  ofxSIPointData.h
 *  ofxSI
 *
 *  Created by Martial on 08/09/2011.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef SUPINTPTDATA
#define SUPINTPTDATA

#include "ofMain.h"


class ofxSISequencerAnimData  { 
    
    
public:
    
    ofxSISequencerAnimData();
    ~ofxSISequencerAnimData();
    string                      type;
	vector<ofVec2f> pnts;
	
	
    
};

#endif