NAME	=	array

CC		=	c++
CFLAGS	=	-Wall -Werror -Wextra -std=c++98 -MMD
RM		=	rm -rf

SRCS	=	main.cpp \
	
OBJS	=	$(SRCS:.cpp=.o)

all: $(NAME) Makefile

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@

%.o: %.cpp
	   $(CC) $(CFLAGS) -c $< $(OUTPUT_OPTION)
clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

-include : $(OBJS:%.o=%.d)

.PHONY:		all clean fclean re 
