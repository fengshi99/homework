#include <iostream>
using std::cout;
using std::endl;
struct Node
{
	int data;
};

void c_type()
{
	cout << "Now in c_type"<<endl;
	Node *node = (Node *)malloc(sizeof(Node));
	node->data=5;
	cout << node->data<<endl;
	free(node);
}

void cpp_type()
{
	cout << "Now in cpp_type"<<endl;
	Node *node = new Node();
	node ->data =5;
	cout << node->data << endl;
	delete node;
}
int main()
{
	c_type();
	cpp_type();
	return 1;
}
