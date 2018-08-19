// https://en.wikipedia.org/wiki/Ellipse#Polar_form_relative_to_focus
// http://en.wikipedia.org/wiki/Apsis
// http://en.wikipedia.org/wiki/Orbital_inclination
// http://en.wikipedia.org/wiki/Semi-major_axis
// http://mathworld.wolfram.com/SemilatusRectum.html
// http://www.asterank.com/api


float sines[512] = {0, 0.012268, 0.024536, 0.036804, 0.049042, 0.06131, 0.073547, 0.085785, 0.097992, 0.1102, 0.12241, 0.13455, 0.1467, 0.15884, 0.17093, 0.18301, 0.19507, 0.20709, 0.21909, 0.23105, 0.24295, 0.25485, 0.26669, 0.2785, 0.29025, 0.30197, 0.31366, 0.32529, 0.33685, 0.34839, 0.35986, 0.37128, 0.38266, 0.39395, 0.40521, 0.41641, 0.42752, 0.4386, 0.44958, 0.46051, 0.47137, 0.48215, 0.49286, 0.50351, 0.51407, 0.52457, 0.53497, 0.54529, 0.55554, 0.5657, 0.57578, 0.58575, 0.59567, 0.60547, 0.6152, 0.62482, 0.63437, 0.6438, 0.65314, 0.66238, 0.67151, 0.68057, 0.68951, 0.69833, 0.70706, 0.7157, 0.72421, 0.7326, 0.74091, 0.74908, 0.75717, 0.76514, 0.77298, 0.7807, 0.7883, 0.79581, 0.80316, 0.81042, 0.81754, 0.82455, 0.83142, 0.8382, 0.84482, 0.85132, 0.8577, 0.86392, 0.87006, 0.87604, 0.88187, 0.8876, 0.89319, 0.89862, 0.90396, 0.90912, 0.91415, 0.91907, 0.92383, 0.92847, 0.93295, 0.93729, 0.9415, 0.94556, 0.94949, 0.95325, 0.95691, 0.96039, 0.96375, 0.96692, 0.97, 0.9729, 0.97565, 0.97827, 0.98074, 0.98306, 0.98523, 0.98724, 0.98914, 0.99084, 0.99243, 0.99387, 0.99515, 0.99628, 0.99725, 0.99808, 0.99875, 0.99927, 0.99966, 0.99988, 0.99997, 0.99988, 0.99966, 0.99927, 0.99875, 0.99808, 0.99725, 0.99628, 0.99515, 0.99387, 0.99243, 0.99084, 0.98914, 0.98724, 0.98523, 0.98306, 0.98074, 0.97827, 0.97565, 0.9729, 0.97, 0.96692, 0.96375, 0.96039, 0.95691, 0.95325, 0.94949, 0.94556, 0.9415, 0.93729, 0.93295, 0.92847, 0.92383, 0.91907, 0.91415, 0.90912, 0.90396, 0.89862, 0.89319, 0.8876, 0.88187, 0.87604, 0.87006, 0.86392, 0.8577, 0.85132, 0.84482, 0.8382, 0.83142, 0.82455, 0.81754, 0.81042, 0.80316, 0.79581, 0.7883, 0.7807, 0.77298, 0.76514, 0.75717, 0.74908, 0.74091, 0.7326, 0.72421, 0.7157, 0.70706, 0.69833, 0.68951, 0.68057, 0.67151, 0.66238, 0.65314, 0.6438, 0.63437, 0.62482, 0.6152, 0.60547, 0.59567, 0.58575, 0.57578, 0.5657, 0.55554, 0.54529, 0.53497, 0.52457, 0.51407, 0.50351, 0.49286, 0.48215, 0.47137, 0.46051, 0.44958, 0.4386, 0.42752, 0.41641, 0.40521, 0.39395, 0.38266, 0.37128, 0.35986, 0.34839, 0.33685, 0.32529, 0.31366, 0.30197, 0.29025, 0.2785, 0.26669, 0.25485, 0.24295, 0.23105, 0.21909, 0.20709, 0.19507, 0.18301, 0.17093, 0.15884, 0.1467, 0.13455, 0.12241, 0.1102, 0.097992, 0.085785, 0.073547, 0.06131, 0.049042, 0.036804, 0.024536, 0.012268, 0, -0.012268, -0.024536, -0.036804, -0.049042, -0.06131, -0.073547, -0.085785, -0.097992, -0.1102, -0.12241, -0.13455, -0.1467, -0.15884, -0.17093, -0.18301, -0.19507, -0.20709, -0.21909, -0.23105, -0.24295, -0.25485, -0.26669, -0.2785, -0.29025, -0.30197, -0.31366, -0.32529, -0.33685, -0.34839, -0.35986, -0.37128, -0.38266, -0.39395, -0.40521, -0.41641, -0.42752, -0.4386, -0.44958, -0.46051, -0.47137, -0.48215, -0.49286, -0.50351, -0.51407, -0.52457, -0.53497, -0.54529, -0.55554, -0.5657, -0.57578, -0.58575, -0.59567, -0.60547, -0.6152, -0.62482, -0.63437, -0.6438, -0.65314, -0.66238, -0.67151, -0.68057, -0.68951, -0.69833, -0.70706, -0.7157, -0.72421, -0.7326, -0.74091, -0.74908, -0.75717, -0.76514, -0.77298, -0.7807, -0.7883, -0.79581, -0.80316, -0.81042, -0.81754, -0.82455, -0.83142, -0.8382, -0.84482, -0.85132, -0.8577, -0.86392, -0.87006, -0.87604, -0.88187, -0.8876, -0.89319, -0.89862, -0.90396, -0.90912, -0.91415, -0.91907, -0.92383, -0.92847, -0.93295, -0.93729, -0.9415, -0.94556, -0.94949, -0.95325, -0.95691, -0.96039, -0.96375, -0.96692, -0.97, -0.9729, -0.97565, -0.97827, -0.98074, -0.98306, -0.98523, -0.98724, -0.98914, -0.99084, -0.99243, -0.99387, -0.99515, -0.99628, -0.99725, -0.99808, -0.99875, -0.99927, -0.99966, -0.99988, -0.99997, -0.99988, -0.99966, -0.99927, -0.99875, -0.99808, -0.99725, -0.99628, -0.99515, -0.99387, -0.99243, -0.99084, -0.98914, -0.98724, -0.98523, -0.98306, -0.98074, -0.97827, -0.97565, -0.9729, -0.97, -0.96692, -0.96375, -0.96039, -0.95691, -0.95325, -0.94949, -0.94556, -0.9415, -0.93729, -0.93295, -0.92847, -0.92383, -0.91907, -0.91415, -0.90912, -0.90396, -0.89862, -0.89319, -0.8876, -0.88187, -0.87604, -0.87006, -0.86392, -0.8577, -0.85132, -0.84482, -0.8382, -0.83142, -0.82455, -0.81754, -0.81042, -0.80316, -0.79581, -0.7883, -0.7807, -0.77298, -0.76514, -0.75717, -0.74908, -0.74091, -0.7326, -0.72421, -0.7157, -0.70706, -0.69833, -0.68951, -0.68057, -0.67151, -0.66238, -0.65314, -0.6438, -0.63437, -0.62482, -0.6152, -0.60547, -0.59567, -0.58575, -0.57578, -0.5657, -0.55554, -0.54529, -0.53497, -0.52457, -0.51407, -0.50351, -0.49286, -0.48215, -0.47137, -0.46051, -0.44958, -0.4386, -0.42752, -0.41641, -0.40521, -0.39395, -0.38266, -0.37128, -0.35986, -0.34839, -0.33685, -0.32529, -0.31366, -0.30197, -0.29025, -0.2785, -0.26669, -0.25485, -0.24295, -0.23105, -0.21909, -0.20709, -0.19507, -0.18301, -0.17093, -0.15884, -0.1467, -0.13455, -0.12241, -0.1102, -0.097992, -0.085785, -0.073547, -0.06131, -0.049042, -0.036804, -0.024536, -0.012268};




#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

// #ifdef DEBUG

// #else
//     // ofSetDataPathRoot("../Resources/data/");
// #endif
//     // ofSetDataPathRoot("../Resources/data/");

    ofBackground(0);
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
    auto devices = soundStream.getMatchingDevices("default");
    if (!devices.empty()) {
        settings.setOutDevice(devices[1]);
    }
    settings.setOutListener(this);
    settings.bufferSize = INITIAL_BUFFER_SIZE;
    settings.sampleRate = SAMPLE_RATE;
    settings.numInputChannels = 0;
    settings.numOutputChannels = 2;
    soundStream.setup(settings);

    bPlaying = false;
    line = 0.1;


    maxHertz = 8000;
    minHertz = 150;

    astroidFBO.allocate(30, BIT, GL_RGB);

    // http://www.asterank.com/api
    string url = "http://asterank.com/api/asterank?query={\"e\":{\"$lt\":0.9},\"i\":{\"$lt\":2},\"a\":{\"$lt\":1.5}}&limit=1";

    // Now parse the JSON
    //    bool parsingInternetSuccessful = json(url);
    //    parsingInternetSuccessful = false;
    //    if (!parsingInternetSuccessful) {
    //        json.open("asteroid_500.json");
    //    } else {
    //        json.open(url);
    //    }


    threshold = 0.9;

    cam.setAutoDistance(false);
    cam.setDistance(400);

    //    if (parsingSuccessful) {
    //        ofLogNotice("ofApp::setup") << json.getRawString(true);
    //    } else {
    //        ofLogNotice("ofApp::setup") << "Failed to parse JSON.";
    //    }

    sun.set(2, 10);

    mesh.setMode(OF_PRIMITIVE_POINTS);

    earthOrbit = setupEarthOrbit();

    orbits = setupOrbits("asteroid_500.json");

    rotateZ = 0;

    _nYPos.resize(orbits.size());
    _lineDraw.resize(orbits.size());

    longLine.resize(orbits.size());
    longLinePoint.resize(orbits.size());

    for (int i = 0; i < orbits.size(); i++) {
        longLinePoint[i].resize(360);
    }

}



//--------------------------------------------------------------
vector<Orbit> ofApp::setupOrbits(string _s) {

    vector<Orbit> _oV;

    ofFile _file(_s);

    int _counter = 0;
    if (_file.exists()) {
        _file >> json;
        _oV.resize( json.size() );
        Orbit _orbitE;

        for (auto & stroke : json) {

            // double _a = stroke["a"];
            // double _ad = stroke["ad"];
            // double _e = stroke["e"];
            // double _q = stroke["q"];
            double _i = stroke["i"];
            double _om = stroke["om"];

            per_y.push_back( stroke["per_y"] );

            mesh.addVertex( ofVec3f( 0, 0, 0) );

            _orbitE.path = circlePath(stroke);
            _orbitE.inclination = _i;
            _orbitE.omega = _om;
            _orbitE.mVbo = circleMesh(stroke);
            _orbitE.per_y = stroke["per_y"];

            //            int _counter = &stroke - &json[0];
            _oV[_counter] = _orbitE;
            _counter++;
        }

    } else {
        Orbit _orbitE;

        for (auto & stroke : json) {

            // double _a = stroke["a"];
            // double _ad = stroke["ad"];
            // double _e = stroke["e"];
            // double _q = stroke["q"];
            double _i = stroke["i"];
            double _om = stroke["om"];

            per_y.push_back( stroke["per_y"] );

            mesh.addVertex( ofVec3f( 0, 0, 0) );

            _orbitE.path = circlePath(stroke);
            _orbitE.inclination = _i;
            _orbitE.omega = _om;
            _orbitE.mVbo = circleMesh(stroke);
            _orbitE.per_y = stroke["per_y"];

            //            int _counter = &stroke - &json[0];
            _oV[_counter] = _orbitE;
            _counter++;

        }
    }

    return _oV;

}



//--------------------------------------------------------------
Orbit ofApp::setupEarthOrbit() {

    Orbit _o;

    float _eEarth = 0.01671123;
    for (int i = 0; i <= 360; i++) {
        double _r = 1.0167 * (1 - (_eEarth * _eEarth)) / (1 + _eEarth * cos(ofDegToRad(i)));

        float _size = 100;
        float _x1 = _r * cos(ofDegToRad(i)) * _size;
        float _y1 = _r * sin(ofDegToRad(i)) * _size;

        _o.path.addVertex( _x1, _y1 );
    }

    return _o;

}


//--------------------------------------------------------------
ofMesh ofApp::circleMesh(ofJson _j) {

    // double _a = _j["a"];
    double _ad = _j["ad"];
    double _e = _j["e"];
    // double _q = _j["q"];
    // double _i = _j["i"];
    double _om = _j["om"];

    ofMesh _mesh;

    for (int _deg = 0; _deg < 360; _deg++) {
        double _r = _ad * (1 - (_e * _e)) / (1 + _e * cos(ofDegToRad(_deg)));
        float _size = 100;
        float _x1 = _r * cos(ofDegToRad(_deg + _om)) * _size;
        float _y1 = _r * sin(ofDegToRad(_deg + _om)) * _size;
        _mesh.setMode(OF_PRIMITIVE_LINE_LOOP);
        _mesh.addVertex( ofVec3f( _x1, _y1, 0) );
    }

    for (int meshIndexA = 0; meshIndexA < 360 - 1; meshIndexA++) {
        _mesh.addIndex(meshIndexA);
        _mesh.addIndex(meshIndexA + 1);
    }

    return _mesh;

}



//--------------------------------------------------------------
ofPolyline ofApp::circlePath(ofJson _j) {

    // double _a = _j["a"];
    double _ad = _j["ad"];
    double _e = _j["e"];
    // double _q = _j["q"];
    // double _i = _j["i"];
    double _om = _j["om"];

    ofPolyline _orbitPath;

    for (int _deg = 0; _deg < 360; _deg++) {
        double _r = _ad * (1 - (_e * _e)) / (1 + _e * cos(ofDegToRad(_deg)));
        float _size = 100;
        float _x1 = _r * cos(ofDegToRad(_deg + _om)) * _size;
        float _y1 = _r * sin(ofDegToRad(_deg + _om)) * _size;
        _orbitPath.addVertex( _x1, _y1 );
    }

    _orbitPath.setClosed(true);

    return _orbitPath;

}




//--------------------------------------------------------------
void ofApp::update() {

    timePlanet = timePlanet + 1;
    rotateZ = rotateZ + 0.25;
    movingPathFactor = movingPathFactor + 0.225;


    astroidFBOBuff();
    //    ofPixels _p;
    //    astroidFBO.readToPixels(_p);


    for (int i = 0; i < orbits.size(); i++) {
        vector<float> _f;
        float _chMovingPath = ((movingPathFactor * per_y[i]));
        ofVec3f _path = orbits[i].path.getPointAtIndexInterpolated(_chMovingPath);
        if ((int)(_chMovingPath + orbits[i].omega) % 360 == 270) {
            _f.push_back( BIT + _path.y );
        }
        _nYPos[i] = _f;
    }


    if ( bPlaying ) {
        for (int i = 0; i < orbits.size(); i++) {
        }

        for (int n = 0; n < BIT; n++) {
            //                        int _yRatioLeft = (int)ofMap(n, 0, BIT-1, 0, BIT*2);
            //                        amp[n] = (amp[n] * line + getAmp(0, _yRatioLeft)) / (line + 1);
            //                        hertzScale[n] = (int)getFreq(n);

            //                    int _yRatioRight = (int)ofMap(n, 0, BIT-1, 0, ofGetHeight());
            //                    ampRight[n] = (ampRight[n]*line + getAmpRight(moviePlay.getWidth()*0.75, _yRatioRight))/(line+1);
            //                    hertzScaleRight[n] = int(getFreqRight(n));
        }




        for (int i = 0; i < BIT; i++) {
            amp[i] *= 0.91;
        }

        for (int n = 0; n < _nYPos.size(); n++) {
            // int _yRatioLeft = (int)ofMap(n, 0, BIT - 1, 0, ofGetHeight());
            if (_nYPos[n].size() > 0) {
                int _index = _nYPos[n].at(0);
                float _valueY = ofMap(_index, 0, BIT, 0, 1);
                amp[_index] = (amp[_index] * line + _valueY) / (line + 1);
                hertzScale[_index] = (int)getFreq(_index);
            }
        }
    }

//    _nYPos.clear();

}





//--------------------------------------------------------------
void ofApp::draw() {

    ofBackgroundGradient(ofColor(0, 0, 40), ofColor(0, 0, 0));


    cam.begin();
    ofRotateXDeg(180);


    ofPushMatrix();

    drawSun();

    ofPushStyle();
    ofSetColor(255, 120);
    earthOrbit.path.draw();
    ofPopStyle();

    if (orbits.size() > 0) {
        ofSetColor(255, 15);

        for (int i = 0; i < orbits.size(); i++) {
            ofPushMatrix();

            ofRotateYDeg( orbits[i].inclination );
            //          ofRotateZ( orbits[i].omega );
            //                      orbits[i].path.draw();
            orbits[i].mVbo.draw();

            ofPopMatrix();

            ofPushMatrix();
            ofPushStyle();

            ofRotateYDeg( orbits[i].inclination );
            //          ofRotateZ( orbits[i].omega );
            float _chMovingPath = ((movingPathFactor * orbits[i].per_y));
            ofVec3f _path = orbits[i].path.getPointAtIndexInterpolated(_chMovingPath);

            mesh.setVertex(0, _path);
            glPointSize(1);


            //            ofSetColor(255, 0, 0, 50);
            ////            longLinePoint[i].push_back(_path);
            //            if( (int)(_chMovingPath + orbits[i].omega) % 360 == 0) {
            ////                longLinePoint[i].erase(longLinePoint[i].begin());
            //            }
            //            longLine[i].addVertex(_path);
            //            longLine[i].draw();


            if ((int)(_chMovingPath + orbits[i].omega) % 360 >= 270 && (int)(_chMovingPath + orbits[i].omega) % 360 < 275) {
                //                float _x = _path.x;
                //                float _y = _path.y;
                //                ofDrawLine(_x, _y, -15, _x, _y, 15);
                ofSetColor(255, 255, 255, 80);
                glPointSize(2);
                _lineDraw[i].addVertex(_path.x, _path.y, _path.z);
                _lineDraw[i].draw();
            } else {
                ofSetColor(255, 255, 255, 255);
                glPointSize(1);

                _lineDraw[i].clear();
            }


            mesh.draw();

            ofPopStyle();
            ofPopMatrix();

        }

    }

    ofPopMatrix();



    ofPushMatrix();
    ofPushStyle();
    ofRotateXDeg(180);
    ofRotateYDeg(90);
    ofNoFill();
    ofSetColor(255, 120);
    ofDrawRectangle(-15, 0, 30, BIT);
    ofFill();
    ofSetColor(255, 20);
    ofDrawRectangle(-15, 0, 30, BIT);
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


    // ofPushMatrix();
    // ofPushStyle();
    // ofSetColor(255);
    // astroidFBO.draw(ofGetMouseX(), ofGetMouseY() - 512);
    // ofPopStyle();
    // ofPopMatrix();


    ofSetColor(255);
    stringstream ss;
    ss << "FPS: " << ofToString(ofGetFrameRate(), 1) << endl;
    //        ss << "Space bar for Sound Play" << endl;
    //        ss << "Mouse or Track Pad for 3D Viewing" << endl;
    //        ss << "\"f\" - key for full screen" << endl;
    ofDrawBitmapString(ss.str().c_str(), 20, ofGetHeight() - 80);


    //    gui.draw();

}


//--------------------------------------------------------------
void ofApp::astroidFBOBuff() {

    astroidFBO.begin();
    ofPushMatrix();
    ofTranslate(0, BIT + 0);
    ofClear(0, 255);
    if (orbits.size() > 0) {
        for (int i = 0; i < orbits.size(); i++) {
            ofPushMatrix();
            ofPushStyle();
            ofSetColor(255);
            ofRotateYDeg( orbits[i].inclination );
            //            ofRotateZ( orbits[i].omega );

            float _chMovingPath = (int)((movingPathFactor * per_y[i])) % 360;
            ofVec3f _path = orbits[i].path.getPointAtIndexInterpolated(_chMovingPath);
            mesh.setVertex(0, _path);

            glPointSize(2);
            mesh.draw();

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

    sun.draw();

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
