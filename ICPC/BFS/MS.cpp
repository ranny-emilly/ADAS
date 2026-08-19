#include <bits/stdc++.h>
using namespace std;

#define el "\n"
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

const int MAX = 2e5+5;
vector<vector<int>>adj(MAX);
vector<int>pai(MAX);
vector<int>dist(MAX);

//CODIGO EM DESENVOLVIMENTO

void bfs(int v){

    for(int i = 0; i < MAX; i++){
        dist[i] = MAX+10;
        pai[i] = -1;

    }
    queue<int>q;
    q.push(v);
    dist[v] = 0;

    while(!q.empty()){
        int u = q.front(); // pega a frente da fila
        q.pop(); //tira o vértice do topo
        // for(int i=0; i<adj)
        for(int s: adj[u]){
            // s-> todos os vértices que são vizinhos de u
            if(dist[s] > dist[u]+1){
                dist[s] = dist[u]+1;
                pai[s] = u;
                q.push(s);
            }
        }
    }

}

//func de recuperar o caminho de v a t:

vector<int>rec_path(int t){
    vector<int>path;

    while(t != -1){
        path.push_back(t);
        t = pai[t];
    }
    reverse(path.begin(), path.end());
    // distancia ta guardada em dist[t]
    return path;
}


int main(){


    return 0;
}
