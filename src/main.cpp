#include "ofMain.h"
#include "ofApp.h"

#include "ofAppGLFWWindow.h"

//========================================================================
int main( ){
    
    ofGLFWWindowSettings settings;
    settings.setGLVersion(4, 1);
    settings.numSamples = 4;
    settings.doubleBuffering = true;
    settings.setSize(1280, 720);
    
    ofCreateWindow(settings);
    // this kicks off the running of my app
    // can be OF_WINDOW or OF_FULLSCREEN
    // pass in width and height too:
    ofRunApp(new ofApp());
    
}
