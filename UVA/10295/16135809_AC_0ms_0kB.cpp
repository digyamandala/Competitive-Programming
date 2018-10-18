#include <iostream>
#include <string>

using namespace std;

struct Node
{
    string word;
    unsigned long dollar;
    int height;

    Node *left;
    Node *right;
};

int max(int x, int y)
{
    if (x > y)
    {
        return x;
    }
    return y;
}

Node *createNode(string word, double dollar)
{
    Node *curr = new Node();
    curr->word = word;
    curr->dollar = dollar;
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

Node *insertVal(Node *root, string word, double dollar)
{
    if (root == NULL)
    {
        return createNode(word, dollar);
    }

    if (word < root->word)
    {
        root->left = insertVal(root->left, word, dollar);
    }
    else
    {
        root->right = insertVal(root->right, word, dollar);
    }

    root->height = max(getHeight(root->left), getHeight(root->right)) + 1;
    int bfactor = getBalFactor(root);

    if (bfactor > 1 && word < root->left->word)
    {
        return rightRotate(root);
    }
    if (bfactor < -1 && word > root->right->word)
    {
        return leftRotate(root);
    }
    if (bfactor > 1 && word > root->left->word)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    if (bfactor < -1 && word < root->right->word)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
    return root;
}

unsigned long findDollar(Node *root, string word)
{
    if (root == NULL)
    {
        return 0;
    }
    if (word < root->word)
    {
        return findDollar(root->left, word);
    }
    if (word > root->word)
    {
        return findDollar(root->right, word);
    }
    if (word == root->word)
    {
        return root->dollar;
    }
}

int main()
{
    Node *root = NULL;
    int m, n;
    string desc;
    unsigned long total = 0;
    cin >> m >> n;
    for (int i = 0; i < m; i++)
    {
        string word;
        unsigned long dollar;
        cin >> word >> dollar;
        root = insertVal(root, word, dollar);
    }
    for(int i = 0 ; i < n ; i++){
        total = 0;
        string temp;
        while(cin >> temp && temp != "."){
            total = total + findDollar(root, temp);
        }
        cout << total << endl;
    }
    return 0;
}