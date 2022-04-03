#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

/*int contar(vector<int> fila, int x) {
    int contador{0};
    for (auto& num : fila) {
        if (num == x) {
            contador++;
        }
    }
    return contador;
}*/

int contar(vector<int> fila, int x) {
    int myCount{count(fila.begin(), fila.end(), x)};
    return myCount;
}

bool existe(vector<int> fila, int x) {
    for (auto& num : fila) {
        if (num == x) {
            return true;
        }
    }
    return false;
}

int procurar(vector<int> fila, int x) {
    for (int i = 0; i < (int) fila.size(); i++) {
        if (fila[i] == x) {
            return i;
        }
    }
    return -1;
}

int procura_valor(vector<int> fila, int x, int inicio) {
    for (int i = inicio; i < (int) fila.size(); i++) {
        if (fila[i] == x) {
            return i;
        }
    }
    return -1;
}


int main() 
{
    //vector<int> fila {1, 3, 5};
    cout << existe({1, 3, 5}, 3) << '\n';
    cout << contar({1, 1, 4, 1}, 1) << '\n';
    cout << procurar({-1, -50, -1 -99}, -50) << '\n';
    cout << procura_valor({5, 3, -1, -50, -1, -99}, -1, 3) <<  '\n';
    /*while(true) {
        string line;
        getline(cin, line);
        stringstream ss(line);
        string cmd;
        ss >> cmd;

        if (cmd == "exit") {
            break;
        } else if ("existe") {

        }
    }*/

}