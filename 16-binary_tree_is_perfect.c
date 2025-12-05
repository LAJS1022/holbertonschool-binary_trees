#include "binary_trees.h"
/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 * @tree: pointer to the root node
 * Return: 1 if tree is perfect, 0 otherwise
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
size_t left_height, right_height;
if (tree == NULL)
return (0);
left_height = binary_tree_height(tree->left);
right_height = binary_tree_height(tree->right);
if (left_height != right_height)
return (0);
if (tree->left == NULL && tree->right == NULL)
return (1);
if (tree->left != NULL && tree->right != NULL)
return (binary_tree_is_perfect(tree->left) && binary_tree_is_perfect(tree->right));
return (0);
}
