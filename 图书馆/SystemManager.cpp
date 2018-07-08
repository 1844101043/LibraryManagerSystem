
#include"PublicFunction.h"

//构造函数
SystemManager::SystemManager(UserInfo obj)
{
  PersonalInfo=obj;
}

//析构函数
SystemManager::~SystemManager()
{}


void SystemManager::Show()
{
  int Function;	
  while(true)
 {
  cout<<"\t\t系统管理员你好!"<<endl;
  cout<<"1:添加用户信息\t";
  cout<<"3:删除用户信息\t";
  cout<<"4:修改密码"<<endl;
  cout<<"5:找回用户密码\t";
  cout<<"6:退出"<<endl;

  cout<<"请选择功能:";
  cin>>Function;
  switch(Function)
  {
  	case 1: AddInfo();break;
  	case 2:   break;
  	case 3: DeleteInfo();break;
  	case 4: ChangePassword(PersonalInfo);  break;
  	case 5:   break;
  	case 6: return ;  break;
  	default:break;
  }
 }
}


//添加用户信息
void SystemManager::AddInfo()
{
	UserInfo  Input;                           //暂存输入信息
	string PasswordCheck;                      //检查密码  
	string Info_Buffer;                        //输入到文件的信息串
  fstream Write;

  //判断输入用户类型是否正确
	while (true)
	{
		int Type = 3;
		cout << "请选择添加用户类型" << endl;
		cout << "0:系统管理员" << endl;
		cout << "1:图书管理员" << endl;
		cout << "2:老师账户" << endl;
		cout << "3:学生账户" << endl;
		cin >> Type;
		if (Type != 0 && Type != 1 && Type != 2 && Type != 3)
		{
			cout << "类型错误!" << endl;
		}
		else
		{
			Input.Limit = Type;
			break;
		}
	}

//判断输入用户名是否已经存在

     
      while(true)
	  {
		  Input.UserName=InputUserName();

       if(GetUserInfo(Input,2))      //只判断用户名是否重用
      {
        cout<<"用户名已被占用！"<<endl;
      }

		  else break;
	  }
	
//输入密码并确认
    Input.Password=InputPassword();


//打开文件保存新增信息
     Write.open("UserInfo.csv", ios::app);
     if (Write.fail())
    {
      cerr << "文件打开失败!" << endl;
      exit(1);
    }


	  Info_Buffer=Input.UserName+","+Input.Password+",";
    Info_Buffer.push_back(Input.Limit+'0');
    Info_Buffer.push_back('\n');
    Write<<Info_Buffer;           //保存个人信息
	  Write.close();                //关闭文件
}


void SystemManager::DeleteInfo()
{
   vector<UserInfo>  AllUserInfo;
   UserInfo   Temp;                   //临时存储输入信息便于查找用户是否存在
   string     TempUserName;                        //从要删除的用户
   fstream    Read;                                 // 输出文件指针
   string     Info_Buffer;                           //从原文件获取一行用户信息

   cout<<"输入要删除的用户名:";
   cin>>Temp.UserName;
   if(!GetUserInfo(Temp,2))          //说明用户名不存在
   {
    cout<<"用户不存在！"<<endl;
    return;
   }
   TempUserName=Temp.UserName;       //要删除的用户名
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
     if(TempUserName==Temp.UserName)                 //获取的用户名与要删除的比较，跳过要删除的用户信息
      continue;



    AllUserInfo.push_back(Temp);                         //全部保存到vector中  
    cout<<"?";              
   }
  Read.close();

  //重新写到文件
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