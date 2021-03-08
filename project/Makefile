
NAME = libasm.a

HEADER = libasm.h

SRC = ft_strcpy.s ft_strlen.s ft_strcmp.s

OBJ = ft_strcpy.o ft_strlen.o ft_strcmp.o
#BONUS=

all: NASM $(NAME) GCC clean

NASM: $(SRC)
	nasm -fmacho64 ft_strcpy.s
	nasm -fmacho64 ft_strlen.s
	nasm -fmacho64 ft_strcmp.s

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

GCC: $(HEADER)
	gcc main.c $(NAME) -o libasm

clean:
	rm -f $(OBJ) main.o

fclean: clean
	rm -f $(NAME) libasm

re: fclean all