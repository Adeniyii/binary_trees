#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_height - measures the height of a binary tree
 *
 * @tree: pointer to the root node of the tree to measure the height
 *
 * Return: height of the tree, or 0 if tree is NULL
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t padding = 0;

	if (tree == NULL)
		return (0);

	size_t left_height = binary_tree_height(tree->left);
	size_t right_height = binary_tree_height(tree->right);

	/* if current node is not a leaf, add 1 to the height. */
	if (tree->left != NULL || tree->right != NULL)
		padding = 1;

	return (left_height > right_height
		    ? left_height + padding
		    : right_height + padding);
}
