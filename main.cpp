#include<fstream.h>
#include<ctype.h>
#include<conio.h>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>

class Consumer
{
  int net;
  double cardno, phno;
  char name[30], address[50] , mail[80] , gendr;

  void Card()
  {
    randomize();
    cardno= (phno * 100000000000000) + random(100000);
  }


 public:

  double retcardno()
  {
    return cardno; 
  }
  char* name()
  {
    return name;
  }


  void Input()
  {
    cout<<" Welcome to FYB ";

    cout<<"\n Enter Name: ";
    gets(name);

    cout<<"\n Enter Gender (M-Male | F-Female | O-Other) : ";
    gend=getche();

    cout<<"\n Residential Address (50 characters) : ";
    gets(address);

    cout<<"\n Enter email id: ";
    gets(mail);

    cout<<"\n Enter phone number: ";
    gets(phno);

    cout<<" Enter Email ID: ";
    gets(mail);

    cout<<"\n Amount to be credited :  ";
    cin>>net;


    Card();
  }
 void Display()
  {
    cout<<"\n Name: "<<name;
    cout<<"\n Gender (M-Male | F-Female | O-Other) : "<<gend;
    cout<<"\n Residential Address (50 characters) : "<< address;
    cout<<"\n Email id: "<<mail;
    cout<<"\n Phone number: "<<phno;    
    cout<<"\n Email ID: "<<mail;    
    cout<<"\n Balance :  "<<net;
};





void create()
{
  Consumer A;
  fstream f1;
  f1.open("A.dat",ios::binary|ios::out);
  char ch;
  do{
     clrscr();
     cout<<"\nEnter the Details:\n";
     A.Input();
     f1.write((char*)&A,sizeof(A));
     cout<<"\n\nAdd another applicant? (Y/N)\n>>> ";
     cin>>ch;
  }while(ch=='y'||ch=='Y');
  f1.close();
}

void newa()
{
  Applicant A;
  fstream f1;
  f1.open("A.dat",ios::binary|ios::app);

  cout<<"\nEnter the Details:\n";
  A.Input();
  f1.write((char*)&A,sizeof(A));

  f1.close();
  clrscr();
  cout<<"\nRecord added!";
  getch();
}

void addc()
{
  Consumer A1,A2;
  fstream f1,f2;

  f1.open("A.dat",ios::binary|ios::in);
  f2.open("temp.dat",ios::binary|ios::out);



  cout<<"\n Enter card number : ";
  double s;
  cin>>s;
  clrscr();
  cout<<"\nEnter amount to be credited : ";
  int amt;
  cin>>amt;
  clrscr();

  while(f1.read((char*)&A1,sizeof(A1)))
  {
    if(A1.retcardno()==s)
    {
     C=A1;
     C.net= C.net + amt ;
     f2.write((char*)&C,sizeof(C));
    }
 
  f1.close();
  f2.close();

  cout<<"\nRecords updated!";
  getch();
}

void search()
{
  Consumer A;
  fstream f1;

  f1.open("A.dat",ios::binary|ios::in);
  cout<<"\n Enter enrollment number of the account to be searched: ";
  int s;
  cin>>s;
  clrscr();
  int f=0;


  while(f1.read((char*)&A1,sizeof(A1)))
  {
    if(A1.retcardeno()==s)
    {
      A1.Display();
      getch();
      f=1;
     }
   }
  if(f==0)
  {
    cout<<"\nApplicant not found!";
    getch();
  }

  f1.close();
}
void buy()
{
cout<<"\n Choose restaurant
              \n1.Joe’s Pizzeria
             \n2.Sushi Temple
             \n3.Fine Dining Barbeque
                  ”;
int choix1, choix2;
cin>>choix1;
 
  switch(choix1)
     {
       case 1: cout<<"\n1.Margherita
                                 \n2.Pepperoni
                                 \n3.Veggie Forrest
                                 \n4.Panner Zest”;
                   cin>>choix2;
	       break;
       case 2:  cout<<"\n1.Raw Tuna
                                  \n2.Lion Fish special
                                 \n3.Pufferfish
                                 \n4.Moshi”;
                     cin>>choix2;  
	       break;

       case 3: cout<<"\n1.Lemon cottage cheese
                                 \n2.Pineapple Marinate
                                 \n3.Baby potato
                                 \n4.Spiced Cop
                   cin>>choix2;

	      break;
       default: cout<<"\nInvalid option!";
		getch();
     }

  int cost ho= 400*choix2;
  fstream f1;
  Consumer Ci,Cf;
  f1.open("A.dat",ios::binary|ios::in);
  while(f1.read((char*)&A1,sizeof(A1)))
  {
    if(Ci.retcardno()==s)
    {
     Cf=Cf;
     if( C.net -  cost > 0 )
    {
      C.net= C.net -  cost ;
    }
    else
    {
      cout<<"Not enough credits";
      break;
     }
     f2.write((char*)&Cf, sizeof(Cf));
    }
 
  f1.close();
  f2.close();

  cout<<"\nRecords updated!";
  getch();
}


void main()
{
  char ch;
  int op;


 do{
     clrscr();
     cout<<"\nMENU:\n
                  \n1. Create New Record File
                  \n2. Add New Consumer
                  \n3. Add Credits
                  \n4. Make Purchase 
                  \n5. Find account
                  \n Enter Choice: ";
     cin>>op;
     cout<<endl;
     clrscr();

     switch(op)
     {
       case 1: create();
	       break;
       case 2: newa();
	       break;
       case 3: addc();
	       break;
       case 4: buy();
	       break;
       case 5: search();
	       break;
       default: cout<<"\nInvalid option!";
		getch();
     }
     clrscr();
     cout<<"\nDo you want to continue? (Y/N)\n>> ";
     cin>>ch;
  }while(ch=='y'||ch=='Y');


  clrscr();
  cout<<"\nHave a good one !";
  getch();
}
