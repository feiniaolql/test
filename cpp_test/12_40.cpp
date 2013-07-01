#include <iostream>

using namespace std;

class Foo {
public:
	int data;
	Foo(int val): data(val) {}
	int getData(void) { return data; }
};

class Bar {
public:
	Foo FooVal(void) { 
		callsFooVal++;
		cout << "val of callsFoolVal:" << callsFooVal << endl;
		return  fval;
	}
private:
	static int ival;
	static Foo fval;
	static int callsFooVal;
};

int Bar::ival = 20;
Foo Bar::fval(0);
int Bar::callsFooVal = 0;

int main(int argc, char **argv)
{
	Bar bar;	
	
	bar.FooVal();
	bar.FooVal();
	bar.FooVal();

	return 0;

}
