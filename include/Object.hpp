#ifndef OBJECT_H
#define OBJECT_H
#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <armadillo>

#include "Vertex.hpp"
#include "Face.hpp"

using namespace std;
	
class Object{
	private:
		vector<string> split(const string& str, const string& delim);
	public:
		Object(string rute);
		string name;
		vector<Face> faces;
		vector<Vertex> verts;
		vector<Vertex> getVertex();
		void print();
};
#endif