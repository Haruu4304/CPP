/*
here we are calculating height of binary tree using recursion - 
*/

#include<bits/stdc++.h>
using namespace std;

struct node {
    int value;
    node* left;
    node* right;
};

// Helper to create new node
node* createNode(int val) {
    node* newNode = new node();
    newNode->value = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Insert in BST style
node* insert(node* root, int val) {
    if (root == NULL) {
        return createNode(val);
    }
    if (val < root->value) {
        root->left = insert(root->left, val);
    } else {
        root->right = insert(root->right, val);
    }
    return root;
}

// Inorder Traversal to check
void inorder(node* root) {
    if (root == NULL) return;
    inorder(root->left);
    cout << root->value << " ";
    inorder(root->right);
}

//recursive function - to get height of tree : 
int height(node *root){
    //base condition - 
    if(root == NULL){
        return 0;
    }
    //hypothesis method - 
    int lh = height(root -> left);
    int rh = height(root -> right);

    //induction method - 
    return(1+max(lh,rh));
}


int main() {
    int n;
    cin >> n;

    node* root = NULL;

    cout << "Enter " << n << " values:\n";
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        root = insert(root, val);
    }

    cout << "Inorder Traversal: ";
    inorder(root);
    cout << endl;

    //recursive call
    int Treeheight = height(root);
    cout << "Height of tree is : " << endl;
    cout << Treeheight;

    return 0;
}
