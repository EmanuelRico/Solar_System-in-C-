#ifndef VERTEX_H
#define VERTEX_H
#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <armadillo>

using namespace std;
	
class Vertex{
	private:
		double x, y, z;
	public:
		Vertex();
		Vertex(double xi, double yi, double zi);
		double get_X();
		double get_Y();
		double get_Z();
		void print();
		arma::dcolvec homg();
};
#endif