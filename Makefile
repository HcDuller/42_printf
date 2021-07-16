AR			=	ar rcs
CC			=	clang
CFLAGS		=	-Wall -Werror -Wextra

NAME		=	libftprintf.a

LIBFT_D		=	libft
LIBAUX_D	=	libaux
BUILD_D		=	build

RM			=	rm -rfd

LIBFT_SRC	=	ft_atoi.c \
				ft_calloc.c \
				ft_isalpha.c \
				ft_isdigit.c \
				ft_memccpy.c \
				ft_memcmp.c \
				ft_memmove.c \
				ft_strchr.c \
				ft_strlcat.c \
				ft_strlen.c \
				ft_strnstr.c \
				ft_tolower.c \
				ft_bzero.c \
				ft_isalnum.c \
				ft_isascii.c \
				ft_isprint.c \
				ft_memchr.c \
				ft_memcpy.c \
				ft_memset.c \
				ft_strdup.c \
				ft_strlcpy.c \
				ft_strncmp.c \
				ft_strrchr.c \
				ft_toupper.c \
				ft_substr.c \
				ft_strjoin.c \
				ft_strtrim.c \
				ft_split.c \
				ft_itoa.c \
				ft_strmapi.c \
				ft_putchar_fd.c \
				ft_putstr_fd.c \
				ft_putendl_fd.c \
				ft_putnbr_fd.c

LIBAUX_SRC	=	apply_padding.c \
				eval_flags.c \
				eval_width.c \
				for_each_chunk.c \
				ft_printf.c \
				input_is_int.c \
				input_is_ulong.c \
				new_chunk.c \
				proc_d_flags.c \
				proc_s_flags.c \
				res_from_c.c \
				eval_conversion.c \
				eval_precision.c \
				first_chunk.c \
				free_chunk.c \
				input_is_char_p.c \
				input_is_uint.c \
				new_last_chunk.c \
				proc_p_flags.c \
				proc_ux_flags.c \
				res_from_d.c

LIBFT_SRC	:= $(addprefix ${LIBFT_D}/${BUILD_D}/,${LIBFT_SRC})
LIBFT_OBJ	:= ${LIBFT_SRC:.c=.o}

LIBAUX_OBJ	:= $(addprefix ${BUILD_D}/,${LIBAUX_SRC:.c=.o})
LIBAUX_SRC	:= $(addprefix ${LIBAUX_D}/,${LIBAUX_SRC})

all : ${NAME}

clean:
	${RM} ${LIBAUX_OBJ} ${BUILD_D} ${LIBFT_OBJ} ${LIBFT_D}/${BUILD_D} ${LIBFT_D}/libft.a 

bonus: all

fclean: clean
	${RM} ${NAME}

re:	fclean all

${LIBFT_D}/libft.a : ${LIBFT_OBJ}
	${AR} ${LIBFT_D}/libft.a ${LIBFT_OBJ}

${LIBFT_D}/${BUILD_D}/%.o : ${LIBFT_D}/%.c
	@mkdir -p ${LIBFT_D}/${BUILD_D}
	${CC} ${CFLAGS} $< -c -o $@

${BUILD_D}/%.o : ${LIBAUX_D}/%.c
	@mkdir -p ${BUILD_D}
	${CC} ${CFLAGS} $< -c -o $@ -I../libft -I../libaux

${NAME} : ${LIBFT_D}/libft.a ${LIBAUX_OBJ}
	@cp ${LIBFT_D}/libft.a ${NAME}
	${AR} ${NAME} ${LIBAUX_OBJ}
	