 ///
 /// @file    SocketIO.h
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-03-18 00:01:50

#ifndef WD_SOCKETIO_H_
#define WD_SOCKETIO_H_


#include "Noncopyable.h"
#include <sys/types.h>

namespace wd
{
 	class SocketIO :Noncopyable
	{
 		public:
 			explicit SocketIO(int sockfd)
				:sockfd_(sockfd)
			{
			}
			ssize_t readn(char *buf,size_t count);
			ssize_t writen(const char *buf,size_t count);
			ssize_t readline(char *buf,size_t maxlen);

		private:
 			ssize_t recv_peek(char *buf,size_t len);

			const int sockfd_;
	};
}//end of namespace wd
#endif 
