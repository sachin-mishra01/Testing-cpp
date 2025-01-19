#include <iostream>
#include "delete_BST.cpp"
using namespace std;


class binary_tree
{
    public:
    node* root = nullptr;
    node* insert(node *root, int value)
    {
        
        // cout<<"start\n";
        if (root == NULL)
        {
            root = new node(value);
            return root;
        }
        if (value < root->data)
        {
            root->left = insert(root->left, value);
        }
        else
        {
            root->right = insert(root->right, value);
        }
        // cout<<"complete";
        return root;
    }

    void inorder(node *root)
    {
        if(root == NULL){
            return;
        }
            inorder(root->left);
            cout << root->data << " ";
            inorder(root->right);
    }
    // function is use to traverse tree in preorder sequence.
    void preorder(node *root)
    {
        if (root != nullptr)
        {
            cout << root->data << " ";
            preorder(root->left);
            preorder(root->right);
        }
    }
    // function is use to traverse tree in P\postorder sequence.
    void postorder(node *root)
    {
        if (root != nullptr)
        {
            postorder(root->left);
            postorder(root->right);
            cout << root->data << " ";
        }
    }
};
int main()
{
    node* root=nullptr;
    binary_tree tree;
    root = tree.insert(root,30);
    root = tree.insert(root,20);
    root = tree.insert(root,10);
    root = tree.insert(root,90);
    root = tree.insert(root,70);
    root = tree.insert(root,36);
    root = tree.insert(root,72);
    root = tree.insert(root,12);
    root = tree.insert(root,42);
    root = tree.insert(root,39);

    cout<<"\nInorder : ";
    tree.inorder(root);
    cout<<"\nPreorder : ";
    tree.preorder(root);
    cout<<"\nPostorder : ";
    tree.postorder(root);

    root  = deleteNode(root,10);
    cout<<"\n\nAfter deletion\n";
    
    cout<<"\nInorder : ";
    tree.inorder(root);
    cout<<"\nPreorder : ";
    tree.preorder(root);
    cout<<"\nPostorder : ";
    tree.postorder(root);

    root  = deleteNode(root,30);
    cout<<"\n\nAfter deletion\n";

    cout<<"\nInorder : ";
    tree.inorder(root);
    cout<<"\nPreorder : ";
    tree.preorder(root);
    cout<<"\nPostorder : ";
    tree.postorder(root);

    return 0;
}