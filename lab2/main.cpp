#include "sixarray.h"

int main()
{

	cout << "hi===========================" << endl;

	Six a(5, 0);
	cout << "a = " << a.getValue() << endl;
	a.print();
	cout << endl;

	Six b({5, 0, 1});
	cout << "b = " << b.getValue() << endl;
	b.print();
	cout << endl;

	Six bb(b);
	cout << "bb = " << bb.getValue() << endl;
	cout << endl;

	try
	{
		Six c1("25");
		cout << "c1 = " << c1.getValue() << endl;
		c1.print();
		cout << endl;
	}
	catch (const char *errStr)
	{
		cout << "Trouble..." << errStr << endl;
	}

	try
	{
		Six c2("27");
		cout << "c2 = " << c2.getValue() << endl;
		c2.print();
		cout << endl;
	}
	catch (const char *errStr)
	{
		cout << "c2 Trouble..." << errStr << endl;
	}

	try
	{
		Six c3("23a");
		cout << "c3 = " << c3.getValue() << endl;
		c3.print();
		cout << endl;
	}
	catch (const char *errStr)
	{
		cout << "c3---Trouble..." << errStr << endl;
	}


	Six c("25");
	cout << "c = " << c.getValue() << endl;
	c.print();
	cout << endl;

	Six d("2315");
	cout << "d = " << d.getValue() << endl;
	cout << endl;

	cout << "e = c + b = " << endl;
	Six e = c + b;
	cout << c.getValue() << " + " << b.getValue() << " = " << e.getValue() << endl;
	cout << endl;

	cout << "zero = c - c = "<<endl;
	Six zero = c - c ;
	cout << c.getValue() << " - "<< c.getValue() << " = " << zero.getValue() << endl;

	cout << "em1 = b - c = " << b.getValue() << " - " << c.getValue();
	Six em1 = b - c;
	cout << " = " << em1.getValue() << endl;

	cout << "em2 = c - b = " << c.getValue() << " - " << b.getValue() << " = ";
	Six em2 = c - b;
	cout << em2.getValue() << endl;

	cout << "em3 = a - b = " << a.getValue() << " - " << b.getValue() << " = ";
	Six em3 = a - b;
	cout << em3.getValue() << endl;
	cout << endl;

	Six a1;
	cout << "a1 = " << a1.getValue() << endl;
	cout << "e = " << e.getValue() << endl;
	a1 = e;
	cout << "a1 = e =" << a1.getValue() << endl;
	cout << endl;

	cout << b.getValue() << "==" << c.getValue() << " = " << (b == c) << endl;
	cout << c.getValue() << "==" << c.getValue() << " = " << (c == c) << endl;
	cout << endl;

	Six d1("143");
	Six d2("124");
	cout << d1.getValue() << "<" << d2.getValue() << " = " << (d1 < d2) << endl
		 << endl;
	cout << d2.getValue() << "<" << d2.getValue() << " = " << (d2 < d2) << endl
		 << endl;
	cout << d2.getValue() << "<" << d1.getValue() << " = " << (d2 < d1) << endl
		 << endl;
	cout << d1.getValue() << ">" << d2.getValue() << " = " << (d1 > d2) << endl
		 << endl;
	cout << d2.getValue() << ">" << d2.getValue() << " = " << (d2 > d2) << endl
		 << endl;
	cout << d2.getValue() << ">" << d1.getValue() << " = " << (d2 > d1) << endl
		 << endl;

	Six d3("1200");
	Six d4("1005");
	cout << "ed1 = d3 - d4 = " << d3.getValue() << " - " << d4.getValue();
	Six ed1 = d3 - d4;
	cout << " = " << ed1.getValue() << endl;

	return 1;
}