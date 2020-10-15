#include "StdAfx.h"
#include "Date.h"

Date::Date()
{
}
Date::~Date()
{
}

void Date::Init(int d, int m)
{
	month = m;
	day = d;
}

Date::Date(int d, int m)
{
	this->day = d;
	this->month = m;
}

void Date::Read()
{
	do{
		scanf("%d %d", &day, &month);
	}while(month > 12 || month < 1 || day > 31 || day < 1);
}

void Date::Display()
{
	//printf("Date: %d.%d", day, month);
	cout << "Date: " << day << "." << month << endl;
}

int Date::GetDay()
{
	return day;
}

int Date::GetMonth()
{
	return month;
}

int Date::Count()
{
	return CountDay();
}

int Date::CountDay()
{
	int year[13];
	year[1] = 31; year[2] = 28; year[3] = 31; 
	year[4] = 30; year[5] = 31; year[6] = 30; 
	year[7] = 31; year[8] = 31; year[9] = 30;
	year[10] = 31; year[11] = 30; year[12] = 31;
	int count = 0;
	count = day;
	for (int i = 1; i < month; i++)
	{
		count += year[i];
	}
	return count;
}

Date Date::Add(Date date1, Date date2)
{
	Date sum;
	int d = 0, m = 0;
	m = date1.month + date2.month;
	if (m > 12)
		m -= 12;
	d = date1.day + date2.day;
	if (d > 31)
	{
		m++;
		d-=31;
	}
	sum.day = d;
	sum.month = m;
	return sum;
}