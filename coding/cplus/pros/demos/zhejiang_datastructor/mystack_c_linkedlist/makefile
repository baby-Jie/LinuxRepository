target=main
gdebug: test_stack.c mystack.o
	@gcc $^ -o $(target) -g
$(target): test_stack.c mystack.o
	@gcc $^ -o $(target)
mystack.o: MyStack.c
	@gcc -c MyStack.c -o $@
clean:
	@-rm -rf *.o $(target)

run:
	@-make
	@-./main
	@-make clean
