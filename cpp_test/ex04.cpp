#include <iostream>
using namespace std;

int test(char *test)
{
	return 1;
}

class box{
	private:
	double length, width, height;
	double volume;
	public:
	box(double l, double w, double h)
	{
		length = l;
		width = w;
		height = h;
		volume = length * width * height;
	}	
	
	void vol(char *test, char a, int c)
	{
		cout<<"The volume is "<<volume<<endl;	
	}
	
};

int main(void)
{
	box box1(1.5, 2.5, 3.5);
	box1.vol();	
	return 0;
	box1.vol();
	box1.height;
	box1.volume;
}
