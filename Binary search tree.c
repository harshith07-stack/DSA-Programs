#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node*left;
    struct node*right;
};
typedef struct node*NODE;
NODE createBST(NODE root, int item)
{
    NODE temp, prev, cur;

    temp = (NODE)malloc(sizeof(struct node));

    temp->data = item;
    temp->left = NULL;
    temp->right = NULL;

    if (root == NULL)
        return temp;

    prev = NULL;
    cur = root;

    while (cur != NULL)
    {
        prev = cur;

        if (item < cur->data)
            cur = cur->left;
        else
            cur = cur->right;
    }

    if (item < prev->data)
        prev->left = temp;
    else
        prev->right = temp;

    return root;
}

void preorder(NODE root)
{
    if (root != NULL)
    {
        printf("%d\t", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(NODE root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d\t", root->data);
        inorder(root->right);
    }
}

void postorder(NODE root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d\t", root->data);
    }
}

int main()
{
    NODE root = NULL;
    int ch, item;

    for (;;)
    {
        printf("\n1. Insert");
        printf("\n2. Preorder");
        printf("\n3. Inorder");
        printf("\n4. Postorder");
        printf("\n5. Exit");

        printf("\nRead choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
            case 1:printf("\nRead element to be inserted: ");
                   scanf("%d", &item);
                   root = createBST(root, item);
                   break;

            case 2:printf("\nPreorder Traversal:\n");
                   preorder(root);
                   break;

            case 3:printf("\nInorder Traversal:\n");
                   inorder(root);
                   break;

            case 4:printf("\nPostorder Traversal:\n");
                   postorder(root);
                   break;

            case 5:exit(0);

            default:
                printf("\nInvalid choice!");
        }
    }

    return 0;
}
