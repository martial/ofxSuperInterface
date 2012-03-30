//
//  ofxSIMenuPage.cpp
//  emptyExample
//
//  Created by Martial Geoffre-Rouland on 10/08/2011.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//


#include "ofxSIMenuPage.h"
#include "ofxSuperInterface.h"

ofxSIMenuPage::ofxSIMenuPage () {
    enabled = true;
    height = 40;
}

void ofxSIMenuPage::setup (ofxSuperInterface * mom)

{
    
    ofxSIPage::setup(mom, -1);
    
    settingsBtn.setup(mom, mom->bShowSettings, "SETTINGS");
    settingsBtn.cornerRadius = 0;
    settingsBtn.bIsFreePos = true;
    settingsBtn.hGridSize = mom->settings.menuBarGridSize;
    settingsBtn.setFixed(true, 0, 0, 100, mom->settings.grid.y * mom->settings.menuBarGridSize);
    
    //settingsBtn.setTemporary(true);
    addComponent(&settingsBtn);
    //pagesBtn.push_back(&settingsBtn);
}

void ofxSIMenuPage::setNumOfPages(int val) {
    
    // take the settings btn 
    
    val +=1; 
    
    // see if we add or remove a btn to the vector 
    if ( val > pagesBtn.size() ) {
        
        
        for ( int i=0; i< val - pagesBtn.size(); i++ ) {
            
            ofxSISimpleButton * btn = new ofxSISimpleButton();
            string pLabel = "PAGE " + ofToString(val-1);
            
            btn->setup(mom, pLabel);
            btn->id = pagesBtn.size();
        
            ofAddListener(btn->eventMouseDown, this, &ofxSIMenuPage::onPageClickHandler);
        
            // btn->setTemporary(true);
            pagesBtn.push_back(btn);
            addComponent(btn);
            
        }
        
    } else if ( val < pagesBtn.size() ) {
        
        // we should not be in that case.. But who knows
        // TODO check for destructors
        
        ofxSISimpleButton * btnToRemove = pagesBtn[pagesBtn.size()-1];
        removeComponentByLabel(btnToRemove->settings->label);
        pagesBtn.erase (pagesBtn.end(),pagesBtn.end()+1);
        
    }
    
    
    
}

void ofxSIMenuPage::onPageClickHandler(ofxSIEventArgs & args) {
    

	
    ofxSIObject * comp = args.comp;
    
    for ( int i = 0; i<pagesBtn.size(); i++) {
        ofxSISimpleButton * btn = pagesBtn[i];
         btn->isEnabled(( comp->id == btn->id ));
                  
    }
    
    mom->currentPage = comp->id;
    
}

void ofxSIMenuPage::update () {
    
    // adapt
     settingsBtn.setFixed(true, 0, 0, 100, mom->settings.grid.y * mom->settings.menuBarGridSize);
    
    int btnWidth = (int)((ofGetWidth()) / pagesBtn.size());
    
    
    
    for ( int i = 0; i<pagesBtn.size(); i++) {
        pagesBtn[i]->cornerRadius = 0;
        pagesBtn[i]->bIsFreePos = true;
        pagesBtn[i]->hGridSize = mom->settings.menuBarGridSize;
        pagesBtn[i]->setFixed(true, 100 + btnWidth * i, 0, btnWidth, mom->settings.grid.y * mom->settings.menuBarGridSize);
     }
    
    ofxSIPage::update();
}

void ofxSIMenuPage::draw() {
    
    ofxSIPage::draw();
    
}


