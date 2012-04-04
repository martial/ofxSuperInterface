//
//  ofxSITextLabel.h
//  emptyExample
//
//  Created by Martial Geoffre-Rouland on 09/08/2011.
 
 


//

#ifndef SUPINTSTXTLABEL
#define SUPINTSTXTLABEL

#include "ofMain.h"
#include "ofxSIComponent.h"

class ofxSITextLabel : public ofxSIComponent {
    
    public :
    
    ofxSITextLabel();
    void setup(ofxSuperInterface   * mom, int xGridPos, int yGridPos, string label = "button");
    void update();
    void draw();
    
    ofRectangle getBoundingBox();
	string extraText;
};



#endif
