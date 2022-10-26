#include <iostream>
#include <string>
#include <fstream>

using std::cout;
using std::cin;
using std:: endl;

void login();
void regstr();
void forgot();

int main()
{
    int choice;
    MENU:
    cout<<"1.Login\n2.Register\n3.Forgot password\nAny key to exit"<<endl;
    cin>>choice;
    switch (choice)
    {
    case 1:
        login();
        goto MENU;
    case 2:
        regstr();
        goto MENU;
    case 3:
        forgot();
        goto MENU;
    default:
        break;
    }
}

void login()
{
    bool state=false;
	std::string usr,pas,u,p; // u, p are used for checking username and password
	cout<<"Username: ";
	cin>>usr;
	cout<<"Password: ";
	cin>>pas;
	std::ifstream read("account.txt");
	while(read>>u>>p)
	{
		if(u==usr && p==pas)
		{
			state=true;
			break;
		}
	}
	read.close();
	if(state)
	{
		cout<<"Successful"<<endl;
	}
	else
	{
		cout<<"Failed"<<endl;
	}
}

void regstr()
{
    bool state=false;
	std::string usr,pas,u,p;
	system("cls");
	cout<<"Register\nCreate username:";
	cin>>usr;
	std::ifstream read("account.txt");
	while(read>>u)
	{
		if(u==usr)
		{
			state=true;
			break;
		}
	}
	if(state)
	{
		cout<<"Username is already taken."<<endl;
	}
	else
	{
		cout<<"Create password:";
		cin>>pas;
	    std::ofstream write("account.txt",std::ios::app);
		write<<usr<<" "<<pas<<endl;
		cout<<"Successful"<<endl;
	    write.close();
	}
    read.close();
}

void forgot()
{
	system("cls");
    bool state=false;
    std::string usr,u,p;
    cout<<"Username:";
	cin>>usr;
	std::ifstream read("account.txt");
    while(read>>u>>p)
    {
        if(u==usr)
        {
            state=true;
            break;
        }
    }
    read.close();
    if(state)
    {
        cout<<"Your password: "<<p<<endl;
    }
    else
    {
        cout<<"Account not found"<<endl;
    }
}
