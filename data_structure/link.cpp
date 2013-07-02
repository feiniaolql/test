#include <iostream>
#include <cstdio>
#include <new>
#include <string>
#include <vector>

#define NAME_LEN		20
using namespace std;

class node {
	string name;
	node *next;
	friend class LinkList;
};

class LinkList {
public:
	LinkList(int num = 10);
	void insert_node(int num, string str);
	int remove_node(int num);
	void output_nodes();
	~LinkList(void);
private:
	node *head;

};

LinkList::LinkList(int num)
{
	int i;
	node *pre, *post, *curr;
	char str[NAME_LEN];

	head = new node;
	head->name = '\0';

	head->next = NULL;
	pre = head;

	for (i = 0; i < num; i++) {
		curr = new node;
		sprintf(str, "%d", i);
		curr->name = str;
		curr->next = NULL;
		
		pre->next = curr;
		pre = curr;
	}
}

LinkList::~LinkList(void)
{
	node *curr, *pre;
	
	curr = head;
	
	while (curr->next != NULL) {
		pre = curr;
		curr = curr->next;
		delete pre;	
	}
	delete curr;
}

void LinkList::insert_node(int num, string str)
{
	int i;
	node *curr, *insert, *tmp;
	
	curr = head->next;
	for (i = 0; i < num; i++)
		curr = curr->next;		

	insert = new node;
	tmp = curr->next;
	curr->next = insert;
	insert->name = str;
	insert->next = tmp;
}

int LinkList::remove_node(int num)
{
	int i;
	node *curr, *tmp;

	curr = head;
	for (i = 0; i < num; i++) {	
		curr = curr->next;
		if (curr->next == NULL) {
			cout << "No such node." << endl;
			return 1;
		}
	}

	tmp = curr->next;
	curr->next = tmp->next; 

	delete (tmp);
}

void LinkList::output_nodes()
{
	node *curr;
	curr = head;

	while (curr->next != NULL) {
		curr = curr->next;
		cout << curr-> name << " ";
	}
	cout << endl;
}

int main(int argc, char **argv)
{
	LinkList list(8);
	list.output_nodes();
	list.insert_node(4, "test");
	list.output_nodes();
	list.remove_node(4);
	list.output_nodes();

	vector<int> ivec;
	cout << ivec.size() << endl;
	for (vector<int>::size_type i = 0; i < 10; ++i) {
		ivec.push_back(i);
	}	
	cout << ivec.size() << endl;
	cout << "the values of ivec:" << endl;
	for (vector<int>::iterator iter = ivec.begin(); iter != ivec.end(); ++iter)
		cout << *iter << " ";
	cout << endl;

	vector<int>::iterator mid = ivec.begin() + ivec.size() / 2;
	cout << "mid: " << *mid << endl;
	
	string sa[3] = {"str1", "str2", "str3"};
	return 0;
}
