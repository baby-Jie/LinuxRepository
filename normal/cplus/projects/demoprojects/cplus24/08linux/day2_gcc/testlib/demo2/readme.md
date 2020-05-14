# 编译静态库
+ 手动编译
	+ 编译生成链接文件: `gcc -c calc.c -o calc.o`
	+ 编译静态库: `ar -rc libcalc.a calc.o`
	+ 编译时使用静态库: `gcc main.c -o main -L. -lcalc`
		+ 注意 一般lib的名字为: `libxxx.a` 在使用静态库链接的时候只需要使用`xxx`即可。
+ 使用makefile编译，见makefile文件
