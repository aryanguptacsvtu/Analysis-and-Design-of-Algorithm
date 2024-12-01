// C program to implement Binary search tree.
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *createNode(int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (!newNode)
    {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct Node *insertNode(struct Node *root, int value)
{
    if (root == NULL)
    {
        return createNode(value);
    }
    if (value < root->data)
    {
        root->left = insertNode(root->left, value);
    }
    else if (value > root->data)
    {
        root->right = insertNode(root->right, value);
    }
    return root;
}

int searchNode(struct Node *root, int key)
{
    if (root == NULL)
    {
        return 0;
    }
    if (root->data == key)
    {
        return 1;
    }
    if (key < root->data)
    {
        return searchNode(root->left, key);
    }
    else
    {
        return searchNode(root->right, key);
    }
}

void inorderTraversal(struct Node *root)
{
    if (root)
    {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

int main()
{
    struct Node *root = NULL;
    int choice, value, key;

    printf("Binary Search Tree Implementation:-\n");

    while (1)
    {
        printf("\nMenu:\n");
        printf("1. Insert\n");
        printf("2. Search\n");
        printf("3. Inorder Traversal\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            while (1)
            {
                printf("Enter value to insert (-1 to stop): ");
                scanf("%d", &value);
                if (value == -1)
                {
                    break;
                }
                root = insertNode(root, value);
            }
            break;

        case 2:
            printf("Enter value to search: ");
            scanf("%d", &key);
            if (searchNode(root, key))
            {
                printf("Value %d found in tree.\n", key);
            }
            else
            {
                printf("Value %d not found in tree.\n", key);
            }
            break;

        case 3:
            printf("Inorder Traversal: ");
            inorderTraversal(root);
            printf("\n");
            break;

        case 4:
            printf("Exiting...\n");
            return 0;

        default:
            printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}
