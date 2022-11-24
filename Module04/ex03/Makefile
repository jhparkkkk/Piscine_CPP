CC		=	c++
CFLAGS	=	-Wall -Werror -Wextra -std=c++98 -g
RM		=	rm -rf

NAME	=	materia

SRCS	=	main.cpp \
			AMateria.cpp \
			MateriaSource.cpp \
			Character.cpp \
			Ice.cpp \
			Cure.cpp

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
