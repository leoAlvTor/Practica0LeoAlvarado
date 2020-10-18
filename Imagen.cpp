//
// Created by leo on 14/10/20.
//

#include <fstream>
#include "Imagen.h"


vector<string> Imagen::leerDirectorio(const string path) {
    vector<string> files;
    glob_t glob_result;
    glob(path.c_str(), GLOB_TILDE, nullptr, &glob_result);
    files.reserve(glob_result.gl_pathc); // Reserva un 'espacio' para almacenar los resultados.
    for (unsigned int i = 0; i < glob_result.gl_pathc; ++i) {
        files.emplace_back(glob_result.gl_pathv[i]);
    }
    globfree(&glob_result);
    return files;
}

bool Imagen::esImagen(string img) {
    int posicion = img.rfind(".");
    if (posicion == std::string::npos) {
        return false;
    } else {
        string extension = img.substr(posicion + 1);
        if (extension == "jpg" || extension == "png" || extension == "jpeg") {
            return true;
        } else {
            return false;
        }
    }
}

void Imagen::transformarEscalaGrises(string imagen) {
    Magick::Image image(imagen);
    image.type(Magick::GrayscaleType);
    image.write(imagen);
}

void Imagen::calcularHistrogramas(string imagen) {
    Magick::Image image(imagen);
    map<Magick::Color,unsigned long> histogram;
    Magick::colorHistogram(&histogram, image);
    std::ofstream archivo;
    archivo.open("archivo.txt", std::ios_base::app); // Agrega nuevos valores a un archivo existente.
    archivo << "Calculo del Histograma:\n"
               "Cantidad de ocurrencias <-> Color\n";
    std::map<Magick::Color, unsigned long>::const_iterator p=histogram.begin();
    while (p != histogram.end())
    {
        archivo << "Imagen: " + imagen + " -->  ";
        archivo << (int)p->second << ": ("
             << (int)p->first.quantumRed() << ","
             << (int)p->first.quantumGreen() << ","
             << (int)p->first.quantumBlue() << ")"
             << endl;
        p++;
    }

}

