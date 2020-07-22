/*
NAME:DEEPAK KUMAR YADAV
ROLL_NO:1801048
1.State space:
       Here sate space is a 8x8 matrix where the position of a queen is represented by 1
2.State transition operator:
		adding a new queen which is denoted by 1 in the subsequent row.
3.intitial state:
		a 8 x 8 null matrix.
4.Goal state:
		When all the rows are filled with a single queen at non attacking positions,
5.Cost: the total cost i got with my approach was 803.
6.I implemented the heuristic with A* search implementation the cost i reduced greatly from previous assignemnt
  bfs cost of 2056 to heuristic search cost 803.		 				
		       
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool solution=false;
int cost=0;
struct board{
	int mat[8][8],queens,h,p,t;//h is heuristic cost,p is path cost ,queens is number of queens in the board
};
vector<board> q1;
bool compare(board b1,board b2){
	return (b1.h+b1.p<b2.h+b2.p);
}
board initialize(board &b1){
	for(int i=0;i<8;i++){
		for(int j=0;j<8;j++){
			b1.mat[i][j]=0;
		}
	}
	b1.queens=0;
	b1.p=0;
	b1.h=(8-b1.queens);
    b1.t=0;
	return b1;
}
void print(board &temp){
	cout<<"temp"<<endl;
	for(int i=0;i<8;i++){
		for(int j=0;j<8;j++){
			cout<<temp.mat[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<"heuristic:"<<temp.h<<endl;
	cout<<"path cost:"<<temp.p<<endl;
	cout<<"no.of queens"<<temp.queens<<endl;
	cout<<endl<<endl;
}
bool isvalid(board &temp){
	int q=temp.queens,p=0,i,i2;
	for(i=0;i<8;i++){
		if(temp.mat[q-1][i]==1) break;
	}
	for(int j=q-2;j>=0;j--){
		if(temp.mat[j][i]==1){
			return false;
		}
	}
	i2=i-1;
	for(int j=q-2;j>=0;j--){
		if(j<0||i2<0) break;
		if(temp.mat[j][i2]==1) return false;
		i2--;
	}
	i2=i+1;
	for(int j=q-2;j>=0;j--){
		if(j<0||i2>7) break;
		if(temp.mat[j][i2]==1) return false;
		i2++;
	}
	return true;
}
void states(vector<board> &q1){
	board temp;
	bool oc=true;
	int size=q1.size();
	sort(q1.begin(),q1.end(),compare);
	temp=q1.front();
    vector<board>::iterator it; 
    it = q1.begin(); 
    q1.erase(it); 
	int q=temp.queens;
    if(temp.queens==8) {
    	print(temp);
    	cout<<"solution found\n"<<endl;
    	cout<<"cost is "<<cost<<endl;
    	solution=true;
    	return;
	}
	for(int i=0;i<8;i++){
		temp.mat[q][i]=1;
		int pre=temp.p;
		temp.queens++;
		temp.h--;
		temp.p=pre+1;
		if(q==0||isvalid(temp)){
			print(temp);
			q1.push_back(temp);
			cost++;
		}
		temp.queens--;
		temp.h++;
		temp.p=pre;
		temp.mat[q][i]=0;
	}
}
int main(){
	board b1;
	initialize(b1);
	q1.push_back(b1);
    while(!q1.empty()&&solution==false){
    	states(q1);	
	}
	return 0;
}
