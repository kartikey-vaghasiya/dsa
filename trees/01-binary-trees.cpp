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

Node* constructBinaryTree(Node* node) {

    int leftData, rightData;

    cout << "data of left node of " << node -> data << ":  ";
    cin >> leftData;
    cout << endl;

    // creating left node and linking with parent node
    Node* newLeftNode = new Node(leftData);
    node -> left = newLeftNode;

    // if it's not leaf node then... 
    // call "constructBinaryTree" for "newLeftNode"
    if(leftData != -1 ) {constructBinaryTree(newLeftNode);}

    cout << "data of right node of " << node -> data << ":  ";
    cin >> rightData;
    cout << endl;

    // creating right node and linking with parent node
    Node* newRightNode = new Node(rightData);
    node -> right = newRightNode;

    // if it's not leaf node then... 
    // call "constructBinaryTree" for "newLeftNode"
    if(rightData != -1 ) {constructBinaryTree(newRightNode);}
   
    return node;
}

void inOrderDfs(Node* node){
    if ( node -> data == -1 ) { return; }
    inOrderDfs(node -> left);
    cout << "node : "<< node -> data << endl;
    inOrderDfs(node -> right);
}

void preOrderDfs(Node* node){
    if ( node -> data == -1 ) { return; }
    cout << "node : "<< node -> data << endl;
    preOrderDfs(node -> left);
    preOrderDfs(node -> right);
}

void postOrderDfs(Node* node){
    if ( node -> data == -1 ) { return; }
    postOrderDfs(node -> left);
    postOrderDfs(node -> right);
    cout << "node : "<< node -> data << endl;
}

int main() {

    // method-1 for constructing binary trees ( manually )
    Node* root = new Node();
    root -> left  = new Node(1);
    root -> right = new Node(2);

    root -> left -> left = new Node(11);
    root -> left -> right = new Node(22);

    root -> left -> left -> left = new Node(-1);
    root -> left -> left -> right = new Node(-1);

    root -> left -> right -> left = new Node(-1);
    root -> left -> right -> right = new Node(-1);

    root -> right -> left = new Node(-1);
    root -> right -> right = new Node(-1);

    // method - 2 for constructing binary trees ( user input )
    // Node* root = new Node(0);
    // constructBinaryTree(root);

    // dfs
    cout << "inorder"<< endl;
    inOrderDfs(root);
    cout << "postorder"<< endl;
    postOrderDfs(root);
    cout << "preorder"<< endl;
    preOrderDfs(root);

    return 0;
}