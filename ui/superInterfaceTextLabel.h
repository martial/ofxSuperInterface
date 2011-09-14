//
//  superInterfaceTextLabel.h
//  emptyExample
//
//  Created by Martial Geoffre-Rouland on 09/08/2011.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#ifndef SUPINTSTXTLABEL
#define SUPINTSTXTLABEL

#include "ofMain.h"
#include "superInterfaceComponent.h"

class superInterfaceTextLabel : public superInterfaceComponent {
    
    public :
    
    superInterfaceTextLabel();
    void setup(ofxSuperInterface   * mom, int xGridPos, int yGridPos, string label = "button");
    void update();
    void draw();
    
    ofRectangle getBoundingBox();
	string extraText;
};



#endif
