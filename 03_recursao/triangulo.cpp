#include <iostream>
#include <vector>

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

void triangulo(vector<int> v) {
    if (v.size() == 1) {
        return;
    }

    vector<int> somados;
    for (int i = 0; i < (int)v.size()-1; i++) {
        somados.push_back(v[i]+v[i+1]);
    }
    triangulo(somados);
    cout << somados << '\n';
}

int main () 
{
    vector<int> v{1, 2, 3, 7, 8};
    triangulo(v);
    cout << v << '\n';
    return 0;
}