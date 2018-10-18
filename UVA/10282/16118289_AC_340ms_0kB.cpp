#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
using namespace std;

struct Node{
    string key;
    string value;
    int height;
    
    Node* left;
    Node* right;
};

int max(int x, int y){
    if(x > y){
        return x;
    }
    return y;
}

Node* createNode(string key, string value){
    Node* curr = new Node();
    curr->key = key;
    curr->value = value;
    curr->height = 1;
    curr->left = NULL;
    curr->right = NULL;
    
    return curr;
}

int getHeight(Node* x){
    if(x == NULL)
        return 0;
    return x->height;
}

int getBalFactor(Node* x){
    if(x == NULL)
        return 0;
    return getHeight(x->left) - getHeight(x->right);
}

Node *rightRotate(Node *y){
    Node *x = y->left;
    Node *B = x->right;

    x->right = y;
    y->left = B;

    //MUST BE IN ORDER
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

    //return the new parent
    return x;
}

Node *leftRotate(Node *x){
    Node *y = x->right;
    Node *B = y->left;

    y->left = x;
    x->right = B;

    //MUST BE IN ORDER
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

    //return the new parent
    return y;
}

Node *insertVal(Node *root, string key, string value){
    if (root == NULL){
        return createNode(key, value);
    }

    if (key < root->key){
        root->left = insertVal(root->left, key, value);
    }
    else{
        root->right = insertVal(root->right, key, value);
    }

    root->height = max(getHeight(root->left), getHeight(root->right)) + 1;
    int bfactor = getBalFactor(root);

    if (bfactor > 1 && key < root->left->key){
        return rightRotate(root);
    }
    if (bfactor < -1 && key > root->right->key){
        return leftRotate(root);
    }
    if (bfactor > 1 && key > root->left->key){
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    if (bfactor < -1 && key < root->right->key){
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
    return root;
}

string find(struct Node *root, string key)
{
    if(root == NULL)
        return "eh";
    if(key < root->key)
        return find(root->left, key);
    if(key > root->key)
        return find(root->right, key);
    if(key == root->key)
        return root->value;
}

int main(){
    Node* root = NULL;
    string s, key, value,f;
    while(getline(cin,s) && s != ""){
        stringstream ss;
        ss << s;
        ss >> value >> key;
        root = insertVal(root,key,value);
    } 

    while(cin >> f){
        cout << find(root,f) << endl;
    }

    return 0;
}