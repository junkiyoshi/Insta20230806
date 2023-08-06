#include "ofApp.h"	

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(30);
	ofSetWindowTitle("openFrameworks");

	ofBackground(39);
	ofSetColor(255);
	ofSetLineWidth(2);

	this->mesh.setMode(ofPrimitiveMode::OF_PRIMITIVE_LINES);
}

//--------------------------------------------------------------
void ofApp::update() {

	ofSeedRandom(39);

	if (ofGetFrameNum() % 60 < 30) {

		if (ofGetFrameNum() % 60 < 15) {
		
			this->noise_param += ofMap(ofGetFrameNum() % 60, 0, 15, 0, 0.025);
		}
		else {

			this->noise_param += ofMap(ofGetFrameNum() % 60, 15, 30, 0.025, 0);
		}
	}

	this->mesh.clear();
	for (int y = ofGetWindowHeight() * -0.5; y <= ofGetWindowHeight() * 0.5; y += 3) {

		auto x = ofMap(ofNoise(ofRandom(1000), this->noise_param), 0, 1, ofGetWindowWidth() * -0.65, ofGetWindowWidth() * 0.65);
		this->mesh.addVertex(glm::vec3(x - 15, y, 0));
		this->mesh.addVertex(glm::vec3(x + 15, y, 0));
		this->mesh.addIndex(this->mesh.getNumVertices() - 2);
		this->mesh.addIndex(this->mesh.getNumVertices() - 1);
	}

}

//--------------------------------------------------------------
void ofApp::draw() {

	ofTranslate(ofGetWindowSize() * 0.5);

	this->mesh.drawWireframe();
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}