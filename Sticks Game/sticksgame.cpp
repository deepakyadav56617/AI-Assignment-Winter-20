#include<bits/stdc++.h>
using namespace std;
vector<pair<int,char>> tree;

int hashtable[100000];
int ai_turn(int left,int index);
int human_turn(int left);
int parent_ind(int index);
int child_ind(int index);
int tree_insertion(int n,int index,int heur);
void print();
int parent_main(int index,int initial_index);
int main()
{
	int a,b,flag=0,left_old,player,n=13,pick;
	char chance;
	cout<<"AI vs AI - Press 1"<<endl<<"AI vs HUMAN - Press 2"<<endl;
	cin>>player;
	if(player==2)
	{
		cout<<"No. of Sticks you want to play?--";
		cin>>n;
		int initial_index=1,index=0,index1,e=0,left=n,heur;
		cout<<"--:GAME START:--"<<endl<<"HEAD -- Press 1"<<endl<<"TAIL -- Press 2"<<endl;
		srand(time(0));
		cin>>a;
		b=rand()%10;
		b=b%2;
		if(a==b)                                                          
		{
			flag=1;
			cout<<"Hurrah!! You won the toss!  ## Your chance first"<<endl;
		}
		else if(a!=b)
		{
			flag=0;
			cout<<"You loose the toss!   Computer chance first"<<endl;
		}
		while(1)
		{
			if(left==1)
			{
				cout<<"You loose the Game!"<<endl;
				break;
			}
			if(flag==1)
			{
				flag=0;
				left=human_turn(left);
				if(left==1)
				{
					cout<<"You Win"<<endl;
					break;
				}
				index=0;
			}
			if(flag==0)
			{
				left_old=left;
				left=ai_turn(left,index);
				cout<<"Computer picks "<<left_old-left<<" sticks"<<endl<<endl;
				flag=1;
			}

		}
	}
	if(player==1)
	{
		cout<<"How many stick you want to play with---";
		cin>>n;
		int heur;
		int initial_index=1,index=0,index1,e=0,left=n;
		cout<<"enter for toss"<<endl<<endl;
		cin>>chance;
		srand(time(0));
		a=rand()%10;
		a=a%2;
		b=rand()%10;
		b=b%2;
		if(a==b)                                                            //human won the toss
		{
			flag=1;
			cout<<"AI-1 won the toss!AI-1 chance first  press enter"<<endl;
		}
		else if(a!=b)
		{
			flag=0;
			cout<<"AI-2 won the toss!AI-2 chance first press enter"<<endl;
		}
		while(1)
		{
			if(left==1)
			{
				cout<<"AI-2 win"<<endl;
				break;
			}
			if(flag==1)
			{
				left_old=left;
				flag=0;
				left=ai_turn(left,index);
				cout<<"AI-1 picks "<<left_old-left<<" sticks"<<endl; 
				cout<<"sticks left:"<<left<<endl;

				if(left==1)
				{
					cout<<"AI-1 win"<<endl;
					break;
				}
				cin>>chance;
				index=0;
			}
			if(flag==0)
			{
				left_old=left;
				left=ai_turn(left,index);
				cout<<"AI-2 picks "<<left_old-left<<" sticks"<<endl;
				cout<<"sticks left:"<<left<<endl;

				flag=1;
				cin>>chance;
			}

		}
	}
}
int ai_turn(int left,int index)
{
	int heur;
	tree.push_back(make_pair(index,'a'));
	hashtable[index]=left;
	for(int i=13;i>=-1;i--)
	{

		heur=5+(4*i);
		//cout<<heur<<" ";
		if(heur<left)

			break;
	}
	index=0;
	index=tree_insertion(left,index,heur);
	//cout<<endl<<"computer picks "<<left-hashtable[index]<<" sticks"<<endl<<endl;
	left=hashtable[index];
	memset(hashtable,'\0',sizeof(hashtable));
	tree.clear();
	return left;
}
int human_turn(int left)
{
	int pick;
//	left=human_turn(left);
	cout<<"sticks left:"<<left<<endl;
	cout<<"how many stick you want to pick up-";
	cin>>pick;
	if(pick>3 || pick==0)
	{
		cout<<"error!!you must have to chose atleast one stick and not more than 3"<<endl<<endl;
		left=human_turn(left);
	}
	else
	{
		left=left-pick;
	}
	return left;
}
int parent_main(int index,int initial_index)
{
	int index1;
	while(index!=initial_index)
	{
		index1=index;
		index=parent_ind(index);
	}
	return index1;
}
void print()
{
	auto it=tree.begin();
	int i=0;
	while(it!=tree.end())
	{
		cout<<tree[i].first<<" "<<tree[i].second<<endl;
		it++;
		i++;
	}
}
int tree_insertion(int n,int index,int heur)
{
	int initial_index=index;
	int e=n,k,chance;
	int j=index;
	int ind=0;
	k=1;
	int pe=pow(3,k);
	while(1)
	{
		for(int i=1;i<=3;i++)
		{
			ind++;
			index++;
			e=n-i;
			if(e>=heur)
			{
				if(k%2!=0)
				{
					tree.push_back(make_pair(index,'b'));
					hashtable[index]=e;
					if(e==heur)
						return parent_main(index,initial_index);
				}
				else if(k%2==0)
				{
					tree.push_back(make_pair(index,'a'));
					hashtable[index]=e;
				}
			}
		}
		j++;
		n=hashtable[j];
		if(ind==pe)
		{
			ind=0;
			k++;
			pe=pow(3,k);
		}
	}
}
int parent_ind(int index)
{
	int a=index%3;
	int p_index=index/3;
	if(a==0)
	{
		p_index--;
	}
	return p_index;
}

int child_ind(int index)
{
	return ((3*index)+1);
}
