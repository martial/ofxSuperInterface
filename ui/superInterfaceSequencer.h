/*
 *  superInterfaceSequencer.h
 *  superInterface
 *
 *  Created by Martial on 08/09/2011.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */


#ifndef SUPINTSEQ
#define SUPINTSEQ

#include "ofMain.h"
#include "ofxSuperInterface.h"
#include "superInterfaceSequencer.h"
#include "superInterfaceComponent.h"
#include "superInterfaceVSlider.h"
#include "superInterfaceSimpleButton.h"
#include "superInterfaceEventArgs.h"
#include "superInterfaceSequencerGui.h"
#include "superInterfaceSequencerData.h"
#include "superInterfaceAbstractSequencerMapper.h"


class superInterfaceSequencer : public superInterfaceComponent { 
    
    
public:
    
    superInterfaceSequencer();
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
    
    void setMapperAsCanvas(superInterfaceAbstractSequencerMapper * mapper);
    
	void onMousePressed(int x, int y, int id);
    void onMouseDragged(int x, int y, int id );
    void onMouseMoved();
    void onMouseReleased(int id);
	
	superInterfaceSequencerData	sequencerData;
	
    superInterfaceInteractiveObject                 canvas;
    
    bool    bIsPlaying, bMapperPreview;
    
private:
	
	
	void setGui();
	void drawCanvas();
    
    	
    vector<ofPoint>             fingersRecord;
	int                         numOfTouches;
	superInterfaceSequencerGui	sequencerGui;
	
	bool bIsRecording;
	
	superInterfaceAbstractSequencerMapper                 *   mapper;
    
};


#endif
