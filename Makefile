##
## EPITECH PROJECT, 2020
## ASM_minilibc_2019
## File description:
## Makefile
##

NAME	= libasm.so

CC	= gcc

RM	= rm -f

SRCS	= ./strlen.s \
			./strchr.s \
			./memset.s \
			./memcpy.s \
			./strcmp.s \
			./memmove.s

OBJS	= $(SRCS:.s=.o)

ASFLAGS += -f elf64

LDFLAGS += -shared

all: $(NAME)

$(NAME): $(OBJS)
	 $(CC) $(LDFLAGS) $(OBJS) -o $@

%.o: %.s
	 nasm $(ASFLAGS) $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

compil: all
	gcc main.c -L -lasm -fno-builtin -o test

.PHONY: all clean fclean re
