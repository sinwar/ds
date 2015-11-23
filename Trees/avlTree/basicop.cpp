/*
	SINWAR PREM
	premsinwar4@gmail.com
*/
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
//avl binary operation-(avl tree is a type of binary tree which height remains O(logn) after insertoin and deletion)
struct node{
	int data,height;//required for AVL
	struct node *left;
	struct noded *right;
};
//inorder traverse
void inorder(struct node* root)
{
	printf(" ");
	if(root!=NULL)
	{
		inorder(root->left);
		printf("%d\n ",root->data);
		inorder(root->right);
	}
}
//preorder traverse
void preorder(struct node* root)
{
	if(root!=NULL)
	{
		printf("%d\n ",root->data);
		preorder(root->left);
		preorder(root->right);
	}
}
//postorder traverse
void postorder(struct node* root)
{
	if(root!=NULL)
	{
		postorder(root->left);
		postorder(root->right);
		printf("%d\n ",root->data);
	}
}



//insertion in avl tree
//first insert the node for standard BST then rebalance using left rotation and right rotation

