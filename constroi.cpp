#include <stdio.h>
#include <vector>
#include <iostream>
#include <list>
#include <algorithm> // função find
#include "constroi.h"

using namespace std;

Grafo criaGrafo(void)
{
    Grafo grafo(63); //O grafo vai de 0 a 62, precisamos de 63 lugaresinhos bonitinhos
    FILE *in = fopen("soc-dolphins.mtx", "r");
    vector<int> valores;

    if (in != NULL)
    {
        char line[BUFSIZ];

        while (fgets(line, sizeof line, in) != NULL)
        {
            char *start = line;
            int field;
            int n;
            int vertice;
            if (line[0] == '%')
                continue;
            //Aqui iremos usar o vetor valores para armazenar todos os valores de uma linha, para depois podermos adicionar esses valores na lista (tem que ter um jeito melhor de fazer isso, btw)
            while (sscanf(start, "%d%n", &field, &n) == 1)
            {

                valores.push_back(field); //envia o valor que leu na linha para o vetor
                start += n;               //isso aqui é o que faz ele mudar de linha so quando acabar de ler a linha
            }
            for (unsigned int i = 1; i < valores.size(); i++)//o valores[0] é a onde eu adiciono meu valor, assim eu nao começo do indice 0, mas do indice 1
            {
                grafo.addAresta(valores[0], valores[i]); //se o elemento 11 tem 1 como vizinho, adiciona 1 a lista de 11
                if(!grafo.existeElemento(valores[0], valores[i])){
                    grafo.addAresta(valores[i], valores[0]);//se o elemento 1 tem 11 como vizinho, adiciona 11 a lista de 1.
                }
            }
            vertice++;
            valores.clear();
        }   

        fclose(in);
    }

    return grafo;
}

int main(void)
{
    Grafo g = criaGrafo();
    g.printVizinhos(63);

    return 0;
}