#自定义变量
OBJ = selectionSort.o
TARGET = selectionSort

#使用变量:$(变量名)
$(TARGET): $(OBJ)
	gcc $^ -o $@


add.o: selectionSort.c
	gcc -c $^ -o $@

clean:
	@rm -rf  *.o $@