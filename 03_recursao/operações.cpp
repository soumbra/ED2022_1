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

void imprimir(vector<int> v, int size) {
    if (size == 1) {
        cout << v[size-1];
    } else {
        imprimir(v, size - 1);
        cout << v[size-1] << ((size != (int)v.size() ) ? ", " : " ");
    }
}

void inverter(vector<int> v, int size, int i = -1) {
    if (i == (size-1)) {
        return;
    } else {
        i++;
        inverter(v, size, i);
        cout << v[i] << ((i != 0) ? ", " : " ");
    }
}

int soma(vector<int> v, int size) {
    if (size == 1) {
        return v[0];
    }

    return soma(v, size - 1) + v[size - 1];
}

int multiplica(vector<int> v, int size) {
    if (size == 1) {
        return v[0];
    } 

    return multiplica(v,size - 1) * v[size - 1];
}

int menor(vector<int> v,int i = 0, int menor_num = 0) {
    if (i == (int)v.size()) {
        return menor_num;
    }
    if (v[i] < menor_num || i == 0) {
        menor_num = v[i];
    }

    i++;
    return menor(v, i, menor_num);
}


void inv(vector<int> &v, int size, int i = 0, int contador = 1) {
    if (i == (size)/2) {
        cout << v << '\n';
        return;
    } else {
        int auxilio_emergencial {v[i]};
        v[i] = v[(size - contador)];
        v[(size - contador)] = auxilio_emergencial;
        contador++;
        i++;
        inv(v, size, i, contador);
    }

}

int main() {
    vector<int> vetor{1 ,2 ,-3 ,4 ,41 ,6 ,70};
    imprimir(vetor, (int)vetor.size());
    cout << '\n';
    inverter(vetor, (int)vetor.size());
    cout << '\n';
    cout << soma(vetor, (int)vetor.size()) << '\n';
    cout << multiplica(vetor, (int)vetor.size()) << '\n';
    cout << menor(vetor) << '\n';
    inv(vetor, (int)vetor.size());
}