NAME	=	RPN

CC		=	c++
CFLAGS	=	-Wall -Werror -Wextra -std=c++98 
RM		=	rm -rf

SRCS	=	main.cpp \
			RPN.cpp \
	

OBJS	=	$(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@

%.o: %.cpp
	   $(CC) $(CFLAGS) -c $< $(OUTPUT_OPTION)
clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY:		all clean fclean re 
