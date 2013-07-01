#include <iostream>
#include <math.h>

int main(void)
{
	int a, b;
	std::cout<<"Please input a, b:"<<std::endl;
	std::cin>>a>>b;
	float result = log(b) / log(a);	
	std::cout<<"loga b = "<<result<<std::endl;
	return 0;
}
