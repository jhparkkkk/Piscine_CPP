CC		=	clang++
CFLAGS	=	-Wall -Werror -Wextra -std=c++98
RM		=	rm -rf

NAME	=	account

SRCS	=	Account.cpp \
			tests.cpp 

OBJS	=	$(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@

.cpp.o: $(SRCS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY:		all clean fclean re 
