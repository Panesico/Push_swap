NAME		=	push_swap

C			=	gcc

CFLAGS	=	-Wall -Werror -Wextra -g

#directories
SRC_DIR					=	src/
OBJ_DIR					=	obj/
INC_DIR					=	include/
CURRENT_PATH			=	$(shell pwd)
CURRENT_DIRECTORY_NAME	=	$(shell basename $(CURRENT_PATH))
CURRENT_DIRECTORY		:=	./$(CURRENT_DIRECTORY_NAME)

#control codes
RESET		=	\033[0m
GREEN		=	\033[32m
YELLOW		=	\033[33m
BLUE		=	\033[34m
RED			=	\033[31m
UP			=	\033[A
CUT			=	\033[K

#source files
SRC_FILES	=	main.c lis.c move_sets.c parser.c push_swap_moves.c small_sort.c struc.c validator.c

OBJ_FILES	=	$(SRC_FILES:.c=.o)
LIBFT_DIR	=	./libft/
LIBFT		= $(addprefix $(LIBFT_DIR),libft.a)

#paths
SRC			=	$(addprefix $(SRC_DIR), $(SRC_FILES))
OBJ			=	$(addprefix $(OBJ_DIR), $(OBJ_FILES))

#all rule
all: $(NAME)


#compile the executable
$(NAME): $(OBJ)
	@echo "$(YELLOW)Compiling [$(NAME)]...$(RESET)"
	@$(C) $(CFLAGS) $(OBJ) -o $(NAME) $(LIBFT)
	@echo "$(GREEN)Finished [$(NAME)]$(RESET)"

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

#compile objects
$(OBJ_DIR)%.o:$(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	@echo "$(YELLOW)Compiling [$@]...$(RESET)"
	@$(C) $(CFLAGS) -I $(INC_DIR) -o $@ -c $<
	@printf "$(UP)$(CUT)"
	@echo "$(GREEN)Finished [$@]$(RESET)"
	@printf "$(UP)$(CUT)"

#clean rule
clean:
	@if [ -d "$(OBJ_DIR)" ]; then \
	rm -rf $(OBJ_DIR); \
	echo "$(BLUE)Deleting all objects from $(CURRENT_DIRECTORY)...$(RESET)"; else \
	echo "No objects to remove from $(CURRENT_DIRECTORY)."; \
	fi;

#fclean rule
fclean: clean
	@if [ -f "$(NAME)" ]; then \
	rm -f $(NAME); \
	echo "$(BLUE)Deleting $(RED)$(NAME)$(BLUE) binary from $(CURRENT_DIRECTORY)$(RESET)"; else \
	echo "No Executable to remove from $(CURRENT_DIRECTORY)."; \
	fi;

#re rule
re: fclean all

#phony
.PHONY: all clean fclean re