#include <bits/stdc++.h>
using namespace std;

#define el "\n"
#define _ ios_base::sync_with_stdio(0); cin.tie(0);

long long calcular_mdc(long long a, long long b) {
    // euclides para mdc
    while (b != 0) {
        long long resto = a % b;
        a = b;
        b = resto;
    }

    return abs(a);
}

int main() {
    _

    // mdc e mmc
    long long a, b;
    cin >> a >> b;

    long long mdc = calcular_mdc(a, b);
    long long mmc = 0;

    // evita divisao por zero
    if (mdc != 0) {
        mmc = abs((a / mdc) * b);
    }

    cout << "mdc = " << mdc << el;
    cout << "mmc = " << mmc << el;

    return 0;
}
