#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;
struct E{
char name[101];
int age;
int score;
bool operator <(const E &b)const{
if(
