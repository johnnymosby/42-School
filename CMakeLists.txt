cmake_minimum_required(VERSION 3.23)
project(42_School C)

set(CMAKE_C_STANDARD 11)

add_executable(42_School
		"C Piscine/Rush01/main.c"
		"C Piscine/Rush01/check_array.c"
		"C Piscine/Rush01/check_columns.c"
		"C Piscine/Rush01/check_matrix.c"
		"C Piscine/Rush01/conversion.c"
		"C Piscine/Rush01/down_to_up.c"
		"C Piscine/Rush01/ft_check_input.c"
		"C Piscine/Rush01/ft_putchar.c"
		"C Piscine/Rush01/ft_putnbr.c"
		"C Piscine/Rush01/ft_putstr.c"
		"C Piscine/Rush01/ft_rush.c"
		"C Piscine/Rush01/ft_strlen.c"
		"C Piscine/Rush01/left_to_right.c"
		"C Piscine/Rush01/print_matrix.c"
		"C Piscine/Rush01/right_to_left.c"
		"C Piscine/Rush01/up_to_down.c"
		"C Piscine/Rush01/update_row.c")

#[[add_executable(42_School
       C00/main.c
       C00/ex00/ft_putchar.c
       C00/ex01/ft_print_alphabet.c
       C00/ex02/ft_print_reverse_alphabet.c
       C00/ex03/ft_print_numbers.c
       C00/ex04/ft_is_negative.c
       C00/ex05/ft_print_comb.c
       C00/ex06/ft_print_comb2.c
	   C00/ex07/ft_putnbr.c
	   C00/ex08/ft_print_combn.c)]]

#add_executable(42_School
#	Rush00/main.c
#	Rush00/ft_putchar.c
#	Rush00/rush03.c)
