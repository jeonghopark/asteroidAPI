#include "ofApp.h"


float sines[512] = {0, 0.012268, 0.024536, 0.036804, 0.049042, 0.06131, 0.073547, 0.085785, 0.097992, 0.1102, 0.12241, 0.13455, 0.1467, 0.15884, 0.17093, 0.18301, 0.19507, 0.20709, 0.21909, 0.23105, 0.24295, 0.25485, 0.26669, 0.2785, 0.29025, 0.30197, 0.31366, 0.32529, 0.33685, 0.34839, 0.35986, 0.37128, 0.38266, 0.39395, 0.40521, 0.41641, 0.42752, 0.4386, 0.44958, 0.46051, 0.47137, 0.48215, 0.49286, 0.50351, 0.51407, 0.52457, 0.53497, 0.54529, 0.55554, 0.5657, 0.57578, 0.58575, 0.59567, 0.60547, 0.6152, 0.62482, 0.63437, 0.6438, 0.65314, 0.66238, 0.67151, 0.68057, 0.68951, 0.69833, 0.70706, 0.7157, 0.72421, 0.7326, 0.74091, 0.74908, 0.75717, 0.76514, 0.77298, 0.7807, 0.7883, 0.79581, 0.80316, 0.81042, 0.81754, 0.82455, 0.83142, 0.8382, 0.84482, 0.85132, 0.8577, 0.86392, 0.87006, 0.87604, 0.88187, 0.8876, 0.89319, 0.89862, 0.90396, 0.90912, 0.91415, 0.91907, 0.92383, 0.92847, 0.93295, 0.93729, 0.9415, 0.94556, 0.94949, 0.95325, 0.95691, 0.96039, 0.96375, 0.96692, 0.97, 0.9729, 0.97565, 0.97827, 0.98074, 0.98306, 0.98523, 0.98724, 0.98914, 0.99084, 0.99243, 0.99387, 0.99515, 0.99628, 0.99725, 0.99808, 0.99875, 0.99927, 0.99966, 0.99988, 0.99997, 0.99988, 0.99966, 0.99927, 0.99875, 0.99808, 0.99725, 0.99628, 0.99515, 0.99387, 0.99243, 0.99084, 0.98914, 0.98724, 0.98523, 0.98306, 0.98074, 0.97827, 0.97565, 0.9729, 0.97, 0.96692, 0.96375, 0.96039, 0.95691, 0.95325, 0.94949, 0.94556, 0.9415, 0.93729, 0.93295, 0.92847, 0.92383, 0.91907, 0.91415, 0.90912, 0.90396, 0.89862, 0.89319, 0.8876, 0.88187, 0.87604, 0.87006, 0.86392, 0.8577, 0.85132, 0.84482, 0.8382, 0.83142, 0.82455, 0.81754, 0.81042, 0.80316, 0.79581, 0.7883, 0.7807, 0.77298, 0.76514, 0.75717, 0.74908, 0.74091, 0.7326, 0.72421, 0.7157, 0.70706, 0.69833, 0.68951, 0.68057, 0.67151, 0.66238, 0.65314, 0.6438, 0.63437, 0.62482, 0.6152, 0.60547, 0.59567, 0.58575, 0.57578, 0.5657, 0.55554, 0.54529, 0.53497, 0.52457, 0.51407, 0.50351, 0.49286, 0.48215, 0.47137, 0.46051, 0.44958, 0.4386, 0.42752, 0.41641, 0.40521, 0.39395, 0.38266, 0.37128, 0.35986, 0.34839, 0.33685, 0.32529, 0.31366, 0.30197, 0.29025, 0.2785, 0.26669, 0.25485, 0.24295, 0.23105, 0.21909, 0.20709, 0.19507, 0.18301, 0.17093, 0.15884, 0.1467, 0.13455, 0.12241, 0.1102, 0.097992, 0.085785, 0.073547, 0.06131, 0.049042, 0.036804, 0.024536, 0.012268, 0, -0.012268, -0.024536, -0.036804, -0.049042, -0.06131, -0.073547, -0.085785, -0.097992, -0.1102, -0.12241, -0.13455, -0.1467, -0.15884, -0.17093, -0.18301, -0.19507, -0.20709, -0.21909, -0.23105, -0.24295, -0.25485, -0.26669, -0.2785, -0.29025, -0.30197, -0.31366, -0.32529, -0.33685, -0.34839, -0.35986, -0.37128, -0.38266, -0.39395, -0.40521, -0.41641, -0.42752, -0.4386, -0.44958, -0.46051, -0.47137, -0.48215, -0.49286, -0.50351, -0.51407, -0.52457, -0.53497, -0.54529, -0.55554, -0.5657, -0.57578, -0.58575, -0.59567, -0.60547, -0.6152, -0.62482, -0.63437, -0.6438, -0.65314, -0.66238, -0.67151, -0.68057, -0.68951, -0.69833, -0.70706, -0.7157, -0.72421, -0.7326, -0.74091, -0.74908, -0.75717, -0.76514, -0.77298, -0.7807, -0.7883, -0.79581, -0.80316, -0.81042, -0.81754, -0.82455, -0.83142, -0.8382, -0.84482, -0.85132, -0.8577, -0.86392, -0.87006, -0.87604, -0.88187, -0.8876, -0.89319, -0.89862, -0.90396, -0.90912, -0.91415, -0.91907, -0.92383, -0.92847, -0.93295, -0.93729, -0.9415, -0.94556, -0.94949, -0.95325, -0.95691, -0.96039, -0.96375, -0.96692, -0.97, -0.9729, -0.97565, -0.97827, -0.98074, -0.98306, -0.98523, -0.98724, -0.98914, -0.99084, -0.99243, -0.99387, -0.99515, -0.99628, -0.99725, -0.99808, -0.99875, -0.99927, -0.99966, -0.99988, -0.99997, -0.99988, -0.99966, -0.99927, -0.99875, -0.99808, -0.99725, -0.99628, -0.99515, -0.99387, -0.99243, -0.99084, -0.98914, -0.98724, -0.98523, -0.98306, -0.98074, -0.97827, -0.97565, -0.9729, -0.97, -0.96692, -0.96375, -0.96039, -0.95691, -0.95325, -0.94949, -0.94556, -0.9415, -0.93729, -0.93295, -0.92847, -0.92383, -0.91907, -0.91415, -0.90912, -0.90396, -0.89862, -0.89319, -0.8876, -0.88187, -0.87604, -0.87006, -0.86392, -0.8577, -0.85132, -0.84482, -0.8382, -0.83142, -0.82455, -0.81754, -0.81042, -0.80316, -0.79581, -0.7883, -0.7807, -0.77298, -0.76514, -0.75717, -0.74908, -0.74091, -0.7326, -0.72421, -0.7157, -0.70706, -0.69833, -0.68951, -0.68057, -0.67151, -0.66238, -0.65314, -0.6438, -0.63437, -0.62482, -0.6152, -0.60547, -0.59567, -0.58575, -0.57578, -0.5657, -0.55554, -0.54529, -0.53497, -0.52457, -0.51407, -0.50351, -0.49286, -0.48215, -0.47137, -0.46051, -0.44958, -0.4386, -0.42752, -0.41641, -0.40521, -0.39395, -0.38266, -0.37128, -0.35986, -0.34839, -0.33685, -0.32529, -0.31366, -0.30197, -0.29025, -0.2785, -0.26669, -0.25485, -0.24295, -0.23105, -0.21909, -0.20709, -0.19507, -0.18301, -0.17093, -0.15884, -0.1467, -0.13455, -0.12241, -0.1102, -0.097992, -0.085785, -0.073547, -0.06131, -0.049042, -0.036804, -0.024536, -0.012268};



//--------------------------------------------------------------
void ofApp::setup() {

//#ifdef DEBUG
//
//#else
//    ofSetDataPathRoot("../Resources/data/");
//#endif

    ofBackground(0);
    ofSetFrameRate(60);
    ofSetVerticalSync(true);
    ofEnableAntiAliasing();

    gui.setup();
    gui.add(onOffInternet.setup("Connect Internet", false));

    sunName.load("NewMedia Fett.ttf", 20, true);
    sunName.setGlobalDpi(72);

    for (int i = 0; i < 512; i++) {
        amp[i] = 0;
        hertzScale[i] = 0;
        phases[i] = 0;
        sineBuffer[i] = sines[i];
        sineBufferLeft[i] = sines[i];
        sineBufferRight[i] = sines[i];
    }


    //    soundStream.printDeviceList();
    ofSoundStreamSettings settings;
//    auto devices = soundStream.getMatchingDevices("default");
//    if (!devices.empty()) {
//        settings.setOutDevice(devices[1]);
//    }
    settings.setOutListener(this);
    settings.bufferSize = INITIAL_BUFFER_SIZE;
    settings.sampleRate = SAMPLE_RATE;
    settings.numInputChannels = 0;
    settings.numOutputChannels = 2;
    soundStream.setup(settings);

    bPlaying = false;
    line = 0.1;

    orbitBaseSize = 10;

    maxHertz = 8000;
    minHertz = 150;

    astroidFBO.allocate(30, BIT, GL_RGB);

    threshold = 0.9;

    cam.setAutoDistance(false);
    cam.setDistance(50);

    sun.set(2, 10);

    earthOrbit = setupPlanetOrbit(0.01671123, 1.0);
    marsOrbit = setupPlanetOrbit(0.0934, 1.52371);
    jupiterOrbit = setupPlanetOrbit(0.0484, 5.2029);
    saturnOrbit = setupPlanetOrbit(0.0539, 9.537);
    uranusOrbit = setupPlanetOrbit(0.04726, 19.189);
    neptuneOrbit = setupPlanetOrbit(0.00859, 30.0699);

    orbits = setupOrbits("results_comets_edit.csv");
    drawTrackingLine.resize(orbits.size());
    asteroidPoint.setMode(OF_PRIMITIVE_POINTS);
    
    for (int i = 0; i < orbits.size(); i++) {
        asteroidPoint.addVertex(ofVec3f(0, 0, 0));
    }

    
    billboards.getVertices().resize(orbits.size());
    billboards.getColors().resize(orbits.size());
    billboards.getNormals().resize(orbits.size(),glm::vec3(0, 0, 0));
    
    for (int i = 0; i < asteroidPoint.getNumVertices(); i++) {
        glm::vec3 _v = asteroidPoint.getVertex(i);
        billboardVels.push_back(_v);
        billboards.addVertex(billboardVels[i]);
        billboards.setNormal(i, glm::vec3(1, 0, 0));
    }
    
    billboards.setUsage( GL_DYNAMIC_DRAW );
    billboards.setMode(OF_PRIMITIVE_POINTS);
    if(ofIsGLProgrammableRenderer()){
        billboardShader.load("shadersGL3/Billboard");
    }else{
        billboardShader.load("shadersGL2/Billboard");
    }
    
    ofDisableArbTex();
    texture.load("dot_blur1px.png");
    ofEnableAlphaBlending();

    shader.load("shader");

    
}



//--------------------------------------------------------------
vector<Orbit> ofApp::setupOrbits(string _s) {

    vector<Orbit> _oV;

    ofBuffer buffer = ofBufferFromFile(_s);
    if(buffer.size()) {
        int _index = 0;
        Orbit _orbitE;
        
        for (ofBuffer::Line it = buffer.getLines().begin(), end = buffer.getLines().end(); it != end; ++it) {
            string line = *it;

            Orbit _o;
            if (_index > 0) {
                vector<string> _l = ofSplitString(line, ",");
                _orbitE.a = ofToFloat(_l[1]);
                _orbitE.inclination = ofToFloat(_l[3]);
                _orbitE.per_y = ofToFloat(_l[8]);
                
                _orbitE.ad = ofToFloat(_l[6]);
                _orbitE.e = ofToFloat(_l[1]);
                _orbitE.om = ofToFloat(_l[4]);
                
                vector<glm::vec3> _v = makeOrbitPath(_orbitE.ad, _orbitE.e, _orbitE.om, _orbitE.inclination);
                _orbitE.path = circlePath(_v);
                _orbitE.mVbo = circleMesh(_v);

                _orbitE.movingF = ofRandom(circlePath(_v).getLengthAtIndex(circlePath(_v).size() - 1));

                _oV.push_back(_orbitE);
            }
            
            _index++;
        }
    }

    return _oV;

}




//--------------------------------------------------------------
Orbit ofApp::setupPlanetOrbit(float _e, float _ad) {

    Orbit _o;

    for (int i = 0; i <= 360; i+=1) {
        double _r = _ad * (1 - (_e * _e)) / (1 + _e * cos(ofDegToRad(i)));

        float _size = orbitBaseSize * 2;
        float _x1 = _r * cos(ofDegToRad(i)) * _size;
        float _y1 = _r * sin(ofDegToRad(i)) * _size;

        _o.path.addVertex( _x1, _y1 );
    }

    return _o;

}



//--------------------------------------------------------------
vector<glm::vec3> ofApp::makeOrbitPath(float _ad, float _e, float _om, float _inclination) {
             
    vector<glm::vec3> _v;
    
//    _inclination = 0;
    
    float _height = 0;
    for (int _deg = 0; _deg < 361; _deg += 2) {
        double _r = _ad * (1 - (_e * _e)) / (1 + _e * cos(ofDegToRad(_deg)));
        float _x = _r * cos(ofDegToRad(_deg + _om)) * cos(ofDegToRad(_inclination));
        float _y = _r * sin(ofDegToRad(_deg + _om)) * cos(ofDegToRad(_inclination));
        

        float _z = 0;
        if (_inclination < 90) {
            _x = _r * cos(ofDegToRad(_deg + _om - 360)) * cos(ofDegToRad(_inclination - 180));
            _y = _r * sin(ofDegToRad(_deg + _om - 360)) * cos(ofDegToRad(_inclination - 180));
            if (_deg == 0) {
                _height = _r * sin(ofDegToRad(_inclination - 180));
            }
            _z = _r * sin(ofDegToRad(_inclination - 180)) - _height * 2;
        } else {
            _x = _r * cos(ofDegToRad(_deg + _om)) * cos(ofDegToRad(_inclination));
            _y = _r * sin(ofDegToRad(_deg + _om)) * cos(ofDegToRad(_inclination));
            if (_deg == 0) {
                _height = _r * sin(ofDegToRad(_inclination));
            }
            _z = _r * sin(ofDegToRad(_inclination)) - _height * 2;
        }

        float _size = orbitBaseSize;
        _v.push_back(glm::vec3(_x, _y, _z) * _size);
    }
    
    return _v;
    
}




//--------------------------------------------------------------
ofMesh ofApp::circleMesh(vector<glm::vec3> _v) {

    ofMesh _mesh;
    _mesh.setMode(OF_PRIMITIVE_LINE_STRIP);
    _mesh.addVertices(_v);

    return _mesh;

}



//--------------------------------------------------------------
ofPolyline ofApp::circlePath(vector<glm::vec3> _v) {

    ofPolyline _orbitPath;
    _orbitPath.addVertices(_v);
    _orbitPath.setClosed(true);
    
    return _orbitPath;

}



//--------------------------------------------------------------
float ofApp::movingPathFactorUpdate() {

    static float _f = 0;
    _f += 0.225;

    return _f;

}

//--------------------------------------------------------------
float ofApp::movingPathFactorV() {

    return movingPathFactorUpdate();

}


//--------------------------------------------------------------
float ofApp::movingPathFactorF() {
    static int _n = 0;
    _n ++;
    static float _f = 0;
    _f += 0.05;

    return  _f;

}



//--------------------------------------------------------------
void ofApp::update() {

    movingUpdate();

    for (int i = 0; i < asteroidPoint.getNumVertices(); i++) {
        billboards.setVertex(i, asteroidPoint.getVertex(i));
    }

    
}



//--------------------------------------------------------------
void ofApp::movingUpdate() {
    
    for (int i = 0; i < orbits.size(); i++) {
        float _fullLength = orbits[i].path.getLengthAtIndex(orbits[i].path.size() - 1);
        
        if (orbits[i].inclination < 90) {
            orbits[i].movingF += 2.1 / orbits[i].per_y;
            if (orbits[i].movingF > _fullLength) {
                orbits[i].movingF = 0.0;
            }
        } else {
            orbits[i].movingF -= 2.1 / orbits[i].per_y;
            if (orbits[i].movingF < 0) {
                orbits[i].movingF = _fullLength;
            }
        }

        ofVec3f _path = orbits[i].path.getPointAtLength(orbits[i].movingF);
        asteroidPoint.setVertex(i, _path);
    }

}



//--------------------------------------------------------------
void ofApp::audioTriggerUpdate() {
 
//    movingPathFactor = movingPathFactor + 0.225;
//
//    ofPixels _p;
//    astroidFBO.readToPixels(_p);
//
//    astroidFBOBuff(movingPathFactorF());
//
//
//    vector< vector<float> > _nYPos;
//    _nYPos.resize(orbits.size());
//
//    float _movingF = movingPathFactorF();
//
//    for (int i = 0; i < orbits.size(); i++) {
//        vector<float> _f;
//        float _chMovingPath = ((_movingF * orbits[i].per_y));
//        ofVec3f _path = orbits[i].path.getPointAtIndexInterpolated(_chMovingPath);
//        if ((int)(_chMovingPath + orbits[i].omega) % 360 == 270) {
//            _f.push_back( BIT + _path.y );
//        }
//        _nYPos[i] = _f;
//    }
//
//
//    if ( bPlaying ) {
//        for (int i = 0; i < BIT; i++) {
//            amp[i] *= 0.91;
//        }
//
//        for (int n = 0; n < _nYPos.size(); n++) {
//            if (_nYPos[n].size() > 0) {
//                int _index = _nYPos[n][0];
//                float _valueY = ofMap(_index, 0, BIT, 0, 1);
//                amp[_index] = (amp[_index] * line + _valueY) / (line + 1);
//                hertzScale[_index] = (int)getFreq(_index);
//            }
//        }
//    }
    
}



//--------------------------------------------------------------
void ofApp::drawTriggerLine() {

}



//--------------------------------------------------------------
void ofApp::draw() {

    ofBackgroundGradient(ofColor(0, 0, 40), ofColor(0, 0, 0));

    glEnable(GL_CULL_FACE); // Cull back facing polygons
    glCullFace(GL_FRONT); // might be GL_FRONT instead

    cam.begin();

//    drawSun();

    

    ofPushStyle();
    ofSetColor(0, 255, 180, 220);
    earthOrbit.path.draw();
    ofPopStyle();

    ofPushStyle();
    ofSetColor(255, 120, 120, 220);
    marsOrbit.path.draw();
    ofPopStyle();

    ofPushStyle();
    ofSetColor(255, 240, 120, 220);
    jupiterOrbit.path.draw();
    ofPopStyle();

    ofPushStyle();
    ofSetColor(255, 240, 120, 220);
    saturnOrbit.path.draw();
    ofPopStyle();

    ofPushStyle();
    ofSetColor(255, 240, 220, 220);
    uranusOrbit.path.draw();
    ofPopStyle();
    
    ofPushStyle();
    ofSetColor(140, 210, 250, 220);
    neptuneOrbit.path.draw();
    ofPopStyle();



//    for (int i = 0; i < orbits.size(); i++) {
//
//        ofPushMatrix();
//        ofTranslate(0, 0, 0);
////        ofRotateYDeg(orbits[i].inclination);
//
//        ofPushStyle();
//        ofSetColor(255, 35);
//
//        orbits[i].mVbo.draw();
////        orbits[i].path.draw();
//        ofPopStyle();
//        ofPopMatrix();
//
//    }

//    asteroidPoint.draw();
    
    
    
    glDepthMask(GL_FALSE);

    billboardShader.begin();
    billboardShader.setUniform1f("u_time", ofGetElapsedTimef());

    ofEnablePointSprites(); // not needed for GL3/4
    texture.getTexture().bind();
    billboards.draw();
    texture.getTexture().unbind();
    ofDisablePointSprites(); // not needed for GL3/4

    billboardShader.end();

    glDepthMask(GL_TRUE);

    
    
    
    shader.begin();
    shader.setUniform1f("u_time", ofGetElapsedTimef());

    ofSetLineWidth(1);
    ofPushMatrix();
        for (int i = 0; i < orbits.size(); i++) {

            ofPushMatrix();
            ofTranslate(0, 0, 0);
    //        ofRotateYDeg(orbits[i].inclination);

            ofPushStyle();
            ofSetColor(255, 35);

            orbits[i].mVbo.draw();
//            orbits[i].path.draw();
            ofPopStyle();
            ofPopMatrix();

        }
    ofPopMatrix();

    shader.end();

    
    
    
    ofPushMatrix();
    ofPushStyle();
    ofRotateXDeg(180);
    ofRotateYDeg(90);
    ofNoFill();
    ofSetColor(255, 120);
    ofDrawRectangle(-1.5, 0, 3, BIT);
    ofFill();
    ofSetColor(255, 20);
    ofDrawRectangle(-1.5, 0, 3, BIT);
    ofPopStyle();
    ofPopMatrix();

    ofPushMatrix();
    ofPushStyle();
    ofSetColor(255, 40);
    ofDrawLine(-500, 0, 500, 0);
    ofDrawLine(0, 500, 0, -500);
    ofPopStyle();
    ofPopMatrix();


    cam.end();

}




//--------------------------------------------------------------
void ofApp::astroidFBOBuff(float _f) {

    astroidFBO.begin();
    ofPushMatrix();
    ofTranslate(0, BIT + 0);
    ofClear(0, 255);
    if (orbits.size() > 0) {

        ofMesh _p;
        _p.setMode(OF_PRIMITIVE_POINTS);

        for (int i = 0; i < orbits.size(); i++) {
            _p.addVertex( ofVec3f(0, 0, 0) );
            ofPushMatrix();
            ofPushStyle();
            ofSetColor(255);
            ofRotateYDeg( orbits[i].inclination );
            //            ofRotateZ( orbits[i].omega );

            float _chMovingPath = (int)((_f * orbits[i].per_y)) % 360;
            ofVec3f _path = orbits[i].path.getPointAtIndexInterpolated(_chMovingPath);
            _p.setVertex(0, _path);

            glPointSize(2);
            _p.draw();

            ofPopStyle();
            ofPopMatrix();

        }
    }
    ofPopMatrix();
    astroidFBO.end();

}




//--------------------------------------------------------------
void ofApp::textInformation() {

}




//--------------------------------------------------------------
void ofApp::drawSun() {

    ofPushMatrix();

    ofPushStyle();

    ofSetColor(255, 140);

    billboardBegin();
    ofScale(0.1, 0.1);
    billboardEnd();

//    sun.draw();

    ofPopStyle();

    ofPopMatrix();



}



//--------------------------------------------------------------
float ofApp::getAmpLeft(float x, float y, ofPixels _p) {

    float _amp = 0;

    ofColor _color = _p.getColor(x, y);
    _amp = 1.0 - _color.getLightness() / 255.0;

    //    if (_amp>threshold) {
    //        _amp = 0;
    //    }

    return _amp;


}



//--------------------------------------------------------------
float ofApp::getPixel(int x, int y) {

    float _sum;

    ofPixels _p;
    astroidFBO.readToPixels(_p);

    ofColor _color = _p.getColor(x, y);
    _sum = 1.0 - _color.getLightness() / 255.0;

    return _sum;

}



//--------------------------------------------------------------
float ofApp::getAmp(float x, float y) {

    float _amp = 0;

    ofPixels _p;
    astroidFBO.readToPixels(_p);

    ofColor _color = _p.getColor(x, y);
    _amp = _color.getLightness() / 255.0;

    return _amp;

}



//--------------------------------------------------------------
float ofApp::getFreq(float y) {

    float freq = 0;

    float _maxHz = maxHertz;
    float _minHz = minHertz;
    float yToFreq = ofMap(y, 0, BIT - 1, _minHz, _maxHz);

    //TODO logarithmic scale
    freq = 1 - ( log(yToFreq) - log(_minHz) ) / ( log(_maxHz) - log(_minHz) );
    freq *= (_maxHz - _minHz);
    freq += _minHz;
    //    freq = 1-(yToFreq-_minHz) / (_maxHz-_minHz);
    //    freq = (BIT-y+_minHz)/BIT*(_maxHz-_minHz);

    return freq;

}




//--------------------------------------------------------------
float ofApp::getPixelLeft(int x, int y) {

    return 0;

}



//--------------------------------------------------------------
float ofApp::getPixelRight(int x, int y) {

    float _sum;

    ofPixels _p;
    astroidFBO.readToPixels(_p);

    ofColor _color = _p.getColor(x, y);
    _sum = 1.0 - _color.getLightness() / 255.0;

    return _sum;

}



//--------------------------------------------------------------
float ofApp::getAmpLeft(float x, float y) {

    float _amp;

    ofPixels _p;
    astroidFBO.readToPixels(_p);

    ofColor _color = _p.getColor(x, y);
    _amp = 1.0 - _color.getLightness() / 255.0;

    return _amp;

}


//--------------------------------------------------------------
float ofApp::getAmpRight(float x, float y) {

    float _amp = 0;

    _amp = getPixelRight(x, y);

    return _amp;

}



//--------------------------------------------------------------
float ofApp::getFreqLeft(float y) {

    float freq = 0;

    float _maxHz = maxHertz;
    float _minHz = minHertz;
    float yToFreq = ofMap(y, 0, BIT - 1, _minHz, _maxHz);

    //TODO logarithmic scale
    freq = 1 - (log(yToFreq) - log(_minHz)) / (log(_maxHz) - log(_minHz));
    freq *= (_maxHz - _minHz);
    freq += _minHz;
    //    freq = 1-(yToFreq-_minHz) / (_maxHz-_minHz);
    //    freq = (BIT-y+_minHz)/BIT*(_maxHz-_minHz);


    return freq;

}



//--------------------------------------------------------------
float ofApp::getFreqRight(float y) {

    float freq = 0;

    float _maxHz = maxHertz;
    float _minHz = minHertz;
    float yToFreq = ofMap(y, 0, BIT - 1, _minHz, _maxHz);

    //TODO logarithmic scale
    freq = 1 - (log(yToFreq) - log(_minHz)) / (log(_maxHz) - log(_minHz));
    freq *= (_maxHz - _minHz);
    freq += _minHz;
    //freq = 1-(yToFreq-minHz) / (maxHz-minHz);
    //freq= (spectrumHeight-y+minHz)/spectrumHeight*(maxHz-minHz);
    //


    return freq;

}



//--------------------------------------------------------------
void ofApp::audioOut (ofSoundBuffer & buffer) {

    if (bPlaying) {

        for (int i = 0; i < buffer.getNumFrames(); i++) {

            float _wave = 0.0;

            for (int n = 0; n < BIT; n++) {
                phases[n] += 512.0 / ( 44100.0 / (hertzScale[n]) );
                //    remainder = phases[n] - floor(phases[n]);
                //    wave+=(float) ((1-remainder) * sinConst->sines[1+ (long) phases[n]] + remainder * sinConst->sines[2+(long) phases[n]])*amp[n];

                _wave += sineBuffer[(int)phases[n] % 512] * CLAMP(amp[n], -0.9, 0.9);
            }

            _wave *= 0.9;
            float _volume = 0.85;
            buffer[i * buffer.getNumChannels()] = _wave * _volume;
            buffer[i * buffer.getNumChannels() + 1] = _wave * _volume;

        }

    } else {
        for (int i = 0; i < buffer.getNumFrames(); i++) {
            buffer[i * buffer.getNumChannels()    ] = 0;
            buffer[i * buffer.getNumChannels() + 1] = 0;
        }
    }

}




//--------------------------------------------------------------
void ofApp::keyPressed(int key) {

}



//--------------------------------------------------------------
void ofApp::keyReleased(int key) {

    if (key == 'f') {
        fullscreen = !fullscreen;
        ofSetFullscreen(fullscreen);
    }

    if (key == ' ') {
        bPlaying = !bPlaying;
    }

    if (bPlaying)  {
        soundStream.start();
    } else {
        soundStream.stop();
    }


}



//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {

}



//--------------------------------------------------------------
void ofApp::billboardBegin() {

    float modelview[16];
    int i, j;

    // save the current modelview matrix
    glPushMatrix();

    // get the current modelview matrix
    glGetFloatv(GL_MODELVIEW_MATRIX , modelview);

    // undo all rotations
    // beware all scaling is lost as well
    for ( i = 0; i < 3; i++ )
        for ( j = 0; j < 3; j++ ) {
            if ( i == j )
                modelview[i * 4 + j] = 1.0;
            else
                modelview[i * 4 + j] = 0.0;
        }

    // set the modelview with no rotations
    glLoadMatrixf(modelview);
}



//--------------------------------------------------------------
void ofApp::billboardEnd() {

    // restore the previously
    // stored modelview matrix
    glPopMatrix();
}



