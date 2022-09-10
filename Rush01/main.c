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
		m[iv][i][iv] = v;
		m[i][iv][iv] = v;
		i++;
	}
}

void	left_to_right(int x, int y, char v, char map[4][4], char imp[4][4][4])
{
	int	j;

	j = 0;
	while (j < 4)
	{
		map[][] = int_to_char(j);
		j++;
	}
}

void	check_1s(int x, int y, char v, char map[4][4], char imp[4][4][4])
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < 4)
	{
		while (j < 4)
		{
			if (m[i][j] == '1')
				if
		}
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
			for (int z = 0; z < 4; z++)
			{
				imp[i][j][z] = 'n';
			}
		}
	}

	value = '3';
	print_matrix(input);
	update_imp(3, 2, value, imp);
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