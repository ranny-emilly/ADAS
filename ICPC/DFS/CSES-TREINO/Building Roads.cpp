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
    
    
    int n, m;
    
    cin >> n >> m;
    vector<int> representantes;
    
for(int i = 0; i < m; i++){
    int a, b;
    cin >> a >> b;

    vec[a].push_back(b);
    vec[b].push_back(a);
}

    for(int i = 1; i < n+1; i++){
        if(!vis[i]){
            representantes.push_back(i);
            dfs(i);

        }
    }

    cout << representantes.size()-1 << el;

    for(int i = 0; i < representantes.size()-1; i++){

            cout << representantes[i] << " "<< representantes[i+1] << el;

    }

    cout << el;

    return 0;
}