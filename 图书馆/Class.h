 //图书管理员类
#ifndef _CLASS_H_
#define _CLASS_H_

#include<iostream>
#include<vector>
#include<fstream>
#include<cstdlib>
#include<string>
#include<windows.h>
#include<iomanip>
#include<sstream>

using namespace std;

class Time;
class Book;
class Teacher;
class Student;
class UserInfo;
class User;
class BookInfo;
class SystemManagere;
class BookManager;

class Time
{
public:
	Time() { Year = Month = Day = 0; }
	int Year;
	int Month;
	int Day;
};

//个人信息类
class UserInfo
{
public:
	UserInfo()
	{
		UserName = "";
		Password = "";
		Limit = -1;
	}
	~UserInfo() {}
	UserInfo& operator = (const UserInfo& obj)
	{
		UserName = obj.UserName;
		Password = obj.Password;
		Limit = obj.Limit;
		return *this;
	}
	string UserName;                      //用户名
	string Password;                      //密码
	int    Limit;                         //类型
};

//用户类
class User
{
public:
	friend void ChangePassword(UserInfo& obj);         //修改密码 
	User();
	~User();
	int Login();
//private:
	fstream User_FilePtr;             //用户文件指针，打开用户文件
	UserInfo PersonalInfo;            //用户个人信息

};

//图书类
class Book
{
public:
	Book();
	~Book()
	void GetInfo();         //获得书籍信息
	string BookName;
	string ISBN;
	string Type;            //图书类别 
	string Press;           //出版社 
	string Place;           //图书地点 
	string Author;          //作者 
	int    Publish_Year;    //出版年份  
	int    Borrow_Number;   //借出数量 
	int    Stocks;          //库存量 
	int    Borrow_Times;    //借阅次数 
	int    Borrow_Limit;    //书籍借阅权限，学生可借true；否则false
	double Price;
};

//图书信息类，用于获取个人借书信息
class BookInfo
{
public:
	BookInfo();          //构造函数
	~BookInfo();         //析构函数
	void ShowTheInfo();  //显示图书信息

private:
	string BookName;
	string ISBN;
	string Type;         //图书类别 
	string Press;        //出版社
	string Place;        //藏书地点 
	string Author;       //作者
	int    Publish_Year; //出版年份 
	double Price;
	Time BorrowReturnTime; //归还日期 
	Time BorrowTime;       //借阅日期
};

//系统管理员类 
class SystemManager
{
public:
    friend void ChangePassword(UserInfo& obj);
	SystemManager(UserInfo obj);                   //构造函数
	~SystemManager();                              //析构函数
												   // void ShowAllUser();                            //打印所有用户信息
	void AddInfo();                                //添加用户信息，根据提示添加 
	void DeleteInfo();                             //删除用户信息
												   //void UpdateInfo();                             //更新用户信息
	void Show();                                   //显示功能列表
private:
	UserInfo PersonalInfo;                         //保存个人信息 
};


 class BookManager
 {
 	public: 
		friend void ChangePassword(UserInfo& obj);

        BookManager(UserInfo obj);               //构造函数 
       ~BookManager();                           //析构函数 
	    friend void  ChangePassword(fstream fileptr);   //修改密码,公共功能 
	    void Show();                            //展示各种功能
 		void AddBookInfo();                     //添加图书信息 
		void ChangeBookInfo();                  //修改图书信息 
		void DeleteBookInfo();                  //删除图书信息 
		void BookBorrowInfo();                  //图书借阅信息
		void FindUserPassword();                //找回用户密码
		void ReturnBook();                      //手动归还图书 ，需要学生信息 
	
     private:    
        UserInfo PersonalInfo;                  //保存个人信息 
 };

 //学生类
 class Student
 {
 public:
	 friend void ChangePassword(UserInfo& obj);     //修改密码

	 Student(UserInfo obj);

	 ~Student();
	 friend void PersonalBorrowInfo();              //个人图书借阅信息
	 friend void FindBookInfo();                    //查询图书信息 
	 void Show();                                   //显示功能
 private:
	 vector<BookInfo> PersonalBookInfo;             //所有借的书的信息 
	 UserInfo PersonalInfo;                         //保存个人信息 


 };

 //老师类
 class Teacher
 {
 public:
	 friend void ChangePassword(UserInfo& obj);     //修改密码

	 Teacher(UserInfo obj);
	 ~Teacher();
	 friend void PersonalBorrowInfo();              //个人图书借阅信息
	 friend void FindBookInfo();                    //查询图书信息 
	 void Show();                                   //显示功能
 private:
	 vector<BookInfo> PersonalBookInfo;            //所有借的书的信息 
	 UserInfo PersonalInfo;                        //保存个人信息 
 };
#endif