#include<iostream>
using namespace std;

class node
{
public:
    int data;
    node* left;
    node* right;
  
    node(int value)
    {
        data=value;
        left=right=nullptr;
    }
};

// class tree
// {
//     public:
//     node* root=nullptr;
    node* insert(node* root)
    {
        int data;
        cout<<"Enter the data :"<<endl;
        cin>>data;
        root=new node(data);
        if(data==-1) return NULL;
        cout<<"For inserting the data in left child of "<<data<<endl;
        root->left=insert(root->left);
        cout<<"For inserting the data in right node right of "<<data<<endl;
        root->right=insert(root->right);
        return root;
    }

    void inorder(node* root)
    {
        if(root!=NULL)
        {
            inorder(root->left);
            cout<<root->data<<" ";
            inorder(root->right);
        }
    }

     void preorder(node* root)
    {
        if(root!=NULL)
        {
            cout<<root->data<<" ";
            preorder(root->left);
            preorder(root->right);
        }
    }

     void postorder(node* root)
    {
        if(root!=NULL)
        {
            postorder(root->left);
            postorder(root->right);
            cout<<root->data<<" ";
        }
    }

    int maximum(node*root)
    {
        int root_val ,left,right,max;
        if(root==NULL) return 0;
        else
        {
            root_val=root->data;
            left=maximum(root->left);
            right=maximum(root->right);
        }
        if(left>right)
            max=left;
        else
            max=right;
        if(root_val>max)
            max=root_val;
    return max;
    }

    int node_add(node* root)
    {
        if(root==NULL) return 0;
        else
        return (root->data+node_add(root->left)+node_add(root->right));
    }

int main()
{
    node* root=NULL;
    // tree T;
    root=insert(root);
    cout<<"\nInorder : ";
    inorder(root);
    cout<<"\nPreorder : ";
    preorder(root);
    cout<<"\nPostorder : ";
    postorder(root);
    int m=maximum(root);
    cout<<"\nMaximum element of the tree :"<<m;
    int add=node_add(root);
    cout<<"\nAddition of tree :"<<add;
    return 0;
}
// input= 2 1 -1 -1 3 -1 -1 