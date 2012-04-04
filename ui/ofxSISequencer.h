/*
 *  ofxSISequencer.h
 *  ofxSI
 *
 *  Created by Martial on 08/09/2011.
 *   
 


 *
 */


#ifndef SUPINTSEQ
#define SUPINTSEQ

#include "ofMain.h"
#include "ofxSuperInterface.h"
#include "ofxSISequencer.h"
#include "ofxSIComponent.h"
#include "ofxSIVSlider.h"
#include "ofxSISimpleButton.h"
#include "ofxSIEventArgs.h"
#include "ofxSISequencerGui.h"
#include "ofxSISequencerData.h"
#include "ofxSIAbstractSequencerMapper.h"


class ofxSISequencer : public ofxSIComponent { 
    
    
public:
    
    ofxSISequencer();
    void setup(ofxSuperInterface   * mom, int xGridPos, int yGridPos, int wGridSize, int hGridSize,   string label = "slider" );
    void update();
	void update(ofEventArgs & e);
    void draw();
	
	
	void setFullScreen(bool bFullScreen);
	
	void recordValues();
	
	void toggleRecord();
	void togglePlay();
	
	void clear();
	void clearLast();
	
    void sendOsc();
    
    void setMapperAsCanvas(ofxSIAbstractSequencerMapper * mapper);
    
	void onMousePressed(int x, int y, int id);
    void onMouseDragged(int x, int y, int id );
    void onMouseMoved();
    void onMouseReleased(int id);
	
	ofxSISequencerData	sequencerData;
	
    ofxSIInteractiveObject                 canvas;
    
    bool    bIsPlaying, bMapperPreview;
    
private:
	
	
	void setGui();
	void drawCanvas();
    
    	
    vector<ofPoint>             fingersRecord;
	int                         numOfTouches;
	ofxSISequencerGui	sequencerGui;
	
	bool bIsRecording;
	
	ofxSIAbstractSequencerMapper                 *   mapper;
    
};


#endif
