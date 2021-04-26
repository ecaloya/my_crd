CC = gcc
NAME = my_crd
SRC = init_functions.c\
	  list_functions.c\
	  main.c\
	  my_struct.h\
	  ppal_function.c\

OBJ = $(SRC: % .c= % .o)
RM = rm -f
CFLAGS = -W -Wall -ansi -pedantic -L. -I

$(NAME):	$(OBJ)
			$(CC)	-g3	$(OBJ)	-o	$(NAME)

all:	$(NAME)

clean:
		$(RM)	$(OBJ)
