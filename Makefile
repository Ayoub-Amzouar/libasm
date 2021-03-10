
NAME = libasm.a

SRC = ft_strcpy.s ft_strlen.s ft_strcmp.s ft_write.s ft_read.s ft_strdup.s
OBJ = ft_strcpy.o ft_strlen.o ft_strcmp.o ft_write.o ft_read.o ft_strdup.o

BONUS_SRC = ft_list_push_front_bonus.s ft_list_size.s ft_list_sort_bonus.s
BONUS_OBJ = ft_list_push_front_bonus.o ft_list_size.o ft_list_sort_bonus.o

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

GCC:
	gcc main.c $(NAME) -o libasm

clean:
	rm -f $(OBJ) $(BONUS_OBJ)

fclean: clean
	rm -f $(NAME) libasm

re: fclean all

bonus:
	nasm -fmacho64 ft_list_push_front_bonus.s
	nasm -fmacho64 ft_list_size.s
	nasm -fmacho64 ft_list_sort.s