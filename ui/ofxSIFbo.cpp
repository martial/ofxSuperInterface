/*
 *  ofxSIFbo.cpp
 *  ofxSI
 *
 *  Created by Martial on 07/09/2011.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "ofxSIFbo.h"

ofxSIFbo::ofxSIFbo() {
	bKeepProportions = true;
}

void ofxSIFbo::setup(ofxSuperInterface   * mom,  ofFbo * fbo, int xGridPos, int yGridPos, int wGridSize, int hGridSize, string label  ) {
	
	
	this->fbo = fbo;
    this->gridPos.set(xGridPos, yGridPos);
    this->wGridSize = wGridSize;
    this->hGridSize = hGridSize;

    ofxSIComponent::setup(mom, label);
    
	
	
}

void ofxSIFbo::update () {
		
	ofxSIComponent::update();
	
	if(bKeepProportions) {
		
		float fboAspectRatio  = fbo->getWidth() / fbo->getHeight();
		float compAspectRatio = width / height;
		
		float wScale = width / fbo->getWidth();
		float hScale = height / fbo->getHeight();
		
		if (compAspectRatio >= fboAspectRatio) {
			
			fboWidth = width;
			fboHeight = width / fboAspectRatio;
		} else {
			
			fboHeight = height;
			fboWidth = height * fboAspectRatio;
		}
		
				
		
	} else {
			
		fboWidth = width;
		fboHeight = height;
	}
}


void ofxSIFbo::draw() {
	
	
	ofEnableAlphaBlending();
	
	ofSetColor(0, 0, 0);
	ofRect(pos.x, pos.y, width, height);
	ofSetColor(255, 255, 255);
	fbo->draw(pos.x, pos.y, fboWidth, fboHeight);
	
	ofDisableAlphaBlending();
	
}

