/*
 *  ofxSISequencerData.h
 *  ofxSI
 *
 *  Created by Martial on 08/09/2011.
 *   
 


 *
 */

#ifndef SUPINTSEQDATA
#define SUPINTSEQDATA

#include "ofMain.h"

#include "ofxSISequencerFrameData.h"
#include "ofxSISequencerAnimData.h"

class ofxSISequencer;

class ofxSISequencerData  { 
    
    
public:
    
    ofxSISequencerData();
    void setup(ofxSISequencer * sequencer);
    void update();
    void draw();
	
	void addRecord();
	void stopRecording();
	void record(int x, int y, int id, int numOfTouches);
	
	void clear();
	void clearDrawing(int index);
    void clearLast();
    
    
    void pushSelected();
	
	float getPctElapsed();
	
	void onMousePressed(int x, int y, int id);
    void onMouseDragged(int x, int y, int id );

	void setType(string type);
    
	void debugDraw();
    
    bool  bPreviewMode;
    
    int                             selectedAnim,numOfRecords;
    int   maxPoints;
    
    ofxSISequencerFrameData * getCurrentFrameData();
	vector<ofxSISequencerFrameData>				framesData;
private:
	
	ofxSISequencer		*	sequencer;
	
	
	int								currentCount, fillCount, speed;
	int								maxAnims;
    string                          currentType;
	
	bool                            bIsFilling, bIsRecording;

    
    
};


#endif