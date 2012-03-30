/*
 *  superInterfacePalettePicker.h
 *  MODULAR_SHIP
 *
 *  Created by Martial on 12/09/2011.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef SUPINTPLTPICKER
#define SUPINTPLTPICKER

#include "ofMain.h"
#include "superInterfaceSwitch.h"
#include "ofxTween.h"
#include "ofxEasingQuint.h"
#include "superInterfaceTextLabel.h"

class superInterfacePalettePicker : public superInterfaceComponent {
	
    public :
    
    superInterfacePalettePicker();
    void setup(ofxSuperInterface   * mom, ofColor * currentColor, string label = "picker",  int xGridPos = 0, int yGridPos = 0, int wGridSize = 0, int hGridSize = 0);
    void update();
    void draw();
	
	    
	
	void addColor(ofColor color);
		
	void setColor(ofColor color);
	
	void setRandomColor();
	
	ofColor getCurrentColor();
			
	ofColor  * currentColor;
	vector<ofColor> colors;
	
	ofEvent<string>		onClickEvent;
	
	private :
	
	
	int					currentID;
	int					rollOverCurrentID;
	
	ofxTween			tweens[4];
	ofxEasingQuint		quint;
    
    superInterfaceTextLabel txtLabel;
    
};


#endif
