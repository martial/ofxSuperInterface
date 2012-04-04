//
//  ofxSIEvent.h
//  ofxSI
//
//  Created by Martial Geoffre-Rouland on 10/08/2011.
 
 


//

#ifndef SUPERINTEVTARGS
#define SUPERINTEVTARGS

#include "ofMain.h"

class ofxSIObject;

class ofxSIEventArgs : public ofEventArgs {
    
public:
    
    ofxSIObject * comp;
    
	// values - mostly used for OSC
	
	vector<string*>		strVals;
	vector<int*>		intVals;
	vector<float*>		floatVals;
	
	
};

#endif
