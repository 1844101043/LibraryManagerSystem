#include"PublicFunction.h"



Student::Student(UserInfo obj)
{
   PersonalInfo=obj;
}

Student::~Student()
{} 


void Student::Show()
{
  int Function;	
  while(true)
 {
  cout<<"\t\t同学你好!"<<endl;
  cout<<"1:图书借阅信息\t";
  cout<<"2:查询图书"<<endl;
  cout<<"3:暂无此功能\t";
  cout<<"4:修改密码"<<endl;
  // cout<<"5:找回学生密码\t";
  cout<<"5:退出"<<endl;

  cout << "请选择功能:";
  cin>>Function;
  switch(Function)
  {
  	case 1:   break;
  	case 2:   break;
  	case 3:   break;
	  case 4:   ChangePassword(PersonalInfo); break;
  	case 5: return ;  break;
  	default:break;
  }
 }
}
