nasm -fmacho64 ft_list_size.s; nasm -fmacho64 ft_list_sort.s; nasm -fmacho64 ft_list_push_front.s; nasm -fmacho64 compare.s; gcc test.c *.o -fsanitize=address -o test; rm *.o
