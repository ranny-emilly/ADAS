#include <bits/stdc++.h>
using namespace std;

int main () {
ios_base::sync_with_stdio(false);
cin.tie(nullptr);
int n;
cin >> n;
 vector<int> vec(n);
    for (int i = 0; i < n; i++) {
        cin >> vec[i];
    }

for (int i = 1; i < n; i++) {
        // Verifica se é maior ou igual ao anterior
        if (vec[i] >= vec[i - 1]) {
            // Verifica se existe o próximo elemento antes de testar a condição dele
            if (i + 1 < n) {
                if (vec[i] >= vec[i + 1]) {
                    cout << i << '\n';
                    return 0;
                }
            }
        }
    }

    return 0;
}