NAME		= 	philo

SRC_DIR		= 	src
OBJ_DIR		= 	obj
INCLUDE_DIR	= 	include

INCLUDES	=	-I $(INCLUDE_DIR)
SRCDIRS		=	$(shell find $(SRC_DIR) -type d)
INCLUDES 	+=	$(addprefix -I ,$(SRCDIRS))

CC			=	cc
RM			=	rm
CFLAGS		=	-Wall -Wextra -Werror -g

SRCS		=	$(SRC_DIR)/main.c \
				$(SRC_DIR)/init/arg_parse.c \
				$(SRC_DIR)/init/arg_to_env.c \
				$(SRC_DIR)/init/init.c \
				$(SRC_DIR)/init/init_each.c \
				$(SRC_DIR)/process/close.c \
				$(SRC_DIR)/process/process_monitor.c \
				$(SRC_DIR)/process/process_philo.c \
				$(SRC_DIR)/utils/time_utils.c \
				$(SRC_DIR)/utils/utils.c
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