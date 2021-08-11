#ifndef TRANSF_H
#define TRANSF_H
#pragma once
#include <armadillo>
#include "Vertex.hpp"

using namespace std;

class Transf
{
	private:

	public:
		Transf();
		arma::dmat T(double dx, double dy, double dz);
		arma::dmat S(double sx, double sy, double sz);
		arma::dmat Rx(double theta);
		arma::dmat Ry(double theta);
		arma::dmat Rz(double theta);
		arma::dmat Rp1p2(Vertex P1, Vertex P2, double theta);

};
#endif