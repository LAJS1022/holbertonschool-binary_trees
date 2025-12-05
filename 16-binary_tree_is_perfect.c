#include "binary_trees.h"
/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 * @tree: pointer to the root node
 * Return: 1 if tree is perfect, 0 otherwise
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
size_t size, leaves;
if (tree == NULL)
return (0);
size = binary_tree_size(tree);
leaves = binary_tree_leaves(tree);
if (size == (2 * leaves - 1))
return (1);
return (0);
}
