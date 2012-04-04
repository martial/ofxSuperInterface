/*
 *  ofxSISequencerFrameData.h
 *  ofxSI
 *
 *  Created by Martial on 08/09/2011.
 *   
 


 *
 */

#ifndef SUPINTFRDATA
#define SUPINTFRDATA

#include "ofMain.h"
#include "ofxSISequencerAnimData.h"

class ofxSISequencerFrameData  { 
    
    
public:
    
    ofxSISequencerFrameData();
    ~ofxSISequencerFrameData();
    vector<ofxSISequencerAnimData> anims;
	
	
	
    
};

#endif