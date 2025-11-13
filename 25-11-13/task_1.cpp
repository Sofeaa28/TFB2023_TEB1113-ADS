#include <iostream>
using namespace std;

// Define a node in the BST
struct Node {
    int data;
    Node* left;
    Node* right;
};

// Function to create a new node
Node* createNode(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->left = newNode->right = nullptr;
    return newNode;
}

// Insert a value into the BST
Node* insert(Node* root, int value) {
    if (root == nullptr) {
        return createNode(value);
    }
    if (value < root->data) {
        root->left = insert(root->left, value);
    } else if (value > root->data) {
        root->right = insert(root->right, value);
    }
    return root; // unchanged node pointer
}

// Search for a value in the BST
bool search(Node* root, int value) {
    if (root == nullptr)
        return false;
    if (root->data == value)
        return true;
    else if (value < root->data)
        return search(root->left, value);
    else
        return search(root->right, value);
}

// Inorder traversal (Left, Root, Right)
void inorder(Node* root) {
    if (root == nullptr)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// Main program
int main() {
    Node* root = nullptr;
    int n, value;

    cout << "Enter number of elements to insert: ";
    cin >> n;

    cout << "Enter values:\n";
    for (int i = 0; i < n; i++) {
        cin >> value;
        root = insert(root, value);
    }

    cout << "\nInorder Traversal of BST: ";
    inorder(root);
    cout << endl;

    cout << "\nEnter value to search: ";
    cin >> value;

    if (search(root, value))
        cout << value << " is found in the tree.\n";
    else
        cout << value << " is NOT found in the tree.\n";

    return 0;
}
