#include <bits/stdc++.h>
using namespace std;

#define el "\n"
#define _ ios_base::sync_with_stdio(0); cin.tie(0);

int main() {
    _

    // busca binaria em vetor ordenado
    int n, alvo;
    cin >> n >> alvo;

    vector<int> numeros(n);
    for (int i = 0; i < n; i++) {
        cin >> numeros[i];
    }

    sort(numeros.begin(), numeros.end());

    int esquerda = 0;
    int direita = n - 1;
    bool encontrei = false;

    while (esquerda <= direita) {
        // evita problema de overflow que pode ter em (esquerda + direita) / 2
        int meio = esquerda + (direita - esquerda) / 2;

        if (numeros[meio] == alvo) {
            encontrei = true;
            break;
        }

        if (numeros[meio] < alvo) {
            esquerda = meio + 1;
        } else {
            direita = meio - 1;
        }
    }

    cout << (encontrei ? "SIM" : "NAO") << el;

    return 0;
}
