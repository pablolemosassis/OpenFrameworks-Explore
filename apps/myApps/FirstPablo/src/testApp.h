#pragma once

#include "ofMain.h"

#include "ball.h"

class testApp : public ofBaseApp{
	public:
		void setup();
		void update();
		void draw();
		
		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y);
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
        void drawStar(float xpos, float ypos, float radius, int npts);
    
    int myCircleX;
    int myCircleY;
    int myCircleRadius;
    //
    #define NUM_CIRCLES 1000
    float circleX[NUM_CIRCLES];
    float circleY[NUM_CIRCLES];
    float circleRad[NUM_CIRCLES];
    int circleR[NUM_CIRCLES];
    int circleG[NUM_CIRCLES];
    int circleB[NUM_CIRCLES];
    //
    Ball theBall;   // Replaces the previous variables 
                    // with a new object that contains 
                    // the previous information
};
