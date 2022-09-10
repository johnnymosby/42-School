void	ft_putstr(char *str);

void	ft_check_input(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if ((str[i] > 52 || str[i] < 49))
			ft_putstr("pls use number between 1 - 4!\n");
		if (str[i + 1] == '\0')
			break ;
		i++;
		i++;
	}
}
