//
//  ofxSuperInterface.h
//  emptyExample
//
//  Created by Martial Geoffre-Rouland on 05/08/2011.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#ifndef  SUPINT
#define SUPINT

#include "ofMain.h"
#include "superInterfaceSettings.h"
#include "superInterfaceAssets.h"
#include "superInterfaceComponent.h"
#include "superInterfacePage.h"
#include "superInterfaceSettingsPage.h"
#include "superInterfaceMenuPage.h"
#include "superInterfaceDataManager.h"


class ofxSuperInterface {
    
public:
    
    ofxSuperInterface();
    void setup(string initialDirectory = "");
    void setupFromXml(string xmlPath);
    void update();
    void draw();
    
    void addPage();
    void showPage(int id);
    
    void addComponent(superInterfaceComponent * component, int pageNum);
    void removeComponent();
    
    
    void showSettings(bool b);
    void toggleSettings();
    void showGrid(bool bActive);
    void enablePositionMode(bool bActive);
    
    void                addSettingsPage();
    superInterfacePage * getCurrentPage();
    
    
    
    #if !defined( TARGET_OF_IPHONE ) 
    
    void mouseMoved(ofMouseEventArgs &e ){
        menuPage.mouseMoved(e);
        if(bShowSettings) { settingsPage.mouseMoved(e); return; }
        getCurrentPage().mouseMoved(e);
    };
    void mouseDragged(ofMouseEventArgs &e){
        menuPage.mouseDragged(e);
        if(bShowSettings) { settingsPage.mouseDragged(e); return; }
        getCurrentPage().mouseDragged(e);
    };
    void mousePressed(ofMouseEventArgs &e){getCurrentPage().mousePressed(e);};
    void mouseReleased(ofMouseEventArgs &en){getCurrentPage().mouseReleased(e);};
    
    #else
    
    void touchDown(ofTouchEventArgs &touch){
        menuPage.touchDown(touch);
        if(bShowSettings) { settingsPage.touchDown(touch); return; }
        getCurrentPage()->touchDown(touch);
    }
    void touchMoved(ofTouchEventArgs &touch){
        menuPage.touchMoved(touch);
        if(bShowSettings) { settingsPage.touchMoved(touch); return; }
        getCurrentPage()->touchMoved(touch);
    };  
    void touchUp(ofTouchEventArgs &touch){
         menuPage.touchUp(touch);
         if(bShowSettings) { settingsPage.touchUp(touch); return; }
         getCurrentPage()->touchUp(touch);
    };  
    void touchDoubleTap(ofTouchEventArgs &touch){getCurrentPage()->touchDoubleTap(touch);}; 
    void touchCancelled(ofTouchEventArgs &touch){getCurrentPage()->touchCancelled(touch);};

    #endif
    
    bool bShowGrid, bPositionMode,bShowSettings;
    
    superInterfaceSettings  settings;
    superInterfaceAssets    assets;
    
    int                     currentPage;
    string                  initialDirectory;
    
private:
    
    
    superInterfaceDataManager           dataManager;
    
    vector<superInterfaceComponent*>    components;
    vector<superInterfacePage*>         pages;
    
    superInterfaceSettingsPage          settingsPage;
    superInterfaceMenuPage              menuPage;
    
   
    
};

#endif
