#pragma once

#include "ofMain.h"

// core addons
#include "ofxVectorMath.h"
#include "ofxOpenCv.h"
#include "ofxFbo.h"

// extra addons
#include "ofxControlPanel.h" // https://github.com/ofTheo/ofxControlPanel
#include "ofxLibdcPtGrey.h" // https://github.com/kylemcdonald/ofxLibdc

#include "ofxAutoControlPanel.h"
#include "ContourMatcher.h"
#include "Particle.h"

#include "Hole.h"
class Hole;

class testApp : public ofBaseApp{
public:
	static bool debug;
	
	void setup();
	void setupControlPanel();
	void update();
	void draw();
	void drawWarped();

	void keyPressed(int key);
	void mouseMoved(int x, int y);
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	
	void drawBlob(ofxCvBlob& blob);
	void drawNormals(ofxCvBlob& blob, float length);

	ofxLibdcPtGrey camera;
	ofImage curFrame;
	
	ofxCvGrayscaleImage grayImage, grayBg, grayDiff;

	static ofxCvContourFinder contourFinder;
	static vector<ofxCvBlob> resampledBlobs;

	int threshold;
	bool bLearnBakground;
	
	ofxAutoControlPanel panel;
	
	ofxCvGrayscaleImage staticShadow;
	static vector<Hole> holes;
	
	ofxFbo fbo;
	
	ofSoundPlayer ambience;
	
	static const int targetWidth = 1080;
	static const int targetHeight = 1920;
};
