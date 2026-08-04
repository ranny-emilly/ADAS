#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[]) {
    unsigned seed = chrono::steady_clock::now().time_since_epoch().count();
    if (argc >= 2) seed = stoul(argv[1]);
    mt19937 rng(seed);

    // Seleciona um tipo de cenário de teste aleatoriamente (0 a 4)
    int tipo_cenario = uniform_int_distribution<int>(0, 4)(rng);
    
    // N pequeno (1 a 10) aumenta a chance de repetir números e criar padrões específicos
    int n = uniform_int_distribution<int>(1, 10)(rng);
    cout << n << '\n';

    vector<int> vec(n);

    if (tipo_cenario == 0) {
        // Cenário 1: Totalmente aleatório (igual ao seu original)
        for (int i = 0; i < n; i++) {
            vec[i] = uniform_int_distribution<int>(-30, 30)(rng);
        }
    } 
    else if (tipo_cenario == 1) {
        // Cenário 2: Todos os números rigorosamente iguais (testa limites >= ou <=)
        int valor_unico = uniform_int_distribution<int>(-30, 30)(rng);
        for (int i = 0; i < n; i++) {
            vec[i] = valor_unico;
        }
    } 
    else if (tipo_cenario == 2) {
        // Cenário 3: Vetor ordenado Crescente
        int atual = uniform_int_distribution<int>(-30, 0)(rng);
        for (int i = 0; i < n; i++) {
            atual += uniform_int_distribution<int>(0, 5)(rng); // garante que sobe ou empata
            vec[i] = atual;
        }
    } 
    else if (tipo_cenario == 3) {
        // Cenário 4: Vetor ordenado Decrescente
        int atual = uniform_int_distribution<int>(0, 30)(rng);
        for (int i = 0; i < n; i++) {
            atual -= uniform_int_distribution<int>(0, 5)(rng); // garante que desce ou empata
            vec[i] = atual;
        }
    }
    else {
        // Cenário 5: Elementos alternando (Zigue-zague)
        for (int i = 0; i < n; i++) {
            vec[i] = (i % 2 == 0) ? 20 : -20;
        }
    }

    // Imprime o vetor gerado
    for (int i = 0; i < n; i++) {
        cout << vec[i] << (i + 1 == n ? '\n' : ' ');
    }

    return 0;
}
