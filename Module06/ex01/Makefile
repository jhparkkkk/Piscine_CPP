NAME	=	serialize

CC		=	clang++
CFLAGS	=	-Wall -Werror -Wextra -std=c++98 -pedantic
RM		=	rm -rf

SRCS	=	main.cpp \
			serialize.cpp \
			deserialize.cpp  

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
