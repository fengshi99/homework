#include <iostream>
using std::cout;
using std::endl;
using std::cin;

class Life
{
private:
	int _id;
public:
	Life(int n):_id(n){}
	Life(const Life &L)
	{
		_id = L._id;
		cout << "calling copy constructor!" << endl;
	}
	Life& operator=(const Life&);
	~Life(){
		cout << "i am Life " << _id << ";i am going to deconstructor!" << endl;
	}
};
Life& Life::operator=(const Life& L)
{
	_id = L._id;
	cout << "calling operator= " << endl;
}

Life fun()
{
	Life life(108);
	return life;
}
int main()
{
	Life l_life = fun();
	Life(111);
	return 0;
}
