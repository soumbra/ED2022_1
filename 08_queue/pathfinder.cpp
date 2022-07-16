#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void show(vector<string> labirinto){
    for (auto line : labirinto) {
        cout << line << '\n';
    }
}

struct Pos{
    int l;
    int c;
};

vector<Pos> get_vizinhos(Pos p){
    return {{p.l, p.c - 1}, {p.l - 1, p.c}, {p.l, p.c + 1}, {p.l + 1, p.c}};
}

void retorno(vector<string> &mat, vector<vector<int>> &dist, Pos pos, int value){
    if ((mat[pos.l][pos.c] != '_') || dist[pos.l][pos.c] != value) {
        return;
    }
    mat[pos.l][pos.c] = '.';
    for (Pos viz : get_vizinhos(pos)) {
        retorno(mat, dist, viz, value - 1);
    }
}

bool procurar_saida(vector<string> &labirinto, Pos inicio, Pos fim){
    int nl = labirinto.size();
    int nc = labirinto[0].size();
    vector<vector<int>> dis(nl, vector<int>(nc, -1));
    queue<Pos> fila; 

    fila.push(inicio);
    labirinto[inicio.l][inicio.c] = '_';
    dis[inicio.l][inicio.c] = 0;
    
    while (!fila.empty()) {
        vector<Pos> vizinhos = get_vizinhos(fila.front());
        for (auto viz : vizinhos) {
            if (labirinto[viz.l][viz.c] == ' ') {
                fila.push(viz);
                labirinto[viz.l][viz.c] = '_';
                dis[viz.l][viz.c] = dis[fila.front().l][fila.front().c] + 1;
                if (viz.l == fim.l && viz.c == fim.c) {
                    retorno(labirinto, dis, fim, dis[fila.front().l][fila.front().c] + 1);
                    return true;
                }

            }
        }
        fila.pop();
    }

    return false;

}

void remove_(vector<string> &labirinto){
    int nl = labirinto.size();
    int nc = labirinto[0].size();

    for (int l = 0; l < nl; l++) {
        for (int c = 0; c < nc; c++) {
            if (labirinto[l][c] == '_') {
                labirinto[l][c] = ' ';
            }
        }
    }
}

int main(){
    int nl = 0, nc = 0;
    cin >> nl >> nc;
    vector<string> mat(nl, "");
    getchar();
    Pos inicio{}, fim{};

    for (int i = 0; i < nl; i++) {
        getline(cin, mat[i]);
    }

    for (int l = 0; l < nl; l++) {
        for (int c = 0; c < nc; c++) {
            if (mat[l][c] == 'I') {
                mat[l][c] = ' ';
                inicio = Pos {l, c};
            }
            if (mat[l][c] == 'F') {
                mat[l][c] = ' ';
                fim = Pos {l, c};
            }
        }
    }

    procurar_saida(mat, inicio, fim);
    remove_(mat);
    show(mat);
}