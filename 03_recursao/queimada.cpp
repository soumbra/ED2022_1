#include <iostream>
#include <vector>

using namespace std;

void show(vector<string> floresta){
    for (auto line : floresta) {
        cout << line << '\n';
    }
}

void tocar_fogo(vector<string> &floresta, int lpos, int cpos){
    int nl = floresta.size();
    int nc = floresta[0].size();

    if (lpos < 0 || lpos >= nl || cpos < 0 || cpos >= nc) {
        return;
    }

    if  (floresta[lpos][cpos] != '#') {
        return;
    }

    floresta[lpos][cpos] = 'o';  
    tocar_fogo(floresta, lpos, cpos-1);
    tocar_fogo(floresta, lpos-1, cpos);
    tocar_fogo(floresta, lpos, cpos+1);
    tocar_fogo(floresta, lpos+1, cpos);
}

int main(){
    vector<string> floresta;
    int nl {}, nc {}, li {}, ci {};
    cin >> nl >> nc >> li >> ci;
    for(int l = 0; l < nl; l++){
        string line;
        cin >> line;
        floresta.push_back(line);
    }
    
    tocar_fogo(floresta, li, ci);
    show(floresta);
}