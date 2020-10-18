//
// Created by Leo Alvarado on 14/10/20.
//
#include <string>
#include <vector>
#include <glob.h>
#include <Magick++.h>
#include <chrono>
#include <iostream>
#include <iomanip>

#ifndef PRACTICA0LEOALVARADO_IMAGEN_H
#define PRACTICA0LEOALVARADO_IMAGEN_H

using namespace std;

class Imagen {
public:
    // Metodo para leer los archivos que se encuentran dentro de un directorio (@Param path).
    vector<string> leerDirectorio(string);
    // Convierte las imagenes a escala de grises.
    void transformarEscalaGrises(string); // Por el momento usa auto porque no se que retorna!
    // Calcula el histograma tanto a color como escala de grises.
    void calcularHistrogramas(string);

    bool esImagen(string);



};


#endif //PRACTICA0LEOALVARADO_IMAGEN_H
