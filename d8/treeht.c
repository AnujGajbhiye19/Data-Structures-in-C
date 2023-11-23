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

int tree_height(struct node* root)
{
	if(root==NULL) return 0;
	int hl= tree_height(root->left);
	int hr= tree_height(root->right);
	int h= hl>=hr? hl : hr;
	return h+1;
}

void main()
{
struct node *root=NULL;

root=create_tree(root);
printf("Inorder: ");
inorder(root);
printf("\n");
printf("Pre-order: ");
preorder(root);
printf("\n");
printf("Post-order: ");
postorder(root);
printf("\n");

	printf("Tree Height: %d\n",tree_height(root));
	//printf("\n");
}

