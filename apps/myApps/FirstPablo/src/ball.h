//
//  ball.h
//  FirstPablo
//
//  Created by Pablo Cabana on 9/12/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef FirstPablo_ball_h
#define FirstPablo_ball_h

#include "ofMain.h"

class Ball {
public:
    // Constructor
    Ball();     
    
    // Methods
    void moveTo(int _xDestiny, int _yDestiny);
    void draw();
    
    // Properties
    int x;
    int y;
    ofColor color;
};


#endif
