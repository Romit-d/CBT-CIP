#include<iostream>
#include<vector>
#include<string>
#include<fstream>
using namespace std;

class student{
    public:
        string name;
        int roll_number;
        string stdaddress;
        string acamadic_record;
};

// Load Previous data of the mentioned file (if there is any)

void fileloading(vector<student>& std, const string& file_Name){
    ifstream fromFile(file_Name);
    if(!fromFile){
            // cout<<"Error!! Unable to access file"<<endl;
            return;
    }

    student std1;
    while(getline(fromFile, std1.name)){
        fromFile>>std1.roll_number;
        fromFile.ignore();
        getline(fromFile, std1.stdaddress);
        getline(fromFile, std1.acamadic_record);
        std.push_back(std1);
    }
    fromFile.close();
    // cout<<"Data loaded Successfully!"<<endl;
}

// Add Student

 void addstudent(vector<student>& std){
    student stdd;

    cout<<"Enter Student's name  - ";
    cin.ignore();
    getline(cin, stdd.name);

    cout<<"Enter Student's Roll.No - ";
    if(!(cin >> stdd.roll_number)){
        cin.clear();
        cout<<"Invalid Input !"<<endl;
    }
    cin.ignore();

    cout<<"Enter the address of the Student - ";
    getline(cin, stdd.stdaddress);

    cout<<"Enter the Academic Record - ";
    getline(cin, stdd.acamadic_record);

    std.push_back(stdd);
    cout<<"**Student Data added Successfully**"<<endl;
 }

//  Display function

 void disp(const vector<student>& std){
    if(std.empty()){
        cout<<"Unfortunatly, No student data availabe!!"<<endl;
        return;
    }
    for (const auto& stdd : std){
        cout<<"Name - "<<stdd.name<<endl;
        cout<<"Roll Number - "<<stdd.roll_number<<endl;
        cout<<"Address - "<<stdd.stdaddress<<endl;
        cout<<"Academic Performance - "<<stdd.acamadic_record<<endl;
        cout<<endl;
    }
    
 }

// To Save user entered data to a file name in file_Name

void savedatatofile(vector<student>& std, const string& file_Name){
    ofstream savetofile(file_Name);
    if(!savetofile){
        cout<<"Error!! Unable to open file for editing"<<endl;
    }

    for(const auto stdd : std){
        savetofile << stdd.name << endl;
        savetofile << stdd.roll_number << endl;
        savetofile << stdd.stdaddress << endl;
        savetofile << stdd.acamadic_record <<endl;
    }
    savetofile.close();
    cout<<"**Data saved to file Successfully**"<<endl;
}

// To Delete any existing file

void delete_data_of_std(const string& file_Name){
    if(remove(file_Name.c_str())==0){
        cout<<"File Deleted Successfully"<<endl;
    }
    else{
        cout<<"Error!! Unable to delete file"<<endl;
    }
}

int main(){
    vector<student> std;
    string file_Name = "std.txt";
    
    fileloading(std, file_Name);

    int choice;
    do
    {
        cout<<"\n-----* Student Data Management System *-----\n"<<endl;
        cout<<"1.   Add Student Data"<<endl;
        cout<<"2.   Display Data"<<endl;
        cout<<"3.   Save Student Data to file  "<<endl;
        cout<<"4.   Delete File"<<endl;
        cout<<"5.   Exit"<<endl;

        cout<<"\nEnter you choice - ";
        if(!(cin>>choice)){
            cin.clear();
            cout<<"Invalid Input ! "<<endl;
        }
        cout<<endl;
        switch (choice)
        {
        case 1:
            addstudent(std);        //function to add student 
            break;
        
        case 2:
            disp(std);              //function to display student list
            break;
        
        case 3:
            savedatatofile(std, file_Name);     //function for storing data to a particular file as per mentioned earlier in file_Name
            break;
        
        case 4:
            delete_data_of_std(file_Name);      //function for deleting the file along with its data
            break;

        case 5:
            cout<<"Exiting !!"<<endl;
            break;

        default:
            cout<<"Invalid Input!! Enter the correct option"<<endl;
            break;
        }

    } while (choice != 5);
    
}