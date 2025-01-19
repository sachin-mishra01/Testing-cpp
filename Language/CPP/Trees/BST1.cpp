// Header file for input output library.
#include <iostream>
using namespace std;
// Node structure for creating node.
struct node
{
    int data;       
    node* left;
    node* right;
//Constructer to creating node.
    node(int data)
    {
        this->data=data;
        left=nullptr;
        right=nullptr;
    }
};
//Function to insert value in the node.
node* insert(node* root, int value)
{
    // Condition to check root is empty or not.
    if(root==nullptr)
    {
        return new node(value);
    }
    // Checking condition to insert data into the either left subtree or right subtree.
    if(value<root->data)
    {
        root->left=insert(root->left,value);
    }
    else
    {
        root->right=insert(root->right,value);
    }
    return root;
}
// function is use to traverse tree in inorder sequence. 
void inorder(node* root)
{
    if(root!=nullptr)
    {
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
}
// function is use to traverse tree in preorder sequence.
void preorder(node* root)
{
    if(root!=nullptr)
    {
        cout<<root->data<<" ";
        preorder(root->left);
        preorder(root->right);
    }
}
//function is use to traverse tree in P\postorder sequence.
void postorder(node* root)
{
    if(root!=nullptr)
    {
        postorder(root->left);
        postorder(root->right);
        cout<<root->data<<" ";
    }
}
//main function
int main()
{
    //create root and assign null value.
    node* root=nullptr;

    root=insert(root,43);
    root=insert(root,23);
    root=insert(root,34);
    root=insert(root,40);
    root=insert(root,10);
    root=insert(root,72);
    
    cout<<"Inorder :";
    inorder(root);
    cout<<"\nPreorder :";
    preorder(root);
    cout<<"\nPostorder :";
    postorder(root);
    return 0;
}
