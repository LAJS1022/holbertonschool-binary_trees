#include "binary_trees.h"
/**
 * binary_tree_balance - measures the balance factor of a binary tree
 * @tree: pointer to the root node
 * Return: balance factor, 0 if tree is NULL
 */
int binary_tree_balance(const binary_tree_t *tree)
{
int left, right;
if (tree == NULL)
return (0);
left = (int)binary_tree_height(tree->left);
right = (int)binary_tree_height(tree->right);
return (left - right);
}
