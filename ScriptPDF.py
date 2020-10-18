import matplotlib.pyplot as plt
import numpy as np
import sys

def main(argv, arc):
    listaSO = []
    listaTiempo = []
    
    lista = []
    lista.append('')
    lista = lista + argv[1].split(';')
    for i in range(1, len(lista)):
        if(i % 2 == 0):
            listaTiempo.append(float(lista[i]))
        else:
            listaSO.append(lista[i])
    
    plotChart(listaSO, listaTiempo, argv[2])
    
def plotChart(listaSO, listaTiempo, titulo):
    fig = plt.figure(figsize = (12,6))
    ax = fig.add_subplot(111)
    ax.bar(listaSO, listaTiempo)
    ax.set_xticks(listaSO)
    ax.set_xticklabels(listaSO, rotation = 45, zorder=100)
    plt.xlabel('Sistema Operativo')
    plt.ylabel('Tiempo en segundos')
    plt.title(titulo)
    plt.savefig(titulo)
    
    
if __name__ ==  '__main__':
    main(sys.argv, len(sys.argv))
