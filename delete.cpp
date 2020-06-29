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
void levelorder(node *root)
 {
 	 if(root==NULL) return;
 	 queue<node*>q;
 	 q.push(root);
 	 while(!q.empty())
 	  {
 	  	 node *current =q.front();
 	  	 cout<<current->data<<"->";
 	  	 if(current->left!=NULL) q.push(current->left);
 	  	 if(current->right!=NULL) q.push(current->right);
 	  	 q.pop();
	   }
 }
 node *findmin(node *root)
 {   
 	 while(root->left!=NULL)
 	   {
 	   	 root=root->left;
 	   	 
		}
	return root;
 }
  node* Delete(struct node *root, int data) {
	if(root == NULL) return root; 
	else if(data < root->data) root->left = Delete(root->left,data);
	else if (data > root->data) root->right = Delete(root->right,data);
	// Wohoo... I found you, Get ready to be deleted	
	else {
		// Case 1:  No child
		if(root->left == NULL && root->right == NULL) { 
			delete root;
			root = NULL;
		}
		//Case 2: One child 
		else if(root->left == NULL) {
			node *temp = root;
			root = root->right;
			delete temp;
		}
		else if(root->right == NULL) {
			node *temp = root;
			root = root->left;
			delete temp;
		}
		// case 3: 2 children
		else { 
			node *temp = findmin(root->right);
			root->data = temp->data;
			root->right = Delete(root->right,temp->data);
		}
	}
	return root;
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
	
	levelorder(root);
    root=Delete(root,50);
	cout<<endl;				
    levelorder(root);
	     	return 0;
}
