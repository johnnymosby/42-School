int		char_to_int(char num);
char	int_to_char(int num);
void	update_imp(int x, int y, char v, char m[4][4][4]);

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
			{
				if (i == 0)
					up_to_down(j, map, imp);
				else if (i == 1)
					down_to_up(j, map, imp);
				else if (i == 2)
					left_to_right(j, map, imp);
				else if (i == 3)
					right_to_left(j, map, imp);
			}
			j++;
		}
		j = 0;
		i++;
	}
}
