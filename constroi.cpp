    #include <stdio.h>
    #include<vector>
    #include <iostream>
#include <list>
#include <algorithm> // função find

using namespace std;

    class Grafo
    {
	    int vertice; // número de vértices
	    list<int> *adjacencia; // ponteiro para um array contendo as listas de adjacências

        public:
	    Grafo(int Vertice); // construtor
        void addAresta(int vertice, int v);
	
    };

Grafo::Grafo(int vertice)
    {
    	this->vertice = vertice; // atribui o número de vértices
    	adjacencia = new list<int>[vertice]; // cria as listas
    }

void Grafo::addAresta(int vertice, int v){
    adjacencia[vertice].push_back(v);
}

 
    int main(void)
    {
        Grafo grafo(63);//O grafo vai de 0 a 62, precisamos de 63 lugaresinhos bonitinhos
        FILE *in = fopen("soc-dolphins.mtx", "r");
        vector <int> valores;
        
        if (in != NULL) {
            char line[BUFSIZ];
            
            while (fgets(line, sizeof line, in) != NULL) {
                char *start = line;
                int field;
                int n;
                int primeiro;
                int contador;
                int vizinho =1;
                int vertice;
                if(line[0]=='%') continue;
                   contador = 0;
                //Aqui iremos usar o vetor valores para armazenar todos os valores de uma linha, para depois podermos adicionar esses valores na lista (tem que ter um jeito melhor de fazer isso, btw)
                while (sscanf(start, "%d%n", &field, &n) == 1) {
                  
                valores.push_back(field);//envia o valor que leu na linha para o vetor
                    start += n;//isso aqui é o que faz ele mudar de linha so quando acabar de ler a linha
               
                }
                for(int i=1; i< valores.size(); i++){
                    grafo.addAresta(valores[0], valores[i]);
                    printf("valor %d vertice %d", valores[0], valores[i]);
                }
                    vertice ++;
                    contador = 0; 
                    valores.clear();
                puts("");
            }
            
            fclose(in);
        }
        
        return 0;
    }