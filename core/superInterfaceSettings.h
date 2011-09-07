//
//  superInterfaceSettings.h
//  emptyExample
//
//  Created by Martial Geoffre-Rouland on 05/08/2011.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#ifndef SUPINTSETTINGS
#define SUPINTSETTINGS

#include "ofMain.h"

class superInterfaceSettings {
    
public:
    
    void setupDefaults(){
        
        headLineFontPath = ofToDataPath("Arial.ttf");
        labelFontPath = ofToDataPath("Arial.ttf");
        headLineFontSize = 24;
        labelFontSize = 9;
        
        grid.x = 10;
        grid.y = 10;
        
        disabledColor.set(125,125,125);
		
		oscHost = "localhost";
		oscPort = 12345;
        
    }
    
    string  headLineFontPath;
    string  labelFontPath;
    
    int     headLineFontSize;
    int     labelFontSize;
    
    ofPoint grid;
    
    ofColor disabledColor;
    
	string oscHost;
	int	   oscPort;
    
};



#endif
