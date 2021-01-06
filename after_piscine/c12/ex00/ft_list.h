#ifndef FT_LIST
# define FT_LIST

# include <stdlib.h>

typedef struct		s_list
{
	struct s_list	*next;
	void			*data;
}					t_list;

#endif
