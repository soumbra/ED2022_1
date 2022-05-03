#include <iostream>
#include <sstream>

using namespace std;

struct Vector{
    int capacity;
    int size;
    int * data;
};

Vector * vector_create(int capacity){
    //crie um vetor dinâmicamente
    //cria a struct
    //crie o vetor data
    //inicialize size e capacity
    Vector *vetor = new(Vector);
    vetor->data = new int[capacity];
    vetor->size = 0;
    vetor->capacity = capacity;
    return vetor; 
}

void vector_destroy(Vector * vector){
    //destrua data
    //destrua a struct
    delete[] vector->data;
    delete[] vector;
}

void vector_add(Vector * vector, int value){
    //utilize capacity e size para verificar se ainda existe espaço
    if (vector->size < vector->capacity) {
        vector->data[vector->size] = value;
        vector->size+=1;
    }
}

//retorne a string no formato 
// [ a b c ]
string vector_show(Vector * vector){
    //retorne uma string com os dados do vetor
    //você pode usar uma stringstream como buffer
    //stringstream ss;
    //ss << 5 << " eh inteiro";
    //ss.str() será "5 eh inteiro"
    stringstream ss;
    ss << '[';
    for (int i = 0; i < vector->size; i++) {
        ss << " " << vector->data[i];
    }
    ss << " ]";
    return ss.str();
}

int main(){
    string line, cmd;
    int value;
    Vector * v = vector_create(0);
    while(true){
        getline(cin, line);
        cout << "$" << line << endl;
        stringstream ss(line);
        ss >> cmd;
        if(cmd == "end"){
            break;
        } else if(cmd == "init"){
            ss >> value;
            if(v != nullptr)
                vector_destroy(v);
            v = vector_create(value);
        } else if(cmd == "status"){
            cout << "size:" << v->size << " capacity:" << v->capacity << "\n";
        } else if(cmd == "add"){
            while(ss >> value)
                vector_add(v, value);
        } else if(cmd == "show"){
            cout << vector_show(v) << endl;
        } else {
            cout << "fail: comando invalido\n";
        }
    }
    vector_destroy(v);
}