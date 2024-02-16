#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <math.h>
using namespace std;

class Number
{
	double value;
	string stnumber;
public:
	Number()
	{
		value = 0;
		stnumber = "";
	}
	void set(double val, string stnumb)
	{
		value = val;
		stnumber = stnumb;
	}
	Number(double val, string stnumb)
	{
		value = val;
		stnumber = stnumb;
	}
	void print()
	{
		cout << "value = " << value << endl;
		cout << "number = " << stnumber << endl;
	}
	void print_file(ofstream& fout)
	{
		fout << "value = " << value << endl;
		fout << "number = " << stnumber << endl;
	}
	int integer_part()
	{
		int count = 1;
		double val = abs(value);
		while(true)
		{
			val = val / 10;
			++count;
			if (val < 10) break;
		}
		return count;
	}
	double Value()
	{
		return value;
	}
	~Number()
	{
		delete& value;
		delete& stnumber;
	}

};

int main()
{
	setlocale(LC_ALL, "Rus");
	int count = 0, integer = 0, n = 0;
	double value = 0, sum = 0;
	string stnumber;
	vector <double> vecval;
	vector <string> vecstr;
	ifstream fin;
	fin.open("input.txt");
	while (!fin.eof())
	{
		fin >> stnumber;
		vecstr.push_back(stnumber);
		istringstream(stnumber) >> value;
		vecval.push_back(value);
		++count;
	}
	fin.close();
	Number *pnumb;
	pnumb = new Number[count];
	vector <Number> vecNumb(count);
	for (int i = 0; i < count; ++i)
	{
		value = vecval[i];
		stnumber = vecstr[i];
		pnumb[i].set(value, stnumber);
		vecNumb[i].set(value, stnumber);
	}
	ofstream fout;
	fout.open("output.txt");
	for (int i = 0; i < count; ++i)
	{
		cout << i + 1 << "-ое число:" << endl;
		fout << i + 1 << "-ое число:" << endl;
		vecNumb[i].print_file(fout);
		vecNumb[i].print();
	}
	for (int i = 0; i < count; ++i)
	{
		sum += pnumb[i].Value();
	}
	cout << "Сумма всех чисел: " << sum << endl;
	fout << "Сумма всех чисел: " << sum << endl;
	for (int i = 0; i < count; ++i)
	{
		n = pnumb[i].integer_part();
		integer += n;
	}
	cout << "Суммарное количество цифр в целых частях всех чисел: " << integer << endl;
	fout << "Суммарное количество цифр в целых частях всех чисел: " << integer << endl;
	fout.close();
	return 0;
}