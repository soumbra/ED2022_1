#include <iostream>
#include <vector>
#include <algorithm>

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

vector<int> exclusivos(const vector<int>& vetor)
{
    vector<int> vetor_copia = vetor;
    sort(vetor_copia.begin(), vetor_copia.end());
    auto it = unique(vetor_copia.begin(), vetor_copia.end());
    vetor_copia.resize(distance(vetor_copia.begin(), it));
    return vetor_copia;
}

vector<int> absVector(vector<int> fila) {
    vector<int> copia;
    for (auto num : fila) {
        copia.push_back(abs(num)); 
    }
    return copia;
}

vector<int> diferentes(const vector<int>& vetor) 
{
    vector<int> vetor_copia {absVector(vetor)};
    sort(vetor_copia.begin(), vetor_copia.end());
    auto it = unique(vetor_copia.begin(), vetor_copia.end());
    vetor_copia.resize(distance(vetor_copia.begin(), it));
    return vetor_copia;
}

vector<int> abandonados(const vector<int>& vetor) 
{
    vector<int> vetor_copia;
    bool check {false};
    for (int j = 0; j < (int)vetor.size(); j++) {
        for (int i = 0; i < j; i++) {
            if (vetor[i] == vetor[j]) {
                check = true;
                break;
            }
        }
        if (check == true) {
            vetor_copia.push_back(vetor[j]);
            check = false;
        }
    }
    return vetor_copia;
}

int main()
{
    cout << exclusivos({1, 3, 4, 3, -1, -2, -2}) << '\n';
    cout << diferentes({1, 3, 4, 3, 5, -1, -2, -2}) << '\n';
    cout << abandonados({1, 3, 4, 3, -1, -2, -2}) << '\n';
}