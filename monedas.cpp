// Problema 2: Cambio minimo de monedas
// Se busca la menor cantidad de monedas para formar una cantidad dada.
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, cantidad;
    cout << "Cantidad de tipos de monedas: ";
    cin >> n;

    vector<int> monedas(n);
    cout << "Ingrese el valor de las monedas: ";
    for (int i = 0; i < n; i++) cin >> monedas[i];

	// Cantidad que queremos formar
    cout << "Ingrese la cantidad a formar:  ";
    cin >> cantidad;

    // Verificar que los datos sean validos
    if (n <= 0 || cantidad < 0) {
        cout << "Datos invalidos." << endl;
        return 1;
    }
    for (int i = 0; i < n; i++) {
        if (monedas[i] <= 0) {
            cout << "El valor de las monedas debe ser positiva." << endl;
            return 1;
        }
    }

	// Representa un monto que aun no se puede formar
    const int INF = 1000000000;  

    // dp[i] guarda el minimo de monedas para formar el monto i
    // ultima[i] guarda la ultima moneda utilizada
    vector<int> dp(cantidad + 1, INF);
    vector<int> ultima(cantidad + 1, 0);

    // Para formar 0 no se necesita ninguna moneda (caso base)
    dp[0] = 0;

    // Calcular el minimo de monedas para cada monto
    for (int i = 1; i <= cantidad; i++) {
        for (int j = 0; j < n; j++) {
            int c = monedas[j];
            if (c <= i && dp[i - c] != INF && dp[i - c] + 1 < dp[i]) {
                dp[i] = dp[i - c] + 1;
                ultima[i] = c;
            }
        }
    }

    // Verificar si se puede formar la cantidad
    if (dp[cantidad] == INF) {
        cout << "No se puede formar la cantidad con esas monedas." << endl;
        return 0;
    }
	
	// Mostrar la cantidad minima de monedas
    cout << "Cantidad minima de monedas: " << dp[cantidad] << endl;

    // Mostrar las monedas utilizadas
    cout << "Combinacion: ";
    int resto = cantidad;
    
    while (resto > 0) {
        cout << ultima[resto];
        resto -= ultima[resto];
        if (resto > 0) cout << " + ";
    }
    cout << endl;

	// Mostrar la tabla DP
    cout << "Tabla DP: [";
    for (int i = 0; i <= cantidad; i++) {
        if (dp[i] == INF) cout << "INF"; else cout << dp[i];
        if (i < cantidad) cout << ", ";
    }
    cout << "]" << endl;

    return 0;
}
