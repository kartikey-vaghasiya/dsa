// implementation of binary trees
#include<bits/stdc++.h>
using namespace std;

class Node {
    public:
    int data;
    Node* left;
    Node* right;

    // constructors...
    Node(){
        this -> data = 0;
        this -> left = NULL;
        this -> right = NULL;
    }

    Node(int data) {
        this -> data = data;
        this -> left = NULL;
        this -> right = NULL;
    }
};

void constructBinaryTree() {
    // creating root node & initializing it
    // data = -1 means no node connected to the either parent's right or left side  
    // then addind nodes to the right of that node 
}

int main() {

    Node* root = new Node();
    root -> left  = new Node(1);
    root -> right = new Node(2);

    root -> left -> left = new Node(11);
    root -> left -> right = new Node(22);

    cout << "root: " << root -> data << endl;
    cout << "left of root: " << root -> left -> data << endl;
    cout << "right of root: " << root -> right -> data << endl;

    cout << "left of left of root: " << root -> left -> left -> data << endl;
    cout << "right of left of root: " << root -> left -> right -> data << endl;



    return 0;
}