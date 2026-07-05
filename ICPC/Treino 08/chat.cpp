#include <bits/stdc++.h>
using namespace std;

#define el "\n";
#define _ ios_base::sync_with_stdio(0);cin.tie(0);


void lergrafo(vector<int>grafo[], int m){
    
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;

        grafo[a].push_back(b);
        grafo[b].push_back(a);
    }

}

void imprimirgrafo(vector<int>grafo[],int n){
    for(int i = 0; i <= n; i++){
        cout << "Vértice" << i << ":" << el;
    // Como os vertices foram criados de 1 ate n, comecamos em 1.
    for(int i = 1; i <= n; i++){
        cout << "Vertice " << i << ": ";

        // Percorre todos os vertices ligados ao vertice i.
        for(int vizinho : grafo[i]){
            cout << vizinho << " ";
        }

        cout << el;
    }
}

    

    return 0;
}


int main(){


    //n vertices e m arestas. n vertices e m conexões
    int n, m;
    cin >> n >> m;
    vector<int>grafo[n+1];

    lergrafo(grafo,m);

    imprimirgrafo(grafo, n);
    

    return 0;
}