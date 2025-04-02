//p incluir biblioteca
#include <bits/stdc++.h>
using namespace std;

int main () {
    //declarar a variável "a" como inteira
    int a, b, c;
    int soma;


    //funcao de leia
    cin >> a >> b >> c;

    
   soma = a + b + c;
   if (a + b == c) cout <<"Yes";
   if (b + c == a) cout <<"Yes";
   if (c + a == b) cout <<"Yes";


    //funcao de saída     

    else {
        cout << "No" << endl 
    }
    



   
   


return 0;

}
