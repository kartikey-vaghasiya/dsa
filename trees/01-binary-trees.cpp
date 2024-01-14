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

int main() {

    // Method - 1
    // Node* root = new Node();
    // root -> left  = new Node(1);
    // root -> right = new Node(2);

    // root -> left -> left = new Node(11);
    // root -> left -> right = new Node(22);

    // cout << "root: " << root -> data << endl;
    // cout << "left of root: " << root -> left -> data << endl;
    // cout << "right of root: " << root -> right -> data << endl;

    // cout << "left of left of root: " << root -> left -> left -> data << endl;
    // cout << "right of left of root: " << root -> left -> right -> data << endl;

    // Method - 2
    Node* root = new Node(0);
    constructBinaryTree(root);

    return 0;
}