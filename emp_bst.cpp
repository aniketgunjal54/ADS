#include<iostream>
#include<string>
#include <iomanip>
#define max 20 
using namespace std ;
int count,count1,count2 ;
class employ
{
      int salary,id ;
      string name, address ;
      employ *lchild, *rchild ;
      public :
            void accept() ;
            void  insert(employ *root, employ *next) ;
            void display(employ *root);
            void min(employ *root);
            void leaf(employ *root);
            void countGen() ;
            void search(employ *root) ;
}*root, *st[max];
void employ :: accept()
{
     
     employ *next ;
     int choice;
     root = new employ ;
     cout<<"Enter the details of Employ -->" ;
     cout<<"\nEnter the employ id :" ;
     cin>>root->id ;
     cout<<"\nEnter the name of employ name :" ;
     cin>>root->name ;
     cout<<"\nEnter the address :" ;
     cin>>root->address ;
     cout<<"\nEnter the employ salary :" ;
     cin>>root->salary ;
     root->lchild =root->rchild = NULL ;
     count++ ;
     count1 = count2 = count ;
     do
     {
           cout<<"\nDo you want to add more employ information (1/0)-->" ;
            cin >> choice ;
           if(choice == 1)
          {
                next = new employ ;
   		cout<<"\nEnter the details of Employ -->" ;
    	        cout<<"\nEnter the employ id :" ;
     		cin>>next->id ;
    		cout<<"\nEnter the name of employ name :" ;
    		cin>>next->name ;
    		cout<<"\nEnter the address :" ;
     		cin>>next->address ;
     		cout<<"\nEnter the employ salary :" ;
     		cin>>next->salary ;
     		next -> lchild = next->rchild = 0 ;
     		insert(root, next) ;
          }
          
     }while(choice == 1) ;
}
void employ :: insert(employ *root, employ *next)
{
    if(root->salary >= next->salary)
    {
         if(root->lchild == NULL)
         {
             root->lchild = next ;
         }
         else
         {
             insert(root->lchild,next) ;
         }
    }
    else if(root->salary < next->salary)
    {
         if(root->rchild == NULL)
         {
             root->rchild = next ;
         }
         else
         {
             insert(root->rchild,next);
         }
    }
}
void employ :: display(employ *root)
{
      int top = -1 ;
      employ *temp ;
      temp = root ;
      
      if(temp != NULL)
      {
          do
          {
              while(temp != NULL)
              {
                  top++;
                  st[top] = temp ;
                  temp = temp-> lchild ;
              }
              if(top != -1)
              {
                  temp = st[top];
                  cout<<setw(15)<<left<<temp->id ;
                  cout<<setw(15)<<left<<temp->name ;
                  cout<<setw(15)<<left<<temp->address ;
                  cout<<setw(10)<<left<<temp->salary ;
                  cout<<"\n";
                  //cout<<"\n\t"<<temp->ger<<"\t"<<temp->name<<"\t"<<temp->age<<"\t"<<temp->gen ;
                  temp = temp -> rchild ;
              }
              top-- ;
          }while(temp != NULL || top != -1);
     }
}
void employ :: min(employ *root)
{
      int top = -1 ;
      employ *temp ;
      temp = root ;
      
      if(temp != NULL)
      {
              while(temp != NULL)
              {
                  top++;
                  st[top] = temp ;
                  temp = temp-> lchild ;
              }
              if(top != -1)
              {
                  temp = st[top];
                  cout<<setw(15)<<left<<"EmployId" ;
                  cout<<setw(15)<<left<<"Name";
                  cout<<setw(15)<<left<<"Address" ;
                  cout<<setw(10)<<left<<"Salary" ;
                  cout<<"\n";
                  cout<<setw(15)<<left<<temp->id ;
                  cout<<setw(15)<<left<<temp->name ;
                  cout<<setw(15)<<left<<temp->address ;
                  cout<<setw(10)<<left<<temp->salary ;
                  cout<<"\n";
                  //cout<<"\n\t"<<temp->ger<<"\t"<<temp->name<<"\t"<<temp->age<<"\t"<<temp->gen ;
                  //temp = temp -> rchild ;
              }
              top-- ;
          
     }
}
void employ :: leaf(employ *root)
{
      int top = -1 ;
      employ *temp ;
      temp = root ;
      
      if(temp != NULL)
      {
          do
          {
              while(temp != NULL)
              {
                  top++;
                  st[top] = temp ;
                  temp = temp-> lchild ;
                  count1++;
              }
              if(top != -1)
              {
                  temp = st[top];
                  if(temp->lchild == NULL && temp->rchild == NULL)
                  {
                       cout<<setw(15)<<left<<temp->id ;
                       cout<<setw(15)<<left<<temp->name ;
                       cout<<setw(15)<<left<<temp->address ;
                       cout<<setw(10)<<left<<temp->salary ;
                       cout<<"\n";
                      //cout<<"\n\t"<<temp->ger<<"\t"<<temp->name<<"\t"<<temp->age<<"\t"<<temp->gen ;
                 
                  }
                  temp = temp -> rchild ;
              }
              top-- ;
          }while(temp != NULL || top != -1);
     }
}
void employ :: countGen()
{
   if(count1 >= count2)
   {
      cout <<"\nHeight of tree is :"<<count1;
   }
   else
   {
       cout<<"\nHeight of tree is :"<<count2 ; 
   }
}
void employ :: search(employ *root)
{
      int f=0;
      string SearchName ;
      cout<<"\nEnter the  name for search :";
      cin>>SearchName ;
      int top = -1 ;
      employ *temp ;
      temp = root ;
      
      if(temp != NULL)
      {
          do
          {
              while(temp != NULL)
              {
                  top++;
                  st[top] = temp ;
                  temp = temp-> lchild ;
              }
              if(top != -1)
              {
                  temp = st[top];
                  if(temp->name==SearchName)
                  {
                  f=1;
                  cout<<"\nREcord is found-->"<<endl ;
                  cout<<setw(15)<<left<<"EmployId" ;
                  cout<<setw(15)<<left<<"Name";
                  cout<<setw(15)<<left<<"Address" ;
                  cout<<setw(10)<<left<<"Salary" ;
                  cout<<"\n";
                  cout<<setw(15)<<left<<temp->id ;
                  cout<<setw(15)<<left<<temp->name ;
                  cout<<setw(15)<<left<<temp->address ;
                  cout<<setw(10)<<left<<temp->salary ;
                  cout<<"\n";
                  //cout<<"\ngenration"<<"\t"<<"name"<<"\t"<<"age"<<"\t"<<"gender" ;
                  //cout<<"\n\t"<<temp->ger<<"\t"<<temp->name<<"\t"<<temp->age<<"\t"<<temp->gen ;
                   break;
                  //delete temp;
                  }
                  temp = temp -> rchild ;
              }
              top-- ;
          }while(temp != NULL || top != -1);
     }
     if(f==0)
     cout<<"\n record is not present ";
}
int main()
{
    employ f ;
    int ch, choice ;
    do
    {
         cout<<"\n ------------------ MENU ----------------\n" ;
         cout<<"\n1.Accept" ;
         cout<<"\n2.Display" ;
         cout<<"\n3.Display Leap Node" ;
         cout<<"\n4.Count Generation" ;
         cout<<"\n5.Search\n6.min\n7.Exit" ;
         cout<<"\nEnter the choice :" ;
         cin>>choice ;
         switch(choice)
         {
              case 1 :
                    f.accept() ;
                    break ;
              case 2 :
                    cout<<setw(15)<<left<<"EmployId" ;
                    cout<<setw(15)<<left<<"Name";
                    cout<<setw(15)<<left<<"Address" ;
                    cout<<setw(10)<<left<<"Salary" ;
                    cout<<"\n";
                    f.display(root) ;
                    break ;
              case 3 :
                    cout<<setw(15)<<left<<"EmployId" ;
                    cout<<setw(15)<<left<<"Name";
                    cout<<setw(15)<<left<<"Address" ;
                    cout<<setw(10)<<left<<"Salary" ;
                    cout<<"\n";
                    f.leaf(root);
                    break ;
              case 4 :
                    f.countGen() ;
                    break ;
              case 5 :
                    f.search(root);            
                    break;
              case 6 :
                    f.min(root) ;
                    break ;
              case 7:   
                    exit(0) ;
                    break ;
             default  :
                    cout<<"\nWrong choice" ;
                    break ;
         }
         cout<<"\nDo you want to continue(1/0) :" ;
         cin >> ch ;
   }while(ch == 1);
    return 0 ;
    
}




