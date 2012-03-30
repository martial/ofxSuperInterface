/*
 *  ofxSISequencerGui.cpp
 *  ofxSI
 *
 *  Created by Martial on 08/09/2011.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "ofxSISequencerGui.h"
#include "ofxSISequencer.h"

ofxSISequencerGui::ofxSISequencerGui(){
}


void ofxSISequencerGui::setup(ofxSISequencer * sequencer){
	
	this->sequencer = sequencer;
    
    hGridSize = 5;
    wGridSize = 8;
	
    time = 0.0;
	
	enabledBtn.setup(sequencer->mom, sequencer->bIsPlaying,  "ONLINE", 0, 0, wGridSize, hGridSize);
	nextBtn.setup(sequencer->mom, "NEXT", 0, 0, wGridSize, hGridSize);
	clearBtn.setup(sequencer->mom, "CLEAR SLCT", 0, 0, wGridSize, hGridSize);
	clearLastBtn.setup(sequencer->mom, "CLEAR ALL", 0, 0, wGridSize, hGridSize);
    previewBtn.setup(sequencer->mom, sequencer->bMapperPreview, "PREVIEW", 0, 0, wGridSize, hGridSize);
    
    
    timeLine.setup(sequencer->mom, &time, 0,0,0,1.0, 0.0, 1.0, "timeline");
    
    
    dotMode.setup(sequencer->mom,  "DOT", 0, 0, wGridSize, hGridSize);
    lineMode.setup(sequencer->mom,  "LINES", 0, 0, wGridSize, hGridSize);
    circleMode.setup(sequencer->mom,  "CIRCLES", 0, 0, wGridSize, hGridSize);
    rectMode.setup(sequencer->mom,  "RECTANGLES", 0, 0, wGridSize, hGridSize);
    
    dotMode.isEnabled(true);
    
    modeBtns.push_back(&dotMode);
    modeBtns.push_back(&lineMode);
    modeBtns.push_back(&circleMode);
    modeBtns.push_back(&rectMode);
    
    for ( int i=0; i<modeBtns.size(); i++ ) {
        
        modeBtns[i]->cornerRadius = 0;
        ofAddListener(modeBtns[i]->eventMouseDown, this, &ofxSISequencerGui::onModeBtnHandler);
    }
    
    previewBtn.cornerRadius = 0;
    enabledBtn.cornerRadius = 0;
    nextBtn.cornerRadius = 0;
    clearBtn.cornerRadius = 0;
    clearLastBtn.cornerRadius = 0;
	
	ofAddListener(enabledBtn.eventMouseDown, this, &ofxSISequencerGui::onPlayBtnHandler);
	ofAddListener(nextBtn.eventMouseDown, this, &ofxSISequencerGui::onNextBtnHandler);
	ofAddListener(clearBtn.eventMouseDown, this, &ofxSISequencerGui::onClearBtnHandler);
	ofAddListener(clearLastBtn.eventMouseDown, this, &ofxSISequencerGui::onClearLastBtnHandler);
    
    
    
    nextBtn.setTemporary(true);
    clearBtn.setTemporary(true);
    clearLastBtn.setTemporary(true);
    
	
}

void ofxSISequencerGui::update(){
	
    enabledBtn.setFixed(false,sequencer->width - enabledBtn.width);
    nextBtn.setFixed(false,sequencer->width -  nextBtn.width, enabledBtn.height);
    clearBtn.setFixed(false,sequencer->width -  clearBtn.width, nextBtn.pos.y + nextBtn.height  );
    clearLastBtn.setFixed(false,sequencer->width -  clearLastBtn.width, clearBtn.pos.y + clearBtn.height );
    previewBtn.setFixed(false,sequencer->width -  clearLastBtn.width, clearLastBtn.pos.y + clearLastBtn.height );
    
    float xPos = 0;
    
    for ( int i=0; i<modeBtns.size(); i++ ) {
     
        modeBtns[i]->setFixed(false,xPos, sequencer->height - modeBtns[i]->height - timeLine.height);
        xPos+=modeBtns[i]->width;
        modeBtns[i]->update();
    }
    
	enabledBtn.update();
	nextBtn.update();
	clearBtn.update();
	clearLastBtn.update();
    previewBtn.update();
    
    time = sequencer->sequencerData.getPctElapsed();
    timeLine.update();
}

void ofxSISequencerGui::draw(){
    
   
	
	enabledBtn.draw();
	nextBtn.draw();
	clearBtn.draw();
	clearLastBtn.draw();
     previewBtn.draw();
    
    timeLine.setFixed(false,0,sequencer->height - timeLine.height,sequencer->canvas.width);
    timeLine.draw();
    
    
     for ( int i=0; i<modeBtns.size(); i++ ) {
            
         modeBtns[i]->draw();
     }
}

void ofxSISequencerGui::onPlayBtnHandler(ofxSIEventArgs & e){
	//sequencer->bIsPlaying = enabledBtn
}

void ofxSISequencerGui::onClearLastBtnHandler(ofxSIEventArgs & e){
	sequencer->clear();
}

void ofxSISequencerGui::onClearBtnHandler(ofxSIEventArgs & e){
	sequencer->sequencerData.clearDrawing(sequencer->sequencerData.selectedAnim);
}

void ofxSISequencerGui::onNextBtnHandler(ofxSIEventArgs & e){
	sequencer->sequencerData.pushSelected();
}

void ofxSISequencerGui::onModeBtnHandler(ofxSIEventArgs & e){
    string label = e.comp->settings->label;
	sequencer->sequencerData.setType(e.comp->settings->label);
    
     for ( int i=0; i<modeBtns.size(); i++ ) {
         modeBtns[i]->isEnabled(modeBtns[i]->settings->label == label);
     }
    
}






void ofxSISequencerGui::onMousePressed(int x, int y){
	
	
	enabledBtn.onDownHandler(x,y);
	nextBtn.onDownHandler(x,y);
	clearBtn.onDownHandler(x,y);
	clearLastBtn.onDownHandler(x,y);
	  previewBtn.onDownHandler(x,y);
    for ( int i=0; i<modeBtns.size(); i++ ) {
        modeBtns[i]->onDownHandler(x,y);
    }
    
}

void ofxSISequencerGui::onMouseDragged(int x, int y, int id ){
}

void ofxSISequencerGui::onMouseMoved(){
}

void ofxSISequencerGui::onMouseReleased(int id){
    enabledBtn.onMouseReleased(id);
	nextBtn.onMouseReleased(id);
	clearBtn.onMouseReleased(id);
	clearLastBtn.onMouseReleased(id);
     previewBtn.onMouseReleased(id);
    for ( int i=0; i<modeBtns.size(); i++ ) {
        modeBtns[i]->onMouseReleased(id);
    }

    
}
