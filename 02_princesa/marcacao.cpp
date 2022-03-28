#include <iostream>
#include <vector>

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

ostream& operator<<(ostream& os, const vector<bool>& v) 
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

int procurar_vivos(vector<bool> &vetor, int pos) {
    for (int i = (pos+1); i <= (int)vetor.size(); i++) {
        //i++;
        i = i % (int)vetor.size();
        if (vetor[i] == true) {
            return i;
        }
    }
    return 0;
}

void show(vector<bool>& fila, int sword) {
    cout << "[ ";
    for (int i = 0; i < (int) fila.size(); i++) {
        if (i == sword%(int)fila.size()) {
            cout << fila[i] << '>';
        } else {
            cout << fila[i];
        }
        if (i != (int) fila.size() -1) {
            cout << ", ";
        }
    }  
    cout << " ]" << '\n'; 
}

int main() 
{
    int size{};
    cin >> size;
    vector<bool> vet(size, true);
    int sword {};
    cin >> sword;
    sword = sword - 1;
    show(vet, sword);
    int qtd = size - 1;
    while (qtd--) {
        int to_die {procurar_vivos(vet, sword)};
        vet[to_die] = false;
        sword = procurar_vivos(vet, to_die);
        show(vet, sword);
    }
    //cout << vet << '\n';
}