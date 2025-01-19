#include "node.cpp"
node* IS(node* root){
    if(root->left == NULL){
        return root;
    }
    else{
    return IS(root->left);
    }
}
node* deleteNode(node* root,int val){
    if(root == NULL){
        return NULL;
    }
    if(val>root->data ){
        root->right = deleteNode(root->right,val);
    }
    else if(val<root->data ){
        root->left = deleteNode(root->left,val);
    }
    else{
        if(root->left==NULL && root->right==NULL){
            delete root;
            return NULL;
        }
        else if(root->left==NULL || root->right==NULL){
            return root->left==NULL?root->right:root->left;
        }
        else{
            node* is = IS(root->right);
            root->data = is->data;
            deleteNode(root->right,is->data);
        }
    }
}