//
// Created by David Bors on 24.05.2021.
//

#ifndef TEMA3_BST_H
#define TEMA3_BST_H

typedef struct bst_node {
    char *key;
    struct bst_node *left, *right;
}bst_node;

// A utility function to create a new BST node
bst_node* newNode(char *to_add)
{
    struct bst_node* temp = (struct bst_node*)malloc(sizeof(struct bst_node));
    temp->key = (char*) malloc(250 * sizeof(char));
    strcpy(temp->key, to_add);
    temp->left = temp->right = NULL;
    return temp;
}

// A utility function to do inorder traversal of BST
void inorder(struct bst_node* root, FILE *out)
{
    if (root != NULL) {
        inorder(root->left, out);
        fprintf(out, "%s\n", root->key);
        inorder(root->right, out);
    }
}

/* A utility function to insert
   a new node with given key in
 * BST */
bst_node* insert(struct bst_node* node, char *key)
{
    /* If the tree is empty, return a new node */
    if (node == NULL)
        return newNode(key);

    /* Otherwise, recur down the tree */
    if (strcmp(key, node->key) < 0)
        node->left = insert(node->left, key);
    else if (strcmp(key, node->key) > 0)
        node->right = insert(node->right, key);

    /* return the (unchanged) node pointer */
    return node;
}

void destroy_bst(bst_node *node)
{
    if(node == NULL)
        return;
    else
    {
        destroy_bst(node->left);
        destroy_bst(node->right);
        free(node->key);
        free(node);
        node = NULL;
    }
}

#endif //TEMA3_BST_H
