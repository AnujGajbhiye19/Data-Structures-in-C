# include<stdio.h>
# include<stdlib.h>

struct node
{
int data;
struct node *left;
struct node *right;
};

struct node *createnode(int data)
{
	struct node *new=malloc(sizeof(struct node));
	new->data=data;
	new->left=NULL;
	new->right=NULL;
	return new;
}

struct node *create_tree(struct node *root)
{
int data;
printf("Enter data for node:");
scanf("%d",&data);

if(data==-1)
{

return NULL;

}

root=createnode(data);

root->left=create_tree(root->left);
root->right=create_tree(root->right);


return root;

}

void inorder(struct node *root)
{

if(root==NULL)
return;
inorder(root->left);
printf("%d ",root->data);
inorder(root->right);

}

void preorder(struct node *root)
{
if(root==NULL)
return;
printf("%d ",root->data);
preorder(root->left);
preorder(root->right);

}


void postorder(struct node *root)
{

if(root==NULL)
return;

postorder(root->left);
postorder(root->right);
printf("%d ",root->data);

}

int tree_bal(struct node* root)
{
	if(root==NULL) return 0;
	int hl= tree_bal(root->left);
	int hr= tree_bal(root->right);
	int h= hl-hr;
	if(h==-1 || h==1 || h==0)
	printf("Balanced Tree\n");
	else printf("Not Balanced Tree\n");
	return h+1;
}

void tree_mir(struct node* root)
{
	struct node* temp;
	if(root==NULL) return;
	tree_mir(root->left);	
	tree_mir(root->right);
	temp=root->left;
	root->left=root->right;
	root->right=temp;
}

struct node* insert_bst(struct node* root, int data)
{
	if(root==NULL) root = createnode(data);
	else
	{
		if(data<(root->data))
			root->left = insert_bst(root->left, data);
		else
			root->right= insert_bst(root->right, data);
	}
	
	return root;
}

struct node* take_ip(struct node* root)
{
	int data;
	printf("Enter data for node: ");
	scanf("%d",&data);

	while(data!=-1)
	{
		root=insert_bst(root,data);
		printf("Enter data for node: ");
		scanf("%d",&data);
	}
	return root;	
}

int bintree_min(struct node* root)
{
	if(root->left==NULL) return root->data;
	return bintree_min(root->left);
	
}

void main()
{
struct node *root;

root= take_ip(root);
printf("Inorder: ");
inorder(root);
printf("\n");
printf("Pre-order: ");
preorder(root);
printf("\n");
printf("Post-order: ");
postorder(root);
printf("\n");

printf("Min: %d\n",bintree_min(root));

	
}

