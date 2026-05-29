#include <bits/stdc++.h>
using namespace std;

#define el "\n"
#define _ ios_base::sync_with_stdio(0); cin.tie(0);

int main() {
    _

    // two pointers basico para subarray com numeros positivos
    int n;
    long long limite;
    cin >> n >> limite;

    vector<int> numeros(n);
    for (int i = 0; i < n; i++) {
        cin >> numeros[i];
    }

    int esquerda = 0;
    int melhor_tamanho = 0;
    long long soma_atual = 0;

    for (int direita = 0; direita < n; direita++) {
        soma_atual += numeros[direita];

        // passou do limite, anda a esquerda
        while (soma_atual > limite && esquerda <= direita) {
            soma_atual -= numeros[esquerda];
            esquerda++;
        }

        melhor_tamanho = max(melhor_tamanho, direita - esquerda + 1);
    }

    cout << melhor_tamanho << el;

    return 0;
}
