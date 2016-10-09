#include <bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    node* left, * right;
};
typedef struct node node;
node* newnode(int data)
{
    node* n = new node;
    n->data = data;
    n->left = n->right = NULL;
    return (n);
}
int ht(node*tree)
{
	if(tree==NULL)return 0;
	return 1+max(ht(tree->left),ht(tree->right));
}
int width_of_level(node*root,int level)
{
	if(root==NULL)return 0;
	if(level==1)return 1;
	else if(level>1)
	{
		return width_of_level(root->left,level-1)+
		width_of_level(root->right,level-1);
	}
}
int maxw(node*tree)
{
	int h=ht(tree);
	int maxw=-1,w;
	for(int i=1;i<=h;i++)
	{
		w=width_of_level(tree,i);
		if(w>maxw)
			maxw=w;
	}
	return maxw;
}
int main()
{
	node*tree=newnode(1);
	tree->left=newnode(2);
	tree->left->left=newnode(4);
	tree->left->right=newnode(5);
	tree->right=newnode(3);
	tree->right->left=newnode(6);
	tree->right->right=newnode(7);
	cout<<"the max width of tree is : "<<maxw(tree);

}
