##
## Makefile for 205IQ in /home/ikirame/Documents/Projects/205IQ
## 
## Made by Valentin Gérard
## Login   <valentin.gerard@epitech.eu>
## 
## Started on  Mon Apr 10 17:13:28 2017 Valentin Gérard
## Last update Mon Apr 10 17:13:44 2017 Valentin Gérard
##

CC		= g++

RM		= rm -f

CPPFLAGS	= -Wall -Wextra -W -I./includes

NAME		= 205IQ

SRCS		= srcs/IQ.cpp \
		  srcs/main.cpp \
		  srcs/utils.cpp

OBJS		= $(SRCS:.cpp=.o)

$(NAME):	$(OBJS)
		$(CC) $(CPPFLAGS) $(OBJS) -o $(NAME)

all:		$(NAME)

clean:
		$(RM) $(OBJS)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all

.PHONY:		all clean fclean re
