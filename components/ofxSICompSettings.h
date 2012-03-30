//
//  ofxSICompSettings.h
//  emptyExample
//
//  Created by Martial Geoffre-Rouland on 05/08/2011.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#ifndef SUPINTCOMPSETT
#define SUPINTCOMPSETT

#include "ofMain.h"

class ofxSICompSettings {
    
    public :
    
    void setupDefaults() {
        
        label = "default";
        width   = 0;
        height  = 0;
        
        bgColor.set(38,38,38);
        bgColorRoll.set(50,50,50);
        onColor.set(0, 255, 255);
        offColor.set(125,125,125);
        labelOffColor.set(255,255,255);
        labelOnColor.set(0,0,0);        
        
		
		bOscEnabled = false;
		oscAdress = "";
		
    }
    
    string  label;
    int     id;
    int     width, height;
    
    ofColor bgColor, bgColorRoll, onColor, offColor, labelOnColor, labelOffColor;
    
	bool	bOscEnabled;
	string	oscAdress;
	
};


#endif
