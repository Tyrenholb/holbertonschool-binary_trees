#include "binary_trees.h"

/**
 * binary_tree_uncle - Finds the uncle of a node
 * @node: Pointer to the node
 *
 * Return: Pointer to the uncle, or NULL if none exists
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	binary_tree_t *parent;
	binary_tree_t *grandparent;

	if (node == NULL || node->parent == NULL)
		return (NULL);

	parent = node->parent;
	grandparent = parent->parent;

	if (grandparent == NULL)
		return (NULL);

	if (grandparent->left == parent)
		return (grandparent->right);

	return (grandparent->left);
}
