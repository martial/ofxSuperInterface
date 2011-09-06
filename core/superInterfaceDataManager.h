//
//  superInterfaceDataManager.h
//  superInterface
//
//  Created by Martial Geoffre-Rouland on 11/08/2011.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#ifndef SUPINTDATAMNG
#define SUPINTDATAMNG

#include "ofMain.h"
#include "superInterfaceSettings.h"
#include "ofxXmlSettings.h"
#include "superInterfaceEventArgs.h"
#include "superInterfaceSettingsPage.h"

class superInterfaceDataManager {
  
public:
    
    void setup(superInterfaceSettings * interfaceSettings, superInterfaceSettingsPage * settingsPage);
    void createDefaultSettings();
    void updateSettings();
    void loadSettings(string initialDirectory);
    void saveSettings(superInterfaceEventArgs & e);
    void saveSettings();
    
    void loadLayouts();
    void saveLayouts();
    
    superInterfaceSettingsPage * settingsPage;
    superInterfaceSettings * interfaceSettings;
    
    string                  xmlSettingsPath;
    ofxXmlSettings          xmlSettings;
    vector<ofxXmlSettings*> xmlLayouts;
    
    ofDirectory             dir;
    
    string initialDirectory;
};



#endif
