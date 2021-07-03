#include<iostream>
#include<conio.h>
#include<cstdlib>
#include<cstring>
#include<cstdio>
#include<windows.h>
#include<unistd.h>
using namespace std;

class product
{
    private:
        char name[30];
        char code[5];
        char c1[20];
        char c2[20];
        char c3[20];
        char c4[20];
        void waitForEnter(void)
        {
            cout<<"\n\n\n Press enter to go back \n\n";
            cin.get();
            cin.get();
        }
        void list_product(void)
        {
            system("cls");
            FILE *file;
            file= fopen("data.txt", "r");
            cout<<"\n\t      List of Product\n";
            cout<<"\n--------------------------------------------------------------------------------";
            cout<<"\n PRODUCT NAME         |     PRODUCT CODE     |           COMPOSITION\n";
            cout<<"------------------------------------------------------------------------------------";
            while(fscanf(file, "%s %s %s %s %s %s", &name[0], &code[0] , &c1[0], &c2[0], &c3[0], &c4[0])!= EOF)
                cout<<"\n"<<name<<"\t\t\t\t"<<code<<"\t\t\t"<<c1<<", "<<c2<<", "<<c3<<", "<<c4;

            fclose(file);
            waitForEnter();
        }

        void showDetails(void)
        {
            system("cls");
            FILE *file;
            char checkId[5];
            cout<<"\n\nEnter Product : ";
            cin>>checkId;
            file= fopen("data.txt", "r");
            while(fscanf(file, "%s %s %s %s %s %s", &name[0], &code[0] , &c1[0], &c2[0], &c3[0], &c4[0])!=EOF)
                if(strcmp(checkId,code)==0){
                	cout<<"\n---------------------";
                    cout<<"\nProduct Name: "<<name;
                    cout<<"\n---------------------";
                    cout<<"\nProduct Code: "<<code;
                    cout<<"\n---------------------";
                    cout<<"\ncomposition no1: "<<c1;
                    cout<<"\n---------------------";
                    cout<<"\ncomposition no2: "<<c2;
                    cout<<"\n---------------------";
                    cout<<"\ncomposition no3: "<<c3;
                    cout<<"\n---------------------";
                    cout<<"\ncomposition no4: "<<c4;
                    cout<<"\n---------------------";
                }
            fclose(file);
            waitForEnter();
        }

        void editExisting(void)
        {
            system("cls");
            char checkId[5];
            cout<<"\nEnter Product Code: ";
            cin>>checkId;
            char new_c1[20],new_c2[20],new_c3[20],new_c4[20];
            cout<<"\n-----------------------------";
            cout<<"\nEnter new composition no1: ";
            cin>>new_c1;

            cout<<"\n-----------------------------";
            cout<<"\nEnter new composition no2: ";
            cin>>new_c2;

            cout<<"------------------------------";
            cout<<"\nEnter new composition no3: ";
            cin>>new_c3;
            cout<<"\n-----------------------------";
            cout<<"\nEnter new composition no4: ";
            cin>>new_c4;
            FILE *file, *tempfile;
            file= fopen("data.txt", "r");
            tempfile= fopen("temp.txt", "w");
            while(fscanf(file, "%s %s %s %s %s %s", &name[0], &code[0] , &c1[0], &c2[0], &c3[0], &c4[0])!=EOF)
            {
                if(strcmp(checkId, code)==0)
                    {
                        fprintf(tempfile, "%s %s %s %s %s %s \n", name, code, new_c1, new_c2, new_c3, new_c4 );
                        cout<<"Modify Record.....";
                    }
                else
                    fprintf(tempfile, "%s %s %s %s %s %s \n", name, code, c1, c2, c3, c4 );
            }
            fclose(file);
            fclose(tempfile);
            remove("data.txt");
            rename("temp.txt", "data.txt");
            waitForEnter();
        }

        void addNew_product(void)
        {
            system("cls");
            cout<<"\n----------------------------------------";
            cout<<"\n Enter Name of Product: ";
            cin>>name;
            cout<<"\n----------------------------------------";
            cout<<"\n Enter Product Code [max 4 digits]: ";
            cin>>code;
            cout<<"\n----------------------------------------";
            cout<<"\n Enter composition no1: ";
            cin>>c1;
            cout<<"\n----------------------------------------";
            cout<<"\n Enter composition no2: ";
            cin>>c2;
            cout<<"\n----------------------------------------";
            cout<<"\n Enter composition no3: ";
            cin>>c3;
            cout<<"\n----------------------------------------";
            cout<<"\n Enter composition no4: ";
            cin>>c4;
            cout<<"\n----------------------------------------";

            char ch;
            cout<<"\nEnter 'y' to save above information\n";
            cin>>ch;
            if(ch=='y')
            {
                FILE  *file;
                file= fopen("data.txt","a");
                fprintf(file, "%s %s %s %s %s %s \n", name, code, c1, c2, c3, c4 );
                fclose(file);
                cout<<"\nNew Product has been added to database\n";
            }
            else
                addNew_product();
            waitForEnter();
        }

        void delete_product_Details(void)
        {
            system("cls");
            char checkId[5];
            cout<<"\n----------------------------------";
            cout<<"\nEnter Product ID To Remove: ";
            cin>>checkId;
            char ch;
            cout<<"----------------------------------";
            cout<<"\n\n\n\n\nCONFIRMATION\nEnter 'y' To Confirm Deletion \n";
            cin>>ch;
            if(ch=='y')
            {
                FILE *file, *tempfile;
                file= fopen("data.txt", "r");
                tempfile= fopen("temp.txt", "w");
                while(fscanf(file, "%s %s %s %s %s %s", &name[0], &code[0] , &c1[0], &c2[0], &c3[0], &c4[0])!=EOF)
                    if(strcmp(checkId, code)!=0)
                        fprintf(tempfile, "%s %s %s %s %s %s \n", name, code, c1, c2, c3, c4 );
                fclose(file);
                fclose(tempfile);
                int isRemoved= remove("data.txt");
                int isRenamed= rename("temp.txt", "data.txt");
                cout<<"\nRemoved Successfully\n";
                waitForEnter();
            }
            else
                delete_product_Details();
        }


    public:
        void options(void)
        {
        int login();
                login();
            while(true)
            {
                system("cls");
                cout<<"\n\t\t\t>>>>>>>>>  Product Chemical Composition Information  <<<<<<<<<";
                cout<<"\n";
                cout<<"\n\t\t\t------------------------------------------------";
                cout<<"\n\t\t\tENTER   1:   To View List of Product";
                cout<<"\n\t\t\t------------------------------------------------";
                cout<<"\n\t\t\tENTER   2:   To View Product details";
                cout<<"\n\t\t\t------------------------------------------------";
                cout<<"\n\t\t\tENTER   3:   To Modify Existing Product Composition";
                cout<<"\n\t\t\t------------------------------------------------";
                cout<<"\n\t\t\tENTER   4:   To Add New Product Detail";
                cout<<"\n\t\t\t------------------------------------------------";
                cout<<"\n\t\t\tENTER   5:   To Remove any Product";
                cout<<"\n\t\t\t------------------------------------------------";
                cout<<"\n\t\t\tENTER   0:   To Exit     ";
                cout<<"\n\t\t\t------------------------------------------------";
                cout<<"\n\n\t\t\t   Please Enter Your Choice: ";

                int choice;
                cin>>choice;
                switch (choice)
                {
                    case 0:
                    	system("CLS");
                        cout<<"\n\nPRODUCT CHEMICAL COMPOSITION INFORMATION \n\n  ";
                        Sleep(10);
                        return;
                    case 1:
                        list_product();
                        break;
                    case 2:
                        showDetails();
                        break;
                    case 3:
                        editExisting();
                        break;
                    case 4:
                        addNew_product();
                        break;
                    case 5:
                        delete_product_Details();
                        break;
                    default:

                        cout<<"\n Sorry! APNE GALAT OPTION NUMBER ENTER KIYA HAI! \n";
                        break;
                }

            }
        }

};

int main()
{
    product e;
    e.options();
    return 0;
}

int login()
{
   string pass ="";
   char ch;
   cout <<"\n\n\n\n\t\t\t\tPRODUCT CHEMICAL COMPOSITION INFORMATION";
   cout <<"\n\n\n\n\n\t\t\t\tEnter Your Password (hint 2020) :";
   ch = _getch();
   while(ch != 13)
   {
      pass.push_back(ch);
      cout << '*';
      ch = _getch();
   }
   if(pass == "2020")
   {
   	cout<<"\n\n\n\t\t\t\t\tLOADING \n\t\t\t\t\t";
   	for(int a=1;a<8;a++)
	{
		Sleep(500);
		cout << "...";
	}
      cout << "\n\n\n\t\t\t\t\tAccess Granted !! \n\n\n";

      system("PAUSE");
      system("CLS");
   }else{
      cout << "\nAccess Aborted...\n";
      login();
   }
}
