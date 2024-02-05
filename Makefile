# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tokazaki <tokazaki@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/04 23:29:09 by tokazaki          #+#    #+#              #
#    Updated: 2024/02/05 16:35:17 by kaaaaakun_       ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SUBDIRS := $(wildcard */)

.PHONY: all clean fclean $(SUBDIRS)

all: $(SUBDIRS)

$(SUBDIRS):
	@echo "Make all..."
	$(MAKE) -C $@

clean:
	@echo "Cleaning up..."
	for dir in $(SUBDIRS); do \
        $(MAKE) -C $$dir clean; \
    done

fclean:
	@echo "Fully cleaning up..."
	for dir in $(SUBDIRS); do \
		$(MAKE) -C $$dir fclean; \
		done

format: 
	@for dir in $(SUBDIRS); do \
		$(MAKE) -C $$dir format; \
	done


