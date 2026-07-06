#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define el "\n";

const int MAX = 1e5+5;
vector<vector<int>>vec(MAX);
vector<bool>vis(MAX);

void dfs(int v){
    vis[v] = true;
    
    for(auto w : vec[v]) if(!vis[w]){
        dfs(w);
    }
}

int main(){_
    
    int n, m, cont = 0, aux = 0;
    
    cin >> n >> m;
    
    for(int i = 0; i < m; i++){
        int a, b;
        
        cin >> a >> b;
        
        vec[a].push_back(b);
        vec[b].push_back(a);
    }
    
    for(int i = 1; i <= n; i++){
        if(!vis[i]){
            dfs(i);
            cont++;
            aux = i;
        }
    
    }
    
    cout << cont << el;

    
    return 0;
}
