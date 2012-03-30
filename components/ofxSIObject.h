//
//  ofxSIObject.h
//  emptyExample
//
//  Created by Martial Geoffre-Rouland on 04/08/2011.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#ifndef SUPINTOBJ
#define SUPINTOBJ

#include "ofMain.h"
//#include "ofxSuperInterface.h"
#include "ofxSICompSettings.h"
#include "ofxSIEventArgs.h"

class ofxSuperInterface;

class ofxSIObject {
    
    
    public:
    
    ofxSIObject();
    
    virtual void setup(ofxSuperInterface   * mom, string label);
    virtual void update();
	virtual void update(ofEventArgs &e);
    virtual void draw();
    
    virtual void setGridPosByScreenCoords(int x, int y);
    virtual void setFixed(bool b, int fixedXPos = 0, int fixedYPos = 0,int fixedWidth = 0, int fixedHeight = 0);
    virtual void setSettings(ofxSICompSettings * settings);
    
    
    void calculatePos();
    void calculateSize();
	    
    virtual ofRectangle getBoundingBox();
   
    
    ofPoint pos, gridPos;
    
    int     wGridSize, hGridSize, width, height, fixedXPos, fixedYPos, fixedWidth, fixedHeight, cornerRadius;
    bool    bEnabled, bIsFixed, bIsFreePos;
    
    
    // for custom purposes
    int id;
    int pageNum;
	
    ofRectangle boundingBox;
    
    ofxSuperInterface   * mom;
    
    ofxSICompSettings * settings;
    ofxSIEventArgs      eventsArgs;
    
    
    void roundedRect(float x, float y, float w, float h, float r);
    
    
    
    private :
    
    void  quadraticBezierVertex(float cpx, float cpy, float x, float y, float prevX, float prevY);
    
    
    
};


#endif
