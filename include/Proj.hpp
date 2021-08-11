#ifndef PROJ_H
#define PROJ_H
#pragma once
#include <armadillo>
	
class Proj  
{
	private:

	public:
		Proj();
		arma::dmat m_per(double d);
		arma::dmat m_pper(double d);
		arma::dmat m_ort();
		arma::dmat m_gen(double zp, double Q, double dx, double dy, double dz);

};
#endif