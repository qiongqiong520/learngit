 ///
 /// @file    A1075.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-09-03 12:26:12
 ///
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn =10010;
struct Student{
	int id;
	int score[6];
	bool flag;
	int score_all;
	int solve;
}stu[maxn];
int n,k,m;
int full[6];
bool cmp(Student a,Student b){
	if(a.score_all !=b.score_all)return a.score_all>b.score_all;
	else if(a.solve!=b.solve)return a.solve>b.solve;
	else return a.id>b.id;
}
void init(){
	for(int i=1;i<=n;i++){
		stu[i].id=i;
		stu[i].score_all =0;
		stu[i].solve=0;
		stu[i].flag=false;
		memset(stu[i].score,-1,sizeof(stu[i].score));
	}
}
int main(){
	scanf("%d%d%d",&n,&k,&m);
	init();
	for(int i=1;i<=k;i++){
		scanf("%d",&full[i]);
	}
	int u_id,p_id,score_obtained;
	for(int i=0;i<m;i++){
		scanf("%d%d%d",&u_id,&p_id,&score_obtained);
		if(score_obtained!=-1){
			stu[u_id].flag =true;
		}
		if(score_obtained ==-1&& stu[u_id].score[p_id]==-1){
			//谋体第一次编译错误，分支记为0分，输出
		stu[u_id].score[p_id]=0;
		}
		if(score_obtained>stu[u_id].score[p_id]){
			stu[u_id].score[p_id] =score_obtained;//某题获得更高分值
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=k;j++){
			if(stu[i].score[j]!=-1){//计算总分
				stu[i].score_all +=stu[i].score[j];
			}
		}
	}
	sort(stu+1,stu+n+1,cmp);//按要求排序
	int r=1;
	for(int i=1;i<=n&&stu[i].flag==true;i++){
		if(i>1&&stu[i].score_all!=stu[i-1].score_all){
			//当前考生分数低于前一位考生分数，则排名靠前在该考生之前的总考生数
			r=i;
		}
		printf("%d %05d %d",r,stu[i].id,stu[i].score_all);
		for(int j=1;j<=k;j++){
			if(stu[i].score[j]==-1){
				printf(" -");//没有提交过
			}else{
				printf(" %d",stu[i].score[j]);
			}
		}
		printf("\n");
	}
	return 0;
}

