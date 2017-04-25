# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dbotova <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/11 10:46:30 by dbotova           #+#    #+#              #
#    Updated: 2016/11/11 10:50:50 by dbotova          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PPATH = ./print
RPATH = ./read
LPATH = ./lib
UPATH = ./util

SRC	=	ft_printf.h	ft_printf.c													\
		$(PPATH)/ft_cchar_print.c $(PPATH)/ft_char_print.c 						\
		$(PPATH)/ft_chex_print.c $(PPATH)/ft_cint_print.c 						\
		$(PPATH)/ft_cocta_print.c $(PPATH)/ft_cstr_print.c 						\
		$(PPATH)/ft_cunsigned_print.c $(PPATH)/ft_float_print.c 				\
		$(PPATH)/ft_hex_print.c $(PPATH)/ft_int_print.c 						\
		$(PPATH)/ft_octa_print.c $(PPATH)/ft_pointer_print.c 					\
		$(PPATH)/ft_print.c $(PPATH)/ft_str_print.c $(PPATH)/ft_undef_print.c 	\
		$(PPATH)/ft_unsigned_print.c 											\
		$(RPATH)/ft_char_read.c $(RPATH)/ft_float_read.c $(RPATH)/ft_hex_read.c \
		$(RPATH)/ft_num_read.c $(RPATH)/ft_pointer_read.c $(RPATH)/ft_str_read.c\
		$(RPATH)/ft_undef_read.c $(RPATH)/ft_wchar_read.c 						\
		$(RPATH)/ft_wstr_read.c 												\
		$(LPATH)/ft_atoi.c $(LPATH)/ft_bzero.c $(LPATH)/ft_ftoa_precision.c 	\
		$(LPATH)/ft_getnum.c $(LPATH)/ft_isalpha.c $(LPATH)/ft_isdigit.c 		\
		$(LPATH)/ft_itoa_base.c $(LPATH)/ft_ltoa_base.c $(LPATH)/ft_memset.c 	\
		$(LPATH)/ft_nbrsize.c $(LPATH)/ft_power.c $(LPATH)/ft_putchar.c 		\
		$(LPATH)/ft_putnstr.c $(LPATH)/ft_putstr.c $(LPATH)/ft_putwchar.c 		\
		$(LPATH)/ft_putwstr.c $(LPATH)/ft_strchr.c $(LPATH)/ft_strcpy.c 		\
		$(LPATH)/ft_strdup.c $(LPATH)/ft_strlen.c $(LPATH)/ft_strncpy.c 		\
		$(LPATH)/ft_strsub.c $(LPATH)/ft_strupcase.c $(LPATH)/ft_ultoa_base.c 	\
		$(LPATH)/ft_wcharlen.c $(LPATH)/ft_wstrlen.c $(LPATH)/ft_num_separete.c	\
		$(UPATH)/ft_create_jump_table.c $(UPATH)/ft_getflags.c 					\
		$(UPATH)/ft_newflagslst.c 

OBJ	=	ft_printf.o	ft_cchar_print.o ft_char_print.o ft_chex_print.o 			\
		ft_cint_print.o ft_cocta_print.o ft_cstr_print.o ft_cunsigned_print.o   \
		ft_float_print.o ft_hex_print.o ft_int_print.o ft_octa_print.o 			\
		ft_pointer_print.o ft_print.o ft_str_print.o ft_undef_print.o 			\
		ft_unsigned_print.o ft_char_read.o ft_float_read.o ft_hex_read.o 		\
		ft_num_read.o ft_pointer_read.o ft_str_read.o ft_undef_read.o 			\
		ft_wchar_read.o ft_wstr_read.o ft_atoi.o ft_bzero.o ft_ftoa_precision.o \
		ft_getnum.o ft_isalpha.o ft_isdigit.o ft_itoa_base.o ft_ltoa_base.o 	\
		ft_memset.o ft_nbrsize.o ft_power.o ft_putchar.o ft_putnstr.o 			\
		ft_putstr.o ft_putwchar.o ft_putwstr.o ft_strchr.o ft_strcpy.o 			\
		ft_strdup.o ft_strlen.o ft_strncpy.o ft_strsub.o ft_strupcase.o 		\
		ft_ultoa_base.o ft_wcharlen.o ft_wstrlen.o ft_create_jump_table.o 		\
		ft_getflags.o ft_newflagslst.o ft_num_separete.o
NAME = 	libftprintf.a

all: $(NAME)

$(NAME):
	gcc -c -Wall -Werror -Wextra $(SRC)
	ar rc $(NAME) $(OBJ)

clean: 
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
