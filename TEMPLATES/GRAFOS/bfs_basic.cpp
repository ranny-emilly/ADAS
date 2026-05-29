#include <bits/stdc++.h>
using namespace std;

#define el "\n"
#define _ ios_base::sync_with_stdio(0); cin.tie(0);

int main() {
    _

    // bfs por camadas, distancia em arestas
    int n, m;
    cin >> n >> m;

    vector<vector<int>> grafo(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;

        grafo[u].push_back(v);
        grafo[v].push_back(u);
    }

    int inicio;
    cin >> inicio;

    vector<int> distancia(n, -1);
    queue<int> fila;

    distancia[inicio] = 0;
    fila.push(inicio);

    while (!fila.empty()) {
        int vertice = fila.front();
        fila.pop();

        for (int vizinho : grafo[vertice]) {
            // -1 significa que ainda nao visitei
            if (distancia[vizinho] == -1) {
                distancia[vizinho] = distancia[vertice] + 1;
                fila.push(vizinho);
            }
        }
    }

    for (int d : distancia) {
        cout << d << " ";
    }
    cout << el;

    return 0;
}
