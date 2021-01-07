#include "ft_btree.h"

void	*btree_search_item(t_btree *root, void *data_ref, int (*cmpf)(void *, void *))
{
	void	*returnn;

	if (!root)
		return (0);
	if ((returnn = btree_search_item(root->left, data_ref, cmpf)))
		return (returnn);
	if (!cmpf(root->item, data_ref))
		return (root->item);
	if ((returnn = btree_search_item(root->right, data_ref, cmpf)))
		return (returnn);
	return (0);
}
