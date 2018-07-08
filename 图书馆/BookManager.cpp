#include"PublicFunction.h"
BookManager::BookManager(UserInfo obj)
{
	PersonalInfo = obj;
}

BookManager::~BookManager()
{}

void BookManager::Show()
{
  int Function;	
  while(true)
 {
  cout<<"\t\t图书管理员你好!"<<endl;
  cout<<"1:修改密码\t";
  cout<<"2:添加图书信息"<<endl;
  cout<<"3:修改图书信息\t";
  cout<<"4:删除图书信息"<<endl;
  cout<<"5:图书借阅信息\t";
  cout<<"6:手动归还图书"<<endl;
  cout<<"7:找回用户密码\t";
  cout<<"8:退出"<<endl;

  cout<<"请选择功能:";
  cin>>Function;
  switch(Function)
  {
  case 1:  ChangePassword(PersonalInfo);  break;
  	case 2:   break;
  	case 3:   break;
  	case 4:   break;
  	case 5:   break;
  	case 6:   break;
  	case 7:   break;
  	case 8: return;
  	default:break;
  }
 }
}

void BookManager::AddBookInfo()                     //添加图书信息 
{
  vector<Book> Books;
  Book         InputBook;    //暂存图书输入   
}