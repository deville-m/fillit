NAME=fillit
CC=gcc
CFLAGS=-Wall -Wextra -Werror
LIBDIR=libft
LIB=libft.a
LDLIB=-lft
LDFLAGS=-L$(LIBDIR)
SRCDIR=srcs
INCLUDES=-I$(LIBDIR) -Iincludes
SRC=$(addprefix $(SRCDIR)/, main.c input.c output.c list.c tetronew.c num_piece.c map.c solver.c set.c)
OBJ=$(SRC:.c=.o)

all: $(NAME)

$(LIBDIR)/$(LIB):
	@$(MAKE) -C $(LIBDIR) $(LIB)

%.o: %.c
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(NAME): $(OBJ) $(LIBDIR)/$(LIB)
	$(CC) $(CFLAGS) $(INCLUDES) -o $(NAME) $(OBJ) $(LDFLAGS) $(LDLIB)

clean:
	@rm -f $(OBJ)
	@$(MAKE) -C $(LIBDIR) clean

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) -C $(LIBDIR) fclean

re: fclean
	@$(MAKE)

.PHONY: all clean fclean re $(LIBDIR)/$(LIB)
