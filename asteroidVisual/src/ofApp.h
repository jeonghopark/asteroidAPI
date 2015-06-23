#pragma once

#include "ofMain.h"
#include "ofxJSON.h"

struct orbit{
    
    ofPolyline path;
    double inclination;
    double omega;
    
};

class ofApp : public ofBaseApp {

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
    
    
    ofxJSONElement json;

    ofEasyCam cam;
    float timePlanet;
    bool fullscreen;
    
    ofSpherePrimitive sun;
    
    vector<orbit> orbits;

    float rotateZ;
    
    float movingPathFactor;
    
    ofMesh mesh;
    
    vector<float> per_y;
    
};