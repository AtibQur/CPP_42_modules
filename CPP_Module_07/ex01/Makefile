NAME		=	iter
SRC_DIR		=	./src/
OBJ_DIR		=	obj/

INCS_DIR	=	./includes
MAIN_INC	=	-I $(INCS_DIR)
INCS		=	$($(INCS_DIR) -type f -name "*.hpp")

SRC			=	main.cpp \

OBJ			=	$(addprefix $(OBJ_DIR), $(SRC:.cpp=.o))

CC			=	c++
CFLAGS		=	-Wall -Wextra -Werror -std=c++98 -pedantic

$(OBJ_DIR)%.o:	$(SRC_DIR)%.cpp $(INCS)
		@mkdir -p $(OBJ_DIR)
		$(CC) ${CFLAGS}  $(MAIN_INC) -o $@ -c $<

$(NAME)		:	$(OBJ) $(INCS)
		$(CC) $(CFLAGS) $(OBJ) $(MAIN_INC) -o $(NAME)

all			:	$(NAME)

clean		:
		@rm -rf $(OBJ_DIR)

fclean		:	clean
		@rm -rf $(NAME)
		@rm -rf *.dSYM

re			:	fclean	all

exe			:	all
	./$(NAME)

.PHONY		:	all clean fclean re exe