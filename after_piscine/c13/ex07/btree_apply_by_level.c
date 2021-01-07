#include "ft_btree.h"

int		levels_recursive(t_btree *root, int level, t_levels *levels, int i)
{
	if (!root)
		return (i - 1);
	levels[i].address = root;
	levels[i].level = level;
	i = levels_recursive(root->left, level + 1, levels, i + 1);
	i = levels_recursive(root->right, level + 1, levels, i + 1);
	return (i);
}

int		btree_size(t_btree *root, int size)
{
    if (!root)
	    return (size - 1);
	size = btree_size(root->left, size + 1);
	size = btree_size(root->right, size + 1);
	return (size);
}

int		btree_level_count(t_btree *root)
{
    int left;
    int right;

    if (!root)
        return (0);
    left = btree_level_count(root->left);
    right = btree_level_count(root->right);
    if (left > right)
        return (left + 1);
    else
        return (right + 1);
}

void	apply_levels(t_levels *levels, int size, int max, void (*applyf)(void *item, int current_level, int is_first_elem))
{
	int		i;
	int		j;
	bool	first;

	i = 0;
	while (i < max)
	{
		j = 0;
		first = true;
		while (j < size)
		{
			if (levels[j].level == i)
			{
				if (first)
					applyf(levels[j].address->item, levels[j].level, 1);
				else
					applyf(levels[j].address->item, levels[j].level, 0);
				first = false;
			}
			j++;
		}
		i++;
	}
}

void	btree_apply_by_level(t_btree *root, void (*applyf)(void *item, int current_level, int is_first_elem))
{
	t_levels	*levels;
	int			size;
	int			max;

	size = btree_size(root, 1);
	max = btree_level_count(root);
	if (!(levels = (t_levels *)malloc(size * sizeof(t_levels))))
		return ;
	levels_recursive(root, 0, levels, 0);
	apply_levels(levels, size, max, applyf);
	free(levels);
}
