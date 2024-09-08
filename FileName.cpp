#include<iostream>
using namespace std;
class Date
{
public:
	int GetMonthDay(int year, int month)
	{
		static int monthDays[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
		//是2月且是闰年返回29
		if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0))
		{
			return 29;
		}
		return monthDays[month];
	}

	Date(int year = 0, int month = 1, int day = 1)
	{
		if (year >= 0 
			&& month >= 1 && month <= 12
			&& day >= 1 && day<= GetMonthDay(year, month))
		{
			_year = year;
			_month = month;
			_day = day;
		}
		else
		{
			cout << "非法日期" << endl;
		}
	}

	Date(const Date& d)//拷贝函数 
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}

	void Print()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}
	//d1<d2;
	//d1.operator<(&d1,d2)
	bool operator < (const Date& d)//bool operator < (Date* this,const Date& d)
	{
		if (_year < d._year)
			return true;
		else if (_year == d._year && _month < d._month)
			return true;
		else if (_year == d._year && _month == d._month && _day < d._day)
			return true;
		else
			return false;
	}

	bool operator==(const Date& d)
	{
		return (_year == d._year && _month == d._month && _day == d._day);
	}

	bool operator<=(const Date& d)
	{
		return *this < d || *this == d;
	}

	bool operator>(const Date& d)
	{
		return !(*this <= d);
	}

	Date operator+(int day)
	{
		Date ret(*this);//用d1拷贝一个ret
		ret._day += day;
		while (ret._day > GetMonthDay(ret._year, ret._month))
		{
			//如果日期不合法，就要进位
			ret._day -= GetMonthDay(ret._year,ret._month);
				ret._month++;
				if (ret._month == 13)
				{
					ret._year++;
					ret._month = 1;
				}
		}
		return ret;
	}

private:
	int _year=0;
	int _month=1;
	int _day=1;
};

int main()
{
	Date d2(2021,2,20);
	d2.Print();
	Date d3= d2+ 1000;
	d3.Print();
	return 0;
}