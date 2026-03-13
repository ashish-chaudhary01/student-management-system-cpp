#include<iostream>
#include<vector>
using namespace std;

class Student{
public:
    int id;
    string name;
    float marks;

    void input(){
        cout<<"Enter Student Name: ";
        cin>>name;
        cout<<"Enter Student ID: ";
        cin>>id;
        cout<<"Enter Student Marks: ";
        cin>>marks;
        cout<<"\nStudent Successfully Added!"<<endl;
    }

    void display(){
        cout<<"\nName: "<<name<<endl;
        cout<<"ID: "<<id<<endl;
        cout<<"Marks: "<<marks<<endl;
        cout<<"--------------------"<<endl;
    }


};

int main(){
    vector <Student> Students;
    int choice;
    
    while(1){
        cout<<"\n-----STUDENT MANAGEMENT SYSTEM-----"<<endl;
        cout<<"\n1.Add Student"<<endl;
        cout<<"2.Display Students"<<endl;
        cout<<"3.Search Student"<<endl;
        cout<<"4.Delete Student"<<endl;
        cout<<"5.Update Student"<<endl;
        cout<<"6.Exit"<<endl;
        cout<<"Enter Your Choice: ";
        cin>>choice;

        if(choice ==1){
            Student s;
            s.input();
            Students.push_back(s);
        }

        else if(choice ==2){
            cout<<"\n-----Students Records-----\n";
            for(Student &s: Students){
                s.display();
            }
        }

        else if(choice ==3){
            int searchid,found = 0;
            cout<<"Enter Student ID: ";
            cin>>searchid;
            for(Student &s:Students){
                if(s.id == searchid){
                    cout<<"\n-----Student Found!-----"<<endl;
                    s.display();
                    found = 1;
                    break;
                }
            }
            if(found ==0){
                cout<<"No Student Found!!"<<endl;
            }
        }

        else if(choice == 4){
            int deleteid,found=0;
            cout<<"Enter Student ID: ";
            cin>>deleteid;
            for(int i=0;i<Students.size();i++){
                if(Students[i].id == deleteid){
                    Students.erase(Students.begin()+i);
                    found = 1;
                    cout<<"Student Deleted Successfully"<<endl;
                    break;
                }
            }
            if(found == 0){
                cout<<"No Student Found!"<<endl;
            }
        }

        else if(choice == 5){
            int updateid,found = 0;
            cout<<"Enter Student ID: ";
            cin>>updateid;

            for(Student &s: Students){
                if(updateid == s.id){
                    found = 1;
                    cout<<"Enter New Name: ";
                    cin>>s.name;

                    cout<<"Enter New Marks: ";
                    cin>>s.marks;

                    cout<<"Student Updated Succesfully!!"<<endl;
                    break;
                }
            }
            if(found==0){
                cout<<"No Student Found!"<<endl;
            }
        }

        else if(choice == 6){
            break;
        }

        else{
            cout<<"Invalid Choice!!"<<endl;
        }

    }
    return 0;
}