NAME = minishell

CC = cc

FLAGS = -Wextra -Wall -Werror -I/Users/kelmounj/.brew/opt/readline/include  -g3 -fsanitize=address -g

LDFLAGS = -lreadline -L/Users/kelmounj/.brew/opt/readline/lib  -g3  -fsanitize=address -g

SRCS = sources/minishell.c lexer/lexer0.c lexer/lexer1.c lexer/lexer2.c lexer/lexer3.c lexer/lexer4.c \
		parser/parser.c parser/parser0.c parser/parser1.c parser/parser2.c \
		tokenizer/tokenizer0.c tokenizer/tokenizer1.c tokenizer/tokenizer2.c \
		sources/utils1.c sources/utils2.c sources/utils3.c sources/utils4.c sources/utils5.c sources/init.c sources/is_utils1.c sources/is_utils2.c \
		sources/is_utils3.c sources/ft_getfullenv.c sources/ft_getenv.c sources/ft_setenv.c \
		sources/ft_itoa.c sources/ft_openhd.c sources/ft_execution.c sources/ft_split.c sources/ft_atoi.c \
		sources/ft_openfd.c sources/ft_getnode.c sources/ft_printferror.c sources/ft_redirection.c\
		sources/ft_data_init.c\
		sources/fill_tok.c 
		sources/ft_data_init.c  builtins/env.c builtins/handel_builtin.c builtins/exit.c builtins/pwd.c\
		builtins/unset.c builtins/echo.c builtins/cd.c

HEADERS = sources/minishell.h

OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	@$(CC) $(LDFLAGS) $^ -o $@
	@echo "\033[32mMaking Completed ✅😜"

$(OBJS) : %.o: %.c $(HEADERS) Makefile
	@$(CC) $(FLAGS) -c $< -o $@

clean :
	@rm -f $(OBJS)
	@echo "\033[0;33mCleaning Completed 🧼✨"

fclean : clean
	@rm -f $(NAME)
	@echo "\033[0;31mRemoving Completed 🗑 💔"

re : fclean all

.PHONY : clean		