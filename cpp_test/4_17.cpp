#include <iostream>
#include <string.h>
#include <stdlib.h>

using namespace std;

static char *strsave(char *s)
{
	char *p;
	p = new char[strlen(s) + 1];
	strcpy(p, s);
	return p;
}

class data_rec {
private:
	char *last_name;
	char *first_name;
	char *gender;
public:
	data_rec()
	{
		last_name = '\0';	
		first_name = '\0';	
		gender = '\0';	
	}
	
	data_rec(char *ln, char *fn, char *g)
	{
		last_name = strsave(ln);
		first_name = strsave(fn);
		gender = strsave(g);
	}
	
	void print()
	{
		cout<<"\r\nlast name: "<<last_name<<endl;
		cout<<"first name: "<<first_name<<endl;
		cout<<"gender: "<<first_name<<endl;
	}
	
	~data_rec()
	{
		delete last_name;
		delete first_name;
		delete gender;
	}
};

class student : virtual public data_rec {
private: 
	char *major;
	unsigned int idnumber;
	char *level;
public:
	student(char *ln, char *fn, char *g, char *m, unsigned int id, char *l) : data_rec(ln, fn, g)
	{
		major = strsave(m);
		idnumber = id;
		level = strsave(l);
	}
	
	void print()
	{
		data_rec::print();
		cout<<"major: "<<major<<endl;
		cout<<"idnumber: "<<idnumber<<endl;
		cout<<"level : "<<level<<endl;
	}
	
	~student()
	{
		delete major;
		delete level;
	}

};

class teacher : virtual public data_rec {


};

int main()
{
	student li_ming("Li", "Ming", "M", "Computer Engineering", 12345, "Senior");
	li_ming.print();
	return 0;
}
