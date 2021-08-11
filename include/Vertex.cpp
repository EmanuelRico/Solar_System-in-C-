#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <armadillo>

#include "Vertex.hpp"

using namespace std;
	
Vertex::Vertex(){
	x = y = z = 0.0;
}

Vertex::Vertex(double xi, double yi, double zi){
	x = xi;
	y = yi;
	z = zi;
}

double Vertex::get_X(){
	return x;
}

double Vertex::get_Y(){
	return y;
}

double Vertex::get_Z(){
	return z;
}

void Vertex::print(){
	cout << "(" << x << "," << y << "," << z << ")" << endl;
}

arma::dcolvec Vertex::homg(){
	arma::dcolvec h = {this->x, this->y, this->z, 1};

	return h;
}