#include <unistd.h>

void	ft_putchar(char c);
void	print_matrix(char m[4][4]);
void	input_to_matrix(char *raw_input, char input[4][4]);
void	check_1s(char input[4][4], char map[4][4], char imp[4][4][4]);

void	ft_rush(char *raw_input)
{
	char	input[4][4];
	char	map[4][4];
	char	imp[4][4][4];
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < 4)
	{
		while (j < 4)
		{
			map[i][j] = 'n';
			j++;
		}
		j = 0;
		i++;
	}
	input_to_matrix(raw_input, input);
	check_1s(input, map, imp);
	print_matrix(map);
}