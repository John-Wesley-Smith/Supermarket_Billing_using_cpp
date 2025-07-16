#include<iostream>
#include<fstream>
using namespace std;

class Shopping{
    private:
        int pcode;//product code
        float price;
        float dis;//discount
        string pname;//product name

    public:
        void menu();
        void administrator();
        void buyer();
        void add();
        void edit();
        void rem();//remove
        void list();
        void receipt();
};

void Shopping :: menu(){
    int choice;
    string email;
    string password;

    menu: // label
    cout<<"____________________________________________\n";
    cout<<"                                            \n";
    cout<<"          Super Market Main Menu            \n";
    cout<<"____________________________________________\n\n";

    cout<<"|                                           | \n";
    cout<<"|        1) Administrator                   | \n";    
    cout<<"|                                           | \n";    
    cout<<"|        2) Buyer                           | \n";    
    cout<<"|                                           | \n";    
    cout<<"|        3) Exit                            | \n";    
    cout<<"|                                           | \n";
    
    cout<<"\nPlease select your choice: ";
    cin>> choice;

    switch(choice){
        case 1:
            cout<<"\n\nPlease Login \n";
            cout<<"\nEnter the Email : ";
            cin >> email;
            cout<<"\nPassword : ";
            cin >> password;

            if(email == "jude24@gmail.com"  && password == "Jude123"){
                administrator();
            }
            else{
                cout<< "\nInvalid Email / Password"<<endl;
            }
            break;

        case 2:
            buyer();
            break;
         
        case 3:
            exit(0);
        
        default:
            cout<<"\n Please select from the given options: ";    
    }
    goto menu; // The goto terminates when the user choose the option 3
}

void Shopping :: administrator(){
    int choice;

    menu:
    cout<<"\n\n\n\tAdministrator Menu\n";
    cout<<"\n|     1) Add the product       |";
    cout<<"\n|     2) Modify the product    |";
    cout<<"\n|     3) Delete the product    |";
    cout<<"\n|     4) Back to the main menu |";    

    cout<<"\n\n Please Enter your choice: ";
    cin>>choice;

    switch (choice){
        case 1:
            add();  
            break;

        case 2:
            edit();
            break;
            
        case 3: 
            rem();
            break;
            
        case 4:
            menu();
            break;    
        
        default:
            cout<<"Invalid Choice!";
            break;
    }

    goto menu;
}

void Shopping :: buyer(){
    int choice;

    menu:
    cout<<"\n BUYER \n";
    cout<<"\n 1) Buy Product  ";
    cout<<"\n 2) Go Back ";
    cout<<"\n\n Enter your choice: ";
    cin>>choice;

    switch (choice){
    case 1:
        receipt();
        break;
    
    case 2:
        menu();
        break;

    default:
        cout<<"Invalid choice";
        break;
    }
    goto menu;

}

void Shopping :: add(){
    
    menu:
    fstream data;
    int c;
    int token = 0;
    float p;
    float d;
    string n;

    cout<<"\n\nAdd New Product";
    cout<<"\n Product code of the product: ";
    cin>>pcode;
    cout<<"\n Name of the product: ";
    cin>>pname;
    cout<<"\n Price of the product: ";
    cin>>price;
    cout<<"\n Discount on product: ";
    cin>>dis;
     
    data.open("database.txt",ios::in);//open the file in reading mode

    if(!data){// The control goes to if-block, if the database.txt is not open(exist) successfully
        data.open("database.txt", ios::app | ios::out); //append and write mode
        data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";// writing the file
        data.close();
    }
    else{
        data>>c>>n>>p>>d;// reads the first set of four value

        while(!data.eof()){// Check for duplication in product code(pcode)
            if(c == pcode){
                token++;
            }
            data >>c>>n>>p>>d;// used for read the dataset line by line
        }
        data.close();
    }
    if(token == 1){ // if duplication exist goes to menu
        cout<<"\nThe Product code is already exist, enter new product code with details";
        goto menu;
    }
    else{ // if duplication is not exist, then add to file
        data.open("database.txt", ios::app | ios::out); 
        data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
        data.close();
    }
    cout<<"\n\n\t\t Record inserted !";
}

void Shopping :: edit(){
    fstream data,data1;
    int pkey;
    int token = 0;
    int c;
    float p;
    float d;
    string n;
     
    cout<<"\n\n\t\t Modify the record";
    cout<<"\n Product code: ";
    cin>>pkey;
    data.open("database.txt",ios::in);
    if(!data){
        cout<<"\n\t\t File doesn't exist! ";
    }
    else{
        data1.open("database1.txt",ios::app | ios::out);
        data>>pcode>>pname>>price>>dis;
        while(!data.eof()){ // traversing line by line, if product code matches, control enters the if block to modify.else add the remaining details
            if(pkey == pcode){
                cout<<"\n Product new code: ";
                cin>>c;
                cout<<"\n Name of the product: ";
                cin>>n;
                cout<<"\n Price: ";
                cin>>p;
                cout<<"\n Discount: ";
                cin>>d;
                data1<<" "<<c<<" "<<n<<" "<<p<<" "<<d<<"\n";
                cout<<"\n\n\t\t Record edited";
                token++;
            }
            else{
                data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
            }
            data>>pcode>>pname>>price>>dis;
        }
        data.close();
        data1.close();

        remove("database.txt");
        rename("database1.txt", "database.txt");

        if(token == 0){
            cout<<"\n\n Record not found sorry! ";
        }
    }
}

void Shopping::rem(){
    fstream data,data1;
    int pkey;
    int token = 0;
    cout<<"\n\t Delete Product";
    cout<<"\n\n Product code: ";
    cin>>pkey;
    data.open("database.txt", ios::in);
    if(!data){
        cout<<"\n\t\tFile doesn't exist";
    }
    else{
        data1.open("database1.txt",ios::app | ios::out);
        data>>pcode>>pname>>price>>dis;
        while(!data.eof()){
            if(pcode == pkey){// To delete, just skip the product code which matches
                cout<<"\n\n\t\t Product deleted Successfully";
                token++;
            }
            else{
                data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
            }
            data>>pcode>>pname>>price>>dis;
        }
        data.close();
        data1.close();
        remove("database.txt");
        rename("database1.txt","database.txt");

        if(token == 0){
            cout<<"\n\n Record not found";
        }
    }
}

void Shopping:: list(){
    fstream data;
    data.open("database.txt",ios::in);
    cout<<"\n_____________________________________________________\n";
    cout<<"\nProduct No \tName\t\tPrice\n";
    cout<<"_____________________________________________________\n\n";
    data>>pcode>>pname>>price>>dis;
    while(!data.eof()){
        cout<<pcode<<" \t\t"<<pname<<"\t\t"<<price<<"\n";
        data>>pcode>>pname>>price>>dis;
    }
    data.close();
}

void Shopping:: receipt(){

    fstream data;
    int arrc[100];// arrays of code
    int arrq[100];//array of quantity
    char choice;
    int c = 0;
    float amount = 0;
    float diss = 0;
    float total = 0;

    cout<<"\n\n\t RECEIPT";
    data.open("database.txt",ios::in);
    if(!data){
        cout<<"\n\n Empty database";
    }
    else{
        data.close();
        list();
        cout<<"\n__________________________________________________________\n";
        cout<<"\n                 Please place the order                   ";
        cout<<"\n__________________________________________________________\n";
        do{
            menu:
            cout<<"\nEnter the Product code: ";
            cin>>arrc[c];
            cout<<"\nEnter the product quantity: ";
            cin>>arrq[c];
            for(int i=0; i<c; i++){
                if(arrc[c] == arrc[i]){
                    cout<<"\n Duplicate product code. Please try again";
                    goto menu;
                }
            }
            c++;
            cout<<"\nDo you want to buy another product? if yes then press y else n: ";
            cin>>choice;
        }while(choice == 'y');

        cout<<"\n\n\t______________________RECEIPT__________________\n";
        cout<<"\nProduct No\t Name\t     Quantity\tPrice \tAmount \t discount \n";

        for(int i=0; i<c; i++){
            data.open("database.txt", ios::in);
            data>>pcode>>pname>>price>>dis;
            while(!data.eof()){
                if(pcode == arrc[i]){
                    amount = price * arrq[i];
                    diss = amount - (amount *dis/100);
                    total = total + diss;
                    cout<<"\n"<<pcode<<"\t\t"<<pname<<"\t"<<"\t"<<arrq[i]<<"\t"<<price<<"\t"<<amount<<"\t"<<diss;
                    break;
                }
                data>>pcode>>pname>>price>>dis;
            }
            data.close();
        }
        cout<<"\n____________________________________________________________";
        cout<<"\n\nTotal Amount: "<<total<<endl;

    }
}

int main(){
    Shopping s;
    s.menu();
}