#include <iostream>
#include <vector>

using namespace std;

/*
class Exmpl {
public:
	Exmpl() { cout << "Exmpl()" << endl; }
	Exmpl(const Exmpl&) { cout << "Exmpl(const Exmpl&)" << endl; }
};
*/

struct Exmpl {
	Exmpl() { cout << "Exmpl()" << endl; }
	Exmpl(const Exmpl &) { cout << "Exmpl(const Exmpl&)" << endl; }
	Exmpl& operator=(const Exmpl& obj) {
		cout << "operator=" << endl;
		return *this;
	}
	
	~Exmpl() {
		cout << "~Exmple()" << endl;
	}
};

void func1(Exmpl obj)
{
}

void func2(Exmpl& obj)
{
}

Exmpl func3(void)
{
	cout << "func3" << endl;
	Exmpl obj;
	return obj;
}

int main(int argc, char **argv)
{
	//Exmpl a;	
	//func1(a);
	//func2(a);
	Exmpl b ;
	b = func3();
	cout << "vector:" << endl;
	vector<Exmpl> evec(3);

	return 0;	
}
