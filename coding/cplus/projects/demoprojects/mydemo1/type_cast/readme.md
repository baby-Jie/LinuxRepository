+ c++中的类型转换
	+ `static_cast`: 一般c语言中能够隐式转换的，用这种 `i = static_cast<int>(d)`
	+ `reinterpret_cast`: c语言中使用强制转换的，用这种 `int*p = reinterpret_cast<int*>(str)`
	+ `dynamic_cast`: 一般父类指针指向子类对象，然后想将父类指针转换成子类指针用这个
	+ `const_cast`:  const type* 修饰普通 type, 将 `const type *` 转换成 `type *` 以便可以修改其内容，注意: 变量本身要支持修改。
