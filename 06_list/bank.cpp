#include <iostream>
#include <list>
#include <vector>
#include <queue>
#include <sstream>

using namespace std;

struct Client{
    string name;
    int docs;
    int patience;
    Client(string _name, int _actions, int _patience){
        this->name = _name;
        this->docs = _actions;
        this->patience = _patience;
    }
    string str(){
        return name + ":" + to_string(docs) + ":" + to_string(patience);
    }
};

struct Banco{
    vector<Client*> teller; //caixas
    list<Client*> queue_in; //fila de entrada
    list<Client*> queue_out;//fila de saida
    int received {0};       //documentos processados
    int lost {0};           //documentos perdidos
    int tics {0};           //quantidade de tempo que passou


    //iniciliza so caixas
    Banco(int teller_size) : teller(teller_size, nullptr){ 
        //(teller_size, nullptr);
    }

    //insere cliente na fila de entrada
    void insert(Client * client) { 
        queue_in.push_back(client);
    }

    //esta vazio se não tem ninguém no banco
    bool empty() { 
        if(queue_in.empty()) {
            return true;
        }    
        return false;
    }

    //roda o algoritmo de passagem de tempo
    void tic() {
        if (!queue_out.empty()) {
            for (auto it = queue_out.begin(); it != queue_out.end(); it++) {                      
                auto backup = it;             
                it = this->queue_out.erase(it);               
                delete *backup;
            }
        }
        
        for (auto &elem : teller) {
            if (elem != nullptr) {
                if (elem->docs != 0) {
                    elem->docs--;
                    this->received++;
                } else {
                    queue_out.push_back(elem);
                    elem = nullptr;
                }
            } else {
                if (!queue_in.empty()) {
                    elem = queue_in.front();
                    queue_in.pop_front();
                }
            }
        }
        auto it = this->queue_in.begin(); 
        while (it != this->queue_in.end()) {
            if ((*it)->patience > 0) {
                (*it)->patience--;
                ++it;
            } else {
                auto client = *it;
                queue_out.push_back(client);
                it = queue_in.erase(it);
                this->lost++;                
            }
        }
        this->tics++;             
    }
    //mostra o banco
    void show_all(){
        for(auto client : teller){
            cout << "[" << (client == nullptr ? "" : client->str()) << "]";
        }
        cout << "\nin :{ ";
        for(auto client : queue_in)
            cout << client->str() << " ";
        cout << "}\nout:{ ";
        for(auto client : queue_out)
            cout << client->str() << " ";
        cout << "}\n";
    }
};

int main(){
    Banco banco(3);

    while(true){
        string line, cmd;
        getline(cin, line);
        cout << "$" << line << "\n";
        stringstream ss(line);
        ss >> cmd;
        if (cmd == "end"){
            break;
        }
        if (cmd == "show"){
            banco.show_all();
        }else if(cmd == "in"){
            string name;
            int docs, patience;
            ss >> name >> docs >> patience;
            banco.insert(new Client(name, docs, patience));
        }else if (cmd == "init"){
            int size;
            ss >> size;
            banco = Banco(size);
        }else if (cmd == "tic"){
            banco.tic();
        }else if (cmd == "finish"){
            while (!banco.empty())
                banco.tic();
            cout << "received: " << banco.received << endl;
            cout << "lost: " << banco.lost<< endl;
            cout << "tics: " << banco.tics << endl;
        }else{
            cout << "fail: command not found\n";
        }
    }
}