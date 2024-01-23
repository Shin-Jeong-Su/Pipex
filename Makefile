NAME = pipex
CC = cc
CFLAGS = -Werror -Wall -Wextra 
DEPFLAGS = -MMD -MP
RM = rm -rf

SRCS_NAME = utils\
			 path\
			 pipex
SRCS = $(addsuffix .c,$(SRCS_NAME))
DEPS = $(addsuffix .d,$(SRCS_NAME))
OBJS = $(addsuffix .o,$(SRCS_NAME))
LIB = ./libft/libft.a

all : $(NAME)

$(NAME): $(OBJS) $(LIB)
	@if [ -e $(NAME) ]; then \
		echo "$(NAME) already exists. Skipping bulid"; \
	else \
		$(CC) $^ -o $@; \
	fi
-include $(DEPS)
$(LIB) :
	@$(MAKE) -C ./libft
	@$(MAKE) bonus -C ./libft

%.o : %.c
	@$(CC) $(CFLAGS) $(DEPFLAGS) -c $< -o $@

clean :
	@$(RM) $(OBJS) $(DEPS)
	@$(MAKE) -C ./libft clean
	@echo "cleaned"
fclean : clean
	@$(RM) $(NAME)
	@$(MAKE) -C ./libft fclean
	@echo "fcleaned"
re : fclean all

.PHONY = all clean fclean re
