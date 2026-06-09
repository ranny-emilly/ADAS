#include <bits/stdc++.h>
using namespace std;

#define el "\n";
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

int main(){
    _;
    int n;
    long long soma = 0, sleft = 0, menor= 2e18, sr = 0, diferenc;
    
    cin >> n;
    vector<int>ve(n);

    for(int i = 0; i < n; i++){
        cin >> ve[i];
        soma+=ve[i];
    }

    for(int i = 0; i < n; i++){
        sleft += ve[i];
        sr = soma - sleft;
        diferenc = abs(sleft - sr);

        if(diferenc < menor){
            menor = diferenc;
        }
    }

    cout << menor << el;


    return 0;
}