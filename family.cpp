#include<iostream>
#include<string>
using namespace std ;
class family
{
      int age,ger ;
      string name, gen ;
      family *lchild, *rchild ;
      public :
            void accept() ;
            void  insert(family *root, family *next) ;
            void display(family *root);
}*root ;
void family :: accept()
{
     
     family *next ;
     int choice;
     root = new family ;
     cout<<"Enter the details of family member" ;
     cout<<"\nEnter the generation no :" ;
     cin>>root->ger ;
     cout<<"\nEnter the name of family member :" ;
     cin>>root->name ;
     cout<<"\nEnter the age :" ;
     cin>>root->age ;
     cout<<"\nEnter the gender of family member :" ;
     cin>>root->gen ;
     root->lchild =root->rchild = NULL ;
     do
     {
           cout<<"\nDo you want to add more family information (1):" ;
            cin >> choice ;
           if(choice == 1)
          {
                next = new family ;
                cout<<"\nEnter the details of family member -->" ;
     		 cout<<"\nEnter the generation no :" ;
     		 cin>>next->ger ;
     		 cout<<"\nEnter the name of family member :" ;
     		 cin>>next->name ;
     		 cout<<"\nEnter the age :" ;
     		 cin>>next->age ;
     		 cout<<"\nEnter the gender of family member :" ;
     		 cin>>next->gen ;
     		 next -> lchild = next->rchild = 0 ;
     		 insert(root, next) ;
          }
          
     }while(choice == 1) ;
}
void family :: insert(family *root, family *next)
{
    char chr ;
    cout<<"\nDo you want to insert more family information :"<<root->name<<"\tL or R"<<endl ;
    cin>>chr ;
    if(chr == 'l' || chr == 'L')
    {
          if( root->lchild == NULL)
          {
               root->lchild = next ;
          }
          else
          {
              insert(root->lchild , next) ;
          }
    }
    else if(chr == 'r' || chr == 'R')
    {
          if( root->rchild == NULL)
          {
               root->rchild = next ;
          }
          else
          {
              insert(root->rchild , next) ;
          }
    }   
}
void family :: display(family *root)
{
      if(root == NULL)
      {
           return  ;
      }
      else
      {
             cout<<"\n" ;
             cout<<"\n"<<root->ger<<"\t"<<root->name<<"\t"<<root->age<<"\t"<<root->gen ;
             display(root->lchild) ;
             display(root->rchild) ;
      }
}
int main()
{
    family f ;
    int ch, choice ;
    do
    {
         cout<<"\n ------------------ MENU ----------------\n" ;
         cout<<"\n1.Accept" ;
         cout<<"\n2.Display" ;
         cout<<"\n3.Exit" ;
         cout<<"\nEnter the choice :" ;
         cin>>choice ;
         switch(choice)
         {
              case 1 :
                    f.accept() ;
                    break ;
              case 2 :
                    cout<<"\ngenration"<<"\t"<<"name"<<"\t"<<"age"<<"\t"<<"gender" ;
                    f.display(root) ;
                    break ;
              case 3 :
                    exit(0) ;
                    break ;
             default  :
                    cout<<"\nWrong choice" ;
         }
         cout<<"\nDo you want to continue(1/0) :" ;
         cin >> ch ;
   }while(ch == 1);
    return 0 ;
    
}




