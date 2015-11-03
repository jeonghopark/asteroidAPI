// http://en.wikipedia.org/wiki/Apsis
// http://en.wikipedia.org/wiki/Orbital_inclination
// http://en.wikipedia.org/wiki/Semi-major_axis

// http://mathworld.wolfram.com/SemilatusRectum.html


float sines[514]={0,0.012268,0.024536,0.036804,0.049042,0.06131,0.073547,0.085785,0.097992,0.1102,0.12241,0.13455,0.1467,0.15884,0.17093,0.18301,0.19507,0.20709,0.21909,0.23105,0.24295,0.25485,0.26669,0.2785,0.29025,0.30197,0.31366,0.32529,0.33685,0.34839,0.35986,0.37128,0.38266,0.39395,0.40521,0.41641,0.42752,0.4386,0.44958,0.46051,0.47137,0.48215,0.49286,0.50351,0.51407,0.52457,0.53497,0.54529,0.55554,0.5657,0.57578,0.58575,0.59567,0.60547,0.6152,0.62482,0.63437,0.6438,0.65314,0.66238,0.67151,0.68057,0.68951,0.69833,0.70706,0.7157,0.72421,0.7326,0.74091,0.74908,0.75717,0.76514,0.77298,0.7807,0.7883,0.79581,0.80316,0.81042,0.81754,0.82455,0.83142,0.8382,0.84482,0.85132,0.8577,0.86392,0.87006,0.87604,0.88187,0.8876,0.89319,0.89862,0.90396,0.90912,0.91415,0.91907,0.92383,0.92847,0.93295,0.93729,0.9415,0.94556,0.94949,0.95325,0.95691,0.96039,0.96375,0.96692,0.97,0.9729,0.97565,0.97827,0.98074,0.98306,0.98523,0.98724,0.98914,0.99084,0.99243,0.99387,0.99515,0.99628,0.99725,0.99808,0.99875,0.99927,0.99966,0.99988,0.99997,0.99988,0.99966,0.99927,0.99875,0.99808,0.99725,0.99628,0.99515,0.99387,0.99243,0.99084,0.98914,0.98724,0.98523,0.98306,0.98074,0.97827,0.97565,0.9729,0.97,0.96692,0.96375,0.96039,0.95691,0.95325,0.94949,0.94556,0.9415,0.93729,0.93295,0.92847,0.92383,0.91907,0.91415,0.90912,0.90396,0.89862,0.89319,0.8876,0.88187,0.87604,0.87006,0.86392,0.8577,0.85132,0.84482,0.8382,0.83142,0.82455,0.81754,0.81042,0.80316,0.79581,0.7883,0.7807,0.77298,0.76514,0.75717,0.74908,0.74091,0.7326,0.72421,0.7157,0.70706,0.69833,0.68951,0.68057,0.67151,0.66238,0.65314,0.6438,0.63437,0.62482,0.6152,0.60547,0.59567,0.58575,0.57578,0.5657,0.55554,0.54529,0.53497,0.52457,0.51407,0.50351,0.49286,0.48215,0.47137,0.46051,0.44958,0.4386,0.42752,0.41641,0.40521,0.39395,0.38266,0.37128,0.35986,0.34839,0.33685,0.32529,0.31366,0.30197,0.29025,0.2785,0.26669,0.25485,0.24295,0.23105,0.21909,0.20709,0.19507,0.18301,0.17093,0.15884,0.1467,0.13455,0.12241,0.1102,0.097992,0.085785,0.073547,0.06131,0.049042,0.036804,0.024536,0.012268,0,-0.012268,-0.024536,-0.036804,-0.049042,-0.06131,-0.073547,-0.085785,-0.097992,-0.1102,-0.12241,-0.13455,-0.1467,-0.15884,-0.17093,-0.18301,-0.19507,-0.20709,-0.21909,-0.23105,-0.24295,-0.25485,-0.26669,-0.2785,-0.29025,-0.30197,-0.31366,-0.32529,-0.33685,-0.34839,-0.35986,-0.37128,-0.38266,-0.39395,-0.40521,-0.41641,-0.42752,-0.4386,-0.44958,-0.46051,-0.47137,-0.48215,-0.49286,-0.50351,-0.51407,-0.52457,-0.53497,-0.54529,-0.55554,-0.5657,-0.57578,-0.58575,-0.59567,-0.60547,-0.6152,-0.62482,-0.63437,-0.6438,-0.65314,-0.66238,-0.67151,-0.68057,-0.68951,-0.69833,-0.70706,-0.7157,-0.72421,-0.7326,-0.74091,-0.74908,-0.75717,-0.76514,-0.77298,-0.7807,-0.7883,-0.79581,-0.80316,-0.81042,-0.81754,-0.82455,-0.83142,-0.8382,-0.84482,-0.85132,-0.8577,-0.86392,-0.87006,-0.87604,-0.88187,-0.8876,-0.89319,-0.89862,-0.90396,-0.90912,-0.91415,-0.91907,-0.92383,-0.92847,-0.93295,-0.93729,-0.9415,-0.94556,-0.94949,-0.95325,-0.95691,-0.96039,-0.96375,-0.96692,-0.97,-0.9729,-0.97565,-0.97827,-0.98074,-0.98306,-0.98523,-0.98724,-0.98914,-0.99084,-0.99243,-0.99387,-0.99515,-0.99628,-0.99725,-0.99808,-0.99875,-0.99927,-0.99966,-0.99988,-0.99997,-0.99988,-0.99966,-0.99927,-0.99875,-0.99808,-0.99725,-0.99628,-0.99515,-0.99387,-0.99243,-0.99084,-0.98914,-0.98724,-0.98523,-0.98306,-0.98074,-0.97827,-0.97565,-0.9729,-0.97,-0.96692,-0.96375,-0.96039,-0.95691,-0.95325,-0.94949,-0.94556,-0.9415,-0.93729,-0.93295,-0.92847,-0.92383,-0.91907,-0.91415,-0.90912,-0.90396,-0.89862,-0.89319,-0.8876,-0.88187,-0.87604,-0.87006,-0.86392,-0.8577,-0.85132,-0.84482,-0.8382,-0.83142,-0.82455,-0.81754,-0.81042,-0.80316,-0.79581,-0.7883,-0.7807,-0.77298,-0.76514,-0.75717,-0.74908,-0.74091,-0.7326,-0.72421,-0.7157,-0.70706,-0.69833,-0.68951,-0.68057,-0.67151,-0.66238,-0.65314,-0.6438,-0.63437,-0.62482,-0.6152,-0.60547,-0.59567,-0.58575,-0.57578,-0.5657,-0.55554,-0.54529,-0.53497,-0.52457,-0.51407,-0.50351,-0.49286,-0.48215,-0.47137,-0.46051,-0.44958,-0.4386,-0.42752,-0.41641,-0.40521,-0.39395,-0.38266,-0.37128,-0.35986,-0.34839,-0.33685,-0.32529,-0.31366,-0.30197,-0.29025,-0.2785,-0.26669,-0.25485,-0.24295,-0.23105,-0.21909,-0.20709,-0.19507,-0.18301,-0.17093,-0.15884,-0.1467,-0.13455,-0.12241,-0.1102,-0.097992,-0.085785,-0.073547,-0.06131,-0.049042,-0.036804,-0.024536,-0.012268,0,0.012268};




#include "ofApp.h"

void ofApp::setup() {

//    ofSetDataPathRoot("../Resources/data/");

    ofBackground(0);
    ofEnableAntiAliasing();
    //    ofEnableDepthTest();


    for (int i=0; i<514 ; i++) {
        sineBufferLeft[i] = sines[i];
        sineBufferRight[i] = sines[i];
    }

    ofSoundStreamSetup( 2, 0, this, SAMPLE_RATE, INITIAL_BUFFER_SIZE, 4 );
    ofSoundStreamStop();
    bPlaying = false;
    line = 2;

    maxHertz = 18000;
    minHertz = 150;

    astroidFBO.allocate(30, BIT*2, GL_RGB);

    // http://www.asterank.com/api
    string url = "http://www.asterank.com/api/asterank?query={\"e\":{\"$lt\":0.9},\"i\":{\"$lt\":4},\"a\":{\"$lt\":4.5}}&limit=200";

    // Now parse the JSON
    bool parsingSuccessful = json.open("asteroid_300.json");

    threshold = 0.9;

//    if (parsingSuccessful) {
//        ofLogNotice("ofApp::setup") << json.getRawString(true);
//    } else {
//        ofLogNotice("ofApp::setup") << "Failed to parse JSON.";
//    }

    sun.set(2, 10);

    ofNoFill();

    orbits.resize( json.size() );

    ofMesh _mesh;
    mesh.setMode(OF_PRIMITIVE_POINTS);

    float _eEarth = 0.01671123;
    for (int i=0; i<360; i++) {
        double _r = 1.0167 * (1 - (_eEarth * _eEarth)) / (1 + _eEarth * cos(ofDegToRad(i)));

        float _size = 100;
        float _x1 = _r * cos(ofDegToRad(i)) * _size;
        float _y1 = _r * sin(ofDegToRad(i)) * _size;

        earthOrbit.path.addVertex( _x1, _y1 );
    }


    for(int i=0; i<json.size(); i++) {

        orbit _orbitE;

        double _a = json[i]["a"].asDouble();
        double _ad = json[i]["ad"].asDouble();
        double _e = json[i]["e"].asDouble();
        double _q = json[i]["q"].asDouble();
        double _i = json[i]["i"].asDouble();
        double _om = json[i]["om"].asDouble();

        per_y.push_back( json[i]["per_y"].asDouble() );

        mesh.addVertex( ofVec3f( 0, 0, 0) );

        ofPolyline _orbitPath;

        ofMesh _mesh;

        for (int degree=0; degree<360; degree++) {
            double _r = _ad * (1 - (_e * _e)) / (1 + _e * cos(ofDegToRad(degree)));

            float _size = 100;
            float _x1 = _r * cos(ofDegToRad(degree + _om)) * _size;
            float _y1 = _r * sin(ofDegToRad(degree + _om)) * _size;

            _orbitPath.addVertex( _x1, _y1 );
            _mesh.setMode(OF_PRIMITIVE_LINE_LOOP);
            _mesh.addVertex( ofVec3f( _x1, _y1, 0) );
        }


        _orbitPath.setClosed(true);

        for (int meshIndexA=0; meshIndexA<360-1; meshIndexA++) {
            _mesh.addIndex(meshIndexA);
            _mesh.addIndex(meshIndexA+1);
        }


        _orbitE.path = _orbitPath;
        _orbitE.inclination = _i;
        _orbitE.omega = _om;
        _orbitE.mesh = _mesh;
        orbits[i] = _orbitE;

    }

    rotateZ = 0;

}

void ofApp::update(){

    timePlanet = timePlanet + 1;

    rotateZ = rotateZ + 0.25;

    movingPathFactor = movingPathFactor + 0.125;


    //        astroidFBO.begin();
    //        ofPushMatrix();
    //        ofTranslate(0, ofGetHeight());
    //        ofClear(0,255);
    //        if (orbits.size()>0) {
    //            for(int i = 0; i<orbits.size(); i++) {
    //                ofPushMatrix();
    //                ofPushStyle();
    //                ofSetColor(255);
    //                ofRotateY( orbits[i].inclination );
    //                //            ofRotateZ( orbits[i].omega );
    //
    //                float _chMovingPath = (int)((movingPathFactor+ orbits[i].omega) * per_y[i] ) % 360;
    //                ofVec3f _path = orbits[i].path.getPointAtPercent(ofMap(_chMovingPath, 0, 360, 0, 1));
    //                mesh.setVertex(0, _path);
    //
    //                glPointSize(10);
    //                mesh.draw();
    //
    //                ofPopStyle();
    //                ofPopMatrix();
    //
    //            }
    //        }
    //        ofPopMatrix();
    //        astroidFBO.end();


    vector< vector<float> > _nYPos;

    if (orbits.size()>0) {
        vector<float> _f;
        _f.clear();
        for(int i = 0; i<orbits.size(); i++) {
            float _chMovingPath = ((movingPathFactor * per_y[i]));
            ofVec3f _path = orbits[i].path.getPointAtIndexInterpolated(_chMovingPath);
            if((int)(_chMovingPath + orbits[i].omega) % 360==270) {
                _f.push_back( BIT + _path.y );
            }

        }
        _nYPos.push_back( _f );

    }

    ofPixels _p;
    astroidFBO.readToPixels(_p);

    if ( bPlaying ) {
        for(int n=0; n<BIT; n++){
            //                    int _yRatioLeft = (int)ofMap(n, 0, BIT-1, 0, ofGetHeight());
            //                    ampLeft[n] = (ampLeft[n] * line + getAmpLeft(0, _yRatioLeft, _p)) / (line + 1);
            //                    hertzScaleLeft[n] = (int)getFreqLeft(n);
            //
            ////                    int _yRatioRight = (int)ofMap(n, 0, BIT-1, 0, ofGetHeight());
            ////                    ampRight[n] = (ampRight[n]*line + getAmpRight(moviePlay.getWidth()*0.75, _yRatioRight))/(line+1);
            ////                    hertzScaleRight[n] = int(getFreqRight(n));
        }

        for(int i=0; i<BIT; i++){
            ampLeft[i] = 0;
        }

        for(int n=0; n<_nYPos.size(); n++){
            int _yRatioLeft = (int)ofMap(n, 0, BIT-1, 0, ofGetHeight());
            if (_nYPos[n].size()>0) {
                int _index = _nYPos[n].at(0);
                float _valueY = ofMap(_index, 0, BIT, 0, 1);
                ampLeft[_index] = (ampLeft[_index] * line + _valueY) / (line + 1);
                hertzScaleLeft[_index] = (int)getFreqLeft(_index);
            }
        }

    }

    _nYPos.clear();


}



void ofApp::draw() {

    ofBackgroundGradient(ofColor(0,0,40), ofColor(0,0,10));


    ofSetColor(255);

    cam.begin();
    ofRotateX(180);
    //    ofRotateZ( rotateZ );

    ofPushMatrix();

    //    ofTranslate(ofGetWidth() * 0.5, ofGetHeight() * 0.5);
    sun.draw();

    ofSetColor(255, 250);
    //    earthOrbit.path.draw();

    if (orbits.size()>0) {
        ofSetColor(255, 15);
        for(int i = 0; i<orbits.size(); i++) {
            ofPushMatrix();

            ofRotateY( orbits[i].inclination );
            //                        ofRotateZ( orbits[i].omega );
            //            orbits[i].path.draw();
            orbits[i].mesh.draw();

            ofPopMatrix();

            ofPushMatrix();
            ofPushStyle();
            ofSetColor(255);
            ofRotateY( orbits[i].inclination );
            //                        ofRotateZ( orbits[i].omega );
            float _chMovingPath = ((movingPathFactor * per_y[i]));
            ofVec3f _path = orbits[i].path.getPointAtIndexInterpolated(_chMovingPath);

            mesh.setVertex(0, _path);
            glPointSize(1);
            mesh.draw();


            ofSetColor(255,120);
            if((int)(_chMovingPath + orbits[i].omega) % 360==270) {
                float _x = _path.x;
                float _y = _path.y;

                ofDrawLine(_x, _y, -15, _x, _y, 15);
            }


            ofPopStyle();
            ofPopMatrix();

        }

    }

    ofPopMatrix();

    ofPushMatrix();
    ofPushStyle();
    ofRotateX(180);
    ofRotateY(90);
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


    //    ofPushMatrix();
    //    ofPushStyle();
    //    ofSetColor(255);
    //    astroidFBO.draw(0,0);
    //    ofPopStyle();
    //    ofPopMatrix();

    ofSetColor(255);
    ofDrawBitmapString(ofToString(ofGetFrameRate()), 10, ofGetHeight()-20);
    ofDrawBitmapString( "Space bar for Sound Play", 10, ofGetHeight()-40);
    ofDrawBitmapString( "Mouse or Track Pad for 3D Viewing", 10, ofGetHeight()-60);
    ofDrawBitmapString( "\"f\" - key for full screen", 10, ofGetHeight()-80);

}

//--------------------------------------------------------------
float ofApp::getAmpLeft(float x, float y, ofPixels _p){

    float _amp = 0;

    ofColor _color = _p.getColor(x, y);

    float _r = _color.r;
    float _g = _color.g;
    float _b = _color.b;

    _amp = 1.0 - (_r + _g + _b) / 255.0 / 3.0;

    if (_amp>threshold) {
        _amp = 0;
    }

    return _amp;


}


//--------------------------------------------------------------
float ofApp::getPixelLeft(int x, int y){


    //    return _sum;

}

//--------------------------------------------------------------
float ofApp::getPixelRight(int x, int y){

    ofPixels _p;
    astroidFBO.readToPixels(_p);

    ofColor _color = _p.getColor(x, y);

    float _r = _color.r;
    float _g = _color.g;
    float _b = _color.b;

    float _sum = 1.0 - (_r + _g + _b) / 255.0 / 3.0;

    return _sum;

}



//--------------------------------------------------------------
float ofApp::getAmpLeft(float x, float y){

    float _amp = 0;

    ofPixels _p;
    astroidFBO.readToPixels(_p);

    ofColor _color = _p.getColor(x, y);

    float _r = _color.r;
    float _g = _color.g;
    float _b = _color.b;

    _amp = 1.0 - (_r + _g + _b) / 255.0 / 3.0;

    if (_amp>threshold) {
        _amp = 0;
    }

    return _amp;


}


//--------------------------------------------------------------
float ofApp::getAmpRight(float x, float y){

    float _amp = 0;
    _amp = getPixelRight(x, y);

    if (_amp>threshold) {
        _amp = 0;
    }

    return _amp;


}

//--------------------------------------------------------------
float ofApp::getFreqLeft(float y){
    float freq=0;

    float _maxHz = maxHertz;
    float _minHz = minHertz;
    float yToFreq = (y/BIT)*_maxHz;

    //TODO logarithmic scale
    freq = 1-(log(yToFreq)-log(_minHz)) / (log(_maxHz)-log(_minHz));
    freq *= _maxHz;
    //    freq = 1-(yToFreq-_minHz) / (_maxHz-_minHz);
    //    freq = (BIT-y+_minHz)/BIT*(_maxHz-_minHz);


    return freq;


}

//--------------------------------------------------------------
float ofApp::getFreqRight(float y){
    float freq=0;

    //    if(height>0){
    //    y-=9;

    float _maxHz = maxHertz;
    float _minHz = minHertz;
    float yToFreq = (y/BIT)*_maxHz;

    //TODO logarithmic scale
    freq = 1-(log(yToFreq)-log(_minHz)) / (log(_maxHz)-log(_minHz));
    freq *= _maxHz;
    //freq = 1-(yToFreq-minHz) / (maxHz-minHz);
    //freq= (spectrumHeight-y+minHz)/spectrumHeight*(maxHz-minHz);
    //    }


    return freq;


}



//--------------------------------------------------------------
void ofApp::audioRequested (float * output, int bufferSize, int nChannels){

    if (bPlaying) {

        for (int i = 0; i < bufferSize; i+=2){

            waveRight = 0.0;
            waveLeft = 0.0;

            for(int n=0; n<BIT; n++){

                if (ampLeft[n]>0.00001) {
                    phasesLeft[n] += 512./(44100.0/(hertzScaleLeft[n]));

                    if ( phasesLeft[n] >= 511 ) phasesLeft[n] -= 512;

                    //remainder = phases[n] - floor(phases[n]);
                    //wave+=(float) ((1-remainder) * sineBuffer[1+ (long) phases[n]] + remainder * sineBuffer[2+(long) phases[n]])*amp[n];

                    if ( phasesLeft[n] < 0 ) phasesLeft[n] = 0;

                    waveLeft+=(sineBufferLeft[1 + (long)phasesLeft[n]])*ampLeft[n];
                }

                //                if (ampRight[n]>0.00001) {
                //                    phasesRight[n] += 512./(44100.0/(hertzScaleRight[n]));
                //
                //                    if ( phasesRight[n] >= 511 ) phasesRight[n] -= 512;
                //
                //                    //remainder = phases[n] - floor(phases[n]);
                //                    //wave+=(float) ((1-remainder) * sineBuffer[1+ (long) phases[n]] + remainder * sineBuffer[2+(long) phases[n]])*amp[n];
                //
                //                    if ( phasesRight[n] < 0 ) phasesRight[n] = 0;
                //
                //                    waveRight+=(sineBufferRight[1 + (long)phasesRight[n]])*ampRight[n];
                //                }

            }

            waveRight /= 10.0;
            waveLeft /= 10.0;
            if (waveRight > 1.0) waveRight=1.0;
            if (waveRight<-1.0) waveRight=-1.0;
            if (waveLeft>1.0) waveLeft=1.0;
            if (waveLeft<-1.0) waveLeft=-1.0;

            float _volume = 10.85;
            output[i*nChannels    ] = waveLeft * _volume;
            output[i*nChannels + 1] = waveLeft * _volume;
        }

    } else {
        for (int i = 0; i < bufferSize; i++){
            output[i*nChannels    ] = 0;
            output[i*nChannels + 1] = 0;
        }
    }

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

    if (key==' ') bPlaying = !bPlaying;

    if (bPlaying)  {
        ofSoundStreamStart();
    } else {
        ofSoundStreamStop();
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
