//
//  circle.h
//  soundTester
//
//  Created by Michael on 9/16/15.
//
//

#ifndef circle_h
#define circle_h

#include "ofMain.h"

class Circle{
private:
    float x;
    float y;
    int r;
    
public:
    int life;
    
    Circle(float xf, float yf, int rad);
    void draw();
    
    ofColor color;
    bool has_life();
    
};

#endif /* defined(__soundTester__circle__) */
