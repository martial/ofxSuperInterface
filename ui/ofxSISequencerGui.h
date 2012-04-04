/*
 *  ofxSISequencerGui.h
 *  ofxSI
 *
 *  Created by Martial on 08/09/2011.
 *   
 


 *
 */


#ifndef SUPINTSEQGUI
#define SUPINTSEQGUI

#include "ofMain.h"

#include "ofxSIComponent.h"
#include "ofxSIHSlider.h"
#include "ofxSISimpleButton.h"
#include "ofxSIEventArgs.h"

class ofxSISequencer;

class ofxSISequencerGui : public ofxSIComponent { 
    
    
public:
    
    ofxSISequencerGui();
    void setup(ofxSISequencer * sequencer);
    void update();
    void draw();
	
	
	void onPlayBtnHandler(ofxSIEventArgs & e);
	void onClearLastBtnHandler(ofxSIEventArgs & e);
	void onClearBtnHandler(ofxSIEventArgs & e);
	void onNextBtnHandler(ofxSIEventArgs & e);
	void onModeBtnHandler(ofxSIEventArgs & e);
    
	void onMousePressed(int x, int y);
    void onMouseDragged(int x, int y, int id );
    void onMouseMoved();
    void onMouseReleased(int id);
	
	ofxSIHSlider		timeLine;

	
private:
	
	ofxSISequencer		* sequencer;
	
	ofxSISimpleButton	enabledBtn, nextBtn, clearBtn, clearLastBtn, previewBtn;
    
    ofxSISimpleButton	dotMode, lineMode, circleMode, rectMode;
    vector<ofxSISimpleButton*> modeBtns;
		
    float                       time;
    
};


#endif