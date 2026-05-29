#include <bits/stdc++.h>
using namespace std;

#define el "\n"
#define _ ios_base::sync_with_stdio(0); cin.tie(0);

vector<vector<int>> grafo;
vector<bool> visitado;

void dfs(int vertice) {
    visitado[vertice] = true;

    for (int vizinho : grafo[vertice]) {
        // visitado impede loop infinito
        if (!visitado[vizinho]) {
            dfs(vizinho);
        }
    }
}

int main() {
    _

    // dfs recursiva simples
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

    dfs(inicio);

    return 0;
}
