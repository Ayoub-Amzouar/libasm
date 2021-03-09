
NAME = libasm.a

HEADER = libasm.h

SRC = ft_strcpy.s ft_strlen.s ft_strcmp.s ft_write.s ft_read.s ft_strdup.s

OBJ = ft_strcpy.o ft_strlen.o ft_strcmp.o ft_write.o ft_read.o ft_strdup.o
#BONUS=

all: NASM $(NAME) GCC clean

NASM: $(SRC)
	nasm -fmacho64 ft_strcpy.s
	nasm -fmacho64 ft_strlen.s
	nasm -fmacho64 ft_strcmp.s
	nasm -fmacho64 ft_write.s
	nasm -fmacho64 ft_read.s
	nasm -fmacho64 ft_strdup.s

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