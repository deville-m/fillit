NAME = libft.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRCS = \
	ft_atoi.c \
	ft_bzero.c \
	ft_isalnum.c \
	ft_isalpha.c \
	ft_isascii.c \
	ft_isblank.c \
	ft_iscntrl.c \
	ft_isdigit.c \
	ft_isgraph.c \
	ft_islower.c \
	ft_isnumber.c \
	ft_isprint.c \
	ft_ispunct.c \
	ft_isspace.c \
	ft_isupper.c \
	ft_isxdigit.c \
	ft_itoa.c \
	ft_lstadd.c \
	ft_lstappend.c \
	ft_lstat.c \
	ft_lstdel.c \
	ft_lstdelone.c \
	ft_lstfind.c \
	ft_lstiter.c \
	ft_lstiterif.c \
	ft_lstlast.c \
	ft_lstmap.c \
	ft_lstmerge.c \
	ft_lstnew.c \
	ft_lstrev.c \
	ft_lstsize.c \
	ft_memalloc.c \
	ft_memccpy.c \
	ft_memchr.c \
	ft_memcmp.c \
	ft_memcpy.c \
	ft_memdel.c \
	ft_memmove.c \
	ft_memset.c \
	ft_putchar.c \
	ft_putchar_fd.c \
	ft_putendl.c \
	ft_putendl_fd.c \
	ft_putnbr.c \
	ft_putnbr_fd.c \
	ft_putstr.c \
	ft_putstr_fd.c \
	ft_showctab.c \
	ft_showctab_fd.c \
	ft_str_is_alpha.c \
	ft_str_is_lowercase.c \
	ft_str_is_numeric.c \
	ft_str_is_printable.c \
	ft_str_is_uppercase.c \
	ft_strcapitalize.c \
	ft_strcasecmp.c \
	ft_strcasestr.c \
	ft_strcat.c \
	ft_strchr.c \
	ft_strclr.c \
	ft_strcmp.c \
	ft_strcpy.c \
	ft_strdel.c \
	ft_strdup.c \
	ft_strequ.c \
	ft_striter.c \
	ft_striteri.c \
	ft_strjoin.c \
	ft_strlcat.c \
	ft_strlen.c \
	ft_strlowcase.c \
	ft_strmap.c \
	ft_strmapi.c \
	ft_strncasecmp.c \
	ft_strncat.c \
	ft_strncmp.c \
	ft_strncpy.c \
	ft_strndup.c \
	ft_strnequ.c \
	ft_strnew.c \
	ft_strnstr.c \
	ft_strrchr.c \
	ft_strrev.c \
	ft_strsplit.c \
	ft_strstr.c \
	ft_strsub.c \
	ft_strtrim.c \
	ft_strupcase.c \
	ft_swap.c \
	ft_tolower.c \
	ft_toupper.c
OBJECTS = $(SRCS:.c=.o)

all: $(NAME)

%.o: %.c libft.h
	@$(CC) $(CFLAGS) -c $<

$(NAME): $(OBJECTS)
	@ar -rc $(NAME) $(OBJECTS)
	@ranlib $(NAME)

clean:
	@rm -f $(OBJECTS)

fclean: clean
	@rm -f $(NAME)

re:
	@$(MAKE) fclean
	@$(MAKE) all
