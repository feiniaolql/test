#include <iostream>

using namespace std;


class Person {
	public:
		Person(string str1, string str2): name("lql"), address("Ferndale") {
			name = str1;
			address = str2;
		}
		
		void input_name();
		void input_address() {}
		void output_name(void) { 
			cout << "Your name is " << name << endl;
		}
		void output_address(void) {
			cout << "Your address is " << address << endl;
		}

	private:
		string name, address;
};

void Person::input_name(void) {
	cout << "Please input your name:";
	cin >> name;
}



int main(int argc, char **argv)
{
	Person a("feiniao", "ISU");
	a.output_name();
	a.output_address();

	return 0;
}
