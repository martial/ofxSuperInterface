//
//  ofxSuperInterface.h
//  emptyExample
//
//  Created by Martial Geoffre-Rouland on 05/08/2011.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#ifndef SUPINT
#define SUPINT

//#define USE_OSC

#include "ofMain.h"
#include "ofxSISettings.h"
#include "ofxSIAssets.h"
#include "ofxSIComponent.h"
#include "ofxSIPage.h"
#include "ofxSISettingsPage.h"
#include "ofxSIMenuPage.h"
#include "ofxSIDataManager.h"



class ofxSuperInterface {
    
public:
    
    ofxSuperInterface();
    void setup(string initialDirectory = "");
    void setupFromXml(string xmlPath);
    void update();
    void draw();
    
    void addPage(int pageNumber);
    void showPage(int id);
    
    void addComponent(ofxSIComponent * component, int pageNumber);
    void removeComponent();
    
    
    void showSettings(bool b);
    void toggleSettings();
	void showMenu(bool b);
	
    void showGrid(bool bActive);
    void enablePositionMode(bool bActive);
    
    void alignAll(ofxSIEventArgs & e) {alignAll();};
    void alignAll();
    
    void  addSettingsPage();
    
    
    
    
    #if !defined( TARGET_OF_IPHONE ) 
    
    void mouseMoved(ofMouseEventArgs &e ){
		
        menuPage.mouseMoved(e);
        if(bShowSettings) { settingsPage.mouseMoved(e); return; }
        dataManager.getPage(currentPage)->mouseMoved(e);
    };
    void mouseDragged(ofMouseEventArgs &e){
        menuPage.mouseDragged(e);
        if(bShowSettings) { settingsPage.mouseDragged(e); return; }
         dataManager.getPage(currentPage)->mouseDragged(e);
    };
    void mousePressed(ofMouseEventArgs &e){
		menuPage.mousePressed(e);
		if(bShowSettings) { settingsPage.mousePressed(e); return; }
		dataManager.getPage(currentPage)->mousePressed(e);
	};
    void mouseReleased(ofMouseEventArgs &e){
		menuPage.mouseReleased(e);
		if(bShowSettings) { settingsPage.mouseReleased(e); return; }
		dataManager.getPage(currentPage)->mouseReleased(e);
	};
    
    #else
    
    void touchDown(ofTouchEventArgs &touch){
        menuPage.touchDown(touch);
        if(bShowSettings) { settingsPage.touchDown(touch); return; }
         dataManager.getPage(currentPage)->touchDown(touch);
    }
    void touchMoved(ofTouchEventArgs &touch){
        menuPage.touchMoved(touch);
        if(bShowSettings) { settingsPage.touchMoved(touch); return; }
		dataManager.getPage(currentPage)->touchMoved(touch);
    };  
    void touchUp(ofTouchEventArgs &touch){
         menuPage.touchUp(touch);
         if(bShowSettings) { settingsPage.touchUp(touch); return; }
		 dataManager.getPage(currentPage)->touchUp(touch);
    };  
    void touchDoubleTap(ofTouchEventArgs &touch){dataManager.getPage(currentPage)->touchDoubleTap(touch);}; 
    void touchCancelled(ofTouchEventArgs &touch){dataManager.getPage(currentPage)->touchCancelled(touch);};

    #endif
    
    bool bShowGrid, bPositionMode,bShowSettings,bShowMenuPage;
    
    ofxSISettings  settings;
    ofxSIAssets    assets;
    
    int                     currentPage;
    string                  initialDirectory;
    
    
    
    
    
private:
    
    
    ofxSIDataManager           dataManager;
    ofxSISettingsPage          settingsPage;
    ofxSIMenuPage              menuPage;
    
   
    
};

#endif
