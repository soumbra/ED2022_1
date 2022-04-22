#include <iostream>
#include <ctime>

using namespace std;

bool procura_valido(string& linha) {
    for (auto caractere : linha) {
        if (caractere == '.') {
            cout << "Com esse limite nao eh possivel preencher a linha" << '\n';
            return false;
        }
    }
    cout << "Limite valido" << '\n';
    return true;
}

bool pode_inserir(string& linha, int indice, int valor, int proximidade) {
    for (int i = indice + 1; i < indice + 1 + proximidade; i++) {
        if (i < (int)linha.size() && linha[i] ==  valor + '0') {
            return false;
        }
    }

    for (int i = indice - proximidade; i < indice; i++) {
        if (i >= 0 && linha[i] == '0' + valor) {
            return false;
        }
    }

    return true;
}

bool preencher(string& linha, int indice, int limite, int proximidade) {
    if ((int)linha.size() == indice) {
        return true;
    }

    if (linha[indice] != '.') {
        return preencher(linha, indice + 1, limite, proximidade);
    }

    for (int valor = 0; valor <= limite; valor++) {
        if (pode_inserir(linha, indice, valor, proximidade)) {
            linha[indice] = valor + '0';
            cout << linha << '\n';
            if (preencher(linha, indice + 1, limite, proximidade)) {
                return true;
            }
        }
    }

    linha[indice] = '.';
    cout << linha << '\n';
    return false;

}

int main()
{
    string linha;
    int proximidade{0};
    cin >> linha >> proximidade;
    
    //Brincando de sortear o limite
    srand((unsigned)time(0));
    int limite = rand()%(10-0)+1;

    preencher(linha, 0, limite, proximidade);
    cout << linha << '\n';
    cout << "Limite: " << limite << " " << procura_valido(linha);

}