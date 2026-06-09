#include <bits/stdc++.h>
using namespace std;

#define el "\n";
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

int main(){
    _

    long long n, m, l = 0, r = 0, type = 0, result = 0;;
    
    
    cin >> n;
    vector<long long>v(n+1);
    vector<long long>pre(n+1);
    vector <long long> ord(n+1);
    
    v[0] = 0;
    pre[0] = 0;
    ord[0] = 0;

    for(long int i = 1; i <= n; i++){
        cin >> v[i];
        pre[i] = pre[i-1]+ v[i];
    }
    
    sort(v.begin() + 1, v.end());
    
    for(long int i = 1; i <= n; i++){
        ord[i] = v[i] + ord[i-1];
    }

    cin >> m;

    while(m--){

        cin >> type >> l >> r;

        if(type == 1){
            result = pre[r]-pre[l-1];
        }else{
            result = ord[r]-ord[l-1];
        }
        cout << result << el;
    }




    return 0;
}