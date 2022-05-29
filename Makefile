NAME		= GBU_tester
INC_DIR		= includes
SRC_DIR		= srcs
OBJ_DIR		= objs
LIB_DIR		= $(SRC_DIR)/lib

INCS		= -I$(INC_DIR)
SRCS		= $(wildcard $(SRC_DIR)/*.c)
OBJS		= $(addprefix $(OBJ_DIR)/, $(notdir $(SRCS:.c=.o)))
LIB			= libft.a
LIB_INC		= $(LIB_DIR)/$(INC_DIR)

CC			= gcc -g -Wall -Werror -Wextra
LINK		= -L$(LIB_DIR) -lft -I$(LIB_INC)

all: $(NAME)

$(LIB):
	@make -s -C $(LIB_DIR)

$(NAME): $(LIB) $(OBJS)
	$(CC) $(INCS) $(OBJS) -o $@ $(LINK)

$(OBJ_DIR)/%.o: */%.c | $(OBJ_DIR)
	$(CC) $(INCS) -c $< -o $@ $(LINK)

$(OBJ_DIR):
	@mkdir $@

clean:
	@rm -rf $(NAME)

fclean: clean
	@rm -rf $(OBJ_DIR)
	@make -s -C $(LIB_DIR) fclean

re: fclean all