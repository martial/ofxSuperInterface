/*
 *  ofxSIFbo.h
 *  ofxSI
 *
 *  Created by Martial on 07/09/2011.
 *   
 


 *
 */

#ifndef SUPINTFBO
#define SUPINTFBO

#include "ofMain.h"
#include "ofxSIComponent.h"


class ofxSIFbo : public ofxSIComponent { 
    
    
public:
    
    ofxSIFbo();
    void setup(ofxSuperInterface   * mom, ofFbo * fbo, int xGridPos, int yGridPos, int wGridSize, int hGridSize, string label = "fbo" );
	void update();
    void draw();
    
	ofFbo * fbo;
    bool	bKeepProportions;
	int		fboWidth, fboHeight;
    
};


#endif
