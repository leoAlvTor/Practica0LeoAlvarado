// c++ `Magick++-config --cxxflags --cppflags` -O2 -o main main.cpp Imagen.cpp `Magick++-config --ldflags --libs`

#include <iostream>
#include "Imagen.h"
#include "PDF.h"

void manipularImagenes(){
    string path;
    cout << "Bienvenido, tenga en cuenta que las imagenes van a ser transformadas a escala de grises, \npor lo tanto asegurese de tener una copia de las mismas." << endl;
    cout << "Ingrese el absolute path de la carpeta de imagenes (Ejm: /home/usr/carpeta/): ";
    cin >> path;
    cout << endl;
    Magick::Image image;
    Imagen imagen;
    vector<string> strs = imagen.leerDirectorio(path.append("*"));
    std::ofstream archivo;
    archivo.open("archivo.txt");
    archivo << "";
    long tiempoInicial = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
    for(const string& string1 : strs){
        if(imagen.esImagen(string1)) {
            imagen.transformarEscalaGrises(string1);
        }
    }
    long tiempoFinal = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
    long tiempoInicial1 = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
    for(const string& string1 : strs){
        if(imagen.esImagen(string1)) {
            imagen.calcularHistrogramas(string1);
        }
    }
    long tiempoFinal1 = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
    auto calculo = ((double)tiempoFinal - (double)tiempoInicial)/1000;
    auto calculo1 = ((double)tiempoFinal1 - (double)tiempoInicial1)/1000;
    cout << "Tiempo aproximado para transformar en escala de grises: " << calculo << " segundos." << endl;
    cout << "Tiempo aproximado para calcular el histrograma de color: " << calculo1 << " segundos." << endl;
}

void generarInforme(){
    PDF pdf;
    cout << "Ingrese los datos para generar el reporte de la conversion de color (OS;TiempoEnSegundos), ejemplo Windows;5.34;GNU;4.65" << endl;
    string conversionColor;
    cin >> conversionColor;
    cout << "Ingrese los datos para generar el reporte del histograma (OS;TiempoEnSegundos), ejemplo Windows;5.34;GNU;4.65" << endl;
    string histograma;
    cin >> histograma;
    pdf.generarGrafica(conversionColor, histograma);
    pdf.crearPDF();
}

int main(int argc, char *argv[]) {
    cout << "Menu de Opciones:" << endl
        << "\t 1. Conversion de color y calculo del histograma." << endl
        << "\t 2. Generar un informe en PDF en base a los tiempos previamente obtenidos." << endl
        << "Opcion Seleccionada: ";
    int opcionSelecionada;
    cin >> opcionSelecionada;
    cout << endl;
    if(opcionSelecionada == 1){
        Magick::InitializeMagick(*argv);
        manipularImagenes();
    }else if(opcionSelecionada == 2){
        generarInforme();
    }else{
        cout << "Adios!";
    }
    return 0;
}
