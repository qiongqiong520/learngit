 ///
 /// @file    InetAddress.h
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-03-17 22:54:43
 ///


#ifndef WD_INETADDRESS_H_
#define WD_INETADDRESS_H_

#include<string>
#include<netinet/in.h>

namespace wd
{
  	class InetAddress//copyable
	{
  		public:
 			explicit InetAddress(uint16_t port);
			InetAddress(const std::string &ip,uint16_t port);
			InetAddress(const struct sockaddr_in &addr);

			//st port
			void setSockAddrInet(const struct sockaddr_in addr)
			{
				addr_ = addr;
			}

			const struct sockaddr_in *getSockAddrInet() const
			{return &addr_;
			}

			//ip port
			std::string toIp() const;
			uint16_t toPort() const;

		private:
			struct sockaddr_in addr_;

	};
}//end of namespace wd

#endif
