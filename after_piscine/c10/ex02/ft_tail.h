#ifndef FT_TAIL
# define FT_TAIL

# include <unistd.h>
# include <fcntl.h>
# include <string.h>
# include <libgen.h>
# include <errno.h>
# define ABS(x) (x > 0 ? x : -x)

void	ft_put_header(int, char **, int);
void	ft_putstr(char *);
int		ft_bytes_error(int, char **, char *);
int		ft_display_file(int, char **, int, int);
int		ft_print(int, int);
int		ft_error(char *, char *, char *);
int		ft_str_is_numeric(char *);
int		ft_strcmp(char *, char *);
int		ft_atoi(char *);
int     ft_check_flag(int, char **);
int		ft_char_count(char **, int, int);

#endif
