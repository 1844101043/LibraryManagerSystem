#include"PublicFunction.h"
const string BookInfo_ShowTHeInfo_ShowInfo="书名\t\tISBN\t\t作者\t\t出版社\t\t图书类别\t\t出版年份\t\t藏书地点\t\t价格";

Book::Book()
{
		BookName="NotExist";
		ISBN="NotExist";
	    Type="NotExist";         //图书类别
		Press="NotExist";        //出版社 
		Place="NotExist";        //藏书地点 
		Author="NotExist";       //作者
		Publish_Year=0;          //出版年份  
		Price=0;
	    Borrow_Number=0;   //借出数量 
	    Stocks=0;          //库存量 
	    Borrow_Times=0;    //借阅次数 
	    Borrow_Limit=0;    //书籍借阅权限，学生可借true；否则false
	
}

Book::~Book()
{}


void Book::GetInfo()
{

	cout<<"请输入书名:";cin>>BookName;
	cout<<"请输入ISBN:";cin>>ISBN;

	cout<<"请输入图书类别:";cin>>Type;

	cout<<"请输入出版社:";cin>>Press;

	cout<<"请输入作者:";cin>>Author;

	cout<<"请输入出版年份:";cin>>Publish_Year;

	cout<<"请输入价格:";cin>>Price;

	cout<<"请输入库存量:";cin>>Stocks;
	cout<<"请输入藏书区:";cin>>Place;

	cout<<"请输入借阅限制(输入0代表不能外借):";cin>>Borrow_Limit;

}

//constructive function
BookInfo::BookInfo()
{
		BookName="NotExist";
		ISBN="NotExist";
	    Type="NotExist";         //图书类别
		Press="NotExist";        //出版社 
		Place="NotExist";        //藏书地点 
		Author="NotExist";       //作者
		Publish_Year=0;          //出版年份  
		Price=0;  
		BorrowReturnTime.Year=0; //归还日期 
		BorrowReturnTime.Month=0;
		BorrowReturnTime.Day=0;
		BorrowTime.Year=0;       //借阅日期
		BorrowTime.Month=0;
		BorrowTime.Day=0;
}

BookInfo::~BookInfo()
{}


void BookInfo::ShowTheInfo()
{
    //调用WindowsAPI,获取本地时间，与借阅日期归还日期作比较
    SYSTEMTIME sys;
	GetLocalTime(&sys);
	int Year_Diff=sys.wYear-BorrowReturnTime.Year;
	int Month_Diff=sys.wMonth-BorrowReturnTime.Month;
	int Day_Diff=sys.wDay-BorrowReturnTime.Day;

	//输出所借图书所有信息
	cout<<BookInfo_ShowTHeInfo_ShowInfo<<endl;
	cout<<BookName;
	cout<<setw(16)<<ISBN;
	cout<<setw(16)<<Author;
    cout<< setw(16) << setw(16)<<Press;
	cout<< setw(16) << Type;
	cout<< setw(20) << Publish_Year;
	cout<< setw(28) << Place;
	cout<< setw(18) << Price;
	cout<<endl;

   
    if(Year_Diff>0||Month_Diff>0||Day_Diff>0)
    {
    	cout<<"你已经超过应还日期，请尽快还书或者续借！"<<endl;
    }

}
