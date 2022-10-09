/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbasyrov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 17:31:21 by rbasyrov          #+#    #+#             */
/*   Updated: 2022/09/11 17:31:24 by rbasyrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);
void	ft_putstr(char *str);
void	print_matrix(char m[4][4]);
void	ft_putnbr(int nb);
void	update_row(int row, int what_array, char *arrays, char map[4][4]);
char	check_array(int what_side, int what_index,	char map[4][4]);
int		char_to_int(char num);
char	int_to_char(int num);
int		check_matrix(char *input, char map[4][4]);
int		check_columns(char map[4][4]);
int		ft_strlen(char *str);
char	ft_check_input(char *str);
char	ft_rush(char *input, char map[4][4]);

int	main(int argc, char *argv[])
{
	int		real_len;
	char	map[4][4];
	char	*input;

	if (argc == 2)
	{
		input = argv[1];
		real_len = ft_strlen(input) - 15;
		if ((real_len > 17) || (real_len < 16))
			ft_putstr("Error\n");
		else if (ft_check_input(input) == '-')
			ft_putstr("Error\n");
		else
		{
			if (ft_rush(input, map) == '+')
				print_matrix(map);
			else
				ft_putstr("Error\n");
		}
	}
	else
		ft_putstr("Error\n");
	return (0);
}
