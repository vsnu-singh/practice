#include <bits/stdc++.h>
using namespace std;


struct c
 {
 char co;
 int no;
 };

 bool comp(c a, c b)
 {
 if(a.no>b.no)return 1;
 return 0;
 }
 int fun(char s)
 {
 if(s=='2')return 2;if(s=='3')return 3;if(s=='4')return 4;if(s=='5')return 5;if(s=='6')return 6;if(s=='7')return 7;if(s=='8')return 8;if(s=='9')return 9;
 if(s=='T')return 10;if(s=='J')return 11;if(s=='Q')return 12;if(s=='K')return 13;if(s=='A')return 14;
 }
 int main()
 {
 string s1,string s2;
 cin>>s1;
 cin>>s2;
 vector <c>v1;
 vector <c>v2;
 unsigned int i=0;
 while(i<s1.size())
 {
 v1.push_back({s1[i],fun(s1[i+1])});
 i+=3;
 }
 i=0;
 while(i<s2.size())
 {
 v2.push_back({s2[i],fun(s2[i+1])});
 i+=3;
 }
 //calculating for player 1;
 vector<c>arr1;vector<c>arr2;
 sort(v1.begin(),v1.end(),comp);
 sort(v2.begin(),v2.end(),comp);
 arr1=v1;
 arr2=v2;
 int an=10000;
 int an2=10000;
 i=0;
 int ch=0;
 int ch2=0;
 int coun=1;
 for(unsigned int j=1;j<v1.size();j++)
 {
 if(v1[j].co!=v1[0].co)ch=1;
 if(v1[j].no==v1[i].no)
 {
 coun++;
 ch2=1;
 continue;
 }
 if(coun==2 && an%100==0)an=an*2+v1[j-1].no;
 if(coun==3)an=an*5+v1[j-1].no*100;
 if(coun==4)an=an*11+v1[j-1].no;
 i=j;coun=1;
 }
 if(coun==2 && an%100==0)an=an*2+v1[4].no;
 if(coun==3)an=an*5+v1[4].no*100;
 if(coun==4)an=an*11+v1[4].no;
 if(ch==0 && an!=110000)an=100000;
 if(ch2==0)
 {
 if(v1[1].no-v1[4].no==3 && (v1[0].no-v1[1].no==1 || v1[0].no-v1[4].no==12))
{
 an=70000;
 if(ch==0)an=220000;
 if(v1[0].no-v1[4].no==12)v1[0].no=1;
 }
 }
 //2nd playersfsf
 i=0;
 ch=0;
 ch2=0;
 coun=1;
 for(unsigned int j=1;j<v2.size();j++)
 {
 if(v2[j].co!=v2[0].co)ch=1;
 if(v2[j].no==v2[i].no)
 {
 coun++;
 ch2=1;
 continue;
 }
 if(coun==2 && an2%100==0)an2=an2*2+v2[j-1].no;
 if(coun==3)an2=an2*5+v2[j-1].no*100;
 if(coun==4)an2=an2*11+v2[j-1].no;
 i=j;coun=1;
 }
 if(coun==2 && an2%100==0)an2=an2*2+v1[4].no;
 if(coun==3)an2=an2*5+v1[4].no*100;
 if(coun==4)an2=an2*11+v1[4].no;
 if(ch==0 && an2!=110000)an2=100000;
 if(ch2==0)
 {
 if(v2[1].no-v2[4].no==3 && (v2[0].no-v2[1].no==1 || v2[0].no-v2[4].no==12))
{
 an2=70000;
 if(ch==0)an2=220000;
 if(v2[0].no-v2[4].no==12){v2[0].no=1;}
 }
 }
 int ch3=1;
 //cout<<an<<" "<<an2;
 if(an2>an){cout<<"Hand 2 wins"<<endl;ch3=0;}
 if(an2<an){cout<<"Hand 1 wins"<<endl;ch3=0;}
 if(an2==an ){
     //cout<<v2[0].no<<" ";
 for(int it=0;it<4;it++)
 { //cout<<v1[it].no<<" "<<v2[it].no;
 if(v2[it].no>v1[it].no){cout<<"Hand 2 wins";ch3=0;break;}
 if(v2[it].no<v1[it].no){cout<<"Hand 1 wins";ch3=0;break;}
 }}
 if(ch3==1)cout<<"its a tie";
cout<<endl;
 }
