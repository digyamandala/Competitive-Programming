#include <iostream>
#include <string>
#include <fstream>
#include <string.h>

using namespace std;
struct Node
{
    // char key[10];
    string key;
    int value;
    int height;

    Node *left;
    Node *right;
};
// Node* root = NULL;
int max(int x, int y)
{
    if (x > y)
    {
        return x;
    }
    return y;
}

Node *createNode(string key, int value)
{
    Node *curr = new Node();
    curr->key = key;
    curr->value = value;
    curr->height = 1;
    curr->left = NULL;
    curr->right = NULL;

    return curr;
}

int getHeight(Node *x)
{
    if (x == NULL)
        return 0;
    return x->height;
}

int getBalFactor(Node *x)
{
    if (x == NULL)
        return 0;
    return getHeight(x->left) - getHeight(x->right);
}

Node *rightRotate(Node *y)
{
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

Node *leftRotate(Node *x)
{
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

Node *insertVal(Node *root, string key, int value)
{
    if (root == NULL)
    {
        return createNode(key, value);
    }

    if (key < root->key)
    {
        root->left = insertVal(root->left, key, value);
    }
    else
    {
        root->right = insertVal(root->right, key, value);
    }

    root->height = max(getHeight(root->left), getHeight(root->right)) + 1;
    int bfactor = getBalFactor(root);

    if (bfactor > 1 && key < root->left->key)
    {
        return rightRotate(root);
    }
    if (bfactor < -1 && key > root->right->key)
    {
        return leftRotate(root);
    }
    if (bfactor > 1 && key > root->left->key)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    if (bfactor < -1 && key < root->right->key)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
    return root;
}
Node* words = NULL;
void makeWords(){
    string s = " ";
    int count = 1;
    int l = s.length();
    for (s[0] = 'a'; s[0] <= 'z'; s[0]++){
        words = insertVal(words, s, count);
        count++;
    }
    s.push_back(' ');
    for (s[0] = 'a'; s[0] <= 'z'; s[0]++){
        for (s[1] = s[0] + 1; s[1] <= 'z'; s[1]++){
            words = insertVal(words, s, count);
            count++;
        }
    }
    s.push_back(' ');
    for (s[0] = 'a'; s[0] <= 'z'; s[0]++){
        for (s[1] = s[0] + 1; s[1] <= 'z'; s[1]++){
            for (s[2] = s[1] + 1; s[2] <= 'z'; s[2]++){
                words = insertVal(words, s, count);
                count++;
            }
        }
    }
    s.push_back(' ');
    for (s[0] = 'a'; s[0] <= 'z'; s[0]++){
        for (s[1] = s[0] + 1; s[1] <= 'z'; s[1]++){
            for (s[2] = s[1] + 1; s[2] <= 'z'; s[2]++){
                for (s[3] = s[2] + 1; s[3] <= 'z'; s[3]++){
                    words = insertVal(words, s, count);
                    count++;
                }
            }
        }
    }
    s.push_back(' ');
    for (s[0] = 'a'; s[0] <= 'z'; s[0]++){
        for (s[1] = s[0] + 1; s[1] <= 'z'; s[1]++){
            for (s[2] = s[1] + 1; s[2] <= 'z'; s[2]++){
                for (s[3] = s[2] + 1; s[3] <= 'z'; s[3]++){
                    for (s[4] = s[3] + 1; s[4] <= 'z'; s[4]++){
                        words = insertVal(words, s, count);
                        count++;
                    }
                }
            }
        }
    }
}

int findValue(Node* root, string key){
    if(root == NULL){
        return 0;
    }
    if(key < root->key){
        return findValue(root->left, key);
    }
    if(key > root->key){
        return findValue(root->right, key);
    }
    if(key == root->key){
        return root->value;
    }
}

int main(){
    makeWords();
    string k;
    while (cin >> k){
        cout << findValue(words,k) << endl;
    }
    return 0;
}