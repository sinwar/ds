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
//for minimum value traverse left in tree else right
struct node* min(struct node* root)
{
	while(root->left!=NULL)
		root=root->left;
	return root;
}
struct node* max(struct node* root)
{
	while(root->right!=NULL)
		root=root->right;
	return root;
}
//function for delete a node from given tree
//deletion depends on the number of children of node to be deleted
struct node* del(struct node* root,int key)
{
	if(root==NULL)
	return root;//simply return root
	if(key<root->data)
		del(root->left,key);
	else if(key>root->data)
		del(root->right,key);
	//the data of root and the equal it means that root is the node having same key to be deleted
	else{
		if(root->left==NULL)//root having only left child
		{
			//here a change is required
			struct node* fi=root->right;
			free(root);
			return fi;
		}
		else if(root->right==NULL){//root having only right child
			struct node* fi=root->left;
			free(root);
			return fi;
		}
		else//root having two childern
		{
			struct node* fi=min(root->right);
			root->data=fi->data;
			root->right=del(root->right,fi->data);
		}
		return root;
	}
}
int main()
{
	int ch,k,p,t;
	struct node* root=NULL;
	root=insert(root,1);
	printf("Binary serch tree operation\n");
	lable:
		printf("Press\n1 for insertion \n2 for search \n3 for traverse \n4 for max/min of tree \n5 for deletion");
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
				printf("\n");
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
				}
				break;
			case 4:
				int si;
				printf("For min press 0 else press 1\n");
				scanf("%d",&si);
				struct node* p;
				switch(si){
					case 0:
						p=min(root);//return node having lowest value
						printf("minimum element is %d \n",p->data);
						break;
					case 1:
						p=max(root);
						printf("maximum element is %d \n",p->data);
						break;
					default:
						printf("Invalid choice\n");
						break;
						}
					break;
			case 5:
				int ke;
				printf("Enter the key to be deleted\n");
				scanf("%d",&ke);
				root=del(root,ke);//root will be updated after deletion
				break;
			default:
				printf("Invalid choice\n");
				break;
		}
		goto lable;
		return 0;
}
