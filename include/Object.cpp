#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <armadillo>
#include <GLFW/glfw3.h>

#include "Object.hpp"
#include "Vertex.hpp"
#include "Face.hpp"

using namespace std;

Object::Object(string rute){
	string line; //Variable tipo string que guardará linea por linea del archivo
    ifstream file(rute); //Se abre el archivo en modo lectura
    
    while(getline (file, line)){ //Ciclo para leer mientras siga habiendo lineas por leer en el archivo
        vector<string> elems = this->split(line, " "); //vector que guardará el split entre cada espacio
        if(elems.size() > 0){
            
            if (elems[0].compare("g") == 0 || elems[0].compare("o") == 0){ //Si encuentra una g se guarda el nombre
                this->name = elems[1];
            }

            if(elems[0].compare("v") == 0){ //Si encuentra una v guarda los vertices
                double x = stod(elems[1]);
                double y = stod(elems[2]);
                double z = stod(elems[3]);
                Vertex new_vertex(x, y, z);
                this->verts.push_back(new_vertex);
            }

            if(elems[0].compare("f") == 0){ //Si encuentra una f guarda las caras
                vector<int> v;
                int v_index;   //Variable que guardará los vertices que ya están en elems

                //Ciclo para leer, hacer split y guardar los elementos del archivo en el vector v_faces
                //Se empieza en 1 porque en 0 está guardado el nombre del objeto
                for(int i=1;i<elems.size();i++){
                    v_index = stoi(this->split(elems[i], "/")[0]);
                    v.push_back(v_index);
                }
                Face f(v);
                this->faces.push_back(f);
                f.set_v(v);
            }
        }
    }
}

vector<string> Object::split(const string& str, const string& delim){
    vector<string> tokens;
    size_t prev = 0, pos = 0;
    do{
        pos = str.find(delim, prev);
        if(pos == string::npos)
            pos = str.length();

        string token = str.substr(prev, pos-prev);

        if(!token.empty())
            tokens.push_back(token);

        prev = pos + delim.length();
    }while(pos < str.length() && prev < str.length());

    return tokens;
}

vector<Vertex> Object::getVertex(){
    return this->verts;
}

void Object::print(){
    cout << "o " << this->name << endl;

    for(Vertex vertex : this->verts){
        cout << "v " << vertex.get_X() << " " << vertex.get_Y() << " " << vertex.get_Z() << endl;
    }
    
    for(Face f : this->faces){
        cout << "f ";
        for(int i : f.get_v()){
            cout << i << " ";
        }
        //f.calculate_normal(this->verts);
        //cout << "Ec. normal:" << f.get_A() << "x + " << f.get_B() << "y + " << f.get_C() << "z + " << f.get_D() << " = 0" << endl;
        cout << endl;
    }
}