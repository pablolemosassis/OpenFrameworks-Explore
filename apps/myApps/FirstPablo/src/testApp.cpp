#include "testApp.h"



//--------------------------------------------------------------
void testApp::setup(){
    ofSetFrameRate(60);
    
    myCircleRadius=100;
    myCircleX = 0;
    myCircleY = 0;
    ///
    for(int i=0; i<NUM_CIRCLES; i++)
    {
        circleX[i] = ofRandom(0, ofGetWidth());
        circleY[i] = ofRandom(0, ofGetHeight());
        circleRad[i] = ofRandom(10, 40);
        
        circleR[i] = ofRandom(0, 255);
        circleG[i] = ofRandom(0, 255);
        circleB[i] = ofRandom(0, 255);
        //
        
    }
}

//--------------------------------------------------------------
void testApp::update(){
    myCircleX+=4;
    if(myCircleX > 1024)
    {
        myCircleX = 0;
    }
    //
    for(int i=0; i<NUM_CIRCLES; i++)
    {
        circleX[i] += ofRandom(-1,1);
        circleY[i] += ofRandom(-1,1);
    }
    //
    theBall.moveTo(mouseX,mouseY);
    
}

//--------------------------------------------------------------
void testApp::draw(){
    ofEnableSmoothing();
    ofBackgroundGradient(ofColor::white,ofColor(255,255,200), OF_GRADIENT_CIRCULAR);
    //
    for(int i=0; i<NUM_CIRCLES; i++)
    {
        ofSetColor(circleR[i], circleG[i], circleB[i]);
        ofCircle(circleX[i], circleY[i], circleRad[i]);
    }
    //
    int x = 20;
    do {
        ofCircle(x, 300, 10);
        x+=20;
    } while(x < ofGetWidth());
    
    ofSetColor(255, 0, 255);
    ofCircle(200, 300, 60);
    
    ofSetColor(0, myCircleY, myCircleX);
    ofCircle(myCircleX, myCircleY, myCircleRadius);
    
    ofRect(ofGetScreenWidth()*0.5, ofGetScreenHeight()*0.5, 100, 100);
    ofRect(ofGetWindowWidth()*0.5, ofGetWindowHeight()*0.5, 100, 100);
    ofTriangle(10, 10, 40, 40, 100, 100);
    ofLine(0, 0, 1024, 768);
    ofEllipse(500, 500, 200, 100);
    ofCurve(0, 0, 200, 100, 400, 500, 1024, 768);
    //
    ofSetColor(0, 0, 0);
    ofNoFill();
    ofSetLineWidth( 4 );
    drawStar(800, 520, myCircleRadius, 16);
    ofFill();
    //
    ofSetRectMode(OF_RECTMODE_CENTER);
    ofRect(mouseX,mouseY, 100, 100);
    ofSetRectMode(OF_RECTMODE_CORNER);
    //
    
    theBall.draw();
    
    ofDrawBitmapString(ofToString(ofGetFrameRate())+"fps", 10, 15);
    
}
//--------------------------------------------------------------
void testApp::drawStar(float xpos, float ypos, float radius, int npts)
{
    bool useInner=false;
    ofBeginShape();
    for(int i=0; i<360; i+=360/npts)
    {
        int r = useInner ? radius*.6 : radius;
        int x = xpos + cos( ofDegToRad(i) ) * r;
        int y = ypos + sin( ofDegToRad(i) ) * r;
        ofVertex(x, y);
        useInner = !useInner;
    }
    ofEndShape();
}
//--------------------------------------------------------------
void testApp::keyPressed(int key){
    if(key=='w')myCircleY++;
    cout << "keyPressed " << (char)key << endl;
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){
    cout << "keyReleased " << key << endl;
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y){
    cout << "mouseMoved: " << x << ", " << y << endl;
    //myCircleRadius++;
}

void testApp::mouseDragged(int x, int y, int button){
    cout << "mouseDragged: " << x << ", " << y << " button: " << button << endl;
}

void testApp::mousePressed(int x, int y, int button){
    //cout << "mousePressed: " << x << ", " << y << " button: " << button << endl;
    float distance = ofDist(myCircleX, myCircleY, x, y);
    if(distance < myCircleRadius)
    {
        myCircleRadius+=50;
    }
}

void testApp::mouseReleased(int x, int y, int button){
    cout << "mouseReleased: " << x << ", " << y << " button: " << button << endl;
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