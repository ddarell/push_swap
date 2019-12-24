NAME_CH = checker
NAME_PS = push_swap
LIB = libftprintf.a
LIB_DIR = ./ft_printf/
HEADER = ps_header.h
CC = gcc
CFLAGS = -Wall -Wextra -Werror
IFLAGS = -I $(HEADER)
LFLAGS = -L $(LIB_DIR) -lftprintf

SRCS_CH =	checker.c\
			ft_check_pa.c\
			ft_check_pb.c\
			ft_check_rr.c\
			ft_check_rrr.c\
			ft_check_sa.c\
			ft_commant_list.c\
			ft_detect_sorted_data.c\
			ft_error.c\
			ft_fill_stack_a.c\
			ft_find_closest_insert.c\
			ft_finish_sort.c\
			ft_func_ls.c\
			ft_generate_commands.c\
			ft_read_exec_commands.c\
			ft_get_order.c\
			ft_insert.c\
			ft_int_tab_func.c\
			ft_nodes.c\
			ft_pab.c\
			ft_show.c\
			ft_rabr.c\
			ft_rrabr.c\
			ft_sabs.c\
			ft_search_in_ls.c\
			ft_sets.c\
			ft_usage.c\
			ft_check_option.c\

SRCS_PS =	push_swap.c\
			ft_check_pa.c\
			ft_check_pb.c\
			ft_check_rr.c\
			ft_check_rrr.c\
			ft_check_sa.c\
			ft_commant_list.c\
			ft_detect_sorted_data.c\
			ft_error.c\
			ft_fill_stack_a.c\
			ft_find_closest_insert.c\
			ft_finish_sort.c\
			ft_func_ls.c\
			ft_generate_commands.c\
			ft_get_next_command.c\
			ft_get_order.c\
			ft_insert.c\
			ft_int_tab_func.c\
			ft_nodes.c\
			ft_pab.c\
			ft_show.c\
			ft_rabr.c\
			ft_rrabr.c\
			ft_sabs.c\
			ft_search_in_ls.c\
			ft_sets.c\
			ft_usage.c\
			ft_check_option.c\

.PHONY: all clean fclean re lib

OBJS_CH = $(SRCS_CH:.c=.o)

OBJS_PS = $(SRCS_PS:.c=.o)

LIB = make -C $(LIB_DIR)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) $(IFLAGS) -c -o $@ ./$<

all: $(NAME_CH) $(NAME_PS)

$(NAME_CH): $(OBJS_CH)
	$(LIB)
	$(CC) $(CFLAGS) $(IFLAGS) -o $@ $^ $(LFLAGS)


$(NAME_PS): $(OBJS_PS)
	$(LIB)
	$(CC) $(CFLAGS) $(IFLAGS) -o $@ $^ $(LFLAGS)

clean:
	make clean -C $(LIB_DIR)
	rm -f $(OBJS_CH)
	rm -f $(OBJS_PS)

fclean: clean
	make fclean -C $(LIB_DIR)
	rm -f $(NAME_CH)
	rm -f $(NAME_PS)

re: fclean all
