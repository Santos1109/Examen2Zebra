#include <iostream>
#include <list>
#include <fstream>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include "Libro.h"
#include "Evaluador.h"
#include "NodoBinario.h"

using namespace std;
int tam = 204;

//Escribe todos los datos del libro en un archivo con nombre nombre_archivo en la posicion dada
void escribir(string nombre_archivo, Libro*libro, int posicion)
{

    ofstream out(nombre_archivo.c_str(),ios::in | ios::out);
        if(!out.is_open()) {
            out.open(nombre_archivo.c_str());
        }

    out.seekp(posicion * tam);
    out.write(libro->nombre.c_str(),100);
    out.write(libro->autor.c_str(), 100);
    out.write((char*)&libro->existencias,4);
    out.close();
}

//Devuelve el libro guardado en el archivo en la posicion dada
Libro* leer(string nombre_archivo, int posicion)
{
    char nombre[100];
    char autor[100];
    int existencia;


    ifstream in(nombre_archivo.c_str());

    in.seekg(posicion * tam);

    in.read(nombre,100);
    in.read(autor, 100);
    in.read((char*)&existencia,4);

    return new Libro(nombre, autor, existencia);
}

//Crea un mapa en base a las llaves y valores dados, asocia cada llave con los valores en la misma posicion
map<string, int> convertirEnMapa(set<string> llaves, set<int> valores)
{
    map<string, int> respuesta;
    set<string>::iterator x = llaves.begin();
    set<int>::iterator y =  valores.begin();

    while(x!=llaves.end()){
        respuesta[*x] = *y;
        y++;
        x++;
    }
    return respuesta;

}

//Devuelve una cola con los mismos valores que el parametro exepto que no tiene el ultimo valor
queue<int> popBack(queue<int> cola)
{
    queue<int> respuesta;
    stack<int> respuestaT;
    stack<int> temporal;
    int agregar,contador;
    while(!cola.empty())
    {
        agregar = cola.front();
        temporal.push(agregar);
        cola.pop();
    }
    temporal.pop();
    while(!temporal.empty())
    {
        agregar = temporal.top();
        respuestaT.push(agregar);
        temporal.pop();
    }
    while(!respuestaT.empty())
    {
        agregar = respuestaT.top();
        respuesta.push(agregar);
        respuestaT.pop();
    }
    return respuesta;
}

//Reemplaza todos los valores del arbol
void reemplazarValores(NodoBinario* raiz, int valor)
{
    if(raiz == NULL)
        return;

    if(raiz->valor = valor)

    reemplazarValores(raiz->izquierdo, valor);
    reemplazarValores(raiz->derecho, valor);
}

//Devuelve la cantidad de bits "encendidos" o con el valores de 1
int contarBits(char byte)
{
    int mascara=0;
    int cont=0;
    for(int i=0; i<(int)byte; i++){
        if(byte&mascara<<i) {
            cont++;
        }
    }
    return cont;
}

int main ()
{
    //Funcion evaluadora
    evaluar();
    return 0;
}

