CC = gcc

all: test_point_add

test_point_add: 
	$(CC) main.c point_add.c -o test_point_add

# %.o: %.c
# 	$(CC) -O3 -c $< -o $@ -Wl,-Bstatic -lpthread -lrt -D_GNU_SOURCE

.PHONY: clean test
clean:
	rm -f *.o test_point_add

test: test_point_add
	./test_point_add