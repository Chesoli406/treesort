#include <iostream>
using namespace std;

// Define structure for BST node
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = NULL;
        right = NULL;
    }
};

// Function to insert a node into BST
Node* insert(Node* root, int value) {
    if (root == NULL) {
        return new Node(value);
    }

    if (value < root->data) {
        root->left = insert(root->left, value);
    } else {
        // Duplicates go to the right subtree
        root->right = insert(root->right, value);
    }

    return root;
}

// Inorder traversal (Left → Root → Right)
void inorder(Node* root) {
    if (root != NULL) {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

// Tree Sort function
void treeSort(int arr[], int n) {
    Node* root = NULL;

    // Insert elements into BST
    for (int i = 0; i < n; i++) {
        root = insert(root, arr[i]);
    }

    // Print sorted elements using inorder traversal
    cout << "Sorted array: ";
    inorder(root);
}

// Main function
int main() {
    int arr[] = {50, 30, 20, 40, 70, 60, 80};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    cout << endl;

    treeSort(arr, n);

    return 0;
}