#include "ofApp.h"
#include <ofVideoGrabber.h>
#include "ofxCvHaarFinder.h"
#include <math.h>

ofxCvHaarFinder finder;
ofImage img;
float x,y,width, height;
ofVideoGrabber mygrabber;


//------MALUQUICE
double sizeOfObject;
double distance;
double YtoX;

#define PI 3.14159265
//--------------------------------------------------------------
void ofApp::setup(){
	finder.setup("haarcascade_frontalface_default.xml");
	//---------------------------------------------

	mygrabber.initGrabber(800,800);
	mygrabber.listDevices();
	mygrabber.setDeviceID(0);
}

//--------------------------------------------------------------
void ofApp::update(){
	img.setFromPixels((ofImage)mygrabber.getPixelsRef());
	finder.findHaarObjects(img, 221, 221);
	mygrabber.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
	//mygrabber.draw(0,0);
	img.draw(0,0);

	for(int i = 0; i < finder.blobs.size(); i++){
		/*ofRectangle cur = finder.blobs[i].boundingRect;
		// Assigning the size of each face.
		x = cur.x; y = cur.y; width = cur.width; height = cur.height; 

		//Writing the size in console.
		cout<<"--------------------------------------------"<<endl;
		cout<<"Rosto "<<i+1<<" :"<<endl;
		cout<<"X = "<<x<<"; "<<"Y = "<<y<<"; "<<"Width = "<<width<<"; "<<"Height = "<<height<<"."<<endl;
		cout<<"--------------------------------------------"<<endl;
		ofNoFill();
		ofRect(x,y,width, height);*/
		ofNoFill();
		ofRect(finder.blobs[i].boundingRect);
		sizeOfObject = finder.blobs[i].boundingRect.height;//*0.02645833333;

	}
	
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
