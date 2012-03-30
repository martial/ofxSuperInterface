//
//  ofxSIComponent.h
//  emptyExample
//
//  Created by Martial Geoffre-Rouland on 05/08/2011.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#ifndef SUPINTCOMP
#define SUPINTCOMP

#include "ofMain.h"
#include "ofxSIInteractiveObject.h"
#include "ofxSIAssets.h"

class ofxSIComponent : public ofxSIInteractiveObject {
    
public:
    
    ofxSIComponent();
    void setup(ofxSuperInterface   * mom, string label);
    void setAssets( ofxSIAssets * assets);
    void update();
	void update(ofEventArgs & e);
    void draw();
    
    void onMousePressed(int x, int y, int id);
    void onMouseDragged(int x, int y);
    void onMouseMoved();
    void onMouseReleased();
    
      
    
    
};


#endif
