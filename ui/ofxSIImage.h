/*
 *  superInterfaceImage.h
 *  MODULAR_SHIP
 *
 *  Created by Martial on 15/09/2011.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef SUPINTOFIMG
#define SUPINTOFIMG

#include "ofMain.h"
#include "superInterfaceComponent.h"


class superInterfaceImage : public superInterfaceComponent { 
    
    
public:
    
    superInterfaceImage();
    void setup(ofxSuperInterface   * mom, ofImage * img, int xGridPos, int yGridPos, int wGridSize, int hGridSize, string label = "img" );
	void update();
    void draw();
    
	ofImage * img;
    bool	bKeepProportions;
	int		fboWidth, fboHeight;
    
};


#endif