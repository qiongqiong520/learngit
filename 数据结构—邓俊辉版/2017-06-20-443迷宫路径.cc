 ///
 /// @file    2017-06-20-443迷宫路径.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-06-20 19:03:02
 ///
 
#include <iostream>
using std::cout;
using std::endl;
typedef enum{AVAILABLE,ROUTE,BACKTRACKED,WALL}Status;//迷宫单元状态
//原始可用，在当前路径上，所有方向均尝试失败后回溯过，不可使用
typedef enum{UNKNOWN,EAST,SOUTH,WEST,NORTH,NO_WAY}ESWN;//单元的相对邻接方向
//未定，东西南北,无路可通

inline ESWN nextESWN(ESWN ewsn){return ESWN(ewsn+1);}//一次转入下一邻接方向

struct Cell{//迷宫格点

