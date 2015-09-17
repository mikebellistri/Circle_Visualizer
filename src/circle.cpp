//
//  circle.cpp
//  soundTester
//
//  Created by Michael on 9/16/15.
//
//

#include "circle.h"

Circle::Circle(float xf, float yf, int rad){
    color.set(ofRandom(255), ofRandom(255), ofRandom(255));
    x = xf;
    y = yf;
    r = rad;
    life = 600;

}

void Circle::draw(){
    ofSetColor(color);
    ofFill();
    ofCircle(x,y,r);
}

bool Circle::has_life(){
    if (life <= 0){
        return false;
    }else{
        return true;
    }
}