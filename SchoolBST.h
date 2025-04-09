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
        if (node == nullptr)
        {
            return node;
        }
        if (node->name == name)
        {
            cout << "School found." << endl;
            cout << "Name: " << node->name << endl;
            cout << "Address: " << node->address << endl;
            cout << "City: " << node->city << endl;
            cout << "State: " << node->state << endl;
            cout << "County: " << node->county << endl;
        }

        return (name < node->name) ? findNode(node->left, name) : findNode(node->right, name);
    }

    BSTSchool* getSuccessor(BSTSchool* curr){
        curr = curr->right;
        while (curr != nullptr && curr->left != nullptr)
            curr = curr->left;
        return curr;
    }

    BSTSchool* deleteNode(BSTSchool* node, string name) {
        if (node == nullptr) return nullptr;

        if (name < node->name) {
            node->left = deleteNode(node->left, name);
        } else if (name > node->name) {
            node->right = deleteNode(node->right, name);
        } else {

            if (node->left == nullptr && node->right == nullptr) {
                delete node;
                return nullptr;
            }

            else if (node->left == nullptr) {
                BSTSchool* temp = node->right;
                delete node;
                return temp;
            } else if (node->right == nullptr) {
                BSTSchool* temp = node->left;
                delete node;
                return temp;
            }
            else {
                BSTSchool* temp = getSuccessor(node->right);
                node->name = temp->name;
                node->right = deleteNode(node->right, temp->name);
            }
        }
        return node;
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

    void deleteByName(string name) {
        root = deleteNode(root, name);
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
