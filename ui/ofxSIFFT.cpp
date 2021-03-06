/*
 *  ofxSIFFT.cpp
 *  ofxSI
 *
 *  Created by Martial on 07/09/2011.
 *   
 
 
 *
 */

#include "ofxSIFFT.h"

ofxSIFFT::ofxSIFFT() {
	
}
void ofxSIFFT::setup(ofxSuperInterface   * mom, int maxNumOfFreqs, int * filterRange,  int xGridPos, int yGridPos, int wGridSize, int hGridSize, int xPadding, int yPadding, float freqBtnHeight,  string label  ) {
	
	this->mom = mom;
	this->settings->label = label;
	this->gridPos.set(xGridPos, yGridPos);
    this->wGridSize = wGridSize;
    this->hGridSize = hGridSize;
	this->xPadding = xPadding;
	this->yPadding = yPadding;
	this->freqBtnHeight = freqBtnHeight;
	this->maxNumOfFreqs = maxNumOfFreqs;
	this->filterRange = filterRange;
	
	numOfFreqs = maxNumOfFreqs;
	
	// update values
	ofxSIComponent::update();
	
	// find one slider value
	sliderWidth = width / numOfFreqs;
	
	// convert to 
	
	sliders.reserve(numOfFreqs);
	
	for ( int i=0; i<numOfFreqs; i++) {
		
		ofxSIVSlider * slider = new ofxSIVSlider();
		slider->setup(mom, 0, 0, 10, 10, 0, 1, "fft_"+ ofToString(i));
		sliders.push_back(slider);
		
		
		ofxSISimpleButton * freqBtn = new ofxSISimpleButton();
		freqBtn->setup(mom,"-", 0,0,10,10);
		freqBtn->cornerRadius = 2;
		freqBtn->id = i;
		freqBtns.push_back(freqBtn);
		
		ofAddListener(freqBtn->eventMouseDown, this, &ofxSIFFT::onFreqBtnDown);
	}
	
	
	selectedFreq = 0;
	eventsArgs.intVals.push_back(&selectedFreq);
	
	this->settings->bgColor.set(0,0,0);
	
	//setFilterRange(*filterRange);
	
    //txtLabel.setup(mom, pos.x, pos.y + height, label);
}

void ofxSIFFT::update() {
	
	ofxSIComponent::update();
	
	sliderWidth = width / numOfFreqs;
	
	
	for ( int i=0; i<numOfFreqs; i++) {
		sliders[i]->update();
		freqBtns[i]->update();
	}
	
}

void ofxSIFFT::draw() {
	
	ofxSIComponent::draw();
	
	
	float sliderW = sliderWidth - (((float)xPadding * ( (float)numOfFreqs -1 )) / (float)numOfFreqs); 
	
	
	float sliderXPos = xPadding;
	for ( int i=0; i<numOfFreqs; i++) {
		
        
        sliders[i]->bIsFreePos = true;
		sliders[i]->setFixed(false, pos.x + sliderXPos, pos.y , sliderW, height- freqBtnHeight - yPadding);
		sliders[i]->draw();
		
        
		freqBtns[i]->bIsFreePos = true;
		freqBtns[i]->setFixed(false, pos.x + sliderXPos, pos.y + sliders[i]->height + yPadding , sliderW, freqBtnHeight);
		freqBtns[i]->draw();
		sliderXPos += sliderWidth;
	}
	
   // txtLabel.pos.x = pos.x + 3;
   // txtLabel.pos.y = pos.y + height + txtLabel.getBoundingBox().height +3;
   // txtLabel.draw();
	
}

void ofxSIFFT::updateValues(vector<float> * values) {
	
	for ( int i=0; i<values->size(); i++) {
		int index = ( i< numOfFreqs/2) ? i : numOfFreqs -1- ( i - (numOfFreqs/2));
		sliders[i]->pct =  values->at(index);
	}
	
	

}

void ofxSIFFT::onFreqBtnDown(ofxSIEventArgs & e) {
		
	for ( int i=0; i<numOfFreqs; i++) {
				
		if ( e.comp->id == freqBtns[i]->id ) {
			*filterRange = (i < numOfFreqs/2 ) ? i : numOfFreqs -1 - i;
			targetFilterRange = i;
		}
	}
    setFilterRange(targetFilterRange);
}

void ofxSIFFT::setFilterRange(int num) {
	
	
		
	for ( int i=0; i<numOfFreqs; i++) {
		
		bool bEnabled = ( num == freqBtns[i]->id );
        
		freqBtns[i]->isEnabled(bEnabled);
		sliders[i]->isMouseDown = bEnabled;
		
	}
	
	int index = numOfFreqs-1-num;
	if ( index > freqBtns.size() - 1 ) index = freqBtns.size() - 1;
	if ( index < 0 )index =  0;
    // enable diff
    freqBtns[numOfFreqs-1-num]->isEnabled(true);
    sliders[numOfFreqs-1-num]->isMouseDown = true;
	
    selectedFreq = (num < numOfFreqs/2 ) ? num : numOfFreqs - num-1;

	ofNotifyEvent(eventUpdateValues, eventsArgs, this);
	
	
}


void ofxSIFFT::onMousePressed(int x, int y, int id) {
	
	
	for ( int i=0; i<numOfFreqs; i++) {
		freqBtns[i]->onDownHandler(x,y, id);
	}
	
	
}
void ofxSIFFT::onMouseDragged(int x, int y, int id) {

}
void ofxSIFFT::onMouseMoved() {

}
void ofxSIFFT::onMouseReleased(int id) {
    
	for ( int i=0; i<numOfFreqs; i++) {
		freqBtns[i]->onMouseReleased(id);
	}
	
}
