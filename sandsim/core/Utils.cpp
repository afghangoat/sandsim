#include "Utils.hpp"

bool inDebug=true;

void outOfMemHandler(){
	std::cout << "Out of memory error!\n";
	exit(1);
}

double dist(double ax,double ay,double bx, double by){
	return (sqrt((bx-ax)*(bx-ax)+(by-ay)*(by-ay)));
}