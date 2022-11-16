NAME		= 	philo

SRC_DIR		= 	src
OBJ_DIR		= 	obj
INCLUDE_DIR	= 	include

INCLUDES	=	-I $(INCLUDE_DIR)
SRCDIRS		=	$(shell find $(SRC_DIR) -type d)
INCLUDES 	+=	$(addprefix -I,$(SRCDIRS))

CC			=	cc
RM			=	rm
CFLAGS		=	-Wall -Wextra -Werror

SRCS		=	$(SRC_DIR)/main.c
OBJS		=	$(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
DEPS		=	$(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.d)
.PHONY: $(DEPS)

all:			$(NAME)

$(NAME):		$(OBJS)
				$(CC) $(OBJS) $(CFLAGS) -o $(NAME)

$(OBJ_DIR)/%.o:	$(SRC_DIR)/%.c
				@mkdir -p $$(dirname $@)
				$(CC) $(CFLAGS) $(INCLUDES) -MMD -MP -c $< -o $@

clean:
				$(RM) -rf $(OBJS) $(OBJ_DIR)

fclean:			clean
				$(RM) -f $(NAME)

re:				fclean all

.PHONY:			all clean fclean re
-include $(DEPS)