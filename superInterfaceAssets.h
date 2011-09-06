//
//  superInterfaceAssets.h
//  emptyExample
//
//  Created by Martial Geoffre-Rouland on 05/08/2011.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#ifndef SUPINTASSETS
#define SUPINTASSETS

#include "ofMain.h"
#include "superInterfaceSettings.h"

class superInterfaceAssets {
    
        
public:
    
    void setup(superInterfaceSettings * settings);
    void loadFonts();
    
    
    superInterfaceSettings * settings;
    
    ofTrueTypeFont headlineFont;
    ofTrueTypeFont labelFont;
    
};


#endif
