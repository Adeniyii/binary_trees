#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_is_full - checks if a binary tree is full
 * @tree: pointer to the root node of the tree to check
 *
 * Return: 1 if full, 0 if not or if tree is NULL
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	size_t left_leaf, right_leaf, tmp;

	if (tree == NULL)
		return (0);

	left_leaf = binary_tree_is_full(tree->left);
	right_leaf = binary_tree_is_full(tree->right);

	tmp = (left_leaf ^ right_leaf);

	return (tmp == 0 ? 1 : 0);
}
