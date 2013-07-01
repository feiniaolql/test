#include <iostream>
using namespace std;

class ex_string {
	private:
	char contents[100];
	int length;	

	public:
	ex_string(void)
	{ 
		contents[0] = 't'; 
		contents[1] = 'e'; 
		contents[2] = 's'; 
		contents[3] = 't'; 
		contents[4] = '\0'; 
	}

	void print_str(void) 
	{
		cout<<contents<<endl;
	}
	
	int str_len(void)
	{ 
		int cnt = 0;	
		while (contents[cnt] != '\0')
		{ 
			cnt++;
		}
		return cnt;
	}
	
	void str_combine(char *str2)
	{
		int len1, i = 0;
		char *p;
		len1 = str_len();
		p = contents + len1;
		while (str2[i] != '\0') {
			*p++ = str2[i++];
		}	
		*p = '\0';
	}
};

int main(void)
{
	ex_string str_test;
	str_test.print_str();	
	cout<<"str length: "<<str_test.str_len()<<endl;
	str_test.str_combine(" hello world!");
	str_test.print_str();	
	cout<<"str length: "<<str_test.str_len()<<endl;
	str_test.str_combine
	return 0;
}
