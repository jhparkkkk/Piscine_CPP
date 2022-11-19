CC		=	clang++
CFLAGS	=	-Wall -Werror -Wextra -std=c++98 -g3
RM		=	rm -rf

NAME	=	brain

SRCS	=	main.cpp \


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
