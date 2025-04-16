#include <iostream>
#include <stdexcept>
#include <queue> 
#include <iomanip>

class Node {
public:
    int value;
    Node* left;
    Node* right;

    Node(int val) : value(val), left(nullptr), right(nullptr) {}
};

class BinarySearchTree {
private:
    Node* root;

    Node* insertRec(Node* node, int value) {
        if (node == nullptr) return new Node(value);

        if (value < node->value)
            node->left = insertRec(node->left, value);
        else if (value > node->value)
            node->right = insertRec(node->right, value);

        return node;
    }

    bool searchRec(Node* node, int value) {
        if (node == nullptr) return false;

        if (node->value == value) return true;

        return value < node->value
                   ? searchRec(node->left, value)
                   : searchRec(node->right, value);
    }

    Node* removeRec(Node* node, int value) {
        if (node == nullptr) return nullptr;

        if (value < node->value)
            node->left = removeRec(node->left, value);
        else if (value > node->value)
            node->right = removeRec(node->right, value);
        else {
            if (node->left == nullptr) return node->right;
            if (node->right == nullptr) return node->left;

            Node* temp = findMin(node->right);
            node->value = temp->value;
            node->right = removeRec(node->right, temp->value);
        }
        return node;
    }

    Node* findMin(Node* node) {
        while (node->left != nullptr)
            node = node->left;
        return node;
    }

    void inorderRec(Node* node) {
        if (node == nullptr) return;
        inorderRec(node->left);
        std::cout << node->value << " ";
        inorderRec(node->right);
    }

public:
    BinarySearchTree() : root(nullptr) {}

    void insert(int value) {
        root = insertRec(root, value);
    }

    bool search(int value) {
        return searchRec(root, value);
    }

    void remove(int value) {
        root = removeRec(root, value);
    }

    int findMax() {
        if (root == nullptr) throw std::runtime_error("Tree is empty");
        Node* current = root;
        while (current->right != nullptr)
            current = current->right;
        return current->value;
    }

    void inorderTraversal() {
        inorderRec(root);
        std::cout << std::endl;
    }

    int checkBalance(Node* node) {
        if (!node) return 0;
    
        int leftHeight = checkBalance(node->left);
        if (leftHeight == -1) return -1;
    
        int rightHeight = checkBalance(node->right);
        if (rightHeight == -1) return -1;
    
        if (abs(leftHeight - rightHeight) > 1)
            return -1;  
    
        return 1 + std::max(leftHeight, rightHeight);
    }
    
    bool isBalanced() {
        return checkBalance(root) != -1;
    }

    void printLevelOrder() {
        if (!root) return;
    
        std::queue<Node*> q;
        q.push(root);
    
        while (!q.empty()) {
            int levelSize = q.size();
            while (levelSize--) {
                Node* current = q.front();
                q.pop();
                std::cout << current->value << " ";
                if (current->left) q.push(current->left);
                if (current->right) q.push(current->right);
            }
            std::cout << std::endl;
        }
    }

    void print() {
        printLevelOrder();  
    }
};

int main() {
    BinarySearchTree bst;
    bst.insert(50);
    bst.insert(30);
    bst.insert(70);
    bst.insert(20);
    bst.insert(40);
    bst.insert(60);
    bst.insert(80);

    std::cout << "Inorder Traversal: ";
    bst.inorderTraversal();

    std::cout << "Max Value: " << bst.findMax() << std::endl;

    int searchValue = 40;
    if (bst.search(searchValue)) {
        std::cout << searchValue << " found in the tree." << std::endl;
    } else {
        std::cout << searchValue << " not found in the tree." << std::endl;
    }

    if (bst.isBalanced()) {
        std::cout << "The tree is balanced." << std::endl;
    } else {
        std::cout << "The tree is not balanced." << std::endl;
    }

    std::cout << "\nLevel Order Tree Structure:\n";
    bst.print();

    return 0;
}
