NAME = pipex
CC = cc
CFLAGS = -Wall -Wextra -Werror
DEPFLAGS = -MMD -MP
DEBUGFALGS = -g -fsanitize=address
RM = rm -rf

SRCS_NAME = utils\
			 path\
			 pipex\
			 main
SRCS = $(addsuffix .c,$(SRCS_NAME))
DEPS = $(addsuffix .d,$(SRCS_NAME))
OBJS = $(addsuffix .o,$(SRCS_NAME))

SRCS_BONUS_NAME = utils\
			 path\
			 init\
			pipex\
			 main
SRCS_BONUS = $(addsuffix _bonus.c,$(SRCS_BONUS_NAME))
DEPS_BONUS = $(addsuffix _bonus.d,$(SRCS_BONUS_NAME))
OBJS_BONUS = $(addsuffix _bonus.o,$(SRCS_BONUS_NAME))

LIB = ./libft/libft.a

all : $(NAME)

$(NAME): $(OBJS) $(LIB)
	@$(CC) $^ -o $@
	@echo "pipex made"
-include $(DEPS)

bonus : $(OBJS_BONUS) $(LIB)
	@$(CC) $^ -o $(NAME)
	@touch bonus
	@echo "pipex bonus made"
# -include $(DEPS_BONUS)

$(LIB) :
	@$(MAKE) -C ./libft
	@$(MAKE) bonus -C ./libft

%.o : %.c
	@$(CC) $(CFLAGS) $(DEPFLAGS) -c $< -o $@

clean :
	@$(RM) $(OBJS) $(DEPS) $(OBJS_BONUS) $(DEPS_BONUS) bonus
	@$(MAKE) -C ./libft clean
	@echo "cleaned"

fclean : clean
	@$(RM) $(NAME)
	@$(MAKE) -C ./libft fclean
	@echo "fcleaned"

re : fclean all

.PHONY = all clean fclean re
