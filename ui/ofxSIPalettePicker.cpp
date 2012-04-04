/*
 *  ofxSIPalettePicker.cpp
 *  MODULAR_SHIP
 *
 *  Created by Martial on 12/09/2011.
 *   
 
 
 *
 */

#include "ofxSIPalettePicker.h"

ofxSIPalettePicker::ofxSIPalettePicker() {
	
}

void ofxSIPalettePicker:: setup(ofxSuperInterface   * mom, ofColor * currentColor, string label,  int xGridPos, int yGridPos , int wGridSize , int hGridSize ) {
	
	
    this->gridPos.set(xGridPos, yGridPos);
	this->wGridSize = wGridSize;
    this->hGridSize = hGridSize;
    this->settings->label = label;
	this->currentColor = currentColor;
    
    ofxSIComponent::setup(mom, label);
	
    txtLabel.setup(mom, pos.x, pos.y + height, label);
	
}

void ofxSIPalettePicker::addColor(ofColor color) {
	
	colors.push_back(color);
	
}

void ofxSIPalettePicker::setColor(ofColor color){
	
	currentColor->r = color.r;
	currentColor->g = color.g;
	currentColor->b = color.b;
}

void ofxSIPalettePicker::update() {
	
	ofxSIComponent::update();

	
	if (tweens[0].isRunning()){
		currentColor->set(tweens[0].update(), tweens[1].update(),tweens[2].update());
        
        eventsArgs.floatVals.clear();
        
               
        float r = currentColor->r;
        float g = currentColor->g;
        float b = currentColor->b;
       
        eventsArgs.floatVals.push_back(&r);
        eventsArgs.floatVals.push_back(&g);
        eventsArgs.floatVals.push_back(&b);
        
        ofNotifyEvent(eventUpdateValues, eventsArgs, this);
	}
	
			
		
		
		
		if ( isMouseDown ) {
			
			
			int mouseX =  ofGetMouseX() - pos.x;
			int size = colors.size();
			float rectDim = float(width) / float(size);
			rollOverCurrentID = floor ( mouseX / rectDim);
			
			currentID = rollOverCurrentID;	
			for ( int i=0; i<4; i++) {
				tweens[i].setParameters(quint,ofxTween::easeOut,currentColor->v[i],colors[currentID].v[i],3000,0);
			}
			//int dumber = 0;
			ofNotifyEvent(onClickEvent,this->settings->label,this);
		}
		
	 else {
		rollOverCurrentID = -1;	
	}
	
}

void ofxSIPalettePicker::setRandomColor () {
	
	int rdmVal = floor(ofRandom(0, colors.size()-1));
	for ( int i=0; i<4; i++) {
		tweens[i].setParameters(quint,ofxTween::easeOut,currentColor->v[i],colors[rdmVal].v[i],3000,0);
	}
}


void ofxSIPalettePicker::draw() {
	
	ofxSIComponent::draw();

	
	glPushMatrix();
	glTranslatef(pos.x, pos.y,0);
	
	
	int size = colors.size();
	float rectDim = float(width) / float(size);
	float xPos = 0;
	int previewHeight = 10;
	
	
	
	
	ofEnableAlphaBlending();
	
	for ( int i=0; i < size; i++) {	
		
		float alpha = ( i==currentID || i==rollOverCurrentID ) ? 255 : 125; 
		ofSetColor(colors[i].r, colors[i].g, colors[i].b, alpha);
		ofRect(xPos, 0, rectDim-1, height-previewHeight );
		xPos+=rectDim;
	}
	
	ofDisableAlphaBlending();
	
	ofSetColor(currentColor->r, currentColor->g, currentColor->b);
	ofRect(0, height-previewHeight, width, previewHeight);
	
	

	glPopMatrix();
    
    
    txtLabel.pos.x = pos.x + 3;
    txtLabel.pos.y = pos.y + height + txtLabel.getBoundingBox().height +3;
    txtLabel.draw();
	
}