 ///
 /// @file    vertexNum.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-08-16 12:56:33
 ///
 
#include <iostream>
using std::cout;
using std::endl;

#define MaxVertexNum 100//顶点数目的最大值
typedef char VertexType ;//顶点数目的数据类型
typedef int EdgeType ;//带权图中边上权值的数据类型
typedef strcut{
	VertexType Vex[MaxVertexNum];//顶点表
	EdgeType Edge[MaxVertexNum][MaxVertexNum];//邻接矩阵表，边表
	int vexnum,arcnum;//图的当前顶点的数和弧数
}MGraph;
