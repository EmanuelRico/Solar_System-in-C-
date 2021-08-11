#ifndef FACE_H
#define FACE_H
#pragma once
#include "Vertex.hpp"

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iostream>
#include <armadillo>

using namespace std;
	
class Face{
	private:
		double A, B,C, D = 0;
		vector<int> v;
		arma::drowvec normal;
	public:
		Face();
		Face(vector<int> vertices);
		void calculate_normal(vector<Vertex> verts);
		double get_A();
		double get_B();
		double get_C();
		double get_D();
		vector<int> get_v();
		void set_v(vector<int> v_index);
		arma::drowvec get_Normal();
};
#endif