//
//  superInterfaceSettingsPage.h
//  emptyExample
//
//  Created by Martial Geoffre-Rouland on 08/08/2011.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#ifndef SUPINTSETTPG
#define SUPINTSETTPG

#include "ofMain.h"
#include "superInterfacePage.h"
#include "superInterfaceHSlider.h"
#include "superInterfaceSimpleButton.h"
#include "superInterfaceHTextLabel.h"

class ofxSuperInterface;

class superInterfaceSettingsPage : public superInterfacePage {
    
public:
    
    superInterfaceSettingsPage();
    
    void setup(ofxSuperInterface * mom);    
    void update();
    void draw();
    
    superInterfaceHSlider           xUnitSlider;
    superInterfaceHSlider           yUnitSlider;
	superInterfaceSimpleButton      gridBtn;
    superInterfaceSimpleButton      saveBtn;
	superInterfaceSimpleButton      positionBtn;
    superInterfaceHTextLabel        label;
    
    
};



#endif
