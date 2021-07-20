CC			= clang

RM			= rm -rf

AR			= ar rcs

CFLAGS		= -Wall -Wextra -Werror

INCLUDES	=	-I../libft

NAME		= libaux.a

BDIR		= build/

SRC			=	apply_padding.c \
				eval_flags.c \
				eval_width.c \
				for_each_chunk.c \
				ft_printf.c \
				has_char.c \
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

OBJS	=	$(addprefix $(BDIR),${SRC:.c=.o})

.PHONY : clean fclean re

${NAME}: ${OBJS}
	${AR} ${NAME} ${OBJS}

${OBJS}: ${SRC}
	@mkdir -p ${BDIR}
	${CC} ${CFLAGS} -c $< -o $@ ${INCLUDES}

all: ${NAME}

bonus: ${NAME} 
	${AR} ${NAME}

clean:
	${RM} ${OBJS} ${BDIR}

fclean: clean
	${RM} ${NAME} 

re:	fclean all
