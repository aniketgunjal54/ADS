#include<iostream>
using namespace std;
int key[30],c[30],n ,m;
int i;
class student
{
    public:
    int prn,rno;
    string name,ad;
    float p;
    void declare();
    void htable();
    void accept();
    void search();
    void Delete();
    void update();
}h[100];
void student :: declare()
{   
    cout<<"Enter total number of key : ";
    cin>>n;
    cout<<"Enter Keys :  ";
    for(i=0;i<n;i++)
    {
        cin>>key[i];
    }
    for(i=0;i<10;i++)
    {
        h[i].prn=-1;
        c[i]=0;
    }
}
void student :: htable()
{
    cout<<"\nPRN\tRNO\tNAME\tADDRESS\tPERCENTAGE\tCHAIN";
    for(i=0;i<10;i++)
    {
    cout<<"\n"<<h[i].prn<<"\t"<<h[i].rno<<"\t"<<h[i].name<<"\t"<<h[i].ad<<"\t"<<h[i].p<<"\t\t"<<c[i];
    }
}
void student :: accept()
{
    int no,pos;
    for(i=0;i<n;i++)
    {
        no=key[i]%10;
        pos=no;
        do{
            if(h[no].prn==-1)
            {
                h[no].prn=key[i];
                cout<<"Roll no : ";
                cin>>h[no].rno;
                cout<<"Name : ";
                cin>>h[no].name;
                cout<<"Address : ";
                cin>>h[no].ad;
                cout<<"Percentage : ";
                cin>>h[no].p;
                break;
            }
            else 
            {
                no++;
                c[pos]=no;
                
            }
        }while(no<10);
    }

}
void student :: search()
{
    int no,pos,pr,found=0;
    cout<<"Enter Prn to search : ";
    cin>>pr;
    for(i=0;i<n;i++)
    {
        no=pr%10;
        pos=no;
        do{
            if(h[no].prn==pr)
            {
             
                found=1;
                     break;
            }
            else 
            {
                no++;
                c[pos]=no;
                
                
            }
        }while(no<10);
    }
    if(found==1)
    {
        cout<<"\nPRN\tRNO\tNAME\tADDRESS\tPERCENTAGE\tCHAIN";
        cout<<"\n"<<h[no].prn<<"\t"<<h[no].rno<<"\t"<<h[no].name<<"\t"<<h[no].ad<<"\t"<<h[no].p<<"\t\t"<<c[i];
    }
    else
    {
        cout<<"\nRecord not found";
    }
}
void student :: update()
{
    int no,pos,pr,found=0;
    cout<<"Enter Prn to update : ";
    cin>>pr;
    for(i=0;i<n;i++)
    {
        no=pr%10;
        pos=no;
        do{
            if(h[no].prn==pr)
            {
                
                found=1;
                     break;
            }
            else 
            {
                no++;
                c[pos]=no;
                if(no>10)
                {
                    no=0;
                }
                
            }
        }while(no<10);
    }
    if(found==1)
    {
                
                cout<<"Roll no : ";
                cin>>h[no].rno;
                cout<<"Name : ";
                cin>>h[no].name;
                cout<<"Address : ";
                cin>>h[no].ad;
                cout<<"Percentage : ";
                cin>>h[no].p;
    }
    else
    {
        cout<<"\nRecord not found";
    }
}
void student::Delete() {
    int no, pos, pr, found = 0, it = -1;
    int m=10;
    cout << "Enter PRN to delete: ";
    cin >> pr;

    for (int i = 0; i < n; i++) {
        no = pr % 10;
        pos = no;
        
        do {
            if (h[no].prn == pr) {
                found = 1;
       
                
                break;

            } 
            else {
                no++;
            
                c[pos] = no;
            }
        } while (no <10);
    }
    
if(found==1)
{
   h[no].prn=-1;
          h[no].rno=0;
          h[no].name="";
          h[no].ad="";
          h[no].p=0;
}
    if (found == 0) {
      
        cout << "Record not found." << endl;
    }
}

int main()
{
    int ch;
    student s;
     
    do
    {
        cout<<"\n..........STUDENT MANAGEMENT SYSTEM..........";
        cout<<"\n1.declare\n2.ADD RECORD\n3.DISPLAY RECORD\n4.search\n5.delete\n6.update\n7.exit";

        cout<<"\nEnter your choice : ";
        cin>>ch;
        switch(ch)
        {
         
            case 1:
            s.declare();
            break;
            case 2:
            s.accept();
            break;
            case 3:
            s.htable();
            break;
            case 4:
            s.search();
            break;
            case 5:
            s.Delete();
            break;
            case 6:
            s.update();
            break;
            case 7:
            cout<<"Thanks for visiting......!!";
            break;
            default:
            cout<<"Wrong choice";
        }
    } while (ch!=7);
    return 0;
}
