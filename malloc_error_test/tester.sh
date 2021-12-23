for nullturn in 1 2 3 4 5 6 7 8 9 10
do
	for bsize in 1 2 3 4 5 6 7 8 9 1000 1000000
	do
		echo BUFFER_SIZE:$bsize  NULL_TURN:$nullturn
		gcc -D BUFFER_SIZE=$bsize -D NULL_TURN=$nullturn ../get_next_line.c ../get_next_line_utils.c malloc_error.c main_malloc_error.c #-fsanitize=address
		./a.out
	done
done
