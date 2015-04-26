// http://en.wikipedia.org/wiki/Orbital_inclination
// http://en.wikipedia.org/wiki/Apsis
// http://en.wikipedia.org/wiki/Orbital_inclination
// http://en.wikipedia.org/wiki/Semi-major_axis

// http://mathworld.wolfram.com/SemilatusRectum.html


#include "ofApp.h"

void ofApp::setup() {
    
    ofBackground(0);
    ofEnableAntiAliasing();

    // http://www.asterank.com/api
    string url = "http://www.asterank.com/api/asterank?query={\"e\":{\"$lt\":0.9},\"i\":{\"$lt\":4},\"a\":{\"$lt\":4.5}}&limit=2000";
    
    // Now parse the JSON
    bool parsingSuccessful = json.open(url);
    

#ifdef DEBUG
    if (parsingSuccessful) {
        ofLogNotice("ofApp::setup") << json.getRawString(true);
    } else {
        ofLogNotice("ofApp::setup") << "Failed to parse JSON.";
    }
#else
    ofSetDataPathRoot("../Resources/");
#endif


    sun.set(2, 10);

    ofNoFill();
    
    orbits.resize( json.size() );
    
    for(int i=0; i<json.size(); i++) {
        
        double _a = json[i]["a"].asDouble();
        double _ad = json[i]["ad"].asDouble();
        double _e = json[i]["e"].asDouble();
        double _q = json[i]["q"].asDouble();
        
        ofPolyline _orbitE;
        for (int i=0; i<360; i++) {

            // http://mathworld.wolfram.com/SemilatusRectum.html
            double _r = _ad * (1 - (_e * _e)) / (1 + _e * cos(ofDegToRad(i)));
            
            float _size = 100;
            float _x1 = _r * cos(ofDegToRad(i)) * _size;
            float _y1 = _r * sin(ofDegToRad(i)) * _size;
            
            _orbitE.addVertex( _x1, _y1 );
        }
        _orbitE.setClosed(true);
        
        
        orbits[i] = _orbitE;
        
    }

    cout << orbits.size() << endl;
    
    
}

void ofApp::update(){
    
    timePlanet = timePlanet + 1;
    
}



void ofApp::draw() {
    
    ofBackgroundGradient(ofColor(0,0,40), ofColor(0,0,10));
    
    ofSetColor(255);
    
    
    cam.begin();
    
    sun.draw();

    if (orbits.size()>0) {
        ofSetColor(255, 30);
        for(int i = 0; i<orbits.size(); i++) {
            orbits[i].draw();
        }
    }
    
    
    cam.end();
    
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    
    if (key=='f') {
        fullscreen = !fullscreen;
        ofSetFullscreen(fullscreen);
    }
    
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){
    
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
