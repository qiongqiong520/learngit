 ///
 /// @file    skel.h
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-03-22 11:40:35
 ///
 
#ifndef __SKEL_H_
#define __SKEL_H_

/*UNIX version*/
#define INIT(){program_name=\
	strrchr(argv{0},'/'\
			program_name++:\
			(program_name=argv[0])}
#define EXIT(s) exit(s)
#define CLOSE(s) if(close(s))error(1,errno,\
	"close failed")
#define set_errno(e) errno ={e}
#define isvalidsock(s) {(s)>=0}
			typedef int SOCKET;
#endif /*__SKEL_H_*/

