#include <iostream>
using std::cout;
using std::endl;
using std::cin;
#ifdef _cpluscplus
extern C{
#endif
int mul(int n,int m)
{
	cout << "now using int version" << endl;
	return n * m;
}
#ifdef _cplusplus
}
#endif
double mul(double n,double m)
{
	cout << "now using double version" << endl;
	return n * m;
}
int main()
{
	double n,m;
	while(1)
	{
		cout << "input:" << endl;
		cin >> n >> m;
		if((n - static_cast<int>(n)) || (m - static_cast<int>(m)))
			cout << mul(n,m) << endl;
		else
			cout << mul(static_cast<int>(n),static_cast<int>(m)) << endl;
	}
	return 0;
}
