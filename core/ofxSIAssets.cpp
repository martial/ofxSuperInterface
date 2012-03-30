//
//  superInterfaceAssets.cpp
//  emptyExample
//
//  Created by Martial Geoffre-Rouland on 05/08/2011.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#include "superInterfaceAssets.h"

void superInterfaceAssets::setup(superInterfaceSettings * settings) {
    
   
    this->settings = settings;
    loadFonts();
    
}

void superInterfaceAssets::loadFonts() {
    headlineFont.loadFont(settings->headLineFontPath, settings->headLineFontSize, true, false, false );
    labelFont.loadFont(settings->labelFontPath, settings->labelFontSize, false, false, false);
    
}
