#include <iostream>
#include <cmath>
#include "time.h"
using namespace std;
int N;
int q[100];
int m=0;
void show(int n)
{
	cout<<"��"<<++m<<"�ַ���ÿ���ʺ����ڵ��кŷֱ�Ϊ��" ;
	for( int i = 1; i <= N;i ++ )
    cout <<q[i] << " ";
    cout << "\n";
	
}
bool place(int i)
{
	int j=1;
	if(i==1)
	{
		return true;
	}
	while(j<i)
	{
		if((q[j]==q[i])||(abs(q[j]-q[i])==abs(j-i)))
		{
		return false;
	    }
	    j++;
	}
	return true;
}
void NQueen(int n)
{
	int i=1;
	q[i]=0;
	while(i>=1)
	{
		q[i]++;
		while(q[i]<=n&&!place(i))
		{
			q[i]++;
		}
		if(q[i]<=n)
		{
			if(i==n)
			{
				
				show(n);
			}
			else
			{
				i++;
				q[i]=0;
			}
		}
		else i--;
	}
}

int main()
{
	clock_t start, finish; 
	double  duration;
	cout<<"������N��ֵ"<<"\n";
    cin >> N;
    start = clock();
    NQueen(N);
    finish = clock();
    cout<<"һ����"<<m<<"�ְڷ�N�ʺ�ķ���"<<"\n";
    duration = (double)(finish - start) / CLOCKS_PER_SEC;    
    printf( "%f seconds\n", duration );    
    system("pause");
	return 0;
}
