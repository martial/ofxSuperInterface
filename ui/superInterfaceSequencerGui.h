/*
 *  superInterfaceSequencerGui.h
 *  superInterface
 *
 *  Created by Martial on 08/09/2011.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */


#ifndef SUPINTSEQGUI
#define SUPINTSEQGUI

#include "ofMain.h"

#include "superInterfaceComponent.h"
#include "superInterfaceHSlider.h"
#include "superInterfaceSimpleButton.h"
#include "superInterfaceEventArgs.h"

class superInterfaceSequencer;

class superInterfaceSequencerGui : public superInterfaceComponent { 
    
    
public:
    
    superInterfaceSequencerGui();
    void setup(superInterfaceSequencer * sequencer);
    void update();
    void draw();
	
	
	void onPlayBtnHandler(superInterfaceEventArgs & e);
	void onClearLastBtnHandler(superInterfaceEventArgs & e);
	void onClearBtnHandler(superInterfaceEventArgs & e);
	void onNextBtnHandler(superInterfaceEventArgs & e);
	void onModeBtnHandler(superInterfaceEventArgs & e);
    
	void onMousePressed(int x, int y);
    void onMouseDragged(int x, int y, int id );
    void onMouseMoved();
    void onMouseReleased(int id);
	
	superInterfaceHSlider		timeLine;

	
private:
	
	superInterfaceSequencer		* sequencer;
	
	superInterfaceSimpleButton	enabledBtn, nextBtn, clearBtn, clearLastBtn, previewBtn;
    
    superInterfaceSimpleButton	dotMode, lineMode, circleMode, rectMode;
    vector<superInterfaceSimpleButton*> modeBtns;
		
    float                       time;
    
};


#endif