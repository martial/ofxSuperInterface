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
#include "superInterfaceOscManager.h"

class ofxSuperInterface;

class superInterfaceDataManager {
  
public:
    
    void setup(ofxSuperInterface * mom, superInterfaceSettings * interfaceSettings, superInterfaceSettingsPage * settingsPage);
	
    void createDefaultSettings();
    void updateSettings();
    void loadSettings(string initialDirectory);
    void saveSettings(superInterfaceEventArgs & e);
    void saveSettings();
    
	
    void addPage(int pageNumber);
    void addComponent(superInterfaceComponent * component, int pageNumber);

	
	void updateComponentPos(superInterfaceEventArgs & e);
	
	
	vector<superInterfaceComponent*>    components;
    vector<superInterfacePage*>         pages;
	
	superInterfacePage * getPage(int pageNumber );
	
private:
    
	ofxSuperInterface *					mom;
    superInterfaceSettingsPage *		settingsPage;
    superInterfaceSettings *			interfaceSettings;
	superInterfaceOscManager	*		oscManager;

	    
    string								xmlSettingsPath;
    ofxXmlSettings						xmlSettings;
    vector<ofxXmlSettings*>				xmlLayouts;
    
    ofDirectory							dir;
    string								initialDirectory;
	vector<string>						doubleLabels;
	
	int		getLayoutNodeByLabel(string label, int pageNum);
    
	bool	checkIfComponentXmlExists(int pageNumber, superInterfaceComponent *component);
    string	checkIfLayoutXmlExists(int pageNumber);
	void	checkIfLabelExists(superInterfaceComponent *component); // used to avoid same labels in all GUI
	
	void	onOscEnabled(superInterfaceEventArgs & e);
    void    onAutoUpdateEnabled(superInterfaceEventArgs & e);
	
};



#endif
