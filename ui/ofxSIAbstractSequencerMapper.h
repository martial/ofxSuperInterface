//
//  ofxSIAbstractSequencerMapper.h
//  emptyExample
//
//  Created by Martial Geoffre-Rouland on 13/09/2011.
//  Copyright (c) 2011 __MyCompanyName__. All rights reserved.
//

#ifndef SUPTINTABSTRCTMAPP
#define SUPTINTABSTRCTMAPP

#include "ofMain.h"
#include "ofxSISequencerAnimData.h"

class ofxSIAbstractSequencerMapper {
    
  
public:
        
    virtual void setPoints(){};
    virtual void draw(float x, float y){};
    virtual vector<int> * getActivePoints(vector<ofxSISequencerAnimData> * anims){};
    void    clearPoints() {activePoints.clear();} ;
    vector<ofVec2f> pnts;
    vector<int>     activePoints;
    
    int width, height;
    
};

#endif
