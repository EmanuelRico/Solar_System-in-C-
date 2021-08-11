#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iostream>
#include <armadillo>
#include <GLFW/glfw3.h>
#include <GL/glu.h>

#include "include/Object.hpp"
#include "include/Trayectory.hpp"
#include "include/Vertex.hpp"
#include "include/Transf.hpp"
#include "include/Planet.hpp"

//Hecho por Emanuel Rico Martínez
void Presentacion();

using namespace std;

int main(){

    Presentacion();
    
    GLFWwindow* window;

    if( !glfwInit() )
    {
        fprintf( stderr, "Fallo al inicializar GLFW\n" );
        getchar();
        return -1;
    }

    window = glfwCreateWindow(1024, 768, "OBJ_Reader_Rico", NULL, NULL);
    if( window == NULL ) {
        fprintf( stderr, "Fallo al abrir la ventana de GLFW.\n" );
        getchar();
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);

    double Ia (0.6);

    Planet Sun("obj/roca.obj", Ia);
    Sun.color = {1.0, 1.0, 0.0};
    Sun.ka = 0.5;
    Sun.kd = 0.9;

    Planet Mercury("obj/roca.obj", Ia);
    Mercury.color = {0.8, 0.5, 0.0};
    Mercury.ka = 0.5;
    Mercury.kd = 0.9;

    Planet Venus("obj/roca.obj", Ia);
    Venus.color = {0.0, 0.0, 1.0};
    Venus.ka = 0.5;
    Venus.kd = 0.9;

    Planet Earth("obj/roca.obj", Ia);
    Earth.color = {0.0, 1.0, 1.0};
    Earth.ka = 0.5;
    Earth.kd = 0.9;

    Planet Moon("obj/roca.obj", Ia);
    Moon.color = {1.0, 1.0, 1.0};
    Moon.ka = 0.5;
    Moon.kd = 0.9;

    Planet Marth("obj/roca.obj", Ia);
    Marth.color = {1.0, 0.0, 0.0};
    Marth.ka = 0.5;
    Marth.kd = 0.9;

    Planet Jupiter("obj/roca.obj", Ia);
    Jupiter.color = {1.0, 0.5, 0.0};
    Jupiter.ka = 0.5;
    Jupiter.kd = 0.9;

    Transf tr;

    double ang_Sun = 0.0;
    double ang_Mercury = 0.0;
    double ang_Venus = 0.0;
    double ang_Earth = 0.0;
    double ang_Moon = 0.0;
    double ang_Marth = 0.0;
    double ang_Jupiter = 0.0;

    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

    arma::drowvec eye1 = {0.0, 10.0, 0.0};
    arma::drowvec camera1 = {0.0, 0.0, 0.0};

    arma::drowvec eye2 = {0.0, 0.0, 10.0};
    arma::drowvec camera2 = {0.0, 0.0, 0.0};

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    int width, height;
    glfwGetFramebufferSize(window, &width, &height);

    double ar = width / height;

    //Paralellal Projection
    glViewport(0, 0, width, height);
    glOrtho(-ar, ar, -1.0, 1.0, -20.0, 20.0);

    do{
        arma::dmat mtr_sun = tr.S(0.40, 0.40, 0.40);
        arma::dmat mtr_earth = tr.Ry(ang_Earth) * tr.T(-0.52, 0.0, 0.0) * tr.S(0.3, 0.3, 0.3) * mtr_sun;
        Sun.set_transf(tr.S(0.40, 0.40, 0.40) * tr.Ry(ang_Sun));
        Mercury.set_transf(tr.Ry(ang_Mercury) * tr.T(-0.30, 0.0, 0.0) * tr.S(0.1, 0.1, 0.1) * mtr_sun * tr.Ry(ang_Mercury));
        Venus.set_transf(tr.Ry(ang_Venus) * tr.T(-0.38, 0.0, 0.0) * tr.S(0.18, 0.18, 0.18) * mtr_sun * tr.Ry(ang_Venus));
        Earth.set_transf(tr.Ry(ang_Earth) * tr.T(-0.52, 0.0, 0.0) * tr.S(0.3, 0.3, 0.3) * mtr_sun * tr.Ry(ang_Earth));
        Moon.set_transf( mtr_earth * tr.Ry(ang_Moon) * tr.T(-0.9, 0.0, 0.0) * tr.S(0.30, 0.30, 0.30) * tr.Ry(ang_Moon));
        Marth.set_transf(tr.Ry(ang_Marth) * tr.T(-0.67, 0.0, 0.0) * tr.S(0.4, 0.4, 0.4) * mtr_sun * tr.Ry(ang_Marth));
        Jupiter.set_transf(tr.Ry(ang_Jupiter) * tr.T(-0.87, 0.0, 0.0) * tr.S(0.5, 0.5, 0.5) * mtr_sun * tr.Ry(ang_Jupiter));
        
        glClear( GL_COLOR_BUFFER_BIT );
        glClear( GL_DEPTH_BUFFER_BIT );

        if(glfwGetKey(window, GLFW_KEY_1 )){
            glMatrixMode(GL_MODELVIEW);
            glLoadIdentity();
            gluLookAt(eye1[0], eye1[1], eye1[2], camera1[0], camera1[1], camera1[2], -10.0, 0.0, 0.0);
        }

        if(glfwGetKey(window, GLFW_KEY_2 )){
            glMatrixMode(GL_MODELVIEW);
            glLoadIdentity();
            gluLookAt(eye2[0], eye2[1], eye2[2], camera2[0], camera2[1], camera2[2], 0.0, 1.0, 0.0);
        }
        
        double Ip = 0.9;
        arma::drowvec light_pos = {0.0, 5.0, 0.0};

        //Sun
        Sun.print_Planet(Ip, light_pos);
        Mercury.print_Planet(Ip, light_pos);
        Venus.print_Planet(Ip, light_pos);
        Earth.print_Planet(Ip, light_pos);
        Moon.print_Planet(Ip, light_pos);
        Marth.print_Planet(Ip, light_pos);
        Jupiter.print_Planet(Ip, light_pos);

        glfwSwapBuffers(window);
        glfwPollEvents();

        Mercury.rotate(&ang_Mercury, 0.8);
        Venus.rotate(&ang_Venus, 0.7);
        Earth.rotate(&ang_Earth, 0.6);
        Moon.rotate(&ang_Moon, 0.4);
        Marth.rotate(&ang_Marth, 0.3);
        Jupiter.rotate(&ang_Jupiter, 0.2);

    }while( glfwGetKey(window, GLFW_KEY_ESCAPE ) != GLFW_PRESS && glfwWindowShouldClose(window) == 0 );

    glfwTerminate();

    cout << "Hecho por Emanuel Rico Martinez "<< endl;
    return 0;
}

void Presentacion(){

    cout << " \n";
    cout << "\t*******************************************" << endl;
    cout << "\t*******                             *******" << endl;
    cout << "\t*******   Este Proyecto esta hecho  *******" << endl;
    cout << "\t*******     por Emanuel Rico Mtz    *******" << endl;
    cout << "\t*******     de la carrera de ISI    *******" << endl;
    cout << "\t*******   encargado por la materia  *******" << endl;
    cout << "\t******* GRAFICACION POR COMPUTADORA *******" << endl;
    cout << "\t*******    a cargo del Ing. Omar    *******" << endl;
    cout << "\t*******     Rodriguez Gonzalez.     *******" << endl;
    cout << "\t*******                             *******" << endl;
    cout << "\t*******     Tarea Sistema Solar     *******" << endl;
    cout << "\t*******                             *******" << endl;
    cout << "\t*******************************************" << endl;

    do {
        cout << '\n' << "Press the Enter key to continue.";
    }while (cin.get() != '\n');

    cout << endl;
}