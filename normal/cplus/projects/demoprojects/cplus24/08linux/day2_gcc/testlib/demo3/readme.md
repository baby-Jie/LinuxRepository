# 编译动态库
+ 编译动态库
	+ 生成动态库: `gcc -shared -fPIC -o libcalc.so *.o`
	+ 链接动态库: `gcc main.c -o main -L./ -lcalc`
+ 使用动态库
	+ 要将动态库放到指定目录: 三种方法皆已验证
		+ 放在系统的库目录下: `/lib /user/lib`
		+ 修改LD_LIBRARY_PATH环境变量，将库所在的路径添加到环境变量中，用冒号分隔
		+ 修改`sudo vim /etc/ld.so.conf` 添加库路径到该文件下， `sudo ldconfig -v`
			+ 在某些机器上，在此文件中添加无用，需要在`/etc/ld.so.conf.d`目录下添加自己的`mylib.conf`,在此文件中添加so的路径后，使用命令 ldconfig -v 即可
