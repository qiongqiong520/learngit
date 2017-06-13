 ///
 /// @file    挖掘机技术哪家强.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-04-04 14:46:35
 ///
 
#include <iostream>
#include<algorithm>
using std::cin;
using std::string;
using std::cout;
using std::endl;

int main(int argc,char* argv[])
{
    int n;
    while(cin>>n){
        int *school=new int[100000+1];
        for(int i=0;i<=100001;i++)school[i]=0;
        for(int i=0;i<n;i++){
            int a,b;
            cin>>a>>b;
            school[a]+=b;
        }
        int max =1;
        for(int i=1;i<=100001;i++){
            if(school[max]<=school[i]){
                max=i;
            }
        }
        cout<<max<<' '<<school[max]<<endl;
        delete []school;
    }
    return 0;
}
