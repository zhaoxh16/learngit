#include<string>
#include"Stack.cpp"
using namespace std;
int main()
{
	cout << "为了测试，构造函数，析构函数，运算符的定义中都加了输出，正式使用时应当去除掉" << endl;
	cout << endl;


	//测试1

	cout << "测试1：不含参数的构造函数；_size及size函数；_maxSize及maxSize函数；push函数；pop函数；empty函数；get函数；下标运算符；find函数" << endl;

	cout << "测试不含参数的构造函数" << endl;
	cout << "	Stack<int> intStack" << endl;
	Stack<int> intStack;
	//cout << intStack._size << endl; 编译错误，_size是私有成员
	//cout << intStack._maxSize << endl; 编译错误，_maxSize是私有成员
	cout << "	intStack.size(): " << intStack.size() << " intStack.maxSize(): " << intStack.maxSize() << endl;
	cout << "	intStack.empty(): " << intStack.empty() << endl;
	cout << endl;

	cout << "测试push函数" << endl;
	cout << "	intStack.push(3)" << endl;
	intStack.push(3);
	cout << "	intStack.push(-1)" << endl;
	intStack.push(-1);
	cout << "	intStack.size(): " << intStack.size() << " intStack.maxSize(): " << intStack.maxSize() << endl;
	cout << endl;

	cout << "测试get函数" << endl;
	cout << "	intStack.get(): " << intStack.get() << endl;
	cout << endl;

	cout << "	intStack.get(1): " << intStack.get(1) << endl;
	cout << endl;

	cout << "	（下标错误）intStack.get(-1): " << endl;
	intStack.get(-1);
	cout << endl;

	cout << "	（下标错误）intStack.get(5): " << endl;
	intStack.get(5);
	cout << endl;

	cout << "测试find函数" << endl;
	cout << "	intStack.find(3): " << intStack.find(3) << endl;
	cout << endl;

	cout << "	intStack.find(100): " << intStack.find(100) << endl;
	cout << endl;

	cout << "	intStack.find(3, 0, 1): " << intStack.find(3, 0, 1) << endl;
	cout << endl;

	cout << "	intStack.find(3, 1, 2): " << intStack.find(3, 1, 2) << endl;
	cout << endl;

	cout << "	intStack.find(3, 1, 3): ";
	intStack.find(3, 1, 3);
	cout << endl;

	cout << "测试下标运算符" << endl;
	cout << "	（下标错误）intStack[2]: ";
	intStack[2];
	cout << endl;

	cout << "	intStack[1]: " << intStack[1] << endl;
	cout << endl;

	cout << "	执行intStack[1] = 10" << endl;
	intStack[1] = 10;
	cout << "	intStack[1]: " << intStack[1] << endl;
	cout << endl;

	cout << "测试empty函数" << endl;
	cout << "	intStack.empty(): " << intStack.empty() << endl;
	cout << endl;

	//cout << intStack._A[0] << endl; 编译错误，_A是私有成员

	cout << "测试pop函数" << endl;
	cout << "	intStack.pop(): " << intStack.pop() << endl;
	cout << "	intStack.pop(): " << intStack.pop() << endl;
	cout << endl;

	cout << "	（栈已空）intStack.pop(): ";
	intStack.pop();
	cout << endl;


	//测试2

	cout << "测试2：含参数的构造函数；full函数；_expand函数；expand函数；shrink函数" << endl;
	cout << "测试含参数的构造函数" << endl;
	cout << "	Stack<string> strStack(3)" << endl;
	Stack<string> strStack(3);
	cout << "	strStack.full(): " << strStack.full() << endl;
	cout << endl;

	cout << "	strStack.push(\"Hello\")" << endl;
	strStack.push("Hello");
	cout << "	strStack.push(\"World\")" << endl;
	strStack.push("World");
	cout << "	strStack.push(\"I'm strStack\")" << endl;
	strStack.push("I'm strStack");
	cout << endl;

	cout << "测试full函数" << endl;
	cout << "	strStack.size(): " << strStack.size() << " strStack.maxSize(): " << strStack.maxSize() << endl;
	cout << "	strStack.full(): " << strStack.full() << endl;
	cout << endl;

	cout << "测试_expand函数" << endl;
	cout << "	strStack.push(\"Oh!I have been full!\")" << endl;
	strStack.push("Oh! I have been full!");
	cout << "	strStack.size(): " << strStack.size() << " strStack.maxSize(): " << strStack.maxSize() << endl;
	cout << endl;

	cout << "测试expand函数" << endl;
	cout << "	（扩容失败）strStack.expand(5): " << strStack.expand(5) << endl;
	cout << endl;

	cout << "	strStack.expand(10): " << strStack.expand(10) << endl;
	cout << "	strStack.maxSize(): " << strStack.maxSize() << endl;
	cout << endl;

	cout << "测试shrink函数" << endl;
	cout << "	（缩容失败）strStack.shrink(15): " << strStack.shrink(15) << endl;
	cout << endl;

	cout << "	strStack.shrink(7): " << strStack.shrink(7) << endl;
	cout << "	strStack.maxSize(): " << strStack.maxSize() << endl;
	cout << endl;

	cout << "	strStack.size(): " << strStack.size() << endl;
	cout << "	（将有数据被丢失）strStack.shrink(3)" << endl;
	cout << "	";
	strStack.shrink(3);
	cout << "	strStack.maxSize(): " << strStack.maxSize() << endl;
	cout << endl;


	//测试3

	cout << "测试3：拷贝构造函数；赋值运算符；移动拷贝构造函数；移动赋值运算符；copyfrom函数；clear函数" << endl;

	cout << "测试拷贝构造函数" << endl;
	cout << "	Stack<string> strStack2(strStack): ";
	Stack<string> strStack2(strStack);
	cout << "	strStack2.size(): " << strStack2.size() << "	strStack2.maxSize: " << strStack2.maxSize() << endl;
	cout << "	strStack2: ";
	for (int i = 0; i < strStack2.size(); i++)
		cout << strStack2[i] << ' ';
	cout << endl;
	cout << endl;

	cout << "	Stack<string> strStack3: ";
	Stack<string> strStack3;
	cout << endl;

	cout << "测试赋值运算符" << endl;
	cout << "	strStack3 = strStack2: ";
	strStack3 = strStack2;
	cout << "	strStack3.size(): " << strStack3.size() << "	strStack3.maxSize: " << strStack3.maxSize() << endl;
	cout << "	strStack3: ";
	for (int i = 0; i < strStack3.size(); i++)
		cout << strStack3[i] << ' ';
	cout << endl;
	cout << endl;

	cout << "测试移动构造函数" << endl;
	cout << "	Stack<string> strStack4(Stack<string>(5)): ";
	Stack<string> strStack4(Stack<string>(5));
	cout << "	strStack4.size(): " << strStack4.size() << "	strStack4.maxSize: " << strStack4.maxSize() << endl;
	cout << endl;

	cout << "测试移动赋值运算符" << endl;
	cout << "	strStack4 = Stack<string>(7): ";
	strStack4 = Stack<string>(7);
	cout << "	strStack4.size(): " << strStack4.size() << "	strStack4.maxSize: " << strStack4.maxSize() << endl;
	cout << endl;

	cout << "测试copyfrom函数" << endl;
	cout << "	strStack4.copyFrom(strStack, 3)" << endl;
	strStack4.copyFrom(strStack, 3);
	cout << "	strStack4: ";
	for (int i = 0; i < strStack4.size(); i++)
		cout << strStack4[i] << ' ';
	cout << endl;
	cout << endl;

	cout << "	strStack4.copyFrom(strStack, 3, 2, 0)" << endl;
	strStack4.copyFrom(strStack, 3, 2, 0);
	cout << "	strStack4: ";
	for (int i = 0; i < strStack4.size(); i++)
		cout << strStack4[i] << ' ';
	cout << endl;
	cout << endl;

	cout << "	strStack4.copyFrom(strStack, 2, -1, 0)" << endl;
	strStack4.copyFrom(strStack, 2, -1, 0);
	cout << endl;

	cout << "	strStack4.copyFrom(strStack, 2, 0, 2)" << endl;
	strStack4.copyFrom(strStack, 2, 0, 2);
	cout << endl;

	return 0;
}