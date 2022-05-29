NAME	= libft.a
SRC_DIR	= srcs
INC_DIR = includes
OBJ_DIR	= objs

CC		= gcc -Wall -Werror -Wextra -g
AR		= ar rcs
RLIB	= ranlib
INCS	= -I$(INC_DIR)

SRCS	= $(wildcard $(SRC_DIR)/*.c)
OBJS	= $(addprefix $(OBJ_DIR)/, $(notdir $(SRCS:.c=.o)))

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $@ $(OBJS)
	$(RLIB) $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(INCS) -c $< -o $@

$(OBJ_DIR):
	@mkdir $@

clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm $(NAME)

re: fclean all