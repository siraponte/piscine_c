#ifndef FT_BTREE
# define FT_BETREE

# include <stdlib.h>
# include <stdbool.h>

typedef struct		s_btree
{
	struct s_btree	*left;
	struct s_btree	*right;
	void			*item;
}					t_btree;

typedef struct		s_levels
{
	t_btree	*address;
	int		level;
}					t_levels;

#endif
