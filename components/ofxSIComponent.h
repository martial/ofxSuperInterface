//
//  superInterfaceComponent.h
//  emptyExample
//
//  Created by Martial Geoffre-Rouland on 05/08/2011.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#ifndef SUPINTCOMP
#define SUPINTCOMP

#include "ofMain.h"
#include "superInterfaceInteractiveObject.h"
#include "superInterfaceAssets.h"

class superInterfaceComponent : public superInterfaceInteractiveObject {
    
public:
    
    superInterfaceComponent();
    void setup(ofxSuperInterface   * mom, string label);
    void setAssets( superInterfaceAssets * assets);
    void update();
	void update(ofEventArgs & e);
    void draw();
    
    void onMousePressed(int x, int y, int id);
    void onMouseDragged(int x, int y);
    void onMouseMoved();
    void onMouseReleased();
    
      
    
    
};


#endif
