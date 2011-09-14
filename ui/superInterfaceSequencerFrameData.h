/*
 *  superInterfaceSequencerFrameData.h
 *  superInterface
 *
 *  Created by Martial on 08/09/2011.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef SUPINTFRDATA
#define SUPINTFRDATA

#include "ofMain.h"
#include "superInterfaceSequencerAnimData.h"

class superInterfaceSequencerFrameData  { 
    
    
public:
    
    superInterfaceSequencerFrameData();
    ~superInterfaceSequencerFrameData();
    vector<superInterfaceSequencerAnimData> anims;
	
	
	
    
};

#endif