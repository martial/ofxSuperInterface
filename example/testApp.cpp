#include "testApp.h"




//--------------------------------------------------------------
void testApp::setup(){
	
	
    
	ofSetFrameRate(60);
    ofSetLogLevel(OF_LOG_NOTICE);
	
	/*
	 We set basic stuff for our rectangle
	 */
	
	fboTest.allocate(320, 240, GL_RGBA, 1);
	
	rectColor.set(255, 0, 0);
	
	rectWidthPct = 1.0;
	rectHeightPct = 1.0;
	sens = 1;
	xPosRect = 0.0;
	
	bFlickering = true;
	
	
	
	/*
	 Interface setup
	 */
		
    interface.setup();
	
	
	// start with FBO comp
	// send as argument the interface, the fbo, grid pos, grid size, and label
	fboComp.setup(&interface, &fboTest, 0, 0, 8, 8, "fbo");
	
	// some sliders and listeners
    slider.setup(&interface, &rectWidthPct, 0, 10, 10, 4, 0.0, 1.0, "slider one");
    slider2.setup(&interface, &rectHeightPct, 12, 10, 10, 4, 0.0, 1.0, "slider two");
	
	ofAddListener(slider.eventUpdateValues, this, &testApp::onSliderHandler);
	ofAddListener(slider2.eventUpdateValues, this, &testApp::onSliderHandler);
	
	
	// a simple switch button, with a listener
	btn.setup(&interface, bFlickering, "flickering", 24, 10, 10, 4);	
	ofAddListener(btn.eventMouseDown, this, &testApp::onBtnHandler);
	
	
    
	// a color picker
	colorPicker.setup(&interface, &rectColor, "rectangle color color", 0, 16, 10, 5);
	ofColor red, green, blue;
	red.set(255, 0,0);
	green.set(0, 255, 0);
	blue.set(0,0,255);
	
	colorPicker.addColor(red);
	colorPicker.addColor(green);
	colorPicker.addColor(blue);
	
	
    // the we add our components
	// the last argument is the page number
	
	interface.addComponent(&fboComp, 0);
	interface.addComponent(&colorPicker, 0);
	
    interface.addComponent(&slider,0);
    interface.addComponent(&slider2,0);
	interface.addComponent(&btn,0);
    
	
	// send values to OSC for slider with adress 
	// see settings.xml for host and port 
	
	slider.enableOSC(true, "rectWidth");
	
	
}

//--------------------------------------------------------------
void testApp::update(){
    interface.update();
	
	xPosRect+= sens;
	if (xPosRect>320) {
		sens = -1;
	}
	if ( xPosRect<0) {
		sens =1;
	}
	
}

//--------------------------------------------------------------
void testApp::draw(){
    
    ofBackground(0);

	fboTest.begin();
	
	ofSetColor(125, 125, 125);
	ofRect(0, 0, 320.0, 240.0);
	
	
	ofSetColor(rectColor);
	
	if( bFlickering ) {
		
		if( ofGetFrameNum() % 6 < 3 ) {
			ofRect(xPosRect, 0, 50 * rectWidthPct, 50 * rectHeightPct );
		}
		
		
	} else {
		ofRect(xPosRect, 0, 50 * rectWidthPct, 50 * rectHeightPct );
	}
		
	fboTest.end();
    
    interface.draw();
	
	
	
}

//--------------------------------------------------------------


void testApp::onBtnHandler(superInterfaceEventArgs & e ) {
	
	// you can get also the component 
	superInterfaceObject * comp = e.comp; 
	string label = comp->settings->label;
	
	ofLog(OF_LOG_NOTICE, "button clicked ! " + label);
	
}

void testApp::onSliderHandler(superInterfaceEventArgs & e ) {
	
	superInterfaceObject * comp = e.comp; 
	string label = comp->settings->label;
	
	ofLog(OF_LOG_NOTICE, "slider update ! " + label);
	
}



void testApp::keyPressed(int key){
	
	switch ( key ) {
				
		case 'f':
			ofToggleFullscreen();
			break;
			
		
	}

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}