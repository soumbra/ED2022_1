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

void inicializa(vector<int>& fila, int f, int size) {
    if (f < 0) {
        int contador{1};
        for (int i = 0; i < size; i++) {
            if (contador%2 == 0) {
                fila.push_back(contador);
            } else {
                fila.push_back(-contador);
            }
            contador++;
        }   
    } else {
        int contador{1};
        for (int i = 0; i < size; i++) {
            if ((contador%2) == 0) {
                fila.push_back(-contador);
            } else {
                fila.push_back(contador);
            }
            contador++;
        }   
    }
}

void show(vector<int>& fila, int sword) {
    cout << "[ ";
    for (int i = 0; i < (int) fila.size(); i++) {
        if (i == sword && fila[i] > 0) {
            cout << fila[i] << '>';
        } else if (i == sword && fila[i] < 0) {
            cout << "<" << fila[i];
        } else {
            cout << fila[i];
        }

        if (i != (int) fila.size() -1) {
            cout << ", ";
        }
    }  
    cout << " ]" << '\n'; 
}

void matar(vector<int>& fila, int pos) {
    fila.erase(fila.begin()+pos);
}

int main() 
{
    int size{};
    int pos{};
    int f{};
    cin >> size >> pos >> f;
    vector<int> fila;
    inicializa(fila, f, size);
    pos = pos - 1;

    while ((int) fila.size() != 1) {
        if(pos < 0) {
            pos = (int)fila.size()-1;
        }
        show(fila, pos);
        pos = pos % (int)fila.size();
        if (fila[pos] < 0) {
            if (pos-1 < 0) {
                matar(fila, (int)fila.size()-1);
                pos = (int)fila.size()-1;
            } else {
                pos--;
                matar(fila, pos);
                pos--;
                pos = pos % (int)fila.size();
            }
        } else {
            pos++;
            pos = pos % (int)fila.size();
            matar(fila, pos);    
        }
    }
    cout << fila << '\n';
}