/*
 *  ofxSISequencerData.cpp
 *  ofxSI
 *
 *  Created by Martial on 08/09/2011.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "ofxSISequencerData.h"
#include "ofxSISequencer.h"

ofxSISequencerData::ofxSISequencerData(){
}


void ofxSISequencerData::setup(ofxSISequencer * sequencer){
	
	this->sequencer = sequencer;
	
	maxPoints =		70;
	currentCount =	0;
	speed		=	1;
	numOfRecords = 0;
	maxAnims	= 10;
    selectedAnim = 0;
    
    fillCount = 0;
    bIsFilling = true;
	bIsRecording = false;
    bPreviewMode = true;
    currentType = "DOT";
    
	clear();
	
	
	
	
	
	
}

void ofxSISequencerData::update(){
	
    
    if(bIsFilling && bIsRecording) {
                
        ofxSISequencerFrameData frameData;
        ofxSISequencerAnimData animData;
        
        animData.type = currentType;
        frameData.anims.push_back(animData);
        
        framesData.push_back(frameData);
        
    }
    
    currentCount++;
    if(bIsFilling && !bIsRecording) currentCount = 0;
	if(!bIsFilling && currentCount>maxPoints-1) currentCount = 0;
    
    
    
}

void ofxSISequencerData::draw(){
	
	
		
}

void ofxSISequencerData::debugDraw(){
	ofxSISequencerFrameData * frameData = getCurrentFrameData();
	
	
	for ( int i=0; i<numOfRecords; i++ ) {
                
        if(frameData->anims.size()<i) break;
        
		ofxSISequencerAnimData * animData = &frameData->anims[i];
        
        ofColor dotColor;
        bool bSelectednim = false;
        if(i==selectedAnim) {
            dotColor.set(255, 0, 0, 125);
            bSelectednim = true;
        } else {
            dotColor.set(255, 255, 255, 125);
        }

        
		for ( int j=0; j<animData->pnts.size(); j++) {
            
            ofVec2f pnt = animData->pnts[j];
            
            // pas l'temps
            
            if(bSelectednim) {
                
                ofSetColor(255, 255, 255, 125);
                ofCircle(pnt.x, pnt.y, 12);
            }
            
            ofSetColor(dotColor);
			ofCircle(pnt.x, pnt.y, 35);
            
            if(animData->type == "LINES" && j<animData->pnts.size()-1) {
                if(animData->pnts.size() > 1 ) { 
                    
                    
                    ofLine(pnt.x, pnt.y, animData->pnts[j+1].x, animData->pnts[j+1].y);
                    
                    ofVec2f a,b;
                    a.set(pnt.x, pnt.y);
                    b.set(animData->pnts[j+1].x, animData->pnts[j+1].y);
                    
                    
                    float angle = atan2(b.y - a.y, b.x - a.x);
                    float angleInDeg = angle * 180 / PI;
                    
                    ofVec2f middle = a.getMiddle(b);
                    float dist = a.distance(b);
                    
                    
                    ofPushMatrix();
                    
                    glTranslatef(middle.x, middle.y, 0.0);
                    glRotatef(angleInDeg, 0.0, 0.0, 1.0);
                   
                    ofRectangle rect;
                    rect.setFromCenter(0, 0, dist, 35);
                    
                    ofRect(rect);
                    
                    ofPopMatrix();
                    
                    
                    /*
                     * Now let's get poly :)
                     
                     */
                    
                    ofVec2f polyPntA, polyPntB, polyPntC, polyPntD;
                    
                    polyPntA.set(a.x + 20  * cos(angle+ 45), a.y + 20  * sin(angle+ 45));
                    polyPntB.set(a.x + 20  * cos(angle- 45), a.y + 20  * sin(angle- 45));
                    polyPntC.set(b.x + 20  * cos(angle- 45), b.y + 20  * sin(angle- 45));
                    polyPntD.set(b.x + 20  * cos(angle+ 45), b.y + 20  * sin(angle+ 45));
                    
                    ofPolyline triangle1, triangle2;
                    
                    triangle1.addVertex(polyPntA);
                    triangle1.addVertex(polyPntB);
                    triangle1.addVertex(polyPntD);
                    triangle1.setClosed(true);
                    ofSetColor(0, 255, 0);
                    ofFill();
                    triangle1.draw();
                    
                    triangle2.addVertex(polyPntB);
                    triangle2.addVertex(polyPntC);
                    triangle2.addVertex(polyPntD);
                    triangle2.setClosed(true);
                    ofSetColor(0, 255, 0);
                    ofFill();
                    triangle2.draw();
                    
                    
                    /*
                    
                    ofPolyline poly;
                    poly.addVertex(polyPntA);
                    poly.addVertex(polyPntB);
                    poly.addVertex(polyPntC);
                    poly.addVertex(polyPntD);
                    
                    poly.setClosed(true);
                    
                    ofSetColor(0, 255, 0);
                    ofFill();
                    poly.draw();
                    */
                }
            }
            
            if(animData->type == "RECTANGLES" && j<animData->pnts.size()-1) {
                if(animData->pnts.size() > 1 ) { 
                    ofRect(pnt.x, pnt.y, animData->pnts[j+1].x - pnt.x, animData->pnts[j+1].y - pnt.y);
                } 
            }

            
            if(animData->type == "CIRCLES" && j<animData->pnts.size()-1) {
                
                if(animData->pnts.size() > 1 ) {                                   
                ofNoFill();
                ofVec2f middle = pnt.getMiddle(animData->pnts[j+1]);
                ofCircle(middle.x, middle.y, pnt.distance(animData->pnts[j+1]) * .5);
                //ofLine(pnt.x, pnt.y, animData->pnts[j+1].x, animData->pnts[j+1].y);
                ofFill();
                }
            }
            
			//ofLog(OF_LOG_NOTICE, "DRAW %d %d", pnt.x, pnt.y);
		}
		
	}
}

void ofxSISequencerData::addRecord(){
	
	// we add another entry to the global vector
    
    bIsRecording = true;
    
    numOfRecords++;
	if( numOfRecords>maxAnims) numOfRecords = maxAnims-1;
    selectedAnim = numOfRecords-1;
    
    
    if(!bIsFilling) {
        
        
        // add animation 
        for( int i= 0; i<maxPoints; i++) {
            ofxSISequencerFrameData * frameData = &framesData[i];
            if ( frameData->anims.size() < numOfRecords ) {
                ofxSISequencerAnimData animData;
                animData.type = currentType;
                frameData->anims.push_back(animData);
            }
        }

        
        
    } 
      
}

void ofxSISequencerData::stopRecording(){
	
	if(numOfRecords==1 && bIsFilling) {
        bIsFilling = false;
        maxPoints = currentCount;
    }
    bIsRecording = false;
}

void ofxSISequencerData::record(int x, int y, int id, int numOfTouches) {
	    
	ofxSISequencerFrameData * frameData = getCurrentFrameData();
    ofxSISequencerAnimData * animData = &frameData->anims[numOfRecords-1];
	//vector<ofPoint> * animData = &frameData->anims[numOfRecords-1];
	
	if(!animData) return;
		
    
	//animData->pnts.clear();
    
	while (   animData->pnts.size() <= numOfTouches -1 ||  animData->pnts.size() <= id ) {
        ofVec2f pnts;
        animData->pnts.push_back(pnts);
	}
    
    while (id > numOfTouches-1) {
        id--;
        animData->pnts.pop_back();
    }
        
		
	animData->pnts[id].set(x, y);
	
	
}


void ofxSISequencerData::clear() {
	
	
    numOfRecords = 0;
    selectedAnim = 0;
    bIsFilling = true;
    framesData.clear();
}

void ofxSISequencerData::clearLast() {
	
	//for ( int i=0; i<framesData.size(); i++) framesData[i].clear();
    //	framesData.clear();
    if(numOfRecords==0) return;
	clearDrawing(numOfRecords-1);
   
	
}

void ofxSISequencerData::clearDrawing(int index){
    
    if(numOfRecords==0 ) return;
    
    for( int i= 0; i<maxPoints; i++) {
        ofxSISequencerFrameData * frameData = &framesData[i];
        if(index<=frameData->anims.size()-1)
        frameData->anims.erase(frameData->anims.begin() + index);
    }
    
    
    
    numOfRecords--;
    if(numOfRecords <= 0 ) {
        numOfRecords = 0;
        selectedAnim = 0;
        bIsFilling = true;
        clear();
        return;
    }
    if(selectedAnim>numOfRecords-1) selectedAnim = numOfRecords-1;
    if(selectedAnim<0) selectedAnim = 0;
    
}

void ofxSISequencerData::pushSelected() {
    
    if(numOfRecords == 0) return;
    
    selectedAnim++;
    if(selectedAnim > numOfRecords-1) selectedAnim = 0;
    
}

void ofxSISequencerData::setType(string type) {
    
    currentType = type;
    
    
}

float ofxSISequencerData::getPctElapsed() {
		
	return (float)currentCount / (float)maxPoints;
}



void ofxSISequencerData::onMousePressed(int x, int y, int id){
	
	
}

void ofxSISequencerData::onMouseDragged(int x, int y, int id ){
}

ofxSISequencerFrameData * ofxSISequencerData::getCurrentFrameData() {
    
    int index = ( bIsFilling ) ? currentCount-1 : currentCount;
    return &framesData[index];
    
}



