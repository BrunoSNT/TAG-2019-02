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
    float coefAglomeracao(int vertice, Grafo grafo);
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
        float triangulos = 0;
        float numVizinhos = adjacencia[vertice].size();
        float paresDistintos;
        float coeficiente;
    for( list<int>::iterator iterador = adjacencia[vertice].begin(); iterador != adjacencia[vertice].end(); iterador ++){
        int *aux = &*iterador;
        list<int>::iterator it = iterador;
        advance(it, 1); //avança o iterador it
        for(it; it!= adjacencia[vertice].end(); it++){
           
            if(grafo.existeElemento( *aux, *it)){
               
                triangulos ++;
            };
        }
    }    
    paresDistintos = numVizinhos * ((numVizinhos-1)/2);
    coeficiente = triangulos/paresDistintos;
    if(triangulos == 0){
        coeficiente =0;
    }
    return coeficiente;


}

bool Grafo::existeElemento(int elemento, int vertice){
  if (adjacencia[vertice].size()>0){
      list<int>::iterator it;
        it = std::find(adjacencia[vertice].begin(), adjacencia[vertice].end(), elemento);
 
    if(it != adjacencia[vertice].end()){

        
        return true;        cout<< "o elemento" << elemento << "ja esta na lista";
        }
        else{ 
            return false;
        
        };

  }
    return false;

}

// void Grafo::BornKerbosch(vector<int>R, vector<int>P, vector<int>X, vector<vector<int>> CliqueMax){
//     if(P.empty() && X.empty()){
//         CliqueMax.push_back(R);
//     }
//     vector<int> Paux = P;//Vetor auxiliar igual a P

//     //iterar sobre P aux


// }
