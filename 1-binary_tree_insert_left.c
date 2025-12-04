#include "binary_trees.h"
/**
 * binary_tree_insert_left - inserts a node as the left child
 * @parent: pointer to the parent node
 * @value: value to store in the new node
 * Return: pointer to the created node, or NULL on failure
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
binary_tree_t *new;
if (parent == NULL)
return (NULL);
new = malloc(sizeof(binary_tree_t));
if (new == NULL)
return (NULL);
new->n = value;
new->parent = parent;
new->left = parent->left;
new->right = NULL;
if (parent->left != NULL)
parent->left->parent = new;
parent->left = new;
return (new);
}
