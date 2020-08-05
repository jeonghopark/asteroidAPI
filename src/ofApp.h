#pragma once

#include "ofMain.h"
#include "ofxGui.h"

#define BUFFER_SIZE 4086
#define SAMPLE_RATE 44100
#define INITIAL_BUFFER_SIZE 512
#define BIT 512


struct Orbit{
    ofPolyline path;
    ofMesh mesh;
    ofVboMesh mVbo;
    double inclination;
    double omega;
    double a;
    float per_y;
    float movingF;
    float movingFNext;
    float movingFView;
    float ad;
    float e;
    float om;
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
    
    
    
    //    void audioRequested(float * output, int bufferSize, int nChannels);
    
    void audioOut(ofSoundBuffer & buffer);
    ofSoundStream soundStream;
    
    void movingUpdate();
    void audioTriggerUpdate();
    
    float line;
    
    int	maxHertz;
    int	minHertz;
    
    double sineBuffer[514];
    double sineBufferLeft[514];
    double sineBufferRight[514];
    float remainderLeft;
    float remainderRight;
    float waveLeft;
    float waveRight;
    float amp[BIT];
    float ampLeft[BIT];
    float ampRight[BIT];
    int hertzScale[BIT];
    int hertzScaleLeft[BIT];
    int hertzScaleRight[BIT];
    float phases[BIT];
    float phasesLeft[BIT];
    float phasesRight[BIT];
    
    bool bPlaying;
    
    float getPixel(int x, int y);
    float getAmp(float x, float y);
    float getFreq(float y);
    
    float getPixelLeft(int x, int y);
    float getAmpLeft(float x, float y);
    float getFreqLeft(float y);
    float getPixelRight(int x, int y);
    float getAmpRight(float x, float y);
    float getFreqRight(float y);
    
    float getAmpLeft(float x, float y, ofPixels _p);
    
    
    ofJson json;
    
    ofEasyCam cam;
    bool fullscreen;
    
    float orbitBaseSize;
    
    ofSpherePrimitive sun;
    
    vector<Orbit> orbits;
    vector<Orbit> setupOrbits(string _s);
        
    float movingPathFactor;
    float movingPathFactorUpdate();
    float movingPathFactorV();
    float movingPathFactorF();

    
    ofFbo astroidFBO;
    void astroidFBOBuff(float _f);
    float threshold;
    
    Orbit setupPlanetOrbit(float _e, float _ad);
    Orbit earthOrbit;
    Orbit marsOrbit;
    Orbit jupiterOrbit;
    Orbit saturnOrbit;
    Orbit uranusOrbit;
    Orbit neptuneOrbit;

    
    void drawSun();
    ofTrueTypeFont sunName;
    
    // from TextFacingCameraSample sourcecode
    void billboardBegin();
    void billboardEnd();    
    
    
    ofxPanel gui;
    ofxToggle onOffInternet;
    
    void textInformation();

    ofMesh circleMesh(vector<glm::vec3> _v);
    ofPolyline circlePath(vector<glm::vec3> _v);
    
    vector<ofPolyline> drawTrackingLine;

    void drawTriggerLine();

    ofMesh asteroidPoint;
    
    vector<glm::vec3> makeOrbitPath(float _ad, float _e, float _om, float _inclination);
  
    ofShader billboardShader;
    ofImage texture;
    
    ofVboMesh billboards;
    vector<glm::vec3> billboardVels;

    
    ofShader shader;

    
    ofRectangle viewportEarth;
    
    
    ofVbo allOrbitPathMesh;
    
    vector<ofVbo> allOrbitPathMeshMulti;
    ofNode sunNode;
    
    float orbitSpeed;
    
    vector<ofVec3f> currentOrbitPos;
    vector<ofVec3f> nextOrbitPos;
    vector<ofVec3f> backOrbitPos;
    vector<float> angelAtIndex;
    int cometIndex;
    
};



