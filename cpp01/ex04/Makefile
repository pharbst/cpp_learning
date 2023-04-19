# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pharbst <pharbst@student.42heilbronn.de    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/17 12:55:54 by pharbst           #+#    #+#              #
#    Updated: 2023/04/19 10:00:19 by pharbst          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PRONAME = sedForLoosers

CC = c++

CFLAGS = -Wall -Wextra -Werror

SRCS = main.cpp

OBJ_DIR = ./obj/

OBJS = $(addprefix $(OBJ_DIR), $(SRCS:.cpp=.o))

all: $(PRONAME)

$(PRONAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(PRONAME)

$(OBJ_DIR)%.o: %.cpp
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)
	rm *.replace

fclean:
	rm -rf $(OBJ_DIR)
	rm -f $(PRONAME)
	rm *.replace

re: fclean all

.PHONY: all clean fclean re