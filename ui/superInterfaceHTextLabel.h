//
//  superInterfaceHTextLabel.h
//  emptyExample
//
//  Created by Martial Geoffre-Rouland on 09/08/2011.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#ifndef SUPINTTXTLABEL
#define SUPINTTXTLABEL

#include "ofMain.h"
#include "superInterfaceComponent.h"

class superInterfaceHTextLabel : public superInterfaceComponent {
        
    public :
    
    superInterfaceHTextLabel();
    void setup(ofxSuperInterface   * mom, int xGridPos, int yGridPos, string label = "button");
    void update();
    void draw();
    
    ofRectangle getBoundingBox();
    
    
    
};



#endif
