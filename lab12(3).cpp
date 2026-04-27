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


Node* insert(Node* root, int data) 
{
    if (root == NULL)
        return newNode(data);

    if (data < root->data)
        root->left = insert(root->left, data);
    else
        root->right = insert(root->right, data);

    return root;
}


void inorder(Node* root)
 {
    if (root != NULL) {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

int main() 
{
    Node* root = NULL;

    int values[] = {45, 25, 65, 10, 30};

    for (int i = 0; i < 5; i++) {
        root = insert(root, values[i]);

        cout << "After inserting " << values[i] << ": ";
        inorder(root);
        cout << endl;
    }

    return 0;
}
