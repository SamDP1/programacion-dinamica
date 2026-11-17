// Problema 1: Escaleras
// Se puede subir 1 o 2 escalones por paso. 
// Se calcula de cuántas formas se llega al escalón N.
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cout << "Numero de escalones (N): ";
    cin >> n;

    // Verifica que el numero de escalones no sea negativo
    if (n < 0) {
        cout << "Entrada invalida: N debe ser 0 o mayor." << endl;
        return 1;
    }

    // dp[i] guarda las formas de llegar al escalon i
    vector<long long> dp(n + 1);

    // Casos base
    dp[0] = 1;
    if (n >= 1) dp[1] = 1;

    // Calcular las formas de llegar a cada escalon
    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    // Mostrar resultados y la tabla DP
    cout << "Formas posibles: " << dp[n] << endl;
    cout << "Tabla DP: [";
    for (int i = 0; i <= n; i++) {
        cout << dp[i];
        if (i < n) cout << ", ";
    }
    cout << "]" << endl;

    return 0;
}
