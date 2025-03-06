#ifndef SCHOOLBST_H
#define SCHOOLBST_H

#include <iostream>
using namespace std;

struct BSTSchool {
    string name;
    string address;
    string city;
    string state;
    string county;

    BSTSchool* left;
    BSTSchool* right;

    BSTSchool(string n = "", string a = "", string c = "", string s = "", string cty = "", BSTSchool* l = nullptr, BSTSchool* r = nullptr): name(n), address(a), city(c), state(s), county(cty), right(r),left(l) {}
};

class SchoolBST {
private:
    BSTSchool* root;
    BSTSchool* insertNode(BSTSchool* node, BSTSchool& school) {
        if (node == nullptr) return new BSTSchool(school);

        if (school.name < node->name) node->left = insertNode(node->left, school);
        else node->right = insertNode(node->right, school);
        return node;
    }

    BSTSchool* findNode(BSTSchool* node, string name) {
        if (node == nullptr || node->name == name) return node;
        return (name < node->name) ? findNode(node->left, name) : findNode(node->right, name);
    }

    void deleteTree(BSTSchool* node) {
        if (node == nullptr) return;
        deleteTree(node->left);
        deleteTree(node->right);
        delete node;
    }
public:
    SchoolBST() : root(nullptr) {}
    ~SchoolBST() {
        deleteTree(root);
    }
    void insert(BSTSchool& school) {
        root = insertNode(root, school);
    }
    bool find(string name) {
        return findNode(root, name) != nullptr;
    }

    void preorder() {
        preorderTraversal(root);
        cout << endl;
    }

    void preorderTraversal(BSTSchool* node)
    {
        if (node == nullptr) return;

        cout << node->name << " " << endl;

        preorderTraversal(node->left);
        preorderTraversal(node->right);
    }

    void postorder()
    {
        postorderTraversal(root);
        cout << endl;
    }

    void postorderTraversal(BSTSchool* node)
    {
        if (node == nullptr) return;

        postorderTraversal(node->left);
        postorderTraversal(node->right);
        cout << node->name << " " << endl;
    }

    void inOrder()
    {
        inOrderTraversal(root);
        cout << endl;
    }

    void inOrderTraversal(BSTSchool* node) {
        if (node == nullptr) return;

        inOrderTraversal(node->left);
        cout << node->name << " " << endl;
        inOrderTraversal(node->right);
    }


    /*void levelOrder()
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
    */

};
#endif // SCHOOLBST_H
