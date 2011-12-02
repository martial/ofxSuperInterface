#pragma once

#include "ofMain.h"
#include "superInterfaceSimpleButton.h"
#include "ofxSuperInterface.h"
#include "superInterfaceHSlider.h"
#include "superInterfaceFbo.h"
#include "superInterfacePalettePicker.h"

class testApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed  (int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
	
		void onBtnHandler(superInterfaceEventArgs & e );
		void onSliderHandler(superInterfaceEventArgs & e );
    
        	
	private :
	
	
		ofFbo						fboTest;
		ofColor						rectColor;
		float						rectWidthPct, rectHeightPct;
		float						xPosRect;
		int							sens;
		bool						bFlickering;
	
	
		ofxSuperInterface           interface;
	
		superInterfaceFbo			fboComp;
	
		superInterfaceSimpleButton	btn;
	
		superInterfaceHSlider		slider;
		superInterfaceHSlider		slider2;
	
		superInterfacePalettePicker	colorPicker;
	
	
	
	
	
	
};
