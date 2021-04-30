#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#include <getopt.h> 
#include <string>
using std::string;

struct node {
	string data;
	node* prev;
	node* next;
	node(string s="", node* p=NULL, node* n=NULL) : data(s),prev(p),next(n) {}
};

node* first = NULL;
node* last = NULL;

void printListForward(node* L = first);
void printListReverse(node* L = last);
void printList(bool reverse = false);
void insertNext(string line, node*& L = last);
void insertPrev(string line, node*& L = first);
void insertBetween(string line, node*& before, node*& after);
bool isUnique(string line, node*& L = first);



int main(int argc, char *argv[]) {
	static int unique=0, reverse=0;
	static struct option long_opts[] = {
		{"unique",   no_argument,       &unique,   'u'},
		{"reverse",  no_argument,       &reverse,  'r'},
		{0,0,0,0} 
	};

	char c;
	int opt_index = 0;
	while ((c = getopt_long(argc, argv, "ur", long_opts, &opt_index)) != -1) {
		switch (c) {
			case 'u':
				unique = 1;
				break;
			case 'r':
				reverse = 1;
				break;
			case '?': 
				return 1;
		}
	}

	string line;

	if (getline(cin, line)) {
		first = new node(line);
		last = first;
	}

	while (getline(cin, line)) {

	

		if(line > last->data)
			insertNext(line);
		else if (line < first->data)
			insertPrev(line);
		else if(!isUnique(line, first) && (bool)unique) {
		}
		else {
			node* i;
			for (i = first; line >= i->data; i=i->next)
				if (i == last) break;

			if (i == first)
				insertPrev(line);
			else
				insertBetween(line, i->prev, i);
		}

	
	}

	printList((bool)reverse);

	return 0;
}

void printListForward(node* L) {
	for (node* i = L; i != NULL; i = i->next) {
		cout << i->data << endl;
	}
}

void printListReverse(node* L) {
	for (node* i = L; i != NULL; i = i->prev) {
		cout << i->data << endl;
	}
}

void printList(bool reverse) {
	if (reverse) printListReverse();
	else printListForward();
}

void insertNext(string line, node*& L) {
	L->next = new node(line, L);
	L = L->next;
}

void insertPrev(string line, node*& L) {
	L->prev = new node(line, NULL, L);
	L = L->prev;
}

void insertBetween(string line, node*& before, node*& after) {
	node* temp = new node(line, before, after);
	before->next = temp;
	after->prev = temp;
}

bool isUnique(string line, node*& L) {
	for (node* i = L; i != NULL; i = i->next) {
		if (line == i->data) return false;
	}
	return true;
}
