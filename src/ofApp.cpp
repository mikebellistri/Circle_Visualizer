#include "ofApp.h"
#include <list>


//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(54, 54, 54);
    //ofSetFrameRate(60);
    soundStream.listDevices();
    
    int buffSize = 256;
    left.assign(buffSize, 0.0);
    right.assign(buffSize, 0.0);
    
    soundStream.setup(this, 0, 2, 44100, buffSize, 4);
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
    
    
}

//--------------------------------------------------------------
void ofApp::draw(){
   
    ofSetColor(225);
    ofNoFill();
    
    //left Channel
    
    ofPushStyle();
        ofPushMatrix();
       ofTranslate(ofGetWindowWidth()*.5, ofGetWindowHeight()*.5, 0);
    
       // ofSetColor(ofRandom(255), ofRandom(255), ofRandom(255));
        //ofFill();
        for (unsigned int i = 0; i < right.size(); i++){
            
            if (circle.size() < 6 && 100 -right[i]*180.0f > 150) {
                Circle* c = new Circle(ofRandom(100 -right[i]*180.0f), ofRandom(100 -left[i]*180.0f) , 100 -right[i]*180.0f);
                circle.push_back(*c);
                
                
            }
            for (int i = 0; i < circle.size(); i++){
                if(circle[i].has_life()){
                    circle[i].draw();
                    circle[i].life -= 1;
                }else{
                    circle.erase(circle.begin() + i);
                }
                    
            }
            
        }

    
    
//        ofSetColor(225);
//        ofDrawBitmapString("Left Channel", 4, 18);
//    
//        ofSetLineWidth(1);
//        ofRect(0, 0, 512, 200);
//    
//        ofSetColor(245, 58, 135);
//        ofSetLineWidth(3);
//    
//            ofBeginShape();
//            for (unsigned int i = 0; i < left.size(); i++){
//                ofVertex(i*2, 100 -left[i]*180.0f);
//            }
//            ofEndShape(false);
    
        ofPopMatrix();
    ofPopStyle();
   
    //right channel
    
//    ofPushStyle();
//        ofPushMatrix();
//        ofTranslate(32, 370, 0);
//    
//        ofSetColor(225);
//        ofDrawBitmapString("Right Channel", 4, 18);
//    
//        ofSetLineWidth(1);
//        ofRect(0, 0, 512, 200);
//    
//        ofSetColor(245, 58, 135);
//        ofSetLineWidth(3);
//    
//            ofBeginShape();
//            for (unsigned int i = 0; i < right.size(); i++){
//                ofVertex(i*2, 100 -right[i]*180.0f);
//            }
//            ofEndShape(false);
//    
//        ofPopMatrix();
//    ofPopStyle();

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

//---------------------------------------------------
void ofApp::audioIn(float * input, int bufferSize, int nChannels){
    
    //lets go through each sample and calculate the root mean square which is a rough way to calculate volume
    for (int i = 0; i < bufferSize; i++){
        left[i]		= input[i*2]*0.5;
        right[i]	= input[i*2+1]*0.5;
        
    }
    
}
