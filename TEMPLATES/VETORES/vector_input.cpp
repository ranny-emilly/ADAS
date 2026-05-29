#include <bits/stdc++.h>
using namespace std;

#define el "\n"
#define _ ios_base::sync_with_stdio(0); cin.tie(0);

int main() {
    _

    // lendo n numeros no vector
    int n;
    cin >> n;

    vector<int> numeros(n);
    for (int i = 0; i < n; i++) {
        cin >> numeros[i];
    }

    // percorrer todos os elementos
    for (int x : numeros) {
        cout << x << " ";
    }
    cout << el;

    return 0;
}
