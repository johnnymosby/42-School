#include <unistd.h>
#include <stdio.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	print_matrix(char m[4][4])
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < 4)
	{
		while (j < 4)
		{
			ft_putchar(m[i][j]);
			ft_putchar(' ');
			j++;
		}
		j = 0;
		ft_putchar('\n');
		i++;
	}
}

int	char_to_int(char num)
{
	if (num == '4')
		return (3);
	if (num == '3')
		return (2);
	if (num == '2')
		return (1);
	if (num == '1')
		return (0);
}

char	int_to_char(int num)
{
	if (num == 3)
		return ('4');
	if (num == 2)
		return ('3');
	if (num == 1)
		return ('2');
	if (num == 0)
		return ('1');
}

void	update_imp(int x, int y, char v, char m[4][4][4])
{
	int	i;
	int	iv;

	i = 0;
	iv = char_to_int(v);
	while (i < 4)
	{
		m[x][y][i] = int_to_char(i);
		i++;
	}
	i = 0;
	while (i < 4)
	{
		m[x][i][iv] = v;
		m[i][y][iv] = v;
		i++;
	}
}

void	left_to_right(int x, char map[4][4], char imp[4][4][4])
{
	int	j;

	j = 0;
	while (j < 4)
	{
		map[x][j] = int_to_char(j);
		update_imp(x, j, int_to_char(j), imp);
		j++;
	}
}

void	right_to_left(int x, char map[4][4], char imp[4][4][4])
{
	int	j;

	j = 0;
	while (j < 4)
	{
		map[x][j] = int_to_char(3 - j);
		update_imp(x, j, int_to_char(3 - j), imp);
		j++;
	}
}

void	up_to_down(int y, char map[4][4], char imp[4][4][4])
{
	int	i;

	i = 0;
	while (i < 4)
	{
		map[i][y] = int_to_char(i);
		update_imp(i, y, int_to_char(i), imp);
		i++;
	}
}

void	down_to_up(int y, char map[4][4], char imp[4][4][4])
{
	int	i;

	i = 0;
	while (i < 4)
	{
		map[i][y] = int_to_char(3 - i);
		update_imp(i, y, int_to_char(3 - i), imp);
		i++;
	}
}

void	check_1s(char input[4][4], char map[4][4], char imp[4][4][4])
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < 4)
	{
		while (j < 4)
		{
			if (input[i][j] == '4')
				if (i == 0)
					up_to_down(j, map, imp);
				else if (i == 1)
					down_to_up(j, map, imp);
				else if (i == 2)
					left_to_right(j, map, imp);
				else if (i == 3)
					right_to_left(j, map, imp);
			j++;
		}
		j = 0;
		i++;
	}
}

int	main(void)
{
	char	input[4][4] = {
			{'4', '2', '2', '1'},
			{'1', '2', '2', '4'},
			{'4', '2', '2', '1'},
			{'1', '2', '2', '4'}
	};
	char	map[4][4];
	char	imp[4][4][4];
	char	value;

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			map[i][j] = 'n';
		}
	}



	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			for (int z = 0; z < 4; z++)
			{
				imp[i][j][z] = 'n';
			}
		}
	}
	check_1s(input, map, imp);
	print_matrix(input);
	print_matrix(map);

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			for (int z = 0; z < 4; z++)
			{
				printf("%c", imp[i][j][z]);
			}
			printf("%c", '\n');
		}
		printf("%c", '\n');
	}
	return (0);
}