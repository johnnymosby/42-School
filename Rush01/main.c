void	ft_putchar(char c);
int		ft_strlen(char *str);
void	ft_check_input(char *str);
void	ft_putstr(char *str);
void	ft_putnbr(int nb);
void	ft_rush(char *raw_input);

int	main(int argc, char *argv[])
{
	int	real_len;

	real_len = ft_strlen(argv[1]) - 15;
	ft_putnbr(real_len);
	ft_putchar('\n');
	ft_check_input(argv[1]);
	if (argc == 2)
	{
		if ((real_len > 17) || (real_len < 16))
		{
			ft_putstr("Size of input is too big or too short!\n");
		}
		else
		{
			ft_putstr("Input: \n");
			ft_putstr(argv[1]);
			ft_putchar('\n');
			ft_rush(argv[1]);
		}
	}
	else if (argc > 2)
		ft_putstr("Too many args.\n");
	else
		ft_putstr("One arg expected.\n");
	return (0);
}
