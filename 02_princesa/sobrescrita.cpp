#include <iostream>
#include <vector>
#include <numeric>

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

void show(vector<int>& fila, int sword) {
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

void matar(vector<int>& fila, int pos) {
    fila.erase(fila.begin()+pos);
}

int main() 
{
    int size{};
    cin >> size;
    int pos{};
    cin >> pos;
    vector<int> fila(size);
    iota(begin(fila), end(fila), 1);
    pos = pos - 1;
    while ((int) fila.size() != 1) {
        show(fila, pos);
        pos++;
        pos = pos % (int)fila.size();
        matar(fila, pos);
    }
    cout << fila << '\n';
}