/*
 *  ofxSIImage.cpp
 *  MODULAR_SHIP
 *
 *  Created by Martial on 15/09/2011.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "ofxSIImage.h"


ofxSIImage::ofxSIImage() {
	bKeepProportions = true;
}

void ofxSIImage::setup(ofxSuperInterface   * mom,  ofImage * img, int xGridPos, int yGridPos, int wGridSize, int hGridSize, string label  ) {
	
	
	this->img = img;
    this->gridPos.set(xGridPos, yGridPos);
    this->wGridSize = wGridSize;
    this->hGridSize = hGridSize;
	
    ofxSIComponent::setup(mom, label);
    
	
	
}

void ofxSIImage::update () {
	
	ofxSIComponent::update();
	
	if(bKeepProportions) {
		
		float fboAspectRatio  = img->getWidth() / img->getHeight();
		float compAspectRatio = width / height;
		
		float wScale = width / img->getWidth();
		float hScale = height / img->getHeight();
		
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


void ofxSIImage::draw() {
	
	
	ofEnableAlphaBlending();
	
	ofSetColor(0, 0, 0);
	ofRect(pos.x, pos.y, width, height);
	ofSetColor(255, 255, 255);
	img->draw(pos.x, pos.y, fboWidth, fboHeight);
	
	ofDisableAlphaBlending();
	
}

