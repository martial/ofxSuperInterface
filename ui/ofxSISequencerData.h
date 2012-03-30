/*
 *  superInterfaceSequencerData.h
 *  superInterface
 *
 *  Created by Martial on 08/09/2011.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef SUPINTSEQDATA
#define SUPINTSEQDATA

#include "ofMain.h"

#include "superInterfaceSequencerFrameData.h"
#include "superInterfaceSequencerAnimData.h"

class superInterfaceSequencer;

class superInterfaceSequencerData  { 
    
    
public:
    
    superInterfaceSequencerData();
    void setup(superInterfaceSequencer * sequencer);
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
    
    superInterfaceSequencerFrameData * getCurrentFrameData();
	vector<superInterfaceSequencerFrameData>				framesData;
private:
	
	superInterfaceSequencer		*	sequencer;
	
	
	int								currentCount, fillCount, speed;
	int								maxAnims;
    string                          currentType;
	
	bool                            bIsFilling, bIsRecording;

    
    
};


#endif