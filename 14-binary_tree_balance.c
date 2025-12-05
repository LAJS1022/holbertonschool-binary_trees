#include "binary_trees.h"

/**
 * height - measures the height of a binary tree
 * @tree: pointer to the root node
 * Return: height of the tree, or 0 if tree is NULL
 */
static size_t height(const binary_tree_t *tree)
{
size_t left, right;

if (tree == NULL)
return (0);

left = height(tree->left);
right = height(tree->right);

return ((left > right ? left : right) + 1);
}

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

left = (int)height(tree->left);
right = (int)height(tree->right);

return (left - right);
}
