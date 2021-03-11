
NAME = libasm.a

SRC = src/ft_strcpy.s src/ft_strlen.s src/ft_strcmp.s src/ft_write.s src/ft_read.s src/ft_strdup.s
OBJ = src/ft_strcpy.o src/ft_strlen.o src/ft_strcmp.o src/ft_write.o src/ft_read.o src/ft_strdup.o

BONUS_SRC = src/ft_list_push_front_bonus.s src/ft_list_size_bonus.s
BONUS_OBJ = src/ft_list_push_front_bonus.o src/ft_list_size_bonus.o

all: NASM $(NAME) GCC clean

NASM: $(SRC)
	nasm -fmacho64 src/ft_strcpy.s
	nasm -fmacho64 src/ft_strlen.s
	nasm -fmacho64 src/ft_strcmp.s
	nasm -fmacho64 src/ft_write.s
	nasm -fmacho64 src/ft_read.s
	nasm -fmacho64 src/ft_strdup.s

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

GCC:
	gcc src/main.c $(NAME) -o libasm

clean:
	rm -f $(OBJ) $(BONUS_OBJ)

fclean: clean
	rm -f $(NAME) libasm libasm_bonus

re: fclean all

bonus: fclean $(BONUS_SRC)
	nasm -fmacho64 src/ft_list_push_front_bonus.s
	nasm -fmacho64 src/ft_list_size_bonus.s
	ar rc $(NAME) $(BONUS_OBJ)
	ranlib $(NAME)
	gcc src/main_bonus.c $(NAME) -o libasm_bonus
	rm -f $(BONUS_OBJ)