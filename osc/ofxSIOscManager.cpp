/*
 *  ofxSIOscManager.cpp
 *  ofxSI
 *
 *  Created by Martial on 07/09/2011.
 *   
 
 
 *
 */

#include "ofxSIOscManager.h"

ofxSIOscManager::ofxSIOscManager () {
	
	
	
}

void ofxSIOscManager::setup(string host, int port) {
	
	sender.setup( host, port );
}

void ofxSIOscManager::addComponentListener(ofxSIInteractiveObject * comp) {
	ofAddListener(comp->eventUpdateValues, this, &ofxSIOscManager::sendOscValues);

	
}
void ofxSIOscManager::removeComponentListener(ofxSIInteractiveObject * comp) {
	ofRemoveListener(comp->eventUpdateValues, this, &ofxSIOscManager::sendOscValues);
}
void ofxSIOscManager::sendOscValues(ofxSIEventArgs & args) {
	
	ofxSIObject * comp = args.comp;
    
    
	// format message and send it!
	
	ofxOscMessage m;
	m.setAddress( comp->settings->oscAdress);
	int i;
	for (i=0; i<args.strVals.size(); i++) m.addStringArg(*args.strVals[i]);	
	for (i=0; i<args.intVals.size(); i++) m.addIntArg(*args.intVals[i]);
	for (i=0; i<args.floatVals.size(); i++) m.addFloatArg(*args.floatVals[i]);
    
	sender.sendMessage( m );
	
}




