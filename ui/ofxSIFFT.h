/*
 *  ofxSIFFT.h
 *  ofxSI
 *
 *  Created by Martial on 07/09/2011.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef SUPINTFFT
#define SUPINTFFT

#include "ofMain.h"
#include "ofxSIComponent.h"
#include "ofxSIVSlider.h"
#include "ofxSISimpleButton.h"
#include "ofxSITextLabel.h"

class ofxSIFFT : public ofxSIComponent { 
    
    
public:
    
    ofxSIFFT();
    void setup(ofxSuperInterface   * mom, int maxNumOfFreqs, int * filterRange, int xGridPos, int yGridPos, int wGridSize, int hGridSize, int xPadding = 3, int yPadding = 3, float freqBtnHeight = 30,  string label = "FFT" );
    void update();
    void draw();
	
	
	void updateValues(vector<float> * values);
    
	void onFreqBtnDown(ofxSIEventArgs & e);
	void setFilterRange(int num);
	
	void onMousePressed(int x, int y, int id);
    void onMouseDragged(int x, int y, int id );
    void onMouseMoved();
    void onMouseReleased(int id);
	
	int maxNumOfFreqs, numOfFreqs, selectedFreq;
	
	
private:
	
	int targetFilterRange;
	int *filterRange;
	
	float sliderWidth;
	int xPadding, yPadding;
	float freqBtnHeight;
	
	vector<ofxSIVSlider*> sliders;
	vector<ofxSISimpleButton*> freqBtns;
    
    
};


#endif
