//Crontab
//simulation method
//https://blog.csdn.net/wl16wzl/article/details/79265435
//2018/11/10 15:13
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <cstdlib>
#include <queue>
using namespace std;
const int N = 20+1;
const string Month[] = {"Nothing", "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
const string Week[] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};
const sring dnum[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
struct intv{//interval: [a, b)
    //(-1, -1) represents all time is available
    int a;
    int b;
}
struct node{//save the time interval that meets the requirements
    vector<intv> mte;
    vector<intv> hour;
    vector<intv> day;
    vector<intv> mon;
    vector<intv> week;
    string cmd;
}m[N];
struct cmder{//command and operation time
    int year, month, day, hour, mte;
    string cmd;
    cmder(int a, int b, int c, int d, int e, string f){
        year = a; month = b; day = c; hour = d; mte = e;
        cmd = f;
    }
    bool operator < (const cmder &u) const{
        if(year>u.year) return true;
        if(year<u.year) return false;
        if(month>u.month) return true;
        if(month<u.month) return false;
        if(day>u.day) return true;
        if(day<u.day) return false;
        if(hour>u.hour) return true;
        if(hour<u.hour) return false;
        if(mte>u.mte) return true;
        if(mte<u.mte) return false;
        return true;//先入靠前
    }
};
priority_queue<cmder> outq;//把时间范围内需要操作的命令放进来排好序
bool is_end(int year, int month, int day, int hour, int mte, int uyear, int umonth, int uday, int uhour, int umte){//判断是否超出时间范围
    if(year>uyear) return true;
    if(year<uyear) return false;
    if(month>umonth) return true;
    if(month<umonth) return false;
    if(day>uday) return true;
    if(day<uday) return false;
    if(hour>uhour) return true;
    if(hour<uhour) return false;
    if(mte>umte) return true;
    if(mte<umte) return false;
    return true;
}
bool is_week(int q,int e){ //判断周是否符合 
	bool flag=false;
	int l=m[q].week.size();
	for(int i=0;i<l;i++)
		if(m[q].week[i].b==-1||e<=m[q].week[i].b&&e>=m[q].week[i].a){
			flag=true;
			break;
		}
	return flag;
}
bool is_month(int q,int d){ //判断月是否符合
	bool flag=false;
	int l=m[q].mon.size();
	for(int i=0;i<l;i++)
	if(m[q].mon[i].b==-1||d<=m[q].mon[i].b&&d>=m[q].mon[i].a){
		flag=true;
		break;
	}
	return flag;
}
bool is_day(int q,int c){ //判断天是否符合
	bool flag=false;
	int l=m[q].day.size();
	for(int i=0;i<l;i++)
		if(m[q].day[i].b==-1||c<=m[q].day[i].b&&c>=m[q].day[i].a){
			flag=true;
			break;
		}
	return flag;
}
bool is_hour(int q,int nb){ //判断小时是否符合
	bool flag=false;
	int l=m[q].hour.size();
	for(int i=0;i<l;i++)
		if(m[q].hour[i].b==-1||(nb<=m[q].hour[i].b)&&(nb>=m[q].hour[i].a)){
			flag=true;
			break;
		}
	return flag;
}
bool is_mte(int q,int a){ //判断分钟是否符合
	bool flag=false;
	int l=m[q].mte.size();
	for(int i=0;i<l;i++)
		if(m[q].mte[i].b==-1||a<=m[q].mte[i].b&&a>=m[q].mte[i].a){
			flag=true;
			break;
		}
	return flag;
}
int isyear(int a){ //判断闰年 
	if(a%400==0||a%4==0&&a%100!=0) return 1;
	return 0;
}
int zeller(int year,int month,int day){ //蔡勒公式，计算这天是周几，公式只适合于1582年10月15日之后的情形
	int m,d=day;
	if(month<3){
		m=month+12;
		year--;
	}
	else m=month;
	int c=year/100;	
	int y=year%100;
	int w=(c/4)-2*c+(y+y/4)+(13*(m+1)/5)+day-1;
	return (w%7+7)%7;  //返回0代表周日 
}

int n;
string s,t;
int main(){
	cin>>n>>s>>t;
	int sa,sb,sc,sd,se;
	int ea,eb,ec,ed,ee;
	sa=sb=sc=sd=se=0;
	ea=eb=ec=ed=ee=0;
	for(int i=0;i<4;i++) //计算开始时间 
		sa=sa*10+s[i]-'0';
	for(int i=4;i<6;i++)
		sb=sb*10+s[i]-'0';
	for(int i=6;i<8;i++)
		sc=sc*10+s[i]-'0';
	for(int i=8;i<10;i++)
		sd=sd*10+s[i]-'0';
	for(int i=10;i<12;i++)
		se=se*10+s[i]-'0';
	for(int i=0;i<4;i++) //计算结束时间 
		ea=ea*10+t[i]-'0';
	for(int i=4;i<6;i++)
		eb=eb*10+t[i]-'0';
	for(int i=6;i<8;i++)
		ec=ec*10+t[i]-'0';
	for(int i=8;i<10;i++)
		ed=ed*10+t[i]-'0';
	for(int i=10;i<12;i++)
		ee=ee*10+t[i]-'0';
	for(int q=0;q<n;q++){
		string a;
		int l;
		qj k;
		cin>>a;
		l=a.length();
		int t=0,t0;
		bool flag=false;
		for(int i=0;i<l;i++){ //处理分钟
			if(isdigit(a[i])) t=t*10+a[i]-'0';
			else if(a[i]=='-'){
				t0=t;
				t=0;
				flag=true;
			}
			else if(a[i]==','){
				if(flag) k.a=t0;
				else k.a=t;
				k.b=t;
				m[q].mte.push_back(k);
				t=0;
				flag=false;
			}
			else if(a[i]=='*'){
				k.a=k.b=-1;
				m[q].mte.push_back(k);
				break;
			}
			if(i==l-1) {
				if(flag) k.a=t0;
				else k.a=t;
				k.b=t;
				m[q].mte.push_back(k);
				t=0;
			}
		}
		cin>>a;
		l=a.length();
		t=0;
		flag=false;
		for(int i=0;i<l;i++){ //处理小时
			if(isdigit(a[i])) t=t*10+a[i]-'0';
			else if(a[i]=='-'){
				t0=t;
				t=0;
				flag=true;
			}
			else if(a[i]==','){
				if(flag) k.a=t0;
				else k.a=t;
				k.b=t;
				m[q].hour.push_back(k);
				t=0;
				flag=false;
			}
			else if(a[i]=='*'){
				k.a=k.b=-1;
				m[q].hour.push_back(k);break;
			}
			if(i==l-1){
				if(flag) k.a=t0;
				else k.a=t;
				k.b=t;
				m[q].hour.push_back(k);
				t=0;
			}
		}
		cin>>a;
		l=a.length();
		t=0;
		flag=false;
		for(int i=0;i<l;i++){ //处理天
			if(isdigit(a[i])) t=t*10+a[i]-'0';
			else if(a[i]=='-'){
				t0=t;
				t=0;
				flag=true;
			}
			else if(a[i]==','){
				if(flag) k.a=t0;
				else k.a=t;
				k.b=t;
				m[q].day.push_back(k);
				t=0;
				flag=false;
			}
			else if(a[i]=='*'){
				k.a=k.b=-1;
				m[q].day.push_back(k);break;
			}
			if(i==l-1){
				if(flag) k.a=t0;
				else k.a=t;
				k.b=t;
				m[q].day.push_back(k);
				t=0;
				flag=false;
			}
		}
		string a0="";
		cin>>a;
		l=a.length();
		t=0;
		flag=false;
		for(int i=0;i<l;i++){ //处理月
			if(isdigit(a[i])) t=t*10+a[i]-'0';
			else if(isalpha(a[i])) a0+=a[i];
			else if(a[i]=='-'){
				if(a0.length()!=0){
					for(int j=0;j<a0.length();j++)
						a0[j]=tolower(a0[j]);
					for(int j=0;j<13;j++)
						if(Month[j]==a0){
							t=j;
							break;
						}
				}
				a0="";
				t0=t;
				t=0;
				flag=true;
			}
			else if(a[i]==','){
				if(a0.length()!=0){
					for(int j=0;j<a0.length();j++)
					a0[j]=tolower(a0[j]);
					for(int j=0;j<13;j++)
					if(Month[j]==a0){
						t=j;
						break;
					}
				}
				a0="";
				if(flag) k.a=t0;
				else k.a=t;
				k.b=t;
				t=0;
				m[q].mon.push_back(k);
				flag=false;
			}
			else if(a[i]=='*'){
				k.a=k.b=-1;
				m[q].mon.push_back(k);break;
			}
			if(i==l-1){
				if(a0.length()!=0){
					for(int j=0;j<a0.length();j++)
					a0[j]=tolower(a0[j]);
					for(int j=0;j<13;j++)
					if(Month[j]==a0){
						t=j;
						break;
					}
				}
				a0="";
				if(flag) k.a=t0;
				else k.a=t;
				k.b=t;
				t=0;
				m[q].mon.push_back(k);
				flag=false;
			}
		}
		a0="";
		cin>>a;
		l=a.length();
		t=0;
		flag=false;
		for(int i=0;i<l;i++){ //处理周
			if(isdigit(a[i])) t=t*10+a[i]-'0';
			else if(isalpha(a[i])) a0+=a[i];
			else if(a[i]=='-'){
				if(a0.length()!=0){
					for(int j=0;j<a0.length();j++)
						a0[j]=tolower(a0[j]);
					for(int j=0;j<7;j++)
						if(Week[j]==a0){
							t=j;
							break;
						}
				}
				a0="";
				t0=t;
				t=0;
				flag=true;
			}
			else if(a[i]==','){
				if(a0.length()!=0){
					for(int j=0;j<a0.length();j++)
						a0[j]=tolower(a0[j]);
					for(int j=0;j<7;j++)
						if(Week[j]==a0){
							t=j;
							break;
						}
				}
				a0="";
				if(flag) k.a=t0;
				else k.a=t;
				k.b=t;
				t=0;
				m[q].week.push_back(k);
				flag=false;
			}
			else if(a[i]=='*'){
				k.a=k.b=-1;
				m[q].week.push_back(k);break;
			}
			if(i==l-1){
				if(a0.length()!=0){
					for(int j=0;j<a0.length();j++)
						a0[j]=tolower(a0[j]);
					for(int j=0;j<7;j++)
						if(Week[j]==a0){
							t=j;
							break;
						}
				}
				a0="";
				if(flag) k.a=t0;
				else k.a=t;
				k.b=t;
				t=0;
				m[q].week.push_back(k);
				flag=false;
			}
		}
		cin>>a;
		m[q].cmd=a;
		int i=sa,j=sb,nk=sc,x=sd,y=se; //这里从头到尾过一遍时间，加了回溯 
		for(;i<=ea;i++,j=1)
			for(;j<=12;j++,nk=1)
				if(is_month(q,j))
					for(;nk<=dnum[j]+(j==2?isyear(i):0);nk++,x=0)
						if(is_day(q,nk)&&is_week(q,zeller(i,j,nk)))
							for(;x<24;x++,y=0)
								if(is_hour(q,x))
									for(;y<60;y++){
										if(is_end(i,j,nk,x,y,ea,eb,ec,ed,ee)) goto stop; //超出时间跳出循环 
										if(is_mte(q,y)) outq.push(cmder(i,j,nk,x,y,a)); //符合的话就加入队列 
									}
								stop:;
	}
	while(!outq.empty()){ //按顺序输出
		cmder out=outq.top();
		outq.pop();
		printf("%04d%02d%02d%02d%02d ",out.year,out.month,out.day,out.hour,out.mte),cout<<out.cmd<<endl;
	}
	return 0;
}
