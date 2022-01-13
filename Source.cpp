
//STAFF REGISTRATION AND SALARY CHECK FOR ALPHA MALE KINDERGARTEN
#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<string>
using namespace std;
void login(); //function prototype for login
void registr(); // function prototype for registration
void payment1(string user); // function with argument of a user with type string
string user; 



int main()
{
    int choice;
    cout << "///////////////////////////////////////////////////////////////////////\n\n\n";
    cout << "                      ALPHA MALE Staff Portal                           \n\n";
    cout << "/////////////////////        MENU        /////////////////////////////\n\n";
    cout << "1.LOGIN" << endl;
    cout << "2.REGISTER" << endl;
    cout << "3.Exit" << endl; /// main menu display
    cout << "\nEnter your choice :";
    cin >> choice;
    cout << endl;
    switch (choice)//switch statement for choice entered by user
    {
    case 1:
        login();
         break;
    case 2:
        registr();
        break;
    
    case 3:

        cout << "Hope to see you again\n\n";
        break;

    default:
        system("cls");
        cout << "Please ,Try again..\n" << endl; // error message when a bad choice is added
        main();
    }

}

void login() // function header of login type void
{
    int count = 0;//true
    string user, pass, u, p;
    
    cout << "Please enter your username and password" << endl;
    cout << "USERNAME :";
    cin >> user;
    cout << "PASSWORD :";
    cin >> pass;

    ifstream input("database.txt"); // searches on file "database.txt" 
    while (input >> u >> p)
    {
        if (u == user && p == pass) 

        {   
            
            count = 1;//true
            
            system("cls"); //system closes the terminal 
          
        }
    }
    
    
        if (count == 1)//login successful note
        {
           
            int opt;
            cout << "\nHi " << "#" << user << "\n<<LOGIN SUCCESSFUL>>" << endl;
            cout << "1. Check payment \n2. Exit to main menu" << endl;
            cout << "Choice : ";
            cin >> opt;
            if (opt == 1)
            {
                payment1(user);

            }

            else if (opt == 2)
            {
                main();
            }
            else
            {
                cout << "Try again !" << endl;
                login();
            }
        }


        else //retry menu if password or username is wrong 
        {
            
            
            int option;
            cout << "\nLOGIN ERROR\nPlease check your username and password" << endl << endl;
            cout << "Do you want to try again or proceed to main menu ?" << endl;
            cout << " 1 . Main menu \n 2 . Login Page \n Option : ";
            cin >> option;
            system("cls");
            if (option == 1)
            {
                main();
            }
            else if (option == 2)
            {
                login();
            }

            else
            {
                system("PAUSE");
            }
        }
    
    
}

void registr() // function header 
{
    string name, ic, ru, rp, phone, address, email;
    char gender;
    string reguser, regpass;
    int age;
    int maxIC=12;
    int maxPh = 11;
       
            system("cls");
            cout << "Enter your Name as Per IC :" << endl;
            getline(cin.ignore(100, '\n'), name);           
            cout << "\nEnter your Identification Card Number :" << endl;
            cin >> ic;
            
                while (ic.size() > maxIC || ic.size()< maxIC)
                {
                    //validates the ic number entered
                    cout << "Incorrect Idetification Card Number." << endl;
                    cout << "Enter your Identification Card Number :" << endl;
                    cin >> ic;

                }
            
            cout << "Please enter your age :" << endl;
            cin >> age;
            if(age < 20 || age > 58)
            {
                cout << "SORRY ! You are not eligible for this staff recruitment !" << endl;
                main();
            }
            
               do // does the function as long M m F f is entered
                {
                    cout << "\nEnter Your Gender (m/f) :";
                    cin >> gender;
                    if (gender == 'm' || gender == 'M')
                    {
                        cout << "Male" << endl;
                    }
                    else if (gender == 'f' || gender == 'F')
                    {
                        cout << "Female" << endl;
                    }

                } while (!(gender == 'm' || gender == 'M' || gender == 'f' || gender == 'F'));
                //executes do while 'while' statements is true


                cout << "\nEnter your phone number :" << endl;
                cin >> phone;
                while (phone.size() > maxPh || phone.size()<10)//validates the size of phone number 
                {
                    
                    cout << "Incorrect Phone Number!" << endl;
                    cout << "Enter your Phone Number :" << endl;
                    cin >> phone;

                }
                cout << "\nEnter your address :" << endl;
                getline(cin.ignore(1, '\n'), address); // get address with spaces as well
                cout << "\nEnter your email address :" << endl;
                cin >> email;

                ofstream read("details.txt", ios::app); //outputs the given details in "details.txt" with append mode
                read << "NAME\t\t\t   :" << name << endl << "IDENTIFICATION CARD NUMBER :" << ic << endl << "AGE\t\t\t   :" << age << endl << "GENDER\t\t\t   :" << gender << endl << "PHONE NUMBER\t\t   :" << phone << endl << "ADDRESS\t\t\t   :" << address << endl << "EMAIL ID\t\t   :" << email << endl << endl;

                cout << "Please create a account for further uses " << endl;
                string usern;
                cout << "Username :";
                cin >> reguser; "\n";
                cout << "Password :";
                cin >> regpass;

                // output user and passwords registered into "database.txt" with mode append mode
                ofstream reg("database.txt", ios::app);
                reg << reguser << ' ' << regpass << endl;//formats the user and password with a space
                system("cls");
                cout << "\nRegistration Sucessful\n";
                cout << "You may now login" << endl;
            
            main();
        
 }


void payment1(string user)//uses argument as user from login
{
    //array to make a comparison on days worked 
    int days_per_month[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    int month;
    int days, total;
    int day_pay = 10 * 8;
    cout << "Month number [enter a number] :";
    cin >> month;
    while (month > 12 || month <= 0)//disallows user to input month less than equal 0 and more than 12
    {
        cout << "Please enter a valid month number " << endl;
        cout << "Month number [enter a number] :";
        cin >> month;
    }
   
    cout << "How many days did you work in month "<<month<<" " << user << " :";
    cin >> days;
    
    //days of work are also limited as not above 29 days selected and less than equal 0 days arent allowed
    while (days <= 0 || days >= 29) 
    {
        cout << "Please enter a valid value" << endl;
        cout << "To retry please press enter " << endl;
        cout << "How many days did you work in month " << month << " " << user << " :";
        cin >> days;
        

    }
    
        //moduled to show days comparison x/y (12 out of 31 days) according to the days in a month
        if (month != days_per_month[month - 1])
        {
            cout << "\nYou worked " << days << " out of " << days_per_month[month - 1] << " days in month " << month;


            
            // calculation of salary
            total = days * day_pay;
            
            cout << "\n" << "Your salary for month " << month << " is RM " << total << endl;

            cout << "Returning to main menu ..... ";
            system("PAUSE");
            main(); // return to main function
        }
    
   
}


