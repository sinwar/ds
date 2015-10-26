/*
	SINWAR PREM
	premsinwar4@gmail.com
*/
//update required
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
//operation on binary search tree
//node
struct node{
	int data;
	struct node *left, *right;
};
struct node* rot=NULL;
//function for create a node
struct node* inform(int key)
{
	struct node* naya=(struct node*)malloc(sizeof(struct node));
	naya->data=key;
	naya->left=NULL;
	naya->right=NULL;
	return naya;
}
//function for search a element
struct node* search(struct node* root,int key)
{
	if(root==NULL || root->data==key)
	return root;
	else if(root->data<key)
	return search(root->right,key);
	else
	return search(root->left,key);
}
//inorder traverse
void inorder(struct node* root)
{
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
//function for insert a new node in tree with given key
struct node* insert(struct node* naya, int key)
{
	if(naya==NULL)
		return inform(key);
	if (key < naya->data)
        naya->left  = insert(naya->left, key);
    else if(key > naya->data)
        naya->right = insert(naya->right, key);
    return naya;
}
int main()
{
	int ch,k,p,t;
	struct node* root=NULL;
	root=insert(root,1);
	printf("Binary serch tree operation\n");
	lable:
		printf("Press\n1 for insertion \n2 for search \n3 for traverse\n");
		scanf("%d",&ch);
		switch(ch){
			case 1:
				printf("Enter data for new node\n");
				scanf("%d",&k);
				insert(root,k);
				break;
			case 2:
				printf("Insert a element for search");
				scanf("%d",&t);
				search(root,t);
				break;
			case 3:
				printf("Press \n1 for inorder \n2 for preorder \n3 for postorder\n");
				scanf("%d",&p);
				switch(p){
					case 1:
						inorder(root);
						break;
					case 2:
						preorder(root);
						break;
					case 3:
						postorder(root);
						break;
					default:
						printf("Invalid choice\n");
						break;
				}
				break;
			default:
				printf("Invalid choice\n");
				break;
		}
		goto lable;
		return 0;
}
