#include <iostream>
#include <string>

using namespace std;

class Item_base {
public:
	Item_base(const string &book = "", double sales_price = 0.0):
		isbn(book), price(sales_price) {}

	string book() const {
		return isbn;
	}
	
	virtual double net_price(size_t n) const {
		return n * price;
	}

	virtual ~Item_base() {}
private:
	string isbn;
protected:
	double price;
};

class Bulk_item : public Item_base {
public:
	Bulk_item(const string &book = "", double sales_price = 0.0, size_t qty = 0, double disc_rate = 0.0):
		Item_base(book, sales_price) { min_qty = qty; discount = disc_rate; }
	virtual double net_price(size_t n) const {
		if ( n >= min_qty)
			return (1 - discount) * n * price;
		else
			return n * price;
	}
	void output(void) {
		cout << "ISBN: " << book() << endl;
		cout << "Price: " << price << endl;
		cout << "min_qty: " << min_qty << endl;
		cout << "discount: " << discount << endl;
	}
private:
	size_t min_qty;
	double discount;
};

int main(int argc, char **argv)
{
	Bulk_item test("1-asdf-1", 10.0, 10, 0.1);
	test.output();
	cout << "total price: " << test.net_price(2) << endl;	
	cout << "total price: " << test.net_price(10) << endl;	
	return 0;
}
