//
//  ofxSIAssets.h
//  emptyExample
//
//  Created by Martial Geoffre-Rouland on 05/08/2011.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#ifndef SUPINTASSETS
#define SUPINTASSETS

#include "ofMain.h"
#include "ofxSISettings.h"

class ofxSIAssets {
    
        
public:
    
    void setup(ofxSISettings * settings);
    void loadFonts();
    
    
    ofxSISettings * settings;
    
    ofTrueTypeFont headlineFont;
    ofTrueTypeFont labelFont;
    
};


#endif
