#include <bits/stdc++.h>
using namespace std;

#define el "\n"
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

vector<vector<int>> grafo;
vector<bool> visitado;


int caminhos_validos = 0; 

void adicionarAresta(int u, int v){
    grafo[u].push_back(v);
    grafo[v].push_back(u);
}

// A DFS recebe a quantidade de nós visitados no caminho atual e o N total
void dfs(int atual, int qtd_visitados, int n){
    
    // Passo 1: Marca o nó atual como visitado
    visitado[atual] = true;
    
    // Passo 2: Verifica se visitamos todos os vértices do grafo
    if(qtd_visitados == n){
        caminhos_validos++;
    } 
    else {
        // Passo 3: Continua explorando os vizinhos
        for(int vizinho : grafo[atual]){
            if(!visitado[vizinho]){
                // Passamos qtd_visitados + 1 porque estamos entrando em um novo vértice
                dfs(vizinho, qtd_visitados + 1, n);
            }
        }
    }
    
    // Passo 4 (A Mágica do Backtracking): 
    // Quando terminamos de explorar os caminhos a partir daqui, "limpamos nossas pegadas".
    visitado[atual] = false;
}

int main(){
    _
    int n, m;
    cin >> n >> m;

    // Modificação 2: Ajustar o tamanho dos vetores
    // Somamos +1 porque a questão diz que os vértices são numerados de 1 até N.
    // Assim ignoramos o índice 0 e usamos os índices de 1 a N.
    grafo.resize(n + 1);
    visitado.assign(n + 1, false);

    // Modificação 3: Lendo as M arestas da entrada
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        adicionarAresta(u, v);
    }

    // Modificação 4: Iniciando a DFS
    // O problema pede para começar do vértice 1.
    // Como já estamos pisando no vértice 1, a qtd_visitados inicia valendo 1.
    dfs(1, 1, n);

    // Modificação 5: Imprimir a resposta
    cout << caminhos_validos << el;

    return 0;
}