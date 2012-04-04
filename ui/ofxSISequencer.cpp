/*
 *  ofxSISequencer.cpp
 *  ofxSI
 *
 *  Created by Martial on 08/09/2011.
 *   
 
 
 *
 */

#include "ofxSISequencer.h"

ofxSISequencer::ofxSISequencer() {
    
    mapper = NULL;
    
	
}
void ofxSISequencer::setup(ofxSuperInterface   * mom, int xGridPos, int yGridPos, int wGridSize, int hGridSize, string label) {
	
	this->mom = mom;
	this->settings->label = label;
	this->gridPos.set(xGridPos, yGridPos);
    this->wGridSize = wGridSize;
    this->hGridSize = hGridSize;
	
	
	sequencerGui.setup(this);
	sequencerData.setup(this);
    
    canvas.setup(mom, "canvas");
    canvas.settings->bgColor.set(255, 50, 50);
    
    bIsRecording = false;
    bIsPlaying = false;
    bMapperPreview = true;
    
    isMultiTouch = true;
    
    numOfTouches = 0;
    
    fingersRecord.reserve(10);
    
    for ( int i=0; i<10;i++) {
        ofPoint rec;
        rec.set(0,0,0);
        fingersRecord.push_back(rec);
    }
	
}

void ofxSISequencer::update(ofEventArgs & e) {
	update();
}

void ofxSISequencer::update() {
    
    
    
    //this->wGridSize = mom->settings.getFullScreenGridSize().x;
    this->hGridSize =  mom->settings.getFullScreenGridSize().y;
    
    ofxSIComponent::update();
    
    this->width = ofGetWidth();
    
    canvas.pos.x = pos.x;
    canvas.pos.y = pos.y;

    canvas.width = width - (mom->settings.getWidthByGridSize(sequencerGui.wGridSize));
    canvas.height = height - mom->settings.getHeightByGridSize(sequencerGui.hGridSize +1);
    
       
	sequencerGui.update();
	sequencerData.update();
    
    
	if ( bIsRecording ) {
         for ( int i=0; i<10;i++) {
             if(fingersRecord[i] != NULL) {
                 sequencerData.record(fingersRecord[i].x, fingersRecord[i].y, i, numOfTouches);
             }
         }
    }
    
    sendOsc();
	
}
void ofxSISequencer::draw() {
	ofxSIComponent::draw();
    ofEnableAlphaBlending();

    drawCanvas();
    
	sequencerGui.draw();
	if ( bMapperPreview ) sequencerData.debugDraw();
    ofDisableAlphaBlending();
   
}


void ofxSISequencer::setMapperAsCanvas(ofxSIAbstractSequencerMapper * mapper) {
    
    this->mapper = mapper;
    
    
}

	
void ofxSISequencer::togglePlay() {
}

void ofxSISequencer::toggleRecord () {
	
}

void ofxSISequencer::clear() {
    sequencerData.clear();
}

void ofxSISequencer::clearLast() {

    sequencerData.clearLast();
    
}

void ofxSISequencer::drawCanvas() {
    
    if(mapper == NULL) {
        
    ofSetColor(255, 255, 255);
    canvas.draw();
        
    } else {
        
         mapper->draw(canvas.pos.x + ( canvas.width*.5 - mapper->height*.5), canvas.pos.y + ( canvas.height*.5 - mapper->width*.5));
        
    }
	
}
void ofxSISequencer::setFullScreen(bool bFullScreen) {
	
}

void ofxSISequencer::recordValues() {
	
}

void ofxSISequencer::onMousePressed(int x, int y,int id ) {
	
    
    numOfTouches++;
    ofPoint pos;
    pos.set(x,y);
    
	if ( numOfTouches == 1 && canvas.hitTest(pos) ) {
        
        
        
		sequencerData.addRecord();
		bIsRecording = true;
        
       

       
	}
    
     fingersRecord[id] = pos;
    sequencerGui.onMousePressed(x, y);
    
}
void ofxSISequencer::onMouseDragged(int x, int y, int id ) {
    
         
    ofPoint pos;
    pos.set(x,y);
    
    if(canvas.hitTest(pos)) {
        ofPoint touchPos;
        touchPos.set(x, y);
        fingersRecord[id] = touchPos;
        
       
        
    }
	
	
}
void ofxSISequencer::onMouseMoved() {
	
}
void ofxSISequencer::onMouseReleased(int id) {
	
    numOfTouches--;
    if(numOfTouches<0) numOfTouches = 0;
    
	if ( numOfTouches == 0 ) {
		sequencerData.stopRecording();
		bIsRecording =false;
	}
    
    fingersRecord[id] = NULL;
    sequencerGui.onMouseReleased(id);
}

void ofxSISequencer::sendOsc() {
    
    
    int playing = (bIsPlaying) ? 1 : 0;
        
    if(sequencerData.framesData.size() == 0 ) {
        bIsPlaying = false;
        playing = (bIsPlaying) ? 1 : 0;
        mapper->clearPoints();
        eventsArgs.intVals.clear();
         eventsArgs.intVals.push_back(&playing);
        ofNotifyEvent(eventUpdateValues, eventsArgs, this);
        return;
    }
    
    
    
    
    
    ofxSISequencerFrameData * frameData = sequencerData.getCurrentFrameData();
        
        if(mapper != NULL) {
        
        eventsArgs.intVals.clear();
            
        // push isPlaying first
        eventsArgs.intVals.push_back(&playing);
        
        vector<int> * activePnts = mapper->getActivePoints(&frameData->anims);
        
        for ( int j=0; j<activePnts->size(); j++ ) {
             eventsArgs.intVals.push_back(&activePnts->at(j));
            }
            
        ofNotifyEvent(eventUpdateValues, eventsArgs, this);
        return;
        }
    
        
        for ( int i=0; i<sequencerData.numOfRecords; i++ ) {
            
            if(frameData->anims.size()<i) break;
            
            ofxSISequencerAnimData * animData = &frameData->anims[i];
            
            eventsArgs.floatVals.clear();
            
            for ( int j=0; j<animData->pnts.size(); j++) {
                
                ofVec2f pnt = animData->pnts[j];
                
                //ofCircle(pnt.x, pnt.y, 10);
                
                eventsArgs.floatVals.push_back(&animData->pnts[j].x);
                eventsArgs.floatVals.push_back(&animData->pnts[j].y);
               
                
                //ofLog(OF_LOG_NOTICE, "DRAW %d %d", pnt.x, pnt.y);
            }
            
             if(animData->pnts.size() > 0 ) ofNotifyEvent(eventUpdateValues, eventsArgs, this);
            
        }
        
        
    
}


