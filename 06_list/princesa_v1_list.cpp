#include <iostream>
#include <list>
#include <numeric>

using namespace std;

ostream& operator<<(ostream& os, const list<int>& l) 
{
    os << "[ ";
    for (auto item : l) {
        os << item << " ";
    }  
    os << " ]";
    return os;
}

void show(list<int> & l, int sword) {
    cout << "[ ";
    for (auto item : l) {
        if (item == sword) {
            cout << item << "> ";    
        } else {
            cout << item << " ";
        }
    }  
    cout << " ]" << '\n';
}

int main() 
{
    int size {};
    int chosen {};
    cin >> size >> chosen;
    list<int> lista(size);
    iota(begin(lista), end(lista), 1);
    chosen = chosen - 1;
    auto sword = next(lista.begin(), chosen);
    while (lista.size() > 1) {
        show(lista, *sword);
        chosen++;
        chosen = chosen % lista.size();
        auto morto = next(lista.begin(), chosen);
        sword = next(lista.begin(), chosen+1);
        lista.erase(morto);
    }
    cout << lista << '\n';
}