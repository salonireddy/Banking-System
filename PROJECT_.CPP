#include<iostream>
#include<conio.h>
#include<iomanip>
#include<stdio.h>
#include<process.h>
#include<string.h>

using namespace std;

int accno=100;
long int balance= 1000000;
struct address{ 
  int houseno;
  char area[50],city[26],state[26];
  void addr(){
   cout<<"enter house no.";
   cin>>houseno;
   cout<<"enter area";
   gets(area);
   cout<<"enter city";
   gets(city);
   cout<<"enter state";
   gets(state);
  }
};
struct bank{ 
  int ac;
  long int amount;
  int ch;
  char name[26];
  long int ph;
  address add;
  void create(){ 
    cout<<endl<<"enter name";
    gets(name);
    cout<<endl<<"enter address";
    add.addr();
    cout<<endl<<"enter phone number(10 digits)";
    cin>>ph;
    cout<<endl<<"account successfully created"<<endl<<"your account number is"<<accno;
    accno=accno+1;
  }
  void deposit(){ 
    cout<<endl<<"enter account number";
	  cin>>ac;
    cout<<endl<<"enter amount to be deposited";
    cin>>amount;
    balance=balance+amount;
    cout<<endl<<"you have successfully deposited Rs."<<amount<<"into your account";
    cout<<endl<<"your balance"<<balance;

  }
  void withdraw(){ 
    cout<<endl<<"enter account number";
    cin>>ac;
    cout<<endl<<"enter amount to be withdrawn";
    cin>>amount;
    if(amount>balance){
       cout<<endl<<"you can not withdraw Rs,"<<amount<<" as you are short of Rs."<<amount-balance;
    }
    else{ 
      if(amount>20000)
      cout<<endl<<"amount exceeds the daily limits";
      else{ 
       balance=balance-amount;
       cout<<endl<<"you have successfully withdrawedRs."<<amount<<endl<<"your account balace is"<<balance;
      }
     }
  }
  void modify(){
   cout<<endl<<"enter account number";
   cin>>ac;
   cout<<endl<<"what do you want to mofify?";
   cout<<endl<<"1.Address"<<endl<<"2. Phone number";
   cin>>ch;
   switch(ch){ 
     case 1: add.addr();
	    break;
     case 2:
	    break;
     default: cout<<"wrong choice" ;
   }
  }
  void del(){ 
    cout<<endl<<"enter account number";
    cin>>ac;
    balance=0;
    cout<<endl<<"your account is successfully deleted";

  }
  void chkbalance(){ 
    cout<<endl<<"enter account number";
    cin>>ac;
    cout<<endl<<"your account balance is"<<balance;
  }

};
void main(){ 
  system("clr");
  int choice;
  bank obj;
  cout<<endl<<"			WELCOME TO ABC BANK"<<endl;
  cout<<endl<<"1.Add account"<<endl<<"2.Deposit"
	    <<endl<<"3.Withdrawal"<<endl<<"4.Modify account"<<endl
	    <<"5.Delete account"<<endl<<"6.Balance enquiry"<<endl<<"7.Exit";
   again:
  cout<<endl<<"	 Enter choice(1-7)"<<endl<<"choice-";
  cin>>choice;
  switch(choice)
  { case 1:{ obj.create();

	    goto again;
	    break;
	    }
    case 2:{ obj.deposit();
	      goto again;
	    break;
	    }
    case 3:{ obj.withdraw();
	     goto again;
	    break;
	    }
    case 4:{ obj.modify();
	      goto again;
	       break;
	     }
    case 5:{ obj.del();
	     goto again;
	    break;
	    }
    case 6:{ obj.chkbalance();
	    goto again;
	    break;
	    }
    case 7:{ exit(0);
	    break;
	    }
    default: cout<<"wrong choice";
  }
 getch();
}