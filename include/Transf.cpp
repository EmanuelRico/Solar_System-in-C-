#include <math.h>
#include "Transf.hpp"
#include "Vertex.hpp"
	
Transf::Transf(){
	
}

arma::dmat Transf::T(double dx, double dy, double dz){
    arma::dmat Tt = {{1, 0, 0, dx},
                    {0, 1, 0, dy},
                    {0, 0, 1, dz},
                    {0, 0, 0, 1}};

    return Tt;
}

arma::dmat Transf::S(double sx, double sy, double sz){
    arma::dmat St = {{sx, 0, 0, 0},
                    {0, sy, 0, 0},
                    {0, 0, sz, 0},
                    {0, 0, 0, 1}};

    return St;
}

arma::dmat Transf::Rx(double theta){
    double ang = theta * (M_PI / 180);

    arma::dmat Rxt = {{1, 0, 0, 0},
                      {0, cos(ang), -sin(ang), 0},
                      {0, sin(ang), cos(ang), 0},
                      {0, 0, 0, 1}};

    return Rxt;
}

arma::dmat Transf::Ry(double theta){
    double ang = theta * (M_PI / 180);

    arma::dmat Ryt = {{cos(ang), 0, sin(ang), 0},
                      {0, 1, 0, 0},
                      {-sin(ang), 0, cos(ang), 0},
                      {0, 0, 0, 1}};

    return Ryt;
}

arma::dmat Transf::Rz(double theta){
    double ang = theta * (M_PI / 180);

    arma::dmat Rzt = {{cos(ang), -sin(ang), 0, 0},
                      {sin(ang), cos(ang), 0, 0},
                      {0, 0, 1, 0},
                      {0, 0, 0, 1}};

    return Rzt;
}

arma::dmat Transf::Rp1p2(Vertex P1, Vertex P2, double theta){
    //Step 1
    arma::dmat T = {{1, 0, 0, -P1.get_X()},
                    {0, 1, 0, -P1.get_Y()},
                    {0, 0, 1, -P1.get_Z()},
                    {0, 0, 0, 1}};

    //Step 2
    double D1 = sqrt(pow(P2.get_X()-P1.get_X(), 2) + pow(P2.get_Z()-P1.get_Z(), 2));
    arma::dmat Ry = {{(P2.get_Z()-P1.get_Z())/D1, 0, -(P2.get_X()-P1.get_X())/D1, 0},
                     {0, 1, 0, 0},
                     {(P2.get_X()-P1.get_X())/D1, 0, (P2.get_Z()-P1.get_Z())/D1, 0},
                     {0, 0, 0, 1}};

    //Step 3
    double D2 = sqrt(pow(P2.get_X()-P1.get_X(), 2) + pow(P2.get_Y()-P1.get_Y(), 2) + pow(P2.get_Z()-P1.get_Z(), 2));
    arma::dmat Rx = {{1, 0, 0, 0},
                     {0, D1/D2, -(P2.get_Y()-P1.get_Y())/D2, 0},
                     {0, (P2.get_Y()-P1.get_Y())/D2, D1/D2, 0},
                     {0, 0, 0, 1}};

    //Step 4
    Transf tr;
    arma::dmat Tz_t = this->Rz(theta);

    //Step 5
    arma::dmat Rxi = Rx.i();
    
    //Step 6
    arma::dmat Ryi = Ry.i();
    
    //Step 7
    arma::dmat Ti = T.i();

    arma::dmat MC = Ti *Ryi * Rxi * Tz_t * Rx * Ry * T;

    return MC;
}