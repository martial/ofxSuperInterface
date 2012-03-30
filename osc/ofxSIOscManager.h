/*
 *  ofxSIOscManager.h
 *  ofxSI
 *
 *  Created by Martial on 07/09/2011.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef SUPINTOSCMNG
#define SUPINTOSCMNG

#include "ofMain.h"
#include "ofxOsc.h"
#include "ofxSIInteractiveObject.h"
#include "ofxSIObject.h"
#include "ofxSIEventArgs.h"

class ofxSIOscManager {
	
public:
	
	ofxSIOscManager();
	void setup(string host, int port);
	void addComponentListener(ofxSIInteractiveObject * comp);
	void removeComponentListener(ofxSIInteractiveObject * comp);
	void sendOscValues(ofxSIEventArgs & args);
	
	
private:
	
	ofxOscSender sender;
	
};


#endif
