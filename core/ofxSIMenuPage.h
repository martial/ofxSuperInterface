//
//  ofxSIMenuPage.h
//  emptyExample
//
//  Created by Martial Geoffre-Rouland on 10/08/2011.
 
 


//
#ifndef SUPINTMENUPG
#define SUPINTMENUPG

#include "ofMain.h"
#include "ofxSIPage.h"
#include "ofxSIHSlider.h"
#include "ofxSISimpleButton.h"
#include "ofxSIHTextLabel.h"
#include "ofxSIEventArgs.h"

class ofxSuperInterface;

class ofxSIMenuPage : public ofxSIPage {
    
public:
    
    ofxSIMenuPage();
    
    void setup(ofxSuperInterface * mom);    
    void update();
    void draw();
    
    void setNumOfPages(int val);
    
    void onPageClickHandler(ofxSIEventArgs & args);
    
    ofxSISimpleButton          settingsBtn;
    vector<ofxSISimpleButton*> pagesBtn;
   
    int height;
    
};



#endif
