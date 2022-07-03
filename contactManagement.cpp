#include<bits/stdc++.h>
using namespace std;

void addContact();
void contactList();
void searchContact();
void editContact();
void deleteContact();
bool is_Digit(string s);
bool is_Number(string s);
string fn,ln,pn,em;
int main()
{
	system("color A");
	int c=0;
	do
	{
		cout<<"1.Add a new contact.\n2.List of all contacts.\n3.Search for a contact.\n4.Edit a contact.\n5.Delete a contact.\n6.Exit."<<endl<<endl;
		cout<<"Enter your choice:";
		cin>>c;
		switch(c)
		{
			case 1:
				addContact();
				break;
			case 2:
				contactList();
				break;
			case 3:
				searchContact();
				break;
			case 4:
				editContact();
				break;
			case 5:
				deleteContact();
				break;
			default:
				cout<<"Thank You!"<<endl;
		}
	}while(c!=6);
	return 0;
}
void addContact()
{
	ofstream write("contact.txt",ios::app);
	cout<<"Enter first name:";
	cin>>fn;
	cout<<"Enter last name:";
	cin>>ln;
	cout<<"Enter mail id:";
	cin>>em;
	cout<<"Enter a valid 10-digit phone number:";
	cin>>pn;
	if(is_Digit(pn))
	{
		if(is_Number(pn))
		{
			if(write.is_open())
			{
				write<<fn<<" "<<ln<<" "<<em<<" "<<pn<<endl;
				cout<<"Congrats! Phone Number Saved Successfully."<<endl<<endl;
				write.close();
			}
			else
			{
				cout<<"File opening error."<<endl;
			}
		}
		else
		{
			cout<<"Invalid Phone Number."<<endl<<endl;
		}
	}
	else
	{
		cout<<"Invalid Phone Number."<<endl<<endl;
	}
}
bool is_Digit(string s)
{
	if(s.length()==10)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool is_Number(string s)
{
	bool temp=true;
	for(int i=0;i<s.length();i++)
	{
		if(!(int(s[i])>=48 && int(s[i])<=57))
		{
			temp=false;
		}
	}
	return temp;
}
void contactList()
{
	ifstream read("contact.txt");
	system("cls");
	while(read>>fn>>ln>>em>>pn)
	{
		cout<<"First name:"<<fn<<endl;
		cout<<"Last name:"<<ln<<endl;
		cout<<"Email id:"<<em<<endl;
		cout<<"Phone number:"<<pn<<endl;
		cout<<"________________________________"<<endl;
		cout<<endl;
	}
	read.close();
}
void editContact()
{
	string f,l,m,p,ph;
	int count=0;
	bool check=false;
	cout<<"Enter your detailed info for updation of phone number."<<endl;
	cout<<"First name:";
	cin>>f;
	cout<<"Last name:";
	cin>>l;
	cout<<"Email id:";
	cin>>m;
	ifstream read("contact.txt");
	system("cls");
	ofstream write("temp.txt",ios::app);
	while(read>>fn>>ln>>em>>pn)
	{
		if(fn==f && ln==l && em==m)
		{
			cout<<"Enter new phone number:";
			cin>>ph;
			pn=ph;
			check=true;
		}
		write<<fn<<" "<<ln<<" "<<em<<" "<<pn<<endl;
	}
	read.close();
	write.close();
	remove("contact.txt");
	rename("temp.txt","contact.txt");
	if(check)
	{
		cout<<"Great! phone number is updated successfully!"<<endl<<endl;
	}
	else
	{
		cout<<"No such contact exit."<<endl<<endl;
	}
}
void deleteContact()
{
	bool exist=false;
	string ph;
	ifstream read("contact.txt");
	system("cls");
	cout<<"Enter phone number you want to delete:";
	cin>>ph;
	while(read>>fn>>ln>>em>>pn)
	{
		if(ph==pn)
		{
			exist=true;
			break;
		}
	}
	read.close();
	if(exist)
	{   
	    ofstream write("temp.txt",ios::app);
		while(read>>fn>>ln>>em>>pn)
		{
		    if(ph!=pn)
			{
			    write<<fn<<" "<<ln<<" "<<em<<" "<<pn<<endl;
			}
		}
		write.close();
		read.close();
		remove("contact.txt");
		rename("temp.txt","contact.txt");
		cout<<"Great! phone number is deleted successfull!"<<endl<<endl;
	}
	else
	{
		cout<<"Sorry! phone number doesn't match."<<endl<<endl;
	}
}
void searchContact()
{
	string key;
	bool t=false;
	system("cls");
	cout<<"Enter keyword to find account deatils:";
	cin>>key;
	ifstream read("contact.txt");
	while(read>>fn>>ln>>em>>pn)
	{
		if(key==fn || key==ln || key==em || key==pn)
		{
			if(!t)
			{
			    cout<<"Account found! Account details are as follow: "<<endl;
		    }
			cout<<"First name:"<<fn<<endl;
			cout<<"Last name:"<<ln<<endl;
			cout<<"Email id:"<<em<<endl;
			cout<<"Phone number:"<<pn<<endl;
			cout<<"_________________________________"<<endl;
			t=true;
		}
	}
	read.close();
	if(!t)
	{
		cout<<"Sorry! Wrong keyword entered."<<endl<<endl;
	}
}
