#include <unistd.h>

void	ft_putchar(char c);
void	print_matrix(char m[4][4]);
void	input_to_matrix(char *raw_input, char input[4][4]);

void	ft_swap(int *a, int *b)
{
	int	point;

	point = *a;
	*a = *b;
	*b = point;
}

void	fill_arrays(char *seq, char arrays[24], int start, int end)
{
	int i;
	int m;

	i = 0;
	if (start == end)
	{
		m = 0;
		while (m < 24)
		{
			if (arrays[m] == '0')
				arrays[m] = *seq;
				break;
		}
	}
	else
	{
		while (i <= end)
		{
			ft_swap(seq + start, seq + i);
			fill_arrays(seq, 1 + start, end);
			ft_swap(seq + start, seq + i);
		}
	}
}
void	ft_rush(char *raw_input)
{
	char	input[4][4];
	char	map[4][4];
	char	arrays[24];
	int		a;
	int		b;
	int		c;
	int		d;

	a = 0;
	while (a < 24)
	{
		arrays[a] = '0';
		a++;
	}

	while (a < 4)
	{
		while (b < 4)
		{
			while (c < 4)
			{
				while (d < 4)
				{

				}
			}
		}
		j = 0;
		i++;
	}


	input_to_matrix(raw_input, input);
	print_matrix(map);
}