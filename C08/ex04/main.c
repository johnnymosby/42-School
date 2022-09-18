

/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdlib.h>

typedef struct s_stock_str
{
	int size;
	char *str;
	char *copy;
} t_stock_str;

int	ft_strlen(char *str)
{
	int	n;

	n = 0;
	while (*(str + n) != '\0')
	{
		n++;
	}
	return (n);
}

char	*ft_strcpy(char *dest, char *src)
{
	int	counter;

	counter = 0;
	while (src[counter])
	{
		dest[counter] = src[counter];
		counter++;
	}
	dest[counter] = '\0';
	return (dest);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int			i;
	int			j;
	t_stock_str	*tab;

	i = 0;
	tab = (t_stock_str *)malloc(sizeof(t_stock_str) * (ac + 1));
	if (tab == (void *) 0)
		return ((void *) 0);
	while (i < ac)
	{
		tab[i].size = ft_strlen(av[i]);
		tab[i].str = av[i];
		tab -> copy = (char *)malloc(sizeof(char) * (tab[i].size + 1));
		if (tab[i].copy == (void *)0)
			return ((void *) 0);
		j = 0;
		while (j < tab[i].size - 1)
		{
			tab[i].copy[j] = av[i][j];
			j++;
		}
		tab[i].copy[j] = '\0';
		i++;
	}
	tab[i].str = (void *)0;
	return (tab);
}

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int	counter;

	counter = 0;
	while (*(str + counter) != '\0')
	{
		write(1, (str + counter), 1);
		counter++;
	}
}

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		ft_putstr("-2147483648");
	}
	else if (nb < 0)
	{
		ft_putchar('-');
		nb *= -1;
	}
	if (nb != -2147483648)
	{
		if (nb >= 10)
		{
			ft_putnbr(nb / 10);
			ft_putnbr(nb % 10);
		}
		else
		{
			ft_putchar(nb + '0');
		}
	}
}

void	ft_show_tab(struct s_stock_str *par)
{
	int	i;

	i = 0;
	if (par != (void *)0)
	{
		while (par[i].str)
		{
			ft_putstr(par[i].str);
			ft_putchar('\n');
			ft_putnbr(par[i].size);
			ft_putchar('\n');
			ft_putstr(par[i].copy);
			ft_putchar('\n');
			i++;
		}
	}
}

int main()
{
	char *str[] = {"12\0", "as\0", "sd\0"};
	struct s_stock_str *a;
	a = ft_strs_to_tab(3, str);
	ft_show_tab(a);
	free(a);
	return 0;
}
