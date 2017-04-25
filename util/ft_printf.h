/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftprintf.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbotova <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 11:26:01 by dbotova           #+#    #+#             */
/*   Updated: 2017/01/07 14:02:09 by dbotova          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <wchar.h>
# include <locale.h>
# include <stdint.h>
# include <float.h>
# include "../libft.h"
# define ABS(x) (x < 0) ? (-x) : (x)
# define MIN(x, y) (x < y) ? (x) : (y)
# define MAX(x, y) (x > y) ? (x) : (y)
# define ROUND(x) (unsigned long long)(x + 5)
# define SPECS "sSpdDioOuUxXcCfF%"
# define STR "sSpdDioOuUxXcC +-.0123456789zlhj#%*L'"
# define FLAGS "+-.0123456789zlhj#* L'"
# define SMART_FREE(x) {free(x); x = NULL;}

union					u_types
{
	char				*s;
	char				c;
	int					d;
	int					is_digit;
	intmax_t			ix;
	unsigned int		u;
	unsigned long		ul;
	long long			ll;
	long				l;
	unsigned long long	ull;
	long long			p;
	char				ar[2];
	unsigned char		uc;
	unsigned short		us;
	wchar_t				*ws;
	wchar_t				wc;
	double				f;
	long double			lf;
};

typedef struct			s_flags
{
	int					is_hash;
	int					width;
	int					is_dot;
	int					is_minus;
	int					is_plus;
	int					is_zero;
	int					cutoff;
	int					is_l;
	int					is_j;
	int					is_space;
	int					is_h;
	int					is_o;
	int					is_z;
	int					is_cl;
	int					is_separete;
	char				*target;
}						t_flags;

int						ft_printf(char *args, ...);
// char					*ft_strdup(const char *string);
// char					*ft_strcpy(char *dest, const char *src);
int						ft_getnum(char *str, int *value);
void					ft_putwchar(wchar_t chr);
void					ft_putwstr(wchar_t *str, size_t size);
size_t					ft_wstrlen(wchar_t *str);
size_t					ft_wcharlen(wchar_t c);
char					*ft_num_separete(char *str);
unsigned int			ft_power(int n, int pow);
void					ft_putlnbr(unsigned int nb);
// void					ft_putchar(int c);
// void					ft_putstr(char const *s);
void					ft_putnstr(char const *s, int n);
char					*ft_ftoa_precision(long double n, int precision);
// char					*ft_itoa_base(int n, int base);
char					*ft_ltoa_base(long long n, int base);
char					*ft_ultoa_base(unsigned long long nb, int base);
// char					*ft_strupcase(char *str);
// char					*ft_strsub(char const *s, unsigned int start,
						size_t len);
// char					*ft_strncpy(char *dest, const char *src, size_t n);
// void					ft_bzero(void *ptr, int len);
// size_t					ft_strlen(const char *str);
int						ft_nbrsize(long n);
// int						ft_isdigit(int c);
// int						ft_isalpha(int c);
// int						ft_atoi(char *str);
// char					*ft_strchr(const char *str, int c);
// void					*ft_memset(void *ptr, int value, size_t num);
t_flags					*ft_newflagslst();
char					*ft_getflags(char *ptr, t_flags **flags, va_list ap);
void					ft_create_jump_table(int(*jump_table[])(va_list,
						union u_types, t_flags*));
int						ft_float_print(va_list ap, union u_types tp,
						t_flags *flags);
char					*ft_num_read(char *target, t_flags *flags,
						char **prefix, char **width);
char					*ft_char_read(char *target, t_flags *flags,
						char **prefix, char **width);
wchar_t					*ft_wchar_read(wchar_t *target, t_flags *flags,
						char **prefix, char **width);
wchar_t					*ft_wstr_read(wchar_t *target, t_flags *flags,
						char **prefix, char **width);
char					*ft_str_read(char *target, t_flags *flags,
						char **prefix, char **width);
char					*ft_undef_read(char *target, t_flags *flags,
						char **prefix, char **width);
char					*ft_hex_read(t_flags *flags,
						char **prefix, char **width, char *hash);
char					*ft_float_read(char *target, t_flags *flags,
						char **prefix, char **width);
char					*ft_pointer_read(char *target, t_flags *flags,
						char **prefix, char **width);
int						ft_octa_print(va_list ap, union u_types tp,
						t_flags *flags);
int						ft_cocta_print(va_list ap, union u_types tp,
						t_flags *flags);
int						ft_int_print(va_list ap, union u_types tp,
						t_flags *flags);
int						ft_cint_print(va_list ap, union u_types tp,
						t_flags *flags);
int						ft_hex_print(va_list ap, union u_types tp,
						t_flags *flags);
int						ft_chex_print(va_list ap, union u_types tp,
						t_flags *flags);
int						ft_unsigned_print(va_list ap, union u_types tp,
						t_flags *flags);
int						ft_cunsigned_print(va_list ap, union u_types tp,
						t_flags *flags);
int						ft_str_print(va_list ap, union u_types tp,
						t_flags *flags);
int						ft_cstr_print(va_list ap, union u_types tp,
						t_flags *flags);
int						ft_pointer_print(va_list ap, union u_types tp,
						t_flags *flags);
int						ft_char_print(va_list ap, union u_types tp,
						t_flags *flags);
int						ft_cchar_print(va_list ap, union u_types tp,
						t_flags *flags);
int						ft_print(union u_types tp, t_flags *flags);
int						ft_undef_print(char *ptr, t_flags *flags);

#endif
