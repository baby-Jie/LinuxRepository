Target := main
SrcFiles=$(wildcard *.c)
ObjFiles=$(patsubst %.c, %.o, $(SrcFiles))

all: $(Target)
$(Target): $(ObjFiles)
	$(CC) $(ObjFiles) -o $(Target) 

%.o: %.c
	gcc -c $< -o $@ -I./includes
.PHONY:clean all
clean:
	-@rm -rf *.o
