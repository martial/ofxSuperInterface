//
//  superInterfaceEvent.h
//  superInterface
//
//  Created by Martial Geoffre-Rouland on 10/08/2011.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#ifndef SUPERINTEVTARGS
#define SUPERINTEVTARGS

#include "ofMain.h"

class superInterfaceObject;

class superInterfaceEventArgs : public ofEventArgs {
    
public:
    
    superInterfaceObject * comp;
    
};

#endif
