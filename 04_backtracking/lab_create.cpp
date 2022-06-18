#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;
using matrix = vector<string>;

struct Pos {
    int l;
    int c;
    Pos(int l, int c) : l(l), c(c) {};
};

vector<Pos> get_vizinhos(Pos p){
    return {{p.l, p.c - 1}, {p.l - 1, p.c}, {p.l, p.c + 1}, {p.l + 1, p.c}};
}

vector<Pos> shuffle(vector<Pos> vet) {
    random_shuffle(begin(vet), end(vet));
    return vet;
}

/*bool pode_furar(posicao):
    se quantidade de vizinhos com paredes menor que 3
        retorne false
    retorne true*/
bool pode_furar(matrix& mat, Pos p) {
    int nl = mat.size();
    int nc = mat[0].size();
    int contador{0};

    for (auto vizinho : get_vizinhos(p)) {
        auto [l, c] = vizinho;
        if (l < 0 || l >= nl || c < 0 || c >= nc) {
            continue;
        }
        if (mat[vizinho.l][vizinho.c] == '#') {
            contador += 1;
        }
    }

    if (contador >= 3) {
        return true;
    }

    return false;
}
/*void derrubar_parede(mat, posicao):
    if pode_furar(posicao)
        matriz nessa posicao = ' '
    crie um vetor com os vizinhos
    embaralhe o vetor de vizinho
    chama derrubar_parede para todos os vizinhos
*/
void derrubar_parede(matrix& mat, Pos p) {
    int nl = mat.size();
    int nc = mat[0].size();
    auto [l, c] = p;

    if (l < 0 || l >= nl || c < 0 || c >= nc) {
        return;
    }

    if (!pode_furar(mat, p)) {
        return;
    }
    
    if (mat[l][c] != '#') {
        return;
    }
    mat[l][c] = '.';

    for (auto vizinho : shuffle(get_vizinhos(p))) {
        derrubar_parede(mat, vizinho);
    }

    mat[l][c] = ' ';
}

void show(matrix mat) {
    for (auto line : mat)
        cout << line << '\n';
}

int main(int argc, char * argv[]) {
    if (argc != 3) {
        cout << "Numero de argumentos invalidos\n";
        cout << "./executavel nl nc\n";
        exit(1);
    }
    int nl { 0 }, nc { 0 };
    stringstream(argv[1]) >> nl;
    stringstream(argv[2]) >> nc;
    vector<string> mat(nl, string(nc, '#'));

    derrubar_parede(mat, Pos(1, 1));
    show(mat);
}