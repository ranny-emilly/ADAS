#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define el "\n"

int main(){ _
    int n;
    if (!(cin >> n)) return 0;
    
    vector<int> vec(n);
    for(int i = 0; i < n; i++){
        cin >> vec[i];
    }

    int contador = 0;


    for(int i = 0; i < n - 2; i++){
        if(vec[i] < vec[i+1] && vec[i+1] > vec[i+2]){
            contador++; 
        }
    }
            
    cout << contador << el;

    return 0;
}
