#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <armadillo>

#include "Face.hpp"
#include "Vertex.hpp"  

Face::Face(){
}

Face::Face(vector<int> vertices){
    this->v = vertices;
}

double Face::get_A(){
    return A;
}

double Face::get_B(){
    return B;
}

double Face::get_C(){
    return C;
}

double Face::get_D(){
    return D;
}

vector<int> Face::get_v(){
    return v;
}

void Face::set_v(vector<int> v_index){
    this->v = v_index;
}

void Face::calculate_normal(vector<Vertex> verts){

    arma::drowvec v1c = {verts[this->v[0]-1].get_X(), verts[this->v[0]-1].get_Y(), verts[this->v[0]-1].get_Z()};
    arma::drowvec v2c = {verts[this->v[1]-1].get_X(), verts[this->v[1]-1].get_Y(), verts[this->v[1]-1].get_Z()};
    arma::drowvec v3c = {verts[this->v[2]-1].get_X(), verts[this->v[2]-1].get_Y(), verts[this->v[2]-1].get_Z()};

    this->normal = arma::cross(v2c-v1c, v3c-v1c);
    
    this->A = normal[0];
    this->B = normal[1];
    this->C = normal[2];

    this->D = -(A * v1c[0] + B * v1c[1] + C * v1c[2]);

}

arma::drowvec Face::get_Normal(){

    arma::drowvec nor = {this->A, this->B, this->C};

    return nor;
}