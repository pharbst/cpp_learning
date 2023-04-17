# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pharbst <pharbst@student.42heilbronn.de>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/17 12:55:54 by pharbst           #+#    #+#              #
#    Updated: 2023/04/17 13:11:07 by pharbst          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PRONAME = MyPhonebook

CC = c++

CFLAGS = -Wall -Wextra -Werror

SRCS = Contact.cpp PhoneBook.cpp

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

fclean:
	rm -rf $(OBJ_DIR)
	rm -f $(PRONAME)

re: fclean all

.PHONY: all clean fclean re