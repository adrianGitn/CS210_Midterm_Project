#ifndef BST_H
#define BST_H
#include <iostream>
using namespace std;

//template<typename T>
struct TreeNode {
    T data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(T val) : data(val), left(nullptr), right(nullptr) {}
};
template<typename T>
class BinarySearchTree {
private:
    TreeNode<T>* root;
    TreeNode<T>* insertNode(TreeNode<T>* node, T value) {
        if (node == nullptr) return new TreeNode<T>(value);
        if (value < node->data) node->left = insertNode(node->left, value);
        else node->right = insertNode(node->right, value);
        return node;
    }
    TreeNode<T>* findNode(TreeNode<T>* node, T value) {
        if (node == nullptr || node->data == value) return node;
        return (value < node->data) ? findNode(node->left, value) : findNode(node->right, value);
    }
    void deleteTree(TreeNode<T>* node) {
        if (node == nullptr) return;
        deleteTree(node->left);
        deleteTree(node->right);
        delete node;
    }
public:
    BinarySearchTree() : root(nullptr) {}
    ~BinarySearchTree() {
        deleteTree(root);
    }
    void insert(T value) {
        root = insertNode(root, value);
    }
    bool find(T val) {
        return findNode(root, val) != nullptr;
    }

    void preorder() {
        preorderTraversal(root);
        cout << endl;
    }

    void preorderTraversal(TreeNode<T>* node)
    {
        if (node == nullptr) return;

        cout << node->data << " ";

        preorderTraversal(node->left);
        preorderTraversal(node->right);
    }

    void postorder()
    {
        postorderTraversal(root);
        cout << endl;
    }

    void postorderTraversal(TreeNode<T>* node)
    {
        if (node == nullptr) return;

        postorderTraversal(node->left);
        postorderTraversal(node->right);
        cout << node->data << " ";
    }



    void levelOrder()
    {
        if (root == nullptr) return;

        queue<TreeNode<T>*> q;

        q.push(root);
        while (!q.empty()) {

            TreeNode<T>* node = q.front();
            q.pop();

            cout << node->data << " ";

            if (node->left != nullptr) q.push(node->left);
            if (node->right != nullptr) q.push(node->right);
        }
        cout << endl;
    }

};
#endif // BST_H
