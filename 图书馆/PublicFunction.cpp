#include"PublicFunction.h"



void ChangePassword(UserInfo& obj)
{
   vector<UserInfo>   AllUserInfo;
   int        WrongTime=3;	
   UserInfo   Temp;
   string     OldPassword;                           //输入保存原密码
   string     NewPassword;                           //暂时保存新密码
   fstream    Read;                                  // 输出输入文件指针
   string     Info_Buffer;                           //从原文件获取一行用户信息

   while(WrongTime--)
  {
   cout<<"请输入原密码:";
   cin>>OldPassword;
   if(OldPassword!=obj.Password)
   {
   	  if(WrongTime==0)
     {
   	  cout<<"输入次数过多！"<<endl;
   	  exit(1);
     }
   	cout<<"密码输入错误"<<endl;
   }
   
   else break;
  }
   
   cout<<"重置密码"<<endl;
   NewPassword=InputPassword();
   //打开文件
   Read.open("UserInfo.csv",ios::in);
   if(Read.fail())
   {
    cout<<"文件打开失败"<<endl;
    exit(1);
   }

   //读写文件，遇到要删除的用户跳过
   while(true)
   {
     Read>>Info_Buffer;                              //从原文件获取用户信息
     istringstream  Str_Buffer(Info_Buffer);

     getline(Str_Buffer,Temp.UserName,',');          //获取用户名  
     getline(Str_Buffer,Temp.Password,',');          //获取密码
     Temp.Limit = *(Info_Buffer.end() - 1) - '0';    //获取权限段

     if(Read.eof())                                  //文件结束跳出
      break;

     if(Temp.UserName==obj.UserName)                 //修改密码
     {
     	Temp.Password=NewPassword;
     	obj=Temp;                                    //密码已经修改，返回新的个人信息
     }


     AllUserInfo.push_back(Temp);                    //全部保存到vector中
   }
   Read.close();


   Read.open("UserInfo.csv", ios::out);
   if (Read.fail())
   {
	   cout << "文件打开失败" << endl;
	   exit(1);
   }

  for(vector<UserInfo>::iterator begin=AllUserInfo.begin();begin!=AllUserInfo.end();begin++)
  {
    Info_Buffer=begin->UserName+","+begin->Password+",";
    Info_Buffer.push_back(begin->Limit+'0');
    Info_Buffer.push_back('\n');
    Read<<Info_Buffer;
  }
  //关闭文件
   Read.close();
}

//修改密码 


string InputPassword()
{
	string Password;
	string PasswordCheck;
	while(true)
	{
		cout << "请输入密码:";
		cin >> Password;
       if(Password.size()>18)
   	     cout<<"长度错误!"<<endl;

       else if(Password.find(',',0)!=-1)
       {
    	cout<<"不能使用非法字符','!"<<endl;
       }

      else
      {
      	cout << "请确认密码:";
		cin >> PasswordCheck;
		if (Password != PasswordCheck)
		{
			cout << "两次密码输入不正确，请重试！" << endl;
		}
		else break;
      }
	}
	return Password;
}


string InputUserName()
{
	string  UserName; 
	   //输入用户名
   while(true)
   {
    cout<<"请输入用户名:";
    cin>>UserName;
    if(UserName.size()>18)
   	 cout<<"长度错误!"<<endl;

    else if(UserName.find(',',0)!=-1)
    {
    	cout<<"不能使用非法字符','!"<<endl;
    }

    else break;
   }

   return UserName;
}

//判断是否在登陆文件里,登陆时的用户名和密码双重比较
//添加用户信息时只需要判断用户名
bool GetUserInfo(UserInfo& obj,int GetType)               
{
  string   Info_Buffer;                       //保存从文件中读取的一行数据 
  UserInfo Temp;                              //临时保存从文件读取的用户信息

  //文件指针初始化
  fstream User_FilePtr;
  User_FilePtr.open("UserInfo.csv",ios::in);
  if(User_FilePtr.fail())
  {
    cerr<<"文件打开失败!"<<endl;
    exit(1);
  }


 //读取文件，获取用户名和密码、权限
 while(true)
 {
   User_FilePtr >> Info_Buffer;
   istringstream Str_Buffer(Info_Buffer);       //字符串缓冲区 
   getline(Str_Buffer,Temp.UserName,',');       //获取用户名段
   getline(Str_Buffer,Temp.Password,',' ) ;     //获取密码段
   Temp.Limit = *(Info_Buffer.end() - 1) - '0'; //获取权限段
   

   if(Temp.UserName==obj.UserName&&GetType==2)  //只检查用户名是否重用
   {
    User_FilePtr.close();                       //关闭文件 
   	return true;                                //重用返回真
   }

   else if(Temp.UserName==obj.UserName
          &&Temp.Password==obj.Password&&GetType==1)//双重检查
   {
    obj=Temp;                                   //返回用户权限,且将用户信息返回
	User_FilePtr.close();                       //关闭文件 
    return true;                                //密码正确返回真
   }

   if(User_FilePtr.eof())
    {
      break;
    }
 }
 User_FilePtr.close();                       //关闭文件 
 return false;

}