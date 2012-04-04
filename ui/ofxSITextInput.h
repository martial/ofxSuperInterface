//
//  ofxSITextInput.h
//  superInterface
//

// Ported from code by by Elliot Woods on 12/09/2011.
//  Copyright 2011 Kimchi and Chips.
//	MIT license

#ifndef SUPINTSTXTINPUT
#define SUPINTSTXTINPUT

#include "ofMain.h"
#include "ofxSIComponent.h"
#include "ofxSISwitch.h"

class ofxSITextInput : public ofxSISwitch {
    
    public :
    
    ofxSITextInput();
    void setup(ofxSuperInterface   * mom, int xGridPos, int yGridPos,  int wGridSize, int hGridSize, string label = "inputTxt");
    void update();
    void draw();
    
private:
    
    void	keyPressedEvent(ofKeyEventArgs &a);
    void    keyPressed(int key);
    void    onRollOut();
    void    onRollOver();
    
    ofRectangle getBoundingBox();
    
    string	text;
	int		position;
    
    int marginLeft;
    
    
};



#endif


