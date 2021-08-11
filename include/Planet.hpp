#ifndef PLANET_H
#define PLANET_H
#pragma once

#include <armadillo>
#include "Object.hpp"

class Planet : public Object 
{
	private:
		arma::dmat transf;
	public:
		arma::drowvec color;
		double ka;
		double kd;
		double Ia;
		Planet(string obj_file, double Ia);
		void set_transf(arma::dmat tr);
		arma::dmat get_transf();
		void print_Planet(double Ip, arma::drowvec light_pos);
		void rotate(double *ang, double dang);
};
#endif