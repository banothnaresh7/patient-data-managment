#include<iostream>
#include<stdlib.h>
#include<fstream>
#include<string.h>
#include<time.h>


// function declaration
void registration();
void login();
void update();
void appointment();
void view_details();
void new_visit();

 using namespace std;

 string use;
 string pass;

 int main(){
     system("title patient managment");
     system("color 1F");
     system("CLS");
     int a;
     cout<<"1: For login\n";
     cout<<"2: For registration\n";
     cin>>a;
     switch(a)
     {
     case 1:
        {
            login();
            break;
        }
     case 2:
        {
            registration();
            return 0;
            break;
        }
     }
     cout<<"THANKS FOR VISITING!!!...\n";
     cout<<"STAY HEALTHLY AND HAPPY............\n";
     cout<<endl<<endl;

      return 0;
 }


 void registration()                                          //creating a account for the patience
 {

     string username,pswd,repswd;
     ofstream regi("patient.txt",ios::app);                         // creating file obj as regi
     cout<<"enter the mail address\n";
     cin>>username;
     cout<<"enter the high secured password\n";
     cin>>pswd;
     cout<<"re_enter you password\n";
     cin>>repswd;
     if(pswd==repswd)
     {
         regi<<username<<' '<<pswd<<endl;                    // writing in the file
     }
     else
     {

         cout<<" password mismatches\n";
         registration();
     }

     string name,fathername,disease,date,address;
     string age;
     cout<<"enter your name:\n";
     cin>>name;
     cout<<"enter your age:\n";
     cin>>age;
     cout<<"enter your father or mother name:\n";
     cin>>fathername;
     cout<<"describe about your disease:\n";
     cin>>disease;
     cout<<"enter your address:\n";
     cin>>address;
     cout<<"enter your date of visit:\n";
     cin>>date;

     int a;
     cout<<"1:for updates details\n";
     cout<<"2:for Quit\n";
     cin>>a;
     system("CLS");
     switch(a)
     {

     case 1:
        {
            cout<<"1: To correct your name:\n";
            cout<<"2: To correct your age:\n";
            cout<<"3: To correct your father or mother name:\n";
            cout<<"4: To correct about your disease:\n";
            cout<<"5: To correct  your address:\n";
            cout<<"6: To correct  your date of visit:\n";
            int b;
            cin>>b;
            switch(b)
            {
            case 1:
                {
                    cout<<"enter your name:\n";
                    cin>>name;
                    break;
                }
                case 2:
                {
                    cout<<"enter your age:\n";
                    cin>>age;
                    break;
                }
                case 3:
                {
                    cout<<"enter your father or mother name:\n";
                    cin>>fathername;
                    break;
                }
                case 4:
                {
                    cout<<"describe about your disease:\n";
                    cin>>disease;
                    break;
                }
                case 5:
                {
                    cout<<"enter your address:\n";
                    cin>>address;
                    break;
                }
                 case 6:
                {
                    cout<<"enter your visiting date:\n";
                    cin>>date;
                    break;
                }
            }

          break;
        }

            case 2:
                {

                    exit(0);
                    break;
                }
     }
     regi<<name<<' '<<age<<' '<<fathername<<' '<<disease<<"                              "<<date<<"                              "<<address<<endl;
     regi.close();
     cout<<"you have successfully registered\n";
     system("pause");
     main();
     return;
 }

 void login()
{
    string id,pswd,user,password;
    cout<<"enter the  email id:\n";
    cin>>id;
    cout<<"enter the  password:\n";
    cin>>pswd;
    fstream file("patient.txt",ios::in|ios::out|ios::binary);
    while(file>>user>>password)
    {

        if(user==id && password==pswd)
        {
            int a;
            ::use=id;
            ::pass=pswd;
            cout<<"1:get an appointment\n";
            cout<<"2:enter the details of a new visit\n";
            cout<<"3:just view you your details\n";

            cin>>a;
            switch(a)
            {

               case 1:
                {

                    appointment();
                    cout<<endl<<endl;
                    break;
                }
               case 2:
                {
                   new_visit();
                   cout<<endl<<endl;

                        break;

                }
               case 3:
                {
                view_details();

                 cout<<endl<<endl;
                 break;
                }
            }
        }
         if(file==0)
       {

         cout<<"check you ID and password\n";
         system("pause");
         main();
       }
    }
    file.close();
}

void appointment()
 {
                               //time()  return the calender time in sec since jan 1,1970
 time_t now=time(0);          //time_t represent time and date as sort of int
 tm *l=localtime(&now);       // localtime() return local time as pointer
 int a=l->tm_mday;           // l->tm->mday days of month from 1 t0 31
 srand(time(NULL));
 int b=(rand())%10;
 int c ,d;
 if(a+b>31)
 {
      c=2+(l->tm_mon);
      d=(a+b)-31;

 }
  else
    {
    c=1+(l->tm_mon);
    d=a+b;
    }
  cout<<"you appointment date is : "<<d<<"-"<<c<<"-"<<1900+l->tm_year<<endl;
                string name,fathername,disease,date;
                 string age,user,password;
                 char hy='-',co=',';
                 int e=1900+l->tm_year;
                 fstream files("patient.txt",ios::in|ios::out|ios::binary);
                 while(files>>user>>password)
                 {
                  if(user==::use && password==::pass)
                 {
                 files>>name>>age>>fathername>>disease>>date;
                 files<<co<<d<<hy<<d<<c<<hy<<e;
                 }
                 }
   return;
}

void view_details()
{
                 string name,fathername,disease,date,address;
                 string age,user,password;
                 fstream files("patient.txt",ios::in|ios::out|ios::binary);
                 while(files>>user>>password)
                 {
                  if(user==::use && password==::pass)
                 {
                 files>>name>>age>>fathername>>disease>>date>>address;
                 cout<<"name: "<<name<<endl;
                 cout<<"age: "<<age<<endl;
                 cout<<"father_name: "<<fathername<<endl;
                 cout<<"last disease: "<<disease<<endl;
                 cout<<"last visiting dates: "<<date<<endl;
                 cout<<"address: "<<address<<endl;
                 }
              }
              files.close();
                 return;

}

void new_visit()
{
                 string dates,diseases;
                 string user,password;
                 fstream filee("patient.txt",ios::in|ios::out|ios::binary);
                 while(filee>>user>>password)
                 {
                  if(user==::use && password==::pass)
                  {

                    cout<<"describe about your disease:\n";
                    cin>>diseases;
                    cout<<"enter the visiting date:\n";
                    cin>>dates;
                    string name,fathername,disease,date,address;
                    string age;
                    char c=',';
                filee>>name>>age>>fathername>>disease;
                filee<<c<<diseases;
                filee>>date;
                if(dates!=date)
                {
                filee<<c<<dates;
                }
                cout<<"your date is confirmed\n";
             }
           }
           filee.close();
}








