#ifndef TRAYECTORY_H
#define TRAYECTORY_H
#pragma once

#include "Vertex.hpp"

using namespace std;
	
class Trayectory  
{
	private:

	public:

		Trayectory();
		vector<Vertex> lineal(Vertex ini, Vertex end, double dt);
		vector<Vertex> bezier(Vertex ini, Vertex end, double dt, double cp);

};
#endif