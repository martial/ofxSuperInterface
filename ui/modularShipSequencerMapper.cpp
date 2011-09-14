//
//  modularShipSequencerMapper.cpp
//  emptyExample
//
//  Created by Martial Geoffre-Rouland on 13/09/2011.
//  Copyright (c) 2011 __MyCompanyName__. All rights reserved.
//

#include "modularShipSequencerMapper.h"
#include "mainSettings.h" 

void modularShipSequencerMapper::setPoints() {
    
    mapperPos.set(0,0);
    
    coords.x = mainSettings::getGridSize().x;
	coords.y =  mainSettings::getGridSize().y;
	
	padding.x =  mainSettings::getGridPadding().x;
	padding.y =  mainSettings::getGridPadding().y;
	
	centerPoint.x = ( coords.x * padding.x) - padding.x;
	centerPoint.y = ( coords.y * padding.y);
    
    
	ofPushMatrix();
	ofPushMatrix();
	
	ofSetLineWidth(4);
	ofSetHexColor(0xffffff);
	
	
	ofEnableAlphaBlending();
	
    scale = .2;
	
	ofVec2f pos, gridPos;
	int pCount = 0;
    float xPadding = 0.0;
	for ( int z=0; z< 2; z++ ) {
		
        
        xPadding = z* ( centerPoint.x * scale  + 75);
		glTranslatef(xPadding, 0, 0);
						
		for ( int i = 0; i < coords.x; i++) {
			
			for ( int j = 0; j < coords.y; j++) {
				
				if ( j % 3 == 0 ) {
					if ( i > coords.x - 2.0) continue;
				}
				
				
				pos.x = (i * padding.x*scale);
				pos.y = (j * padding.y*scale);
				
				if ( j % 3 == 0 ) {
					pos.x += padding.x*scale/2;
					//	pos.y += padding.y/2;
				}
				
                ofVec2f pnt;
                pnt.set( xPadding + pos.x, pos.y);
                
                pnts.push_back(pnt);
                
				pCount++;
				
			}
			
		}
	}
	ofDisableAlphaBlending();
	
	ofPopMatrix();
	
	ofPopMatrix();
	ofSetColor(255,255,255);
	
    width = xPadding + pos.x;
    height = pos.y + padding.y * scale;
    
    
}
void modularShipSequencerMapper::draw(float x, float y) {
    
    mapperPos.set(x, y);
    
    ofPushMatrix();
    ofTranslate(x, y + width);
    ofRotate(-90, 0.0, 0.0, 1.0);
    
    ofSetColor(0, 0, 0);
    ofRect(0, 0, width, height);
    
    /*
     *  draw lines
     */
    
    ofPushMatrix();
    ofVec2f gridPos;
    for ( int z=0; z< 2; z++ ) {
		
		glTranslatef(z* ( centerPoint.x * scale  + 75), 0, 0);		
		ofPushMatrix();
		
		ofSetColor(125,125,125);
		ofSetLineWidth(1);
		
		for ( int i = 0; i < coords.x; i++) {		
			gridPos.x = (i * padding.x * scale);
			ofLine(gridPos.x, 0, 0, gridPos.x, (coords.y * padding.y* scale - padding.y* scale) , 0  );
		}
		
		for ( int j = 0; j < coords.y; j++) {
			gridPos.y =  (j * padding.y* scale);
			ofLine(0, gridPos.y,  0, coords.x * padding.x* scale - padding.x* scale, gridPos.y,  0);
		}
		ofPopMatrix();	
        
    }
    
    ofPopMatrix();
    
    /*
     *  draw points
     */
    
   
    int activePntsSize = activePoints.size();
    for ( int i=0; i<pnts.size(); i++ ) {
        
        bool bActive = false;
        for ( int j=0; j<activePntsSize;j++) {
            
           int activePnt = activePoints[j];
            if (i == activePnt) {
                bActive = true;
                break;
            }
            
            
            
        }
        
        (bActive) ? ofSetColor(255, 0, 0) : ofSetColor(70, 70, 70);
        ofCircle(pnts[i].x, pnts[i].y, 4);
    }
    
    ofPopMatrix();
}
vector<int> * modularShipSequencerMapper::getActivePoints(vector<superInterfaceSequencerAnimData> * anims) {
    
    clearPoints();
    
    
    
    
    for ( int i=0; i<anims->size(); i++ ) {
        
        superInterfaceSequencerAnimData * anim = &anims->at(i);
        
        for ( int j=0; j<anim->pnts.size(); j++ ) {
            
            ofVec2f animPnt = anim->pnts[j];
           
            ofVec2f mappedPnt = getMappedPnt(&animPnt);
            
            //mappedPnt.set(animPnt.y - mapperPos.y, height - animPnt.x - mapperPos.x);
            
            for ( int k=0; k<pnts.size();k++) {
                
                if ( anim->type == "DOT") {
                    if (hitCircleTest(pnts[k], mappedPnt, 35)) {
                    activePoints.push_back(k);
                    }
                }
                
                
                if ( anim->type == "LINES") {
                    
                    if( anim->pnts.size() <= 1  ) {
                        
                        if  ( hitCircleTest(pnts[k], mappedPnt, 35)) activePoints.push_back(k);
                        
                    } else {
                        
                         if ( j < anim->pnts.size()-1) {
                        
                        ofVec2f a = mappedPnt;
                        ofVec2f b = getMappedPnt(&anim->pnts[j+1]);
                        float angle = atan2(b.y - a.y, b.x - a.x);
                        
                        ofVec2f polyPntA, polyPntB, polyPntC, polyPntD;
                        
                        polyPntA.set(a.x + 20  * cos(angle+45), a.y + 20  * sin(angle+45));
                        polyPntB.set(a.x + 20  * cos(angle-45), a.y + 20  * sin(angle-45));
                        polyPntC.set(b.x + 20  * cos(angle-45), b.y + 20  * sin(angle-45));
                        polyPntD.set(b.x + 20  * cos(angle+45), b.y + 20  * sin(angle+45));
                        
                        
                        
                        
                        ofPolyline poly;
                        poly.addVertex(polyPntA);
                        poly.addVertex(polyPntB);
                        poly.addVertex(polyPntC);
                        poly.addVertex(polyPntD);
                        
                             if ( hitRectTest(pnts[k], poly.getBoundingBox())) {
                                 if(hitTestPoly(poly.getVertices(), pnts[k]))  activePoints.push_back(k);   
                             }
                         }
                        
                    }
                }

                
                if ( anim->type == "RECTANGLES") {
                    
                    if( anim->pnts.size() <= 1  ) {
                        
                        if  ( hitCircleTest(pnts[k], mappedPnt, 35)) activePoints.push_back(k);
                        
                    } else {
                        
                        if ( j < anim->pnts.size()-1) {
                            
                            ofVec2f nextMappedPnt = getMappedPnt(&anim->pnts[j+1]);
                           
                                                       
                            ofRectangle rect;
                            rect.set(mappedPnt.x, mappedPnt.y, nextMappedPnt.x -  mappedPnt.x, nextMappedPnt.y - mappedPnt.y);
                            
                            if  ( hitRectTest(pnts[k], rect)) activePoints.push_back(k);
                        }
                        
                    }
                    
                }
                
                if ( anim->type == "CIRCLES") {
                    
                    if( anim->pnts.size() <= 1  ) {
                        
                      if  ( hitCircleTest(pnts[k], mappedPnt, 35)) activePoints.push_back(k);
                    
                    } else {
                        
                        if ( j < anim->pnts.size()-1) {
                            
                            ofVec2f nextMappedPnt = getMappedPnt(&anim->pnts[j+1]);
                            ofVec2f middle = mappedPnt.getMiddle(nextMappedPnt);
                            float radius = mappedPnt.distance(nextMappedPnt) * .5;
                            
                            if  ( hitCircleTest(pnts[k], middle, radius)) activePoints.push_back(k);
                            
                        }
                        
                    }
                    
                    
                    
                }
                
                
                
                
            }
        }
        // first we will need to match the right pos        
    }
    
    return &activePoints;
}

ofVec2f modularShipSequencerMapper::getMappedPnt(ofVec2f * originalPnt) {
    
    ofVec2f toCanvasPnt;
    ofVec2f mappedPnt;
    
    toCanvasPnt.set(originalPnt->x, originalPnt->y);
    toCanvasPnt.x -= mapperPos.x;
    toCanvasPnt.y -= mapperPos.y;
    
    mappedPnt.set(width-toCanvasPnt.y, toCanvasPnt.x);
    
    return mappedPnt;
}

bool modularShipSequencerMapper::hitCircleTest(ofVec2f pnt, ofVec2f circlePnt,  float radius) {
        
    float dx = circlePnt.x - pnt.x;
    float dy = circlePnt.y - pnt.y;
    float dist = sqrt(dx*dx + dy*dy);
    return ( dist <= radius );
    
}

bool modularShipSequencerMapper::hitRectTest(ofVec2f pnt, ofRectangle rect) {
    
    if ( rect.width < 0 && rect.height < 0) return ((pnt.x < rect.x) && (pnt.x > rect.x + rect.width) && (pnt.y < rect.y) && (pnt.y > rect.y + rect.height));
    
    if ( rect.width > 0 && rect.height > 0) return ((pnt.x > rect.x) && (pnt.x < rect.x + rect.width) && (pnt.y > rect.y) && (pnt.y < rect.y + rect.height));
    
    if ( rect.width < 0 && rect.height > 0) return ((pnt.x < rect.x) && (pnt.x > rect.x + rect.width) && (pnt.y > rect.y) && (pnt.y < rect.y + rect.height));
    
    if ( rect.width > 0 && rect.height < 0) return ((pnt.x > rect.x) && (pnt.x < rect.x + rect.width) && (pnt.y < rect.y) && (pnt.y > rect.y + rect.height));
        
    return false;
    
}



bool modularShipSequencerMapper::pnpoly(int nvert, float *vertx, float *verty, float testx, float testy)
{
    int i, j, c = 0;
    for (i = 0, j = nvert-1; i < nvert; j = i++) {
        if ( ((verty[i]>testy) != (verty[j]>testy)) &&
            (testx < (vertx[j]-vertx[i]) * (testy-verty[i]) / (verty[j]-verty[i]) + vertx[i]) )
            c = !c;
    }
    return ( c!= 0 );
}


bool modularShipSequencerMapper::hitTestPoly(vector<ofPoint> & vertices,  ofPoint pnt)
{   
    
    
    
    int nvert = 4;
    
    
    
    int i, j;
    bool bHit = false;
    for (i = 0, j = nvert-1; i < nvert; j = i++) {
        if ( ((vertices[i].y > pnt.y) != (vertices[j].y > pnt.y)) &&
            (pnt.x < ( vertices[j].x - vertices[i].x) * (pnt.y - vertices[i].y ) / (vertices[j].y - vertices[i].y ) + vertices[i].x ) )
            bHit = !bHit;
    }
    return bHit;
}



