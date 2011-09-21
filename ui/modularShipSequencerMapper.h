//
//  modularShipSequencerMapper.h
//  emptyExample
//
//  Created by Martial Geoffre-Rouland on 13/09/2011.
//  Copyright (c) 2011 __MyCompanyName__. All rights reserved.
//

#ifndef MDLSHIPSEQMAPPER
#define MDLSHIPSEQMAPPER

#include "ofMain.h"
#include "superInterfaceAbstractSequencerMapper.h"

class modularShipSequencerMapper : public  superInterfaceAbstractSequencerMapper {
    
    public :
    
    void setPoints();
    void draw(float x, float y);
    vector<int> * getActivePoints(vector<superInterfaceSequencerAnimData> * anims);
    
    
    ofVec2f getMappedPnt(ofVec2f * originalPnt);
    
    bool hitCircleTest(ofVec2f pnt, ofVec2f circlePnt,  float radius);
    bool hitRectTest(ofVec2f pnt, ofRectangle rect);
    bool hitTestPoly(vector<ofPoint> & vertices,  ofPoint pnt);
    bool hitOtherTestPoly(vector<ofPoint> & vertices,  ofPoint pnt);
    bool hitAhouTestPoly(vector<ofPoint> & vertices,  ofPoint pnt);
    bool pnpoly(int nvert, float *vertx, float *verty, float testx, float testy);
    
    
    bool isPointInTriangle(ofVec2f pt, ofVec2f p1, ofVec2f p2, ofVec2f p3);
    bool sign(ofVec2f p1, ofVec2f p2, ofVec2f p3);
    
    
    ofVec3f		pos;
	ofPoint		coords;
	ofPoint		padding;
    ofPoint		centerPoint;
    
    float scale;
    
    ofPoint mapperPos;
    
        
};


#endif
