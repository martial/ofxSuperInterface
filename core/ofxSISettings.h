//
//  ofxSISettings.h
//  emptyExample
//
//  Created by Martial Geoffre-Rouland on 05/08/2011.
 
 


//

#ifndef SUPINTSETTINGS
#define SUPINTSETTINGS

#include "ofMain.h"

class ofxSISettings {
    
public:
    
    void setupDefaults(){
        
        headLineFontPath = ofToDataPath("Arial.ttf");
        labelFontPath = ofToDataPath("Arial.ttf");
        headLineFontSize = 24;
        labelFontSize = 9;
        
        menuBarGridSize = 4;
        
        grid.x = 20;
        grid.y = 20;
        
        disabledColor.set(125,125,125);
		
		oscHost = "localhost";
		oscPort = 12345;
        
    }
    
    float getWidthByGridSize (int gridSize) {
        
        return gridSize * grid.x;
    }
    
    float getHeightByGridSize (int gridSize) {
        
        return gridSize * grid.y;
    }
    
    ofPoint getFullScreenGridSize () {
        
        ofPoint pnt;
        pnt.x = ofGetWidth() / grid.x;
        pnt.y = (ofGetHeight() / grid.y) - (menuBarGridSize);
        
        return pnt;
        
    }
    
    
    
    string  headLineFontPath;
    string  labelFontPath;
    
    int     headLineFontSize;
    int     labelFontSize;
    
    int     menuBarGridSize;
    
    ofPoint grid;
    
    ofColor disabledColor;
    
	string oscHost;
	int	   oscPort;
    
};



#endif
