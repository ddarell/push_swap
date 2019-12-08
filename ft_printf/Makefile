# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ddarell <ddarell@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/26 14:51:55 by ddarell           #+#    #+#              #
#    Updated: 2019/12/02 19:55:48 by ddarell          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
LIBFT_A = libft.a
H_DIR = ./
LIB_DIR = ./libft/
HEADER = ft_printf.h
CC = gcc -Wall -Wextra -Werror

SRCS =	ft_printf.c\
		ft_sets.c\
		ft_matching_format.c\
		ft_matching_length.c\
		ft_matching_type.c\
		ft_printf_pointer.c\
		ft_printf_string.c\
		ft_printf_char.c\
		ft_printf_d_i_n_h_hh.c\
		ft_printf_d_i_u_ll.c\
		ft_printf_d_i_u_l.c\
		ft_printf_u_n_h_hh.c\
		ft_printf_o_n_h_hh.c\
		ft_printf_o_ll.c\
		ft_printf_o_l.c\
		ft_printf_xx_n_h_hh.c\
		ft_printf_x_n_h_hh.c\
		ft_printf_x_xx_ll.c\
		ft_printf_x_xx_l.c\
		ft_printf_b_l_ll.c\
		ft_printf_b_n_h_hh.c\
		ft_printf_percent.c\
		ft_buff_int.c\
		ft_set_hex_alpha.c\
		ft_buffering.c\
		ft_put_digit.c\
		ft_min_pow_array.c\
		ft_printf_lf.c\
		ft_printf_llf.c\
		ft_printf_e_ee_l_ll.c\
		ft_approx_double.c\
		ft_buff_double.c\
		ft_set_double_struct.c\
		ft_mult_sum_array.c\
		ft_fprint_not_format.c\
		ft_color.c\

OBJS = $(SRCS:.c=.o)

.PHONY: all clean fclean re lib

all: $(NAME)

$(NAME): $(OBJS)
	make -C $(LIB_DIR)
	cp $(LIB_DIR)$(LIBFT_A) .
	mv $(LIBFT_A) $(NAME)
	ar -rc $(NAME) $(OBJS)
	ranlib $(NAME)
	
%.o: %.c $(HEADER)
	$(CC) -I . -c ./$< -o $@

clean:
	make clean -C $(LIB_DIR)
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIB_DIR)

re: fclean all
