int		char_to_int(char num);
char	int_to_char(int num);

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
