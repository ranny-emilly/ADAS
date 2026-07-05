//ideia é fazer um map com char e a quantidade de vezes que cada letra aparece. Preciso estruturar melhor;

#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define el "\n";

int main(){

    string s;

    cin >> s;

    map<char, int>m;

    for(int i = 0; i < s.size(); i++){
        m[s[i]]++;
    }

    for(int i = 0; i < m.size(); i++){
        if(m[s[i]])
    }

    //m em s[0] é a quantidade de vezes que um termo aparece
    cout << m[s[0]] << el;



    return 0;
}
