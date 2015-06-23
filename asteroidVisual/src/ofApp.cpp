// http://en.wikipedia.org/wiki/Apsis
// http://en.wikipedia.org/wiki/Orbital_inclination
// http://en.wikipedia.org/wiki/Semi-major_axis

// http://mathworld.wolfram.com/SemilatusRectum.html


#include "ofApp.h"

void ofApp::setup() {
    
    ofSetDataPathRoot("../Resources/data/");

    ofBackground(0);
    ofEnableAntiAliasing();
    
    // http://www.asterank.com/api
    string url = "http://www.asterank.com/api/asterank?query={\"e\":{\"$lt\":0.9},\"i\":{\"$lt\":4},\"a\":{\"$lt\":4.5}}&limit=200";
    
    // Now parse the JSON
    bool parsingSuccessful = json.open(url);
    
    
    if (parsingSuccessful) {
        ofLogNotice("ofApp::setup") << json.getRawString(true);
    } else {
        ofLogNotice("ofApp::setup") << "Failed to parse JSON.";
    }
    
    sun.set(2, 10);
    
    ofNoFill();
    
    orbits.resize( json.size() );
    
    ofMesh _mesh;
    mesh.setMode(OF_PRIMITIVE_POINTS);

    for(int i=0; i<json.size(); i++) {
        
        orbit _orbitE;
        
        double _a = json[i]["a"].asDouble();
        double _ad = json[i]["ad"].asDouble();
        double _e = json[i]["e"].asDouble();
        double _q = json[i]["q"].asDouble();
        double _i = json[i]["i"].asDouble();
        double _om = json[i]["om"].asDouble();

        per_y.push_back( json[i]["per_y"].asDouble() );
        
        ofPolyline _orbitPath;
        

        for (int i=0; i<360; i++) {
            // http://mathworld.wolfram.com/SemilatusRectum.html
            double _r = _ad * (1 - (_e * _e)) / (1 + _e * cos(ofDegToRad(i)));
            
            float _size = 100;
            float _x1 = _r * cos(ofDegToRad(i)) * _size;
            float _y1 = _r * sin(ofDegToRad(i)) * _size;
            
            _orbitPath.addVertex( _x1, _y1 );
        }
 
        mesh.addVertex( ofVec3f( 0, 0, 0) );

        _orbitPath.setClosed(true);
        
        
        _orbitE.path = _orbitPath;
        _orbitE.inclination = _i;
        _orbitE.omega = _om;
        
        orbits[i] = _orbitE;
        
    }
    
    rotateZ = 0;
    
}

void ofApp::update(){
    
    timePlanet = timePlanet + 1;
    
    rotateZ = rotateZ + 0.25;

    movingPathFactor = movingPathFactor + 0.1;
}



void ofApp::draw() {
    
    ofBackgroundGradient(ofColor(0,0,40), ofColor(0,0,10));
    
    ofSetColor(255);
    
    cam.begin();
    
//    ofRotateZ( rotateZ );
    
    sun.draw();
    
    if (orbits.size()>0) {
        ofSetColor(255, 20);
        for(int i = 0; i<orbits.size(); i++) {
            ofPushMatrix();
            
            ofRotateY( orbits[i].inclination );
            ofRotateZ( orbits[i].omega );
            orbits[i].path.draw();
            
            ofPopMatrix();

            ofPushMatrix();
            ofPushStyle();
            ofSetColor(255);
            ofRotateY( orbits[i].inclination );
            ofRotateZ( orbits[i].omega );
            ofVec3f _path = orbits[i].path.getPointAtPercent(ofMap((int)(movingPathFactor * per_y[i])%360, 0, 360, 0, 1));
            
            mesh.setVertex(0, _path);
            mesh.draw();
            
            ofPopStyle();
            ofPopMatrix();

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
