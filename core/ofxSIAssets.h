//
//  ofxSIAssets.h
//  emptyExample
//
//  Created by Martial Geoffre-Rouland on 05/08/2011.
 
 


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
