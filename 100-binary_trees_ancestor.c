#include "binary_trees.h"

int find_depth(const binary_tree_t *tree);
const binary_tree_t *find_parent(const binary_tree_t *first,
				 const binary_tree_t *second);

/**
 * binary_trees_ancestor - finds the lowest common ancestor of two nodes
 *
 * @first: pointer to the first node
 * @second: pointer to the second node
 *
 * Return: pointer to the lowest common ancestor node of the two given nodes
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
				     const binary_tree_t *second)
{
	int i, left_depth, right_depth, deficit;
	binary_tree_t *ancestor;

	if (first == NULL || second == NULL)
		return (NULL);

	if (first == second)
		return ((binary_tree_t *)first);

	left_depth = find_depth(first);
	right_depth = find_depth(second);

	if (right_depth > left_depth)
	{
		deficit = right_depth - left_depth;

		for (i = 0; i < deficit; i++)
			second = second->parent;
	}
	else if (left_depth > right_depth)
	{
		deficit = left_depth - right_depth;

		for (i = 0; i < deficit; i++)
			first = first->parent;
	}

	ancestor = (binary_tree_t *)find_parent(first, second);
	return (ancestor);
}

/**
 * find_parent - finds the lowest common ancestor of two nodes
 *
 * @first: pointer to the first node
 * @second: pointer to the second node
 *
 * Return: pointer to the lowest common ancestor node of the two given nodes,
 * or NULL if no common ancestor
 */
const binary_tree_t *find_parent(const binary_tree_t *first,
				 const binary_tree_t *second)
{
	const binary_tree_t *parent;

	if (first == NULL || second == NULL)
		return (NULL);

	if (first == second)
		return (first);

	parent = find_parent(first->parent, second->parent);
	return (parent);
}

/**
 * find_depth - finds the depth of a node in a binary tree
 * @tree: pointer to the node to measure the depth
 *
 * Return: depth of the node, or 0 if tree is NULL
 */
int find_depth(const binary_tree_t *tree)
{
	int depth;

	if (tree == NULL)
		return (0);

	depth = find_depth(tree->parent);
	return (depth + 1);
}
