/*
 *  superInterfaceFbo.h
 *  superInterface
 *
 *  Created by Martial on 07/09/2011.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef SUPINTFBO
#define SUPINTFBO

#include "ofMain.h"
#include "superInterfaceComponent.h"


class superInterfaceFbo : public superInterfaceComponent { 
    
    
public:
    
    superInterfaceFbo();
    void setup(ofxSuperInterface   * mom, ofFbo * fbo, int xGridPos, int yGridPos, int wGridSize, int hGridSize, string label = "fbo" );
	void update();
    void draw();
    
	ofFbo * fbo;
    bool	bKeepProportions;
	int		fboWidth, fboHeight;
    
};


#endif
