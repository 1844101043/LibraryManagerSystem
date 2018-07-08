#include"PublicFunction.h"


//构造函数
User::User()
{
	fstream UserFile;
	UserFile.open("UserInfo.csv", ios::in|ios::out);
	if (UserFile.fail())
	{
		cout << "文件打开失败" << endl;
		exit(1);
	}
	UserFile.close();
}	

//析构函数
User::~User()
{}


int User::Login()
{
   int      TypeTemp=-1;
   int      LoginNumber=0;    //登陆次数
   UserInfo UserTemp;         //暂存输入
   
   //输入用户名<=18位
   PersonalInfo.UserName=InputUserName();                      
   
   //输入密码<=18位
   while(true)
   {
   	LoginNumber++;                   //记录登陆次数，超过三次未成功自动退出
   	cout<<"请输入密码:";
   	cin>>PersonalInfo.Password;

    if(GetUserInfo(PersonalInfo,1))  //从文件读取用户信息判断用户密码是否正确，类型为1
    {
      cout<<"登陆成功!"<<endl;
      return PersonalInfo.Limit;     //返回登陆类型，个人信息存在PersonalInfo;
    }

    else 
    {
      cout<<"登录失败!请重试!"<<endl;
    }


   	if(LoginNumber==3)
   	{
   		cout<<"密码输入次数过多，稍后再试！"<<endl;
		  exit(1);
   	}

   }
   return -1;
}
