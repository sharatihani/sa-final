#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofSetFrameRate(240);
        ofBackground(0,0,0);
     
        ofSetLineWidth(3);
    ofSetCircleResolution(100);
    
//    gui.setup();
//    gui.add(lines.setup("lines",0,0,0.009));
    
    sonata.load("sonatamix.mp3");
        
        fftSmooth = new float [8192];
        for (int i = 0; i < 8192; i++) {
            fftSmooth[i] = 0;
        }
        
        bands = 64;
        
        sonata.play();
        sonata.setLoop(true);
        sonata.setVolume(0.2);
}

//--------------------------------------------------------------
void ofApp::update(){
    ofSoundUpdate();
       
       float * value = ofSoundGetSpectrum(bands);
       for (int i = 0; i < bands; i++) {
           fftSmooth[i] *= 0.5f;
           if (fftSmooth[i] < value[i]) {
               fftSmooth[i] = value[i];
           }
       }
   }



//--------------------------------------------------------------
void ofApp::draw(){
    
    

    float noise_value;
        ofColor color;
        
        for (int y = ofGetHeight() * 0; y < ofGetHeight(); y += 20) {
            color.setHsb(y % 60, 140, 200);
            ofSetColor(color);
//            ofSetColor(255, 200, 200);
            
            for (int x = ofGetWidth() * 0; x < ofGetWidth(); x += 1) {
                noise_value = ofMap(ofNoise(x * lines, y * lines, ofGetFrameNum() * lines), 0, 1, -50, 50);
                ofDrawLine(x, y + noise_value, x + 5, y + noise_value);
                
            }
        }
    ofFill();
    ofSetColor(0, 0, 0);
    ofDrawRectangle(60, 58, 600, 604);
    
    ofSetColor(125,48,48,98);
        for (int i = 0; i < bands; i++) {
//            ofSetCircleResolution(100);
            ofDrawCircle(ofGetWidth()/2+300, ofGetHeight()/2+300, -(fftSmooth[i]*2000));
            ofDrawCircle(ofGetWidth()/2+300, ofGetHeight()/2-300, -(fftSmooth[i]*2000));
            ofDrawCircle(ofGetWidth()/2-300, ofGetHeight()/2+300, -(fftSmooth[i]*2000));
            ofDrawCircle(ofGetWidth()/2-300, ofGetHeight()/2-300, -(fftSmooth[i]*2000));
        }

    ofTranslate(ofGetWidth() * 0.5, ofGetHeight() * 0.5);
     
        auto radius = 200;
        for (auto i = 0; i < layers; i++) {
     
            vector<glm::vec2> vertices;
            for (auto deg = 0; deg < 360; deg += 1) {
     
                auto base_location = glm::vec2(radius * cos(deg * DEG_TO_RAD), radius * sin(deg * DEG_TO_RAD));
                auto noise_radius = ofMap(ofNoise(base_location.x * flow, base_location.y * flow, (ofGetFrameNum() - i * 10) * 0.01), 0, 1, radius * pulse, radius * 1.0);
                auto location = glm::vec2(noise_radius * cos(deg * DEG_TO_RAD), noise_radius * sin(deg * DEG_TO_RAD));
     
                vertices.push_back(location);
            }
         
            ofFill();
            ofSetColor(125,48,48);
            ofBeginShape();
            ofVertices(vertices);
            ofEndShape(true);
     
            ofNoFill();
            ofSetColor(186,151,81);
            ofBeginShape();
            ofVertices(vertices);
            ofEndShape(true);
        }
    
    }

 

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    switch (key) {
            case '0':
                lines = 0;
                flow = 0;
                pulse = 1;
                layers = 1;
                break;
            case '1':
                lines =0.001;
                flow = 0.001;
                pulse = 0.9;
                layers = 1;
                break;
            case '2':
                lines = 0.002;
                flow = 0.001;
                pulse = 0.8;
                layers = 2;
                break;
            case '3':
                lines = 0.003;
                flow = 0.002;
                pulse = 0.7;
                layers = 3;
                break;
            case '4':
                lines = 0.004;
                flow = 0.002;
                pulse = 0.7;
                layers = 4;
                break;
            case '5':
                lines = 0.005;
                flow = 0.003;
                pulse = 0.6;
                layers = 5;
                break;
            case '6':
                lines = 0.009;
                flow = 0.004;
                pulse = 0.5;
                layers = 6;
                break;
            case '7':
                lines = 0.015;
                flow = 0.005;
                pulse = 0.5;
                layers = 7;
                break;
            case '8':
                lines = 0.02;
                flow = 0.008;
                pulse = 0.4;
                layers = 8;
                break;
            case '9':
                lines = 0.03;
                flow = 0.009;
                pulse = 0.4;
                layers = 9;
                break;
            
            default:
                break;
        }

}
//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

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
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

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

