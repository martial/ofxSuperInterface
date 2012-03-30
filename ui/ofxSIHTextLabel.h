//
//  ofxSIHTextLabel.h
//  emptyExample
//
//  Created by Martial Geoffre-Rouland on 09/08/2011.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#ifndef SUPINTTXTLABEL
#define SUPINTTXTLABEL

#include "ofMain.h"
#include "ofxSIComponent.h"

class ofxSIHTextLabel : public ofxSIComponent {
        
    public :
    
    ofxSIHTextLabel();
    void setup(ofxSuperInterface   * mom, int xGridPos, int yGridPos, string label = "button");
    void update();
    void draw();
    
    ofRectangle getBoundingBox();
    
    
    
};



#endif
