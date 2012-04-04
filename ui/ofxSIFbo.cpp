/*
 *  ofxSIFbo.cpp
 *  ofxSI
 *
 *  Created by Martial on 07/09/2011.
 *   
 
 
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
		
        float minScale = min(wScale, hScale);
        
        fboWidth = fbo->getWidth() * minScale;
        fboHeight = fbo->getHeight() * minScale;
        
        /*
		if (compAspectRatio >= fboAspectRatio) {
			
			fboWidth = width;
			fboHeight = width / fboAspectRatio;
		} else {
			
			fboHeight = height;
			fboWidth = height * fboAspectRatio;
		}
		*/
        
        
        
				
		
	} else {
			
		fboWidth = width;
		fboHeight = height;
	}
    
    // finally 
    
}


void ofxSIFbo::draw() {
	
	
	ofEnableAlphaBlending();
	
  
	ofSetColor(25, 25, 25);
	ofRect(pos.x, pos.y, width, height);
   
	ofSetColor(255, 255, 255);
	fbo->draw(pos.x + ( width*.5 - fboWidth * .5), pos.y+ ( height*.5 - fboHeight * .5), fboWidth, fboHeight);
	
	ofDisableAlphaBlending();
	
}

