//
// Created by leo on 15/10/20.
//

#include <string>
#include <vector>
//#include <glob.h>
#include <Magick++.h>
#include <chrono>
#include <iostream>
#include <fstream>

#ifndef PRACTICA0LEOALVARADO_PDF_H
#define PRACTICA0LEOALVARADO_PDF_H

using namespace std;
using namespace Magick;

class PDF {
public:
    string cabecera;

    void crearPDF();
    void generarGrafica(string&, string&);
    bool verificarExistencia(string& ,string&);
};


#endif //PRACTICA0LEOALVARADO_PDF_H
