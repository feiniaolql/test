#include <iostream>

using namespace std;

void print(void) {
	cout << "out of class" << endl;
}

class Screen {
public:
	typedef string::size_type index;

	char get() const { return this->contents[cursor]; }
	inline char get(index r, index c) const;
	index get_cursor() const;
	Screen(index hght, index wdth, const string &cntnts);		

	Screen& move(index r, index c);
	Screen& set(char);

	void print(void) {
		cout << "in class" << endl;
	}

	Screen& display(ostream &os)
	{
		os << contents;
		::print();
		return *this;
	}

	const Screen& display(ostream &os) const
	{
		os << contents;
		return *this;
	}

private:
	string contents;
	index cursor;
	index height, width;
};

Screen::Screen(index hght, index wdth, const string &cntnts):
		contents(cntnts), cursor(0), height(hght), width(wdth)
{
}

char Screen::get(index r, index c) const
{
	index row = r * width;
	return contents[row + c];
}

inline Screen::index Screen::get_cursor() const
{
	return cursor;
}

Screen& Screen::move(index r, index c)
{
	index row = r * width; cursor = row + c;
	return *this;
}

Screen& Screen::set(char c)
{
	contents[cursor] = c;
	return *this;
}


int main(int argc, char **argv)
{
	Screen myScreen(5, 6, "aaaaa\naaaaa\naaaaa\naaaaa\naaaaa\n");	
	//myScreen.move(4, 0).set('#').display(cout);
	myScreen.display(cout);

	return 0;
}
