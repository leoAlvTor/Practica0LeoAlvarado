//
// Created by leo on 15/10/20.
//

#include <thread>
#include "PDF.h"

void PDF::crearPDF() {
    Image image1(Geometry(595, 1684, 5, 5), Color("white"));
    image1.font("helvetica");
    image1.annotate("\n Practica 1-1 Parte 1 \n Leonardo Alvarado 15/10/22"
                    "\n GITHUB URL: https://github.com/leoAlvTor/Practica0LeoAlvarado"
                    "\n \t DOS IMAGENES PROCESADAS:", NorthWestGravity);

    cout << "Ingrese la URL de una imagen procesada (Dentro del directorio de la opcion 1): ";
    string directorio1;
    cin >> directorio1;
    cout << "Ingrese la URL de una imagen procesada (Dentro del directorio de la opcion 1): ";
    string directorio2;
    cin >> directorio2;

    Image img(directorio1);
    img.scale(Geometry(550, 450));
    image1.composite(img, 5, 50);
    Image img1(directorio2);
    img1.scale(Geometry(550, 450));
    image1.composite(img1, 5, 400);

    Image image(Geometry(595, 842, 5, 5), Color("white"));
    image.font("helvetica");
    image.annotate("\n Practica 1-1 Parte 1 \n Leonardo Alvarado 15/10/22 \n"
                   "Los valores del histograma estan en el archivo: archivo.txt", NorthWestGravity);

    Image imageColor("Conversion De Color.png");
    imageColor.scale(Geometry(550, 450));
    Image imageHistograma("Histograma.png");
    imageHistograma.scale(Geometry(550, 450));

    image.composite(imageColor, 5, 50);
    image.composite(imageHistograma, 5, 400);

    image.annotate("\t Como se puede evidenciar en los graficos generados por Python, \n"
                   "\tC++ muestra mejores resultados en GNU Linux que en Linux a pesar de \n"
                   "\tque ambos SO trabajan con el mismo hardware en una maquina virutal, \n"
                   "\ten lo que respecta a la practica con ImageMagick se puede concluir que \n"
                   "\tes una gran herramienta que nos permite manipular imagenes en diferentes \n"
                   "\tformatos de una forma relativamente facil, aun que esto depende del lenguaje de \n"
                   "\tprogramacion que se haya elegido, en este caso C++ es un poco complejo pero \n"
                   "\ta pesar de eso se pudo completar el boletin de una manera satisfactoria. \n"
                   "\t \t PDF generado con ImageMagick.", SouthWestGravity);

    image1.composite(image, 0, 842);
    image1.magick("pdf");
    image1.write("Reporte.pdf");

}

void PDF::generarGrafica(string& conversionColor, string& histograma) {
    string archivoConvertir = "Conversion De Color.png";
    string archivoHistograma = "Histograma.png";
    string comandoColor = "python3.8 ScriptPDF.py  '" + conversionColor + "' 'Conversion De Color'";
    string comandoHistograma = "python3.8 ScriptPDF.py  '" + histograma + "' 'Histograma'";

    system(comandoColor.c_str());
    system(comandoHistograma.c_str());
    do{
        chrono::seconds sleep(1);
        this_thread::sleep_for(sleep);
    }while (!verificarExistencia(archivoConvertir, archivoHistograma));
}

bool PDF::verificarExistencia(string& fileName1, string& fileName2){
    ifstream ifstream1(fileName1.c_str());
    ifstream ifstream2(fileName2.c_str());
    return ifstream1.good() && ifstream2.good();
}
