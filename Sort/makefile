#自定义变量
OBJ = bubbleSort.o
TARGET = bubbleSort

#使用变量:$(变量名)
$(TARGET): $(OBJ)
	gcc $^ -o $@


add.o: bubbleSort.c
	gcc -c $^ -o $@

clean:
	@rm -rf  *.o $@