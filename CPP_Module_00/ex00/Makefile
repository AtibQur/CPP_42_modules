NAME		= megaphone

CC			= c++
CPPFLAGS	= -Wall -Werror -Wextra -std=c++98

SRCS		= ./megaphone.cpp
OBJS		= $(SRCS:%.cpp=%.o)

all:		$(NAME)

$(NAME):	$(SRCS)
		$(CC) $(CPPFLAGS) $(SRCS) -o $(NAME)
		@echo "\033[0;32mTime to be LOUD!\033[0m"

clean:
		@rm -f $(OBJS)
		@echo "\033[0;32mCleaned!\033[0m"

fclean:
		@rm -f $(NAME)
		@echo "\033[0;32mCleaned!\033[0m"

re:				fclean all

.PHONY:	all clean fclean re