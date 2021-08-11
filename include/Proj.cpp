#include "Proj.hpp"  
	
Proj::Proj()
{
	
}

arma::dmat Proj::m_per(double d){

    arma::dmat mper = {{1, 0, 0, 0},
                       {0, 1, 0, 0},
                       {0, 0, 1, 0},
                       {0, 0, 1/d, 0}};

    return mper;
}

arma::dmat Proj::m_pper(double d){

    arma::dmat mpper = {{1, 0, 0, 0},
                       {0, 1, 0, 0},
                       {0, 0, 0, 0},
                       {0, 0, 1/d, 1}};

    return mpper;
}

arma::dmat Proj::m_ort(){

    arma::dmat mort = {{1, 0, 0, 0},
                       {0, 1, 0, 0},
                       {0, 0, 0, 0},
                       {0, 0, 0, 1}};

    return mort;
}

arma::dmat Proj::m_gen(double zp, double Q, double dx, double dy, double dz){

    arma::dmat mgen = {{1, 0, -dx / dz, zp*(dx / dz)},
                       {0, 1, -dy / dz, zp*(dy / dz)},
                       {0, 0, -zp / (Q*dz), (pow(zp, 2) / (Q*dz)) + zp},
                       {0, 0, -1 / (Q*dz), (zp / (Q*dz)) + 1}};

    return mgen;

}