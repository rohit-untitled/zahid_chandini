#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node * right , *left ;
};
int count = 0 ;
struct node * newnode (int data)
{
    struct node * temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data ;
    temp->left = NULL;
    temp->right  = NULL ;
    return temp;
}

struct node * insert (struct node * root , int data)
{
    if (root == NULL) return newnode(data);
    if (data == root->data) {
        count++ ;
        return root ;
    }
    if (data < root->data)
        root->left = insert(root->left , data);
    else
        root->right = insert(root->right , data);
    return root ;

}

void inorder(struct node *root)
{
    if (root == NULL)
        return;

    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);

}
int main()
{
    /*
             12(3)
          /        \
       10(2)      20(1)
       /   \
    9(1)  11(1)   */
    struct node *root = NULL;
    root = insert(root, 12);
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 9);
    root = insert(root, 11);
    root = insert(root, 10);
    root = insert(root, 12);
    root = insert(root, 12);
    root = insert(root, 12);

    printf("Inorder traversal of the given tree \n");
    inorder(root);

    printf("\n the no . of duplicates is %d \n" , count);
    return 0 ;
}