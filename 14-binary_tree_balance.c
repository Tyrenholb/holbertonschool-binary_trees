#include "binary_trees.h"

/**
 * tree_height - Measures the height of a subtree
 * @tree: Pointer to the root of the subtree
 *
 * Return: Height of the subtree
 */
static size_t tree_height(const binary_tree_t *tree)
{
	size_t left;
	size_t right;

	if (tree == NULL)
		return (0);

	left = tree_height(tree->left);
	right = tree_height(tree->right);

	if (left > right)
		return (left + 1);

	return (right + 1);
}

/**
 * binary_tree_balance - Measures the balance factor of a binary tree
 * @tree: Pointer to the root node
 *
 * Return: Balance factor of the tree
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return ((int)tree_height(tree->left) -
		(int)tree_height(tree->right));
}
