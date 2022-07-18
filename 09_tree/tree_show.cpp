#include <iostream>
#include <sstream>
using namespace std;

struct Node{
    int value;
    Node * left;
    Node * right;

    Node(int value = 0, Node * left = nullptr, Node * right = nullptr): value(value), left(left), right(right){}

};

struct BTree{
    Node * root {nullptr};
    BTree(){
    }

    Node* criar(stringstream& ss) {
        string data;
        ss >> data;

        if (data == "#") {
            return nullptr;
        } 

        int value{};
        stringstream(data) >> value;

        Node * node = new Node(value);
        node->left = criar(ss);
        node->right = criar(ss);
        return node;
    }

    BTree(string serial){
        stringstream ss(serial);
        root = criar(ss);
    }

    ~BTree(){
        __destroy(this->root);
    }

    void __destroy(Node * node){
        if (node == nullptr) {
            return;
        }

        __destroy(node->left);
        __destroy(node->right);
        delete node;
    }
    
    void percorre(Node * node, stringstream& ss, int tab) {
        if (node == nullptr) {
            ss << string(tab * 4, '.') << '#' << '\n';
            return;
        }

        if (node->left == nullptr && node->right == nullptr) {
            ss << string(tab * 4, '.') << node->value << '\n';
        } else {
            percorre(node->left, ss, tab + 1);
            ss << string(tab * 4, '.') << node->value << '\n';
            percorre(node->right, ss, tab + 1);
        }
    }

    string str() {
        stringstream ss;
        percorre(root, ss, 0);
        return ss.str();
    }
};

int main(){
    string line;
    getline(cin, line);
    BTree bt(line);
    cout << bt.str() << '\n';
}