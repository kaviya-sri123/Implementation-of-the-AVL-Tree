#include "avl_header.h"
TreeNode* AVL::insert(TreeNode *root,string n,int a,int tn,string tc)
{
    TreeNode *temp;
    TreeNode *node = root;
    if(node==NULL)
    {
        temp = new TreeNode();
        temp->name = n;
        temp->age = a;
        temp->ticket_number = tn;
        temp->travel_class = tc;
        temp->left = NULL;
        temp->right = NULL;
        return temp;
    }
    if(tn < node->ticket_number)
        node->left = insert(node->left,n,a,tn,tc);
    else if(tn > node->ticket_number)
        node->right = insert(node->right,n,a,tn,tc);
    else
        return node;
    int balance = getBalanceFactor(node);
    if(balance > 1)
    {
        if(tn < node->left->ticket_number)
            node = rightRotate(node);
        else
            node = LR(node);
    }
    if(balance < -1)
    {
        if(tn > node->right->ticket_number)
            node = leftRotate(node);
        else
            node = RL(node);
    }
    node->height = max(Height(node->left),Height(node->right)) + 1;
    return node;
}
TreeNode* AVL::search(TreeNode *root,int tn)
{
    TreeNode *temp = root;
    if(temp==NULL || temp->ticket_number == tn)
        return temp;
    else if(temp->ticket_number < tn)
        search(temp->right,tn);
    else if(temp->ticket_number > tn)
        search(temp->left,tn);
}
TreeNode* AVL::findMin(TreeNode *root)
{
    TreeNode *temp = root;
    if(temp == NULL)
        return NULL;
    if(temp->left != NULL)
        findMin(temp->left);
    else
        return temp;
}
TreeNode* AVL::findMax(TreeNode *root)
{
    TreeNode *temp = root;
    if(temp == NULL)
        return NULL;
    if(temp->right != NULL)
        findMax(temp->right);
    else
        return temp;
}
int AVL::max(int a,int b)
{
    if(a>b)
        return a;
    else
        return b;
}
int AVL::Height(TreeNode* N)
{
    if(N==NULL)
        return -1;
    else
        return N->height;
}
int AVL::getBalanceFactor(TreeNode *N)
{
    return Height(N->left) - Height(N->right);
}
void AVL::inorder(TreeNode *root)
{
    if(root != NULL)
    {
        inorder(root->left);
        cout<<"\nName : "<<root->name<<endl;
        cout<<"Age : "<<root->age<<endl;
        cout<<"Ticket Number : "<<root->ticket_number<<endl;
        cout<<"Travel Class : "<<root->travel_class<<endl;
        inorder(root->right);
    }
}
void AVL::preorder(TreeNode *root)
{
    if(root != NULL)
    {
        cout<<"\nName : "<<root->name<<endl;
        cout<<"Age : "<<root->age<<endl;
        cout<<"Ticket Number : "<<root->ticket_number<<endl;
        cout<<"Travel Class : "<<root->travel_class<<endl;
        preorder(root->left);
        preorder(root->right);
    }
}
void AVL::postorder(TreeNode *root)
{
    if(root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        cout<<"\nName : "<<root->name<<endl;
        cout<<"Age : "<<root->age<<endl;
        cout<<"Ticket Number : "<<root->ticket_number<<endl;
        cout<<"Travel Class : "<<root->travel_class<<endl;
    }
}
TreeNode* AVL::leftRotate(TreeNode *k1)
{
    TreeNode* k2 = k1->right;
    TreeNode* y = k2->left;
    k2->left = k1;
    k1->right = y;
    k1->height = max(Height(k1->left),Height(k1->right))+1;
    k2->height = max(Height(k2->left),Height(k2->right))+1;
    return k2;
}
TreeNode* AVL::LR(TreeNode *k3)
{
    k3->left = leftRotate(k3->left);
    return rightRotate(k3);
}
TreeNode* AVL::RL(TreeNode *k3)
{
    k3->right = rightRotate(k3->right);
    return leftRotate(k3);
}
TreeNode* AVL::rightRotate(TreeNode *k2)
{
    TreeNode* k1 = k2->left;
    TreeNode* y = k1->right;
    k1->right = k2;
    k2->left = y;
    k1->height = max(Height(k1->left),Height(k1->right))+1;
    k2->height = max(Height(k2->left),Height(k2->right))+1;
    return k1;
}