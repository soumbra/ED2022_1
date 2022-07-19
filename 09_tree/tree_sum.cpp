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

    int somar(Node * root) {
        if (root == nullptr) {
            return 0;
        }
        return root->value + somar(root->left) + somar(root->right);
    }

    int min(Node * root) {
        int menor = root->value;
        int menor_right{2147483647};
        int menor_left{2147483647};

        if (root->left == nullptr && root->right == nullptr) {
            return root->value;
        }

        if (root->left != nullptr) {
            menor_left = min(root->left);       
        }

        if (root->right != nullptr) {
            menor_right = min(root->right);
        }

        if (menor_right <= menor_left && menor_right <= root->value) {
            menor = menor_right;
        } else if(menor_left <= menor_right && menor_left <= root->value) {
            menor = menor_left;
        } else {
            menor = root->value;
        }

        return menor;
    }
};

int main(){
    string line;
    getline(cin, line);
    BTree bt(line);
    cout << bt.somar(bt.root) << " " << bt.min(bt.root) << '\n';
}