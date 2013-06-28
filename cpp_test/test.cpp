#include <stdlib.h>
#include <stdio.h>
#include <iostream>

using namespace std;

int main(void)
{
	int i = 100, sum = 0;
	for(int i = 0; i != 10; ++i) {
		cout << i <<" "<< endl;
		sum += i;
	}
	cout << i <<" "<< sum << endl;
}

