#include <iostream>
#include<bits/stdc++.h>
#include<queue>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
struct node{
	int data;
	node *root;
	node *left;
	node *right;
};


node *create(int n)
 {
 	 node*ptr=new node;
	ptr->data=n;
	ptr->left=NULL;
	ptr->right=NULL;
	return ptr;
 }
node *insert(node *root,int data){


 if(root==NULL)
		root=create(data);
	else if(data<=root->data)
		root->left=insert(root->left,data);
	else if(data>root->data)
		root->right=insert(root->right,data);
	
	return root;

}
bool isgreater(node *root,int value)
{
	if (root==NULL) return true;
	else if((root->data>value)&&(isgreater(root->left,value))&&(isgreater(root->right,value)))
	 return true;
	else
	 return false;
}
bool islesser(node *root,int value)
{
	if (root==NULL) return true;
	else if((root->data<value)&&(islesser(root->left,value))&&(islesser(root->right,value)))
	 return true;
	else
	 return false;
}
bool isbst(node *root)
  {
  	if(root==NULL) return true;
  	else if((islesser(root->left,root->data))&&(isgreater(root->right,root->data))&&(isbst(root->left))&&(isbst(root->right)))
    return true;
    else
      return false;
  }

int main() {
	node *root=NULL;
	
	
	root=insert(root,10);
	root=insert(root,20);
	root=insert(root,30);
	root=insert(root,40);
	root=insert(root,50);
	root=insert(root,60);
	root=insert(root,70);
    if(isbst(root))
	  cout<<"\nIt is a BST";
	 else 
	   cout<<"\nIt is not a BST";		
         	return 0;
}
