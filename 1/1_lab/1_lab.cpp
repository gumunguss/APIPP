// 1_lab.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Date.h"
#include "FullDate.h"

int x;

bool cmd(Date *a, Date *b)
{
	if (dynamic_cast<FullDate*>(a) || dynamic_cast<FullDate*>(b))
		if (dynamic_cast<FullDate*>(a) && dynamic_cast<FullDate*>(b))
			if(a->Count() < b->Count())
				return false;
			else return true;
		else
			if (dynamic_cast<FullDate*>(a) && dynamic_cast<Date*>(b))
				return false;
			else return true;
	else 
		if (a->Count() < b->Count())
			return false;
		else return true;
}

bool con(Date *a)
{
	if(a->Count() > x)
		return true;
	else return false;
}

int _tmain(int argc, _TCHAR* argv[])
{
	vector<Date*> v1;
	Date *d = new Date(19,1);
	FullDate *fd = new FullDate(11,2,2003);
	v1.push_back(d);
	v1.push_back(fd);
	fd = new FullDate(11,11,2011);
	v1.push_back(fd);
	fd = new FullDate(1,7,2014);
	v1.push_back(fd);
	d = new Date(12,8);
	v1.push_back(d);

	vector <Date*>::iterator it;

	cout << "Original array:" << endl;
	for(it = v1.begin(); it != v1.end(); it++)
		(*it)->Display();

	//сортировка
	sort(v1.begin(), v1.end(),cmd);

	cout << "\nSorted array:" << endl;
	for(it = v1.begin(); it != v1.end(); it++)
		(*it)->Display();

	int k;
	cout << "\nInput number: ";
	cin >> x;
	k = 0;
	vector <Date*>::iterator ite;
	for(it = v1.begin(); it != v1.end(); )
	{
		ite = find_if(v1.begin(),v1.end(),con);
		if (ite != v1.end())
		{
			k++;
			v1.erase(ite);
		}
		else ++it;
	}
	cout << "Array after deleting items:" << endl;
	for(it = v1.begin(); it != v1.end(); it++)
		(*it)->Display();

	system("pause");
	return 0;
}

