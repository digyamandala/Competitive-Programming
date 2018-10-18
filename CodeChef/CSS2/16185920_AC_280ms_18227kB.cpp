#include <iostream>
#include <string>
#define ull unsigned long long
using namespace std;

struct Node
{
    ull idAttr, val, priority;
    ull height;
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
ull mergeInt(ull id, ull attr){
    string p = to_string(id) + to_string(attr);
    return stoull(p);
}
Node *createNode(ull idAttr, ull val, ull priority)
{
    Node *curr = new Node();
    curr->idAttr = idAttr;
    curr->val = val;
    curr->priority = priority;
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
Node *insertVal(Node *root, ull idAttr, ull val, ull priority)
{
    if (root == NULL)
    {
        return createNode(idAttr, val, priority);
    }

    if (idAttr < root->idAttr)
    {
        root->left = insertVal(root->left, idAttr, val, priority);
    }
    else if(idAttr > root->idAttr)
    {
        root->right = insertVal(root->right, idAttr, val, priority);
    }
    else{
        if(priority >= root->priority){
            root->priority = priority;
            root->val = val;
        }
        else{
            return root;
        }
    }

    root->height = max(getHeight(root->left), getHeight(root->right)) + 1;
    int bfactor = getBalFactor(root);

    if (bfactor > 1 && idAttr < root->left->idAttr)
    {
        return rightRotate(root);
    }
    if (bfactor < -1 && idAttr > root->right->idAttr)
    {
        return leftRotate(root);
    }
    if (bfactor > 1 && idAttr > root->left->idAttr)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    if (bfactor < -1 && idAttr < root->right->idAttr)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
    return root;
}
ull findValue(Node* root, ull idAttr){
    if(root == NULL){
        return -1;
    }
    if(idAttr > root->idAttr){
        return findValue(root->right, idAttr);
    }
    if(idAttr < root->idAttr){
        return findValue(root->left, idAttr);
    }
    else{
        return root->val;
    }
}
int main()
{
    unsigned long n,m;
    Node* root = NULL;
    ull id, attr, val, priority;
    cin >> n >> m;
    while(n--){
        cin >> id >> attr >> val >> priority;
        ull temp = mergeInt(id,attr);
        root = insertVal(root, temp, val,priority);
    }
    ull x,y;
    while(m--){
        cin >> x >> y;
        ull temp = mergeInt(x,y);
        cout << findValue(root,temp) << endl;
    }
    return 0;
}