#ifndef  _PUBLIC_H_
#define  _PUBLIC_H_

#include"Class.h"
using namespace std;



void ChangePassword(UserInfo& obj);              //修改密码 
bool GetUserInfo(UserInfo& obj,int GetType);     //获取用户信息，判断用户是否存在，或者密码是否正确
string InputPassword();                          //输入密码
string InputUserName();                          //输入用户名

#endif