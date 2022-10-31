
NAME	= megaphone


CC            := clang++
CFLAGS        := -Wall -Wextra -Werror -std=c++98

SRCS_PATH	:=	src
OBJS_PATH	:=	obj

SRCS     	+=	megaphone.cpp

SRCS          := $(SRCS:%=$(SRCS_PATH)/%)

OBJS          := $(SRCS:$(SRCS_PATH)/%.c=$(OBJS_PATH)/%.o)

RM            := rm -f

$(NAME): $(OBJS) $(LIBFT_PATH)$(LIBFT_A) $(MLX_PATH)$(MLX_A)
	$(CC) $(OBJS) $(LFLAGS) $(OUTPUT_OPTION) 
	echo "CREATED $(NAME)"

all:          $(NAME)

$(OBJS_PATH)/%.o: $(SRCS_PATH)/%.c 
	@ mkdir -p $(@D)
	$(CC) $(CFLAGS) $< $(OUTPUT_OPTION) $(INC) 
	echo "CREATED $@"

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

# info:
# 	make --dry-run --always-make --no-print-directory | grep -v "echo \| mkdir"

# .SILENT:
.PHONY:    all clean fclean re 