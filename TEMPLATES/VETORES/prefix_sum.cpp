#include <bits/stdc++.h>
using namespace std;

#define el "\n"
#define _ ios_base::sync_with_stdio(0); cin.tie(0);

int main() {
    _

    // prefix sum para soma de intervalo
    // prefixo[i] guarda a soma dos i primeiros
    int n;
    cin >> n;

    vector<long long> numeros(n);
    for (int i = 0; i < n; i++) {
        cin >> numeros[i];
    }

    vector<long long> prefixo(n + 1, 0);
    for (int i = 0; i < n; i++) {
        prefixo[i + 1] = prefixo[i] + numeros[i];
    }

    // soma do intervalo [l, r] com indice 0
    int l, r;
    cin >> l >> r;

    long long soma_intervalo = prefixo[r + 1] - prefixo[l];
    cout << soma_intervalo << el;

    return 0;
}
