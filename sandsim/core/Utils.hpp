#ifndef UTILS_HPP
#define UTILS_HPP

#include <string>
#include <iostream>
#include <cassert>
#include <cmath>

extern bool inDebug;
//Config
inline int FPS=50;
inline double FRAME_TIME=1000/FPS;
inline double RAD=0.0174532925;

inline int VERT_SIZE=3;

inline std::string GAME_NAME="Sandim V4";

inline int SCREEN_WIDTH=1600;
inline int SCREEN_HEIGHT=1000;

inline void debugAssert(bool statement, const char* comment){
	if(statement==true){
		return;
	}
	std::cout << "Assertion failed: " << comment << "\n";
	if(inDebug==true){
		exit(1);
	} else {
		assert(0);
	}
}

template <typename T = double> T difference(T p1, T p2){
	return fabs(p1-p2);
}

void outOfMemHandler();

double dist(double ax,double ay,double bx, double by);
	
#endif