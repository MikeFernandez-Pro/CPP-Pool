NAME		= ex01
SRCSC		= main.cpp
SRCSH		= 
OBJS		= $(SRCSC:%.cpp=%.o)
LIBS 		= 
FLAGS		= -Wall -Wextra -Werror -std=c++98
CC			= clang++

all:		${NAME}

.c.o: ${OBJS}
	@clang++ ${FLAGS} -cpp $< -o ${<:.cpp=.o}

$(NAME):	${OBJS} ${SRCSH}
			@${CC} ${FLAGS} ${OBJS} ${LIBS} -o ${NAME}
			@echo "\033[1;32m┌─┐┬ ┬┌─┐┌─┐┌─┐┌─┐┌─┐"
			@echo 			"└─┐│ ││  │  ├┤ └─┐└─┐"
			@echo 			"└─┘└─┘└─┘└─┘└─┘└─┘└─┘"
			@echo "${NAME} generated successfully.\033[0;0m"

run:
			@make
			@./${NAME}

clean:
			@rm -f ${OBJS}
			@echo "\033[1;31m${NAME} : Removing .o files\033[0;0m"

fclean:		clean
			@rm -f ${NAME}
			@echo "\033[1;31m${NAME} : Removing binary file\033[0;0m"

re:			fclean all

.PHONY:		all clean fclean re