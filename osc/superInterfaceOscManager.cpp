/*
 *  superInterfaceOscManager.cpp
 *  superInterface
 *
 *  Created by Martial on 07/09/2011.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "superInterfaceOscManager.h"

superInterfaceOscManager::superInterfaceOscManager () {
	
	
	
}

void superInterfaceOscManager::setup(string host, int port) {
	
	sender.setup( host, port );
}

void superInterfaceOscManager::addComponentListener(superInterfaceInteractiveObject * comp) {
	ofAddListener(comp->eventUpdateValues, this, &superInterfaceOscManager::sendOscValues);

	
}
void superInterfaceOscManager::removeComponentListener(superInterfaceInteractiveObject * comp) {
	ofRemoveListener(comp->eventUpdateValues, this, &superInterfaceOscManager::sendOscValues);
}
void superInterfaceOscManager::sendOscValues(superInterfaceEventArgs & args) {
	
	superInterfaceObject * comp = args.comp;
    
    
	// format message and send it!
	
	ofxOscMessage m;
	m.setAddress( comp->settings->oscAdress);
	int i;
	for (i=0; i<args.strVals.size(); i++) m.addStringArg(*args.strVals[i]);	
	for (i=0; i<args.intVals.size(); i++) m.addIntArg(*args.intVals[i]);
	for (i=0; i<args.floatVals.size(); i++) m.addFloatArg(*args.floatVals[i]);
    
	sender.sendMessage( m );
	
}




