/*Write a C++ program to illustrate the overloading of relational 
operator <.*/


#include<iostream>
using namespace std;

class lesser
{
	int data;
	
	public:
		lesser(int d)
		{
			data = d;
		}
		int getdata()
		{
			return data;
		}
		int operator <(lesser d)
		{
			if(data<d.data)
			{
				return 1;
			}
			else
			{
				return 0;
			}
		}
};
int main()
{
	lesser d1(100) , d2(200);
	
	cout<<"Data present in objects "<<endl;
	cout<<"d1 data = "<<d1.getdata()<<endl;
	cout<<"d2 data = "<<d2.getdata()<<endl;
	
	if(d1<d2)
	{
		cout<<"d1 object is the lesser one."<<endl;
	}
	else 
	{
		cout<<"d2 object is the lesser one."<<endl;
	}
	return 0;
}


