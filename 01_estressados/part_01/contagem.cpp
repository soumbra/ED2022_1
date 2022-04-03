#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std; 

float calcular_stress_medio(vector<int> fila)
{
    int acumulador{0};
    for (int i = 0; i < (int) fila.size(); i++) {
        acumulador += abs(fila[i]);
    }
    float media_stress {(float) acumulador/fila.size()};
    return media_stress;
}

string mais_homens_ou_mulheres(vector<int> fila) 
{
    int homens {0}, mulheres{0};
    for (int i = 0; i < (int) fila.size(); i++) {
        if (fila[i] > 0) {
            homens++;
        } else {
            mulheres++;
        }
    }
    if (homens > mulheres) {
        return "homens";
    } else if (mulheres > homens) {
        return "mulheres";
    }
    return "empate";
}

vector<int> absVector(vector<int> fila) {
    vector<int> copia;
    for (auto num : fila) {
        copia.push_back(abs(num)); 
    }
    return copia;
}

string qual_metade_eh_mais_estressada(vector<int> fila) {
    int contador = (int)fila.size()/2;
    vector<int> copia = absVector(fila);

    int primeira {accumulate(copia.begin(), copia.begin()+contador, 0)};
    int segunda {accumulate(copia.begin()+((int)fila.size() - contador), copia.end(), 0)};
    if (primeira > segunda) {
        return "primeira";
    } else if(segunda > primeira) {
        return "segunda";
    }

    return "empate";
    
}

bool homens_sao_mais_estressados_que_mulheres (vector<int> fila) {
    int homens {0}, mulheres {0}, conta_homens {0}, conta_mulheres{0};
    for (int i = 0; i < (int) fila.size(); i++) {
        if (fila[i] > 0) {
            homens += fila[i];
            conta_homens++;
        } else {
            mulheres += -fila[i];
            conta_mulheres++;
        }
    }
    float media_stress_homens {(float) homens/conta_homens};
    float media_stress_mulheres {(float) mulheres/conta_mulheres};
    if(media_stress_homens > media_stress_mulheres){
        return true;
    }
    return false;
}

int main()
{
    cout << calcular_stress_medio({5, 3, -6, -50, -1, -99}) << '\n';
    cout << mais_homens_ou_mulheres({5, 3, 1, -50, -1, 99}) << '\n';
    cout << qual_metade_eh_mais_estressada({5, -6, 10, -4}) << '\n';
    cout << homens_sao_mais_estressados_que_mulheres({5, 4, -7, -3}) << '\n';

}