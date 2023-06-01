#include "binary_trees.h"

/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 * @tree: pointer to the root node of the tree to check
 *
 * Return: 1 if perfect, 0 if not or if tree is NULL
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int left_height, right_height;

	if (tree == NULL)
		return (0);

	left_height = binary_tree_is_perfect(tree->left);
	right_height = binary_tree_is_perfect(tree->right);

	/* check for -ve height if `tree` is the root element */
	if (tree->parent == NULL)
	{
		if (left_height < 0 || right_height < 0)
			return (0);

		return (1);
	}

	if (left_height != right_height)
		return (-1);

	return (left_height + 1);
}
