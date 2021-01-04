#ifndef FT_HEXDUMP
# define FT_HEXDUMP

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <string.h>
# include <stdbool.h>
# include <libgen.h>
# include <errno.h>

typedef struct	s_reader
{
	int print;
	int	i;
}				t_reader;

void	ft_putstr(char *);
int		ft_strcmp(char *, char*);
int		ft_check_flag(int, char**);
int		ft_error(char *, char *, char *);
void	ft_print_address(int, int, int, int);
void    ft_print_with_flag(char *, int, int, int);
void    ft_print_without_flag(char *, int, int, int);
void	ft_last(t_reader *, int, char *);
void	ft_adjust_output(char *, int, int);

#endif
