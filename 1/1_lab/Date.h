#pragma once
class Date
{
public:
	Date(void);
	~Date(void);
	Date(int d,int m);
	virtual int CountDay();
	int Count();
	Date Add(Date date1, Date date2);
	void Init(int d, int m);
	void Read();
	virtual void Display();
	int GetDay();
	int GetMonth();
protected:
	int month;
	int day;
};