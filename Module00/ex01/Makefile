NAME 		= 	phonebook

CC			= 	clang++

RM 			= 	rm -f

INC			=	-I include

CFLAGS		=	-Wall -Wextra -Werror -std=c++98

LFLAGS		=	-I./phonebook 


SRC			=	phonebook.cpp

OBJS		= 	$(SRC:.c=.o)

all:		$(NAME)

bonus:		$(BONUS)

%.o:		%.c
			$(CC) $(CFLAGS) -c $< $(OUTPUT_OPTION) $(INC)

$(NAME):	$(OBJS) 
			$(CC) $(OBJS) $(LFLAGS) $(OUTPUT_OPTION) -o $(NAME)  

clean:
			$(RM) $(OBJS)
		
fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re 