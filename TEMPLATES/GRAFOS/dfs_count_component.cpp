#include <bits/stdc++.h>
using namespace std;

#define el "\n"
#define _ ios_base::sync_with_stdio(0); cin.tie(0);

vector<vector<int>> grafo;
vector<bool> visitado;

int dfs(int vertice) {
    visitado[vertice] = true;
    int tamanho = 1;

    for (int vizinho : grafo[vertice]) {
        // soma os vertices que ainda nao visitei
        if (!visitado[vizinho]) {
            tamanho += dfs(vizinho);
        }
    }

    return tamanho;
}

int main() {
    _

    // tamanho da componente do vertice inicial
    int n, m;
    cin >> n >> m;

    grafo.assign(n, vector<int>());
    visitado.assign(n, false);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;

        grafo[u].push_back(v);
        grafo[v].push_back(u);
    }

    int inicio;
    cin >> inicio;

    cout << dfs(inicio) << el;

    return 0;
}
