/*
 *  superInterfaceOscManager.h
 *  superInterface
 *
 *  Created by Martial on 07/09/2011.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef SUPINTOSCMNG
#define SUPINTOSCMNG

#include "ofMain.h"
#include "ofxOsc.h"
#include "superInterfaceInteractiveObject.h"
#include "superInterfaceObject.h"
#include "superInterfaceEventArgs.h"

class superInterfaceOscManager {
	
public:
	
	superInterfaceOscManager();
	void setup(string host, int port);
	void addComponentListener(superInterfaceInteractiveObject * comp);
	void removeComponentListener(superInterfaceInteractiveObject * comp);
	void sendOscValues(superInterfaceEventArgs & args);
	
	
private:
	
	ofxOscSender sender;
	
};


#endif
