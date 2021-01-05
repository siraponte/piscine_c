#ifndef DO_OP
# define DO_OP

# include <unistd.h>
# include <stdbool.h>

bool    ft_check(char *, char *, int);
bool	ft_error(char);
int		ft_add(int, int);
int		ft_minus(int, int);
int		ft_multiply(int, int);
int		ft_divide(int, int);
int		ft_modulo(int, int);
int		ft_strlen(char *);
int		ft_strcmp(char *, char *);
int		ft_atoi(char *);
void	ft_putstr(char *);
void	ft_putnbr(long);

#endif
