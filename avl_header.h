#include <iostream>
#include <cstdlib>
using namespace std;
class TreeNode 
{
    public:
        int age,ticket_number;
        string name,travel_class;
        TreeNode *left;
        TreeNode *right;
        int height;
};
class AVL
{
    public:
        TreeNode* insert(TreeNode *root,string n,int a,int tn,string tc); 
        TreeNode* search(TreeNode *root,int tn); 
        TreeNode* findMax(TreeNode *root); 
        TreeNode* findMin(TreeNode *root); 
        int max(int a,int b); 
        int Height(TreeNode *N); 
        int getBalanceFactor(TreeNode *N); 
        void inorder(TreeNode *root); 
        void preorder(TreeNode *root); 
        void postorder(TreeNode *root); 
        TreeNode *leftRotate(TreeNode *k1);
        TreeNode *LR(TreeNode *);
        TreeNode *RL(TreeNode *);
        TreeNode *rightRotate(TreeNode *k2);
};