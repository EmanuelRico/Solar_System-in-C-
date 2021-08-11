#include "Trayectory.hpp"  
#include "Vertex.hpp"
	
Trayectory::Trayectory()
{
	
}

vector<Vertex> Trayectory::lineal(Vertex ini, Vertex end, double dt){

    vector<Vertex> line;

    //v1 + t(v2 - v1)
    for(double t = 0.0; t < 1.0 + dt; t += dt){
        
        double x1 = ini.get_X() + (t * (end.get_X()-ini.get_X()));
        double y1 = ini.get_Y() + (t * (end.get_Y()-ini.get_Y()));
        double z1 = ini.get_Z() + (t * (end.get_Z()-ini.get_Z()));
        
        Vertex p(x1, y1, z1);
        line.push_back(p);
    }

    return line;
}

vector<Vertex> Trayectory::bezier(Vertex ini, Vertex end, double dt, double cp){
    vector<Vertex> curve;

	//Se define MB
	arma::dmat MB = {{-1, 3, -3, 1},
					 {3, -6, 3, 0},
					 {-3, 3, 0, 0},
					 {1, 0, 0, 0}};
	
	arma::drowvec P1c = {ini.get_X(), ini.get_Y() , ini.get_Z() };
	arma::drowvec P2c = {rand() % 9 + cp, 1.0, 0.0};
	arma::drowvec P3c = {-(rand() % 9 + cp), -1.0, 0.0};
	arma::drowvec P4c = {end.get_X(), end.get_Y(), end.get_Z()};
	
	//Se define GB
	arma::dmat GB (4,3);
	GB.row(0) = P1c;
	GB.row(1) = P2c;
	GB.row(2) = P3c;
	GB.row(3) = P4c;
	
	for(double t=0.0; t <= 1.0 + dt; t += dt){
		arma::drowvec T = {pow(t, 3), pow(t, 2), t, 1};
		arma::drowvec Qt = T * MB * GB;
		
        double xf = Qt[0];
        double yf = Qt[1];
        double zf = Qt[2];
        
        Vertex v(xf, yf, zf);
        curve.push_back(v);

	}
	
	return curve;
}