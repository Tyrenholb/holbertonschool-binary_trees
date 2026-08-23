#include "binary_trees.h"

/**
 * leaf_depth - Gets the depth of the leftmost leaf
 * @tree: Pointer to the root node
 *
 * Return: Depth of the leftmost leaf
 */
static int leaf_depth(const binary_tree_t *tree)
{
	int depth = 0;

	while (tree->left != NULL)
	{
		depth++;
		tree = tree->left;
	}

	return (depth);
}

/**
 * check_perfect - Checks if a tree is perfect
 * @tree: Pointer to the current node
 * @depth: Expected depth of all leaves
 * @level: Current node depth
 *
 * Return: 1 if perfect, otherwise 0
 */
static int check_perfect(const binary_tree_t *tree, int depth, int level)
{
	if (tree->left == NULL && tree->right == NULL)
		return (level == depth);

	if (tree->left == NULL || tree->right == NULL)
		return (0);

	return (check_perfect(tree->left, depth, level + 1) &&
		check_perfect(tree->right, depth, level + 1));
}

/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect
 * @tree: Pointer to the root node
 *
 * Return: 1 if perfect, otherwise 0
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int depth;

	if (tree == NULL)
		return (0);

	depth = leaf_depth(tree);

	return (check_perfect(tree, depth, 0));
}
