# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: user42 <user42@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/22 13:43:47 by user42            #+#    #+#              #
#    Updated: 2020/10/22 13:43:48 by user42           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= ex01
SRCS_PATH	= ./
OBJS_PATH	= ./objs/
SRCSC		= iter.cpp

SRCSH		=
SRCS		= $(addprefix $(SRCS_PATH),$(SRCSC))
OBJS 		= $(addprefix $(OBJS_PATH),$(OBJS_NAME))
OBJS_NAME	= $(SRCSC:%.cpp=%.o)
LIBS 		= 
CXXFLAGS	= -Wall -Wextra -Werror -std=c++98
CXX			= clang++
LOGFILE		= $(LOGPATH) `date +'%y.%m.%d %H:%M:%S'`

all:		${NAME}

.c.o: 		${OBJS}
			@clang++ ${CXXFLAGS} -cpp $< -o ${<:.cpp=.o}

$(NAME):	${OBJS} ${SRCSH}
			@${CXX} ${CXXFLAGS} ${OBJS} ${LIBS} -o ${NAME}
			@echo "\033[1;32m┌─┐┬ ┬┌─┐┌─┐┌─┐┌─┐┌─┐"
			@echo 			"└─┐│ ││  │  ├┤ └─┐└─┐"
			@echo 			"└─┘└─┘└─┘└─┘└─┘└─┘└─┘"
			@echo "Program generated successfully.\033[0;0m"

$(OBJS_PATH)%.o: $(SRCS_PATH)%.cpp
				@mkdir -p $(OBJS_PATH)
				@clang++ $(CXXFLAGS) -o $@ -c $<

bonus:		${NAME}

clean:
			@rm -f ${OBJS}
			@rm -rf ./objs
			@echo "\033[1;31mProgram : Removing .o files\033[0;0m"

fclean:		clean
			@rm -f ${NAME}
			@echo "\033[1;31mProgram : Removing binary file\033[0;0m"

re:			fclean all

git:		fclean
			git add -A
			git add *
			git commit -u -m "$(LOGFILE) $(MSG)"
			git push

.PHONY:		all clean fclean re git
