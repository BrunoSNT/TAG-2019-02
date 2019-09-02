#include <stdio.h>
#include <vector>
#include <iostream>
#include <list>
#include <algorithm>
using namespace std;

class Grafo
{
    int vertice;           // número de vértices
    list<int> *adjacencia; // ponteiro para um array contendo as listas de adjacências

public:
    Grafo(int Vertice); // construtor
    void addAresta(int vertice, int v);
    void printVizinhos(int n);
    float Grafo::coefAglomeracao(int vertice, Grafo grafo);
    bool existeElemento(int elemento, int vertice);
    bool eVizinho(int vertice, int elemento);
};
Grafo::Grafo(int vertice)
{
    this->vertice = vertice;             // atribui o número de vértices
    adjacencia = new list<int>[vertice]; // cria as listas
}
void Grafo::addAresta(int vertice, int v)
{
    adjacencia[vertice].push_back(v);
}
void Grafo::printVizinhos(int n){
    for(int i =1; i<n; i++){
        printf("vertice %d vizinhos: \n",i);
        for( list<int>::iterator iterador = adjacencia[i].begin(); iterador != adjacencia[i].end(); iterador ++){
            
            cout << " " << *iterador;
            cout << "\n";
        }
    }

}


float Grafo::coefAglomeracao(int vertice, Grafo grafo){
        int triangulos = 0;
        int numVizinhos = adjacencia[vertice].size();
        int paresDistintos;
        int coeficiente;
    for( list<int>::iterator iterador = adjacencia[vertice].begin(); iterador != adjacencia[vertice].end(); iterador ++){
        int aux;
        aux = *iterador;
        list<int>::iterator it = iterador ++;
        for(it; it!= adjacencia[vertice].end(); it++){
            int elemento = *it;
            if(grafo.existeElemento(aux, elemento)){
                triangulos ++;
            };
        }
    }    
    paresDistintos = numVizinhos * ((numVizinhos-1)/2);
    coeficiente = triangulos/paresDistintos;
    return coeficiente;


}

bool Grafo::existeElemento(int elemento, int vertice){
  if (adjacencia[vertice].size()>0){
      list<int>::iterator it;
        it = std::find(adjacencia[vertice].begin(), adjacencia[vertice].end(), elemento);
 
    if(it != adjacencia[vertice].end()){

        getchar();
        return true;        cout<< "o elemento" << elemento << "ja esta na lista";
        }
        else{ 
            return false;
        
        };

  }
    return false;

}
