 ///
 /// @file    stock.h
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-03-02 14:06:42
 ///
 
#include <iostream>
using std::cout;
using std::endl;
#ifndef STOCK10_H__
#define STOCK01_H__

class Stock
{
	private:
		std::String company;
		long shares;
		double share_val;
		double total_val;
		void set_tot(){
			total_val = share * share_val;
		}
	public:
		Stock();
		Stock(const std::string & co, long n =0,double pri =0);
		~Stock();
		void sell(double price,long num);
		void buy(long num,,double pricea);
		void update(double price);
		vois show();
}
#endif

