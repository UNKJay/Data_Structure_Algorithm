#include<iostream>
using namespace std;

int fi[30];
int di[30];
int ti[30];
int tmp_fi[30];
int h,n;

struct 
{
	int max;
	int time[30];
}solution[30];

int getmax(int p[],int i,int j)
{
	int l=i,max=p[i];
	for(int m=i+1;m<=j;m++)
	{
		if(max<p[m])
		{
			max=p[m];
			l=m;
		}
	}
	return l;
}

void getfish()
{
	for(int i=1;i<=n;i++)
	{
		solution[i].max=0;
		for(int j=1;j<=n;j++)
		{
			solution[i].time[j]=0;
		}
	}
	for(int i=1;i<=n;i++)       //枚举终点
	{
		int t=0;
		int T=h*60;
		for(int j=1;j<=i;j++)
		{
			tmp_fi[j]=fi[j];
			if(j<i)
			T=T-ti[j]*5;
		}

		while(t<T)
		{
			int k=getmax(tmp_fi,1,i);//找到当前情况下，钓鱼量最大的湖进行钓鱼 
			solution[i].time[k]+=5;
			solution[i].max+=tmp_fi[k];
			tmp_fi[k]=(tmp_fi[k]>di[k])?tmp_fi[k]-di[k]:0;
			t+=5;
		}
	}

	for(int i=1;i<=n;i++)           //找出钓鱼量最多下标，即为结束钓鱼的湖序号 
	{
		tmp_fi[i]=solution[i].max;
	}

	int l=getmax(tmp_fi,1,n);
	for(int i=1;i<=n;i++)
	{
		if(i!=n)
			cout<<solution[l].time[i]<<", ";
		else
			cout<<solution[l].time[i]<<endl; 
	}
	cout<<"Number of fish expected: "<<solution[l].max<<endl<<endl;
}

int main()
{
	while(cin>>n,n)
	{
		cin>>h;
		for(int i=1;i<=n;i++)
            cin>>fi[i];
		for(int i=1;i<=n;i++)
            cin>>di[i];
		for(int i=1;i<n;i++)
            cin>>ti[i];
		getfish(); 
	}
}  