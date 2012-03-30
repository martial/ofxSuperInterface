//
//  ofxSIDataManager.h
//  ofxSI
//
//  Created by Martial Geoffre-Rouland on 11/08/2011.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#ifndef SUPINTDATAMNG
#define SUPINTDATAMNG

#include "ofMain.h"
#include "ofxSISettings.h"
#include "ofxXmlSettings.h"
#include "ofxSIEventArgs.h"
#include "ofxSISettingsPage.h"

#ifdef USE_OSC
#include "ofxSIOscManager.h"
#endif

class ofxSuperInterface;

class ofxSIDataManager {
  
public:
    
    void setup(ofxSuperInterface * mom, ofxSISettings * interfaceSettings, ofxSISettingsPage * settingsPage);
	
    void createDefaultSettings();
    void updateSettings();
    void loadSettings(string initialDirectory);
    void saveSettings(ofxSIEventArgs & e);
    void saveSettings();
    
	
    void addPage(int pageNumber);
    void addComponent(ofxSIComponent * component, int pageNumber);

	
	void updateComponentPos(ofxSIEventArgs & e);
	
	
	vector<ofxSIComponent*>    components;
    vector<ofxSIPage*>         pages;
	
	ofxSIPage * getPage(int pageNumber );
	
private:
    
	ofxSuperInterface *					mom;
    ofxSISettingsPage *		settingsPage;
    ofxSISettings *			interfaceSettings;
    

	    
    string								xmlSettingsPath;
    ofxXmlSettings						xmlSettings;
    vector<ofxXmlSettings*>				xmlLayouts;
    
    ofDirectory							dir;
    string								initialDirectory;
	vector<string>						doubleLabels;
	
	int		getLayoutNodeByLabel(string label, int pageNum);
    
	bool	checkIfComponentXmlExists(int pageNumber, ofxSIComponent *component);
    string	checkIfLayoutXmlExists(int pageNumber);
	void	checkIfLabelExists(ofxSIComponent *component); // used to avoid same labels in all GUI
	
	
    void    onAutoUpdateEnabled(ofxSIEventArgs & e);
    
#ifdef USE_OSC
	ofxSIOscManager	*		oscManager;
    void	onOscEnabled(ofxSIEventArgs & e);
#endif
    
	
};



#endif
