#include <stdio.h>
#include <stdlib.h>

// Node structure for a binary search tree
struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

// Function to create a new node
struct Node *createNode(int data) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        return NULL;  // Return NULL to indicate failure
    }
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert a new node into the BST
struct Node *insert(struct Node *root, int data) {
    if (root == NULL) {
        struct Node *newNode = createNode(data);
        if (newNode == NULL) {
            // Handle memory allocation failure
            printf("Failed to insert node due to memory allocation failure\n");
            // Additional error handling if needed
            return root;  // or return NULL, depending on your error handling strategy
        }
        return newNode;
    }

    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }

    return root;
}

// Function to find the minimum value node in a BST
struct Node *findMin(struct Node *root) {
    while (root->left != NULL) {
        root = root->left;
    }
    return root;
}

// Function to delete a node with the given data from the BST
struct Node *deleteNode(struct Node *root, int data) {
    if (root == NULL) {
        return root;
    }

    if (data < root->data) {
        root->left = deleteNode(root->left, data);
    } else if (data > root->data) {
        root->right = deleteNode(root->right, data);
    } else {
        if (root->left == NULL) {
            struct Node *temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct Node *temp = root->left;
            free(root);
            return temp;
        }

        struct Node *temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }

    return root;
}

// Function to perform inorder traversal
void inorderTraversal(struct Node *root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

// Function to free the memory allocated for the BST
void freeBST(struct Node *root) {
    if (root != NULL) {
        freeBST(root->left);
        freeBST(root->right);
        free(root);
    }
}

int main() {
    struct Node *root = NULL;

    // Insertion
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    // Display the BST
    printf("BST after insertion: ");
    inorderTraversal(root);
    printf("\n");

    // Deletion
    root = deleteNode(root, 30);
    root = deleteNode(root, 20);
    root = deleteNode(root, 50);

    // Display the BST after deletion
    printf("BST after deletion: ");
    inorderTraversal(root);
    printf("\n");

    // Free the memory allocated for the BST
    freeBST(root);

    return 0;
}
