#include <iostream>
#include <vector>

using namespace std;

struct Pos{
    int l;
    int c;
};

void show(vector<string> labirinto){
    for (auto line : labirinto) {
        cout << line << '\n';
    }
}

vector<Pos> get_vizinhos(Pos p){
    return {{p.l, p.c - 1}, {p.l - 1, p.c}, {p.l, p.c + 1}, {p.l + 1, p.c}};
}

Pos inicio_fim(vector<string> &labirinto, char procurado) {
    int nl = labirinto.size();
    int nc = labirinto[0].size();

    for (int l = 0; l < nl; l++) {
        for (int c = 0; c < nc; c++) {
            if (labirinto[l][c] == procurado) {
                labirinto[l][c] = '_';
                return Pos{l, c};
            }
        }
    }

    return {-1, -1};
}

bool achar_caminho(vector<string> &labirinto, Pos inicio, Pos fim){
    if (inicio.l == fim.l && inicio.c == fim.c) {
        labirinto[inicio.l][inicio.c] = '.'; 
        return true;
    }

    if  (labirinto[inicio.l][inicio.c] != '_' ) {
        return false;
    }

    labirinto[inicio.l][inicio.c] = '.';  
    for (auto vizinho : get_vizinhos(inicio)) {
        bool valido = achar_caminho(labirinto, vizinho, fim);
        if (valido) {
            return true;
        }
    }
    labirinto[inicio.l][inicio.c] = '_';
    return false;
}

int main(){
    int nl = 0, nc = 0;
    cin >> nl >> nc;
    vector<string> labirinto(nl, "");
    getchar();
    Pos inicio, fim;

    for (int i = 0; i < nl; i++) {
        getline(cin, labirinto[i]);
    }

    inicio = inicio_fim (labirinto, 'I');
    fim = inicio_fim (labirinto, 'F');
    achar_caminho (labirinto, inicio, fim);
    show (labirinto);

    return 0;
}