NAME = minishell

CC = cc

FLAGS = -Wextra -Wall -Werror -I/Users/kelmounj/.brew/opt/readline/include 

LDFLAGS = -lreadline -L/Users/kelmounj/.brew/opt/readline/lib 
# -fsanitize=address -g

SRCS = sources/minishell.c sources/parser1.c sources/parser2.c sources/utils1.c sources/utils2.c sources/utils3.c sources/init.c


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