#include <iostream>
#include <list>
#include <vector>
using namespace std;

void inicializa(list<int>& fila, int f, int size) {
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

void show_list(list<int>& l, list<int>::iterator& sword) {
    for (auto it = l.begin(); it != l.end(); it++) {
        if (*it > 0) {
            cout << " " << *it << (it == sword? "> " : " ");
        } else {
            cout << (it == sword ? "<" : "") << *it ;      
        }

    }
    cout << endl;
}

int main() {

    int size {}, sword {}, f{};
    cin >> size >> sword >> f;
    list<int> l;
    inicializa(l, f, size);

    auto it_sword = next(l.begin(), sword - 1);

    auto fix_loop = [&l](auto it) {
        return it == l.end() ? l.begin() : it;
    };

    while(l.size() > 1) {
        show_list(l, it_sword);
        if (*it_sword < 0) {
            it_sword = fix_loop(l.erase(it_sword == l.begin() ? --l.end() : --it_sword));
            if (l.begin() == it_sword) {
                it_sword = --l.end();    
            } else {
                --it_sword;
            }
        } else {
            it_sword = fix_loop(next(it_sword, 1));
            it_sword = fix_loop(l.erase(it_sword));
        }
    }
    show_list(l, it_sword);
}