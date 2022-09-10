void	input_to_matrix(char *raw_input, char input[4][4])
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (i < 4)
    {
        while (j < 4)
        {
            input[i][j] = raw_input[8 * i + 2 * j];
            j++;
        }
        j = 0;
        i++;
    }
}
