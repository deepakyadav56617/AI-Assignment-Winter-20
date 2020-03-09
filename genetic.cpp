#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define population 8

vector<vector<int>> form_population;
vector<int> stu_marks;
set<int> gr_leader;
vector<vector<int>> groups;
void printgroups();
void random(int k,int n,int i)
{
        int e,m;
        mt19937 mt_rand (time(0));
        while(gr_leader.size()!=k)
        {
                e=rand()%n;
                gr_leader.insert(stu_marks[e]);
        }
        m=0;
        vector<int> temp;
        for(auto j=gr_leader.begin();j!=gr_leader.end();j++)
        {
                temp.pb(*j);
                m++;
        }
        groups.pb(temp);
}

int fitness(int k,int n,int i)
{
    int dis[k],fitne=0,in,e;
    int j=0;
    for(in=0;in<n;in++)
    {
        auto gr=groups[i].begin();
        for(j=0;j<k;j++)
        {
            dis[j]=stu_marks[in]-(*gr);
            dis[j]=dis[j]*dis[j];
            gr++;
        }
        e=1000020;
        for(j=0;j<k;j++)
        {
            if(dis[j]<e)
            {
                e=dis[j];
            }
        }
        fitne=fitne+e;
    }
    return fitne;
}
   
int crossover(int e_1,int e_2,int k,int g1)
{
    gr_leader.clear();
    int in=k-1,i;
    for(i=0;i<=g1;i++)
    {
        gr_leader.insert(form_population[e_1][i]);
    }
    for(int j=i;j<k;j++)
    {
        gr_leader.insert(form_population[e_2][j]);
    }
    if(gr_leader.size()!=k)
    {
        return 0;
    }
    else if(gr_leader.size()==k)
    {
    vector<int> temp1;
    for(auto it1=gr_leader.begin();it1!=gr_leader.end();it1++)
    {
         temp1.pb(*it1);
    }
    groups.pb(temp1);
    return 1;
}
}

int fitness2(int k,int mar)
{
int kk=groups.size(),it_val,com=100000,dis,val;
kk--;
auto ite=groups[kk].begin();
for(int i=0;i<k;i++)
{
it_val=*ite;
dis=it_val-mar;
dis=dis*dis;
if(dis<com)
{
val=it_val;
com=dis;
}
ite++;
}
return val;
}
void printgroups()
{
int nn=stu_marks.size();
int kk=groups[0].size();
int stu;
auto stu1=stu_marks.begin();
       // stu=*(stu1);
for(int i=0;i<nn;i++)
{
//auto stu1=stu_marks.begin();
       stu=*(stu1);
int gro=fitness2(kk,stu);
cout<<"student of mark "<<stu<<"->"<<gro<<endl;
stu1++;
}
}

int main()
{
        int n,k,e;
        cout<<"enter value of n:";
        cin>>n;
        cout<<"how many groups:";
        cin>>k;
        cout<<"enter marks:";
        for(int i=0;i<n;i++)
        {
                cin>>e;
                stu_marks.pb(e);
        }
        vector<pair<int,int>> f;
        for(int i=0;i<population;i++)
        {
                mt19937 mt_rand ( time (NULL));
                random(k,n,i);
                gr_leader.clear();
        }
    for(int count1=0;count1<50;count1++)
    {
        for(int i=0;i<population;i++)
        {
            int z=fitness(k,n,i);
            f.pb(make_pair(z,i));
        }
        sort(f.rbegin(),f.rend());
        int i=0;
        mt19937 mt_rand (time(0));
        for(i=0;i<population;i++)
        {
            e=rand()%360;
            if(e>=0 && e<=10)
            {
                int indexno=f[0].second;
                form_population.pb(groups[indexno]);
            }
            else if(e>=11 && e<=30)
            {
                int indexno=f[1].second;
                form_population.pb(groups[indexno]);
            }
            else if(e>=31 && e<=60)
            {
                int indexno=f[2].second;
                form_population.pb(groups[indexno]);
            }
            else if(e>=61 && e<=100)
            {
                int indexno=f[3].second;
                form_population.pb(groups[indexno]);
            }
            else if(e>=101 && e<=150)
            {
                int indexno=f[2].second;
                form_population.pb(groups[indexno]);
            }
            else if(e>=151 && e<=210)
            {
                int indexno=f[2].second;
                form_population.pb(groups[indexno]);
            }
            else if(e>=211 && e<=280)
            {
                int indexno=f[2].second;
                form_population.pb(groups[indexno]);
            }
            else if(e>=281 && e<=360)
            {
                int indexno=f[2].second;
                form_population.pb(groups[indexno]);
            }
        }
        auto it=form_population.begin();
            int cur_pop=0;
            for(i=0;i<4;i++)
            {
                groups[i].clear();
            }
            groups.clear();
            int indexno1=0,indexno2=1;
            while(cur_pop<population)
            {
                mt19937 mt_rand(time(NULL));
                int e_1=rand()%4;
                int e_2=rand()%4;
                int indexno=k-1;
                indexno=rand()%indexno;
                int tell1=crossover(e_1,e_2,k,indexno);
                int tell2=crossover(e_2,e_1,k,indexno);
                if(tell1==0 || tell2==0)
                {
                    groups.erase(groups.begin()+indexno1);
                    continue;
                }
                else if(tell1==1 && tell2==1)
                {
                        indexno1=indexno+2;
                        indexno2=3;
                        gr_leader.clear();        
                        cur_pop=cur_pop+2;
                }
            }
        }
    printgroups();
}
