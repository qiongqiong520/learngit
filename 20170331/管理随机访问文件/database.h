 ///
 /// @file    database.h
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-04-02 21:20:14
 ///
#ifndef DATABASE_H
#define DATABASE_H

template<class T>
class Database{
	public:
		Database();
		void run();
	private:
		fstream database;
		char fName[20];
		ostream& print(ostream&);
		void add(T&);
		bool find(const T&);
		void modify(const T&);
		friend ostream& operator<<(ostream& out,Database& db)
		{
			return db.print(out);
		}
};
#endif

