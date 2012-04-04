//
//  ofxSITextInput.cpp
//  superInterface
//



#include "ofxSITextInput.h"
#include "ofxSuperInterface.h"

ofxSITextInput::ofxSITextInput() {
    
}
void ofxSITextInput::setup(ofxSuperInterface   * mom, int xGridPos, int yGridPos,  int wGridSize, int hGridSize, string label) {
    
    ofxSISwitch::setup(mom, label);
    
    this->gridPos.set(xGridPos, xGridPos);
    this->wGridSize = wGridSize;
    this->hGridSize = hGridSize;
    
    marginLeft = 6;
    text="";
	position=0;
    ofAddListener(ofEvents.keyPressed, this, &ofxSITextInput::keyPressedEvent);
    
}
void ofxSITextInput::update(){
    
    ofxSISwitch::update();

    
    // have to find how many units it is!
    
    //getBoundingBox();
    
    calculatePos();
    
   // wGridSize = (int)(boundingBox.width / this->mom->settings.grid.x);
    //hGridSize = (int)(boundingBox.height / this->mom->settings.grid.y);
    
    // don't update size here
    //ofxSIComponent::update(); 
    
    
}
void ofxSITextInput::draw() {
    
    ofxSISwitch::draw(); 
    
    
    if(*value) {
        ofSetColor(this->settings->bgColorRoll);
    } else {
        ofSetColor(this->settings->bgColor);
    }
    
    ofRect(pos.x, pos.y, width, height);
    
    ofSetColor(this->settings->labelOffColor);
	string txt = this->settings->label  + " : " + text;
    
    this->mom->assets.labelFont.drawString(txt, (int)(pos.x+marginLeft), (int)((pos.y + height*.5) - boundingBox.height*.5 + boundingBox.height));
        
    
}

ofRectangle ofxSITextInput::getBoundingBox() {
    
    string finalTxt = this->settings->label  + " : " + text;
    boundingBox = this->mom->assets.labelFont.getStringBoundingBox(finalTxt.c_str(), pos.x, pos.y);
    return boundingBox;
}

void ofxSITextInput::keyPressedEvent(ofKeyEventArgs &a) {
    
    // if we're enabled
    if(*value) 
        keyPressed(a.key);
}

void ofxSITextInput::keyPressed(int key) {	
    
    
	//add charachter (non unicode sorry!)
	if (key >=32 && key <=126 &&  (boundingBox.width + marginLeft*2) < width)  {
		text.insert(text.begin()+position, key);
		position++;
	}
	
	if (key==OF_KEY_RETURN) {
		//ofNotifyEvent(evtEnter, text, this);
		//if (evtEnter.empty()) {
        //text.insert(text.begin()+position, '\n');
        //position++;
		//}
	}
	
	if (key==OF_KEY_BACKSPACE) {
		if (position>0) {
			text.erase(text.begin()+position-1);
			--position;
		}
	}
	
	if (key==OF_KEY_DEL) {
		if (text.size() > position) {
			text.erase(text.begin()+position);
		}
	}
	
	if (key==OF_KEY_LEFT)
		if (position>0)
			--position;
	
	if (key==OF_KEY_RIGHT)
		if (position<text.size()+1)
			++position;	
	
	
}

void ofxSITextInput::onRollOver() {
    (*value) = false;
    
}
void ofxSITextInput::onRollOut() {
    (*value) = true;
    
}


    