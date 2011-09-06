//
//  superInterfaceMenuPage.h
//  emptyExample
//
//  Created by Martial Geoffre-Rouland on 10/08/2011.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//
#ifndef SUPINTMENUPG
#define SUPINTMENUPG

#include "ofMain.h"
#include "superInterfacePage.h"
#include "superInterfaceHSlider.h"
#include "superInterfaceSimpleButton.h"
#include "superInterfaceHTextLabel.h"
#include "superInterfaceEventArgs.h"

class ofxSuperInterface;

class superInterfaceMenuPage : public superInterfacePage {
    
public:
    
    superInterfaceMenuPage();
    
    void setup(ofxSuperInterface * mom);    
    void update();
    void draw();
    
    void setNumOfPages(int val);
    
    void onPageClickHandler(superInterfaceEventArgs & args);
    
    superInterfaceSimpleButton          settingsBtn;
    vector<superInterfaceSimpleButton*> pagesBtn;
   
    int height;
    
};



#endif
