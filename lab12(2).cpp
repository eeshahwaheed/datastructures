#include <iostream>
using namespace std;

struct Node 
{
    int data;
    Node* left;
    Node* right;
};

Node* newNode(int data) 
{
    Node* node = new Node();
    node->data = data;
    node->left = node->right = NULL;
    return node;
}


void inorder(Node* root) 
{
    if (root != NULL) 
	{
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}


void preorder(Node* root) 
{
    if (root != NULL) 
	{
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }
}


void postorder(Node* root) 
{
    if (root != NULL) 
	{
        postorder(root->left);
        postorder(root->right);
        cout << root->data << " ";
    }
}

int main() 
{
    Node* root = newNode(6);
    root->left = newNode(3);
    root->right = newNode(10);
    root->left->left = newNode(2);
    root->left->right = newNode(5);

    cout << "Inorder: ";
    inorder(root);

    cout << "\nPreorder: ";
    preorder(root);

    cout << "\nPostorder: ";
    postorder(root);

    return 0;
}
