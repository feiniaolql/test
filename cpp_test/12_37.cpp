#include <iostream>

using namespace std;

class Account {
public:
	Account(string name, double cnt);
	void applyint() {
		amount += amount * interestRate;
		cout << owner <<"'account: " << amount << endl;
	}
	
	static double rate() { return interestRate;}
	static void rate(double);

private:
	string owner;
	double amount;
	static double interestRate;
	static double initRate();
};

double Account::interestRate = 0.25;

Account::Account(string name, double cnt)
{
	owner = name;	
	amount = cnt;
}

void Account::rate(double cnt)
{
	interestRate = cnt;
}

double Account::initRate()
{
}

int main(int argc, char **argv)
{
	Account user("Li Ming", 100);	
	user.applyint();
	return  0;
}
