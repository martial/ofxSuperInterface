//
//  ofxSuperInterface.h
//  emptyExample
//
//  Created by Martial Geoffre-Rouland on 05/08/2011.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#ifndef SUPINT
#define SUPINT

#include "ofMain.h"
#include "superInterfaceSettings.h"
#include "superInterfaceAssets.h"
#include "superInterfaceComponent.h"
#include "superInterfacePage.h"
#include "superInterfaceSettingsPage.h"
#include "superInterfaceMenuPage.h"
#include "superInterfaceDataManager.h"
#include "superInterfaceOscManager.h"

class ofxSuperInterface {
    
public:
    
    ofxSuperInterface();
    void setup(string initialDirectory = "");
    void setupFromXml(string xmlPath);
    void update();
    void draw();
    
    void addPage(int pageNumber);
    void showPage(int id);
    
    void addComponent(superInterfaceComponent * component, int pageNumber);
    void removeComponent();
    
    
    void showSettings(bool b);
    void toggleSettings();
    void showGrid(bool bActive);
    void enablePositionMode(bool bActive);
    
    void                addSettingsPage();
    
    
    
    
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
    
    bool bShowGrid, bPositionMode,bShowSettings;
    
    superInterfaceSettings  settings;
    superInterfaceAssets    assets;
    
    int                     currentPage;
    string                  initialDirectory;
    
private:
    
    
    superInterfaceDataManager           dataManager;
    superInterfaceSettingsPage          settingsPage;
    superInterfaceMenuPage              menuPage;
    
   
    
};

#endif
