#ifndef SOCKETIO_H_
#define SOCKETIO_H_

#include "Noncopyable.h"
#include <sys/types.h>

namespace wd
{
class SocketIO : Noncopyable
{
public: 
    explicit SocketIO(int sockfd)//可以阻止不应该允许的经过转换构造函数进行的隐式转换的发生，声明为explicit的构造函数不能在隐式转换中使用
    : sockfd_(sockfd)//只能显示调用，不能隐式调用
    {
		//Socket t1=12;//错误
		//Socket t2(12);//正确,则显式调用成功
		//普通构造函数能被隐式调用，explicit只能被显式调用
    }

    ssize_t readn(char *buf, size_t count);
    ssize_t writen(const char *buf, size_t count);
    ssize_t readline(char *usrbuf, size_t maxlen);
private:
    ssize_t recv_peek(char *buf, size_t len);

    const int sockfd_;
};

}


#endif //SOCKETIO_H_
