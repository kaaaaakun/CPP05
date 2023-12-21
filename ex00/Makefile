# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tokazaki <tokazaki@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/07 16:08:51 by tokazaki          #+#    #+#              #
#    Updated: 2023/12/19 02:31:01 by tokazaki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = main

# Files & Command +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++#
SRCS	= $(wildcard *.cpp)
HEADERS = $(wildcard *.hpp)
OBJDIR	= obj
OBJS    = $(addprefix $(OBJDIR)/, $(SRCS:.cpp=.o))
DEPENDS	= $(OBJS:.o=.d)

# -- flags --
CXX 		= c++
CXXFLAGS	= -Wall -Wextra -Werror
CXXFLAGS	+= -std=c++98
CXXFLAGS	+= -MMD -MP

# -- command --
RM		= rm -rf

# Mandatory target ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++#
.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

$(OBJDIR)/%.o: %.cpp
	mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) -o $@ -c $<

clean:
	$(RM) $(OBJDIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

# Other targets +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++#
.PHONY: format

format:
	clang-format --style=Google -i $(SRCS) $(HEADERS)

-include $(DEPENDS)
#++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++#
