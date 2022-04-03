#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <ctime>

using namespace std;

ostream& operator<<(ostream& os, const vector<int>& v) 
{
    os << "[ ";
    for (int i = 0; i < (int) v.size(); i++) {
        os << v[i];
        if (i != (int) v.size() -1) {
            os << ", ";
        }
    }  
    os << " ]";
    return os;
}

vector<int> inverter_com_copia(const vector<int>& vetor) 
{
    vector<int> vetor2 = vetor;
    reverse(vetor2.begin(), vetor2.end());
    return vetor2; 
}

void inverter_inplace(vector<int>& vetor) 
{
    reverse(vetor.begin(), vetor.end());
}

int sortear(const vector<int>& vetor) 
{
    unsigned seed = time(0);
    srand(seed);
    int tamanho {(int) vetor.size()};
    int sorteio {rand()%tamanho};
    return vetor[sorteio];
}

void embaralhar(vector<int>& vetor)
{
    unsigned seed = time(0);
    srand(seed);
    random_shuffle(vetor.begin(), vetor.end());
    return;
}

void ordenar(vector<int>& vetor)
{
    sort(vetor.begin(), vetor.end());
    return;
}

int main()
{
    vector<int> fila {1, 2, -33, 10, 23, -14};
    vector<int> fila2 {1, 10, -24, 30, -1};
    cout << inverter_com_copia({1, 2, -10, -2}) << '\n';
    inverter_inplace(fila);
    cout << fila << '\n';
    cout << sortear({10, 2, 3, 30, -10, 24, 56}) << '\n';
    embaralhar(fila);
    cout << fila << '\n';
    ordenar(fila2);
    cout << fila2 << '\n';
}