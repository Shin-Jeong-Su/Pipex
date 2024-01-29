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

BONUS = bonus
SRCS_BONUS_NAME = utils\
			 path\
			 init\
			 pipex\
			 main
SRCS_BONUS = $(addsuffix _bonus.c,$(SRCS_NAME))
DEPS_BONUS = $(addsuffix _bonus.d,$(SRCS_NAME))
OBJS_BONUS = $(addsuffix _bonus.o,$(SRCS_NAME))

LIB = ./libft/libft.a

all : $(NAME)

$(NAME): $(OBJS) $(LIB)
	$(CC) $^ -o $@; 
-include $(DEPS)

$(BONUS) : $(OBJS_BONUS) $(LIB)
	$(CC) $^ -o $@;
-include $(DEPS_BONUS)

$(LIB) :
	@$(MAKE) -C ./libft
	@$(MAKE) bonus -C ./libft

%.o : %.c
	@$(CC) $(CFLAGS) $(DEPFLAGS) -c $< -o $@

clean :
	@$(RM) $(OBJS) $(DEPS) $(OBJS_BONUS) $(DEPS_BONUS)
	@$(MAKE) -C ./libft clean
	@echo "cleaned"

fclean : clean
	@$(RM) $(NAME)
	@$(MAKE) -C ./libft fclean
	@echo "fcleaned"

re : fclean all

.PHONY = all clean fclean re
