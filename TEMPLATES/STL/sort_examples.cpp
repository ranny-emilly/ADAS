#include <bits/stdc++.h>
using namespace std;

#define el "\n"
#define _ ios_base::sync_with_stdio(0); cin.tie(0);

int main() {
    _

    // sort basico para busca binaria, greedy e two pointers
    int n;
    cin >> n;

    vector<int> numeros(n);
    for (int i = 0; i < n; i++) {
        cin >> numeros[i];
    }

    sort(numeros.begin(), numeros.end()); // crescente

    for (int x : numeros) {
        cout << x << " ";
    }
    cout << el;

    sort(numeros.begin(), numeros.end(), greater<int>()); // decrescente

    for (int x : numeros) {
        cout << x << " ";
    }
    cout << el;

    return 0;
}
