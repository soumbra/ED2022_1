#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

int procurar_menor(vector<int> fila) { 
    return *min_element(fila.begin(), fila.end());
}

int procurar_pos_menor(vector<int>fila) {
    int menor = procurar_menor(fila);
    for (int i = 0; i < (int)fila.size(); i++) {
        if (fila[i] == menor) {
            return i;
        }
    } 
    return -1;
}

int procurar_pos_menor_apartir(vector<int> fila, int inicio) {
    int menor = *min_element(fila.begin()+inicio, fila.end());
    for (int i = inicio; i < (int)fila.size(); i++) {
        if (fila[i] == menor) {
            return i;
        }
    } 
    return -1;
}

int procurar_melhor_se(vector<int> vetor)
{
    int contador {-1}, mais_calmo{100};
    for (int i = 0; i < (int) vetor.size(); i++) {
        if (vetor[i] > 0 && vetor[i] < mais_calmo) {
            contador = i;
            mais_calmo = vetor[i];
        }
    }
    return contador;
}

int procurar_melhor_pos_se(vector<int> fila) {
    int contador {-1}, mais_calmo{100};
    for (int i = 0; i < (int) fila.size(); i++) {
        if (fila[i] > 0 && fila[i] < mais_calmo) {
            contador = i;
            mais_calmo = fila[i];
        }
    }
    return contador;
}

int main() 
{
    cout << procurar_menor({5, 3, -1, -50, -1, -99}) << '\n';
    cout << procurar_pos_menor({5, 3, -1, -99, -1, -90}) << '\n';
    cout << procurar_pos_menor_apartir({5, 3, -1, -50, -1, 10}, 3) << '\n';
    cout << procurar_melhor_pos_se({5, 3, -1, -99, 1, -90}) << '\n';
}