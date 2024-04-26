#include<iostream>
using namespace std;
int c=0,c1=0,c2=0;
#define max 10
class fmt
{
    public:
    int age;
    string name,bg;
    fmt *rchild,*lchild;
    void accept();
    void insert(fmt *root,fmt *next);
    void search(fmt *root);
    void modify(fmt *root);
    void leaf(fmt *next);
    void ht();
    void display(fmt *next);
    void maximum(fmt *root);
    void minimum(fmt *root);
    void total();
    void del(fmt *root);
}*root,*st[max];
void fmt::del(fmt *root)
{
       int n,f=0;
    fmt *temp;
    temp=new fmt();
    
    cout<<"Enter Age for delete : ";
    cin>>n;
    while(root!=NULL)
    {
        if(root->age > n)
        {
            root=root->lchild;
        }
        else if(root->age < n)
        {
            root=root->rchild;
        }
         else   
       {
        cout<<"\nRecord is found";
        root->name="";
        root->age=0;
        root->bg="";
        f++;
        break;
       }
     
 }
   if(f==0)
   {
   cout<<"\nrecord not found";
   }

}

void fmt::accept()
{   
    int ch;
    fmt *next;
    root=new fmt;
    cout<<"Enter name : ";
    cin>>root->name;
    cout<<"Enter Age : ";
    cin>>root->age;
    cout<<"Enter Blood group : ";
    cin>>root->bg;
    root->rchild=NULL;
    root->lchild=NULL;
    c++;
    c1=c2=c;

   do
   {
     cout<<"\nDo you want to add new member : ";
     cout<<"\n1.Yes\n2.NO";
     cout<<"\nEnter your choice : ";
     cin>>ch;
     if(ch==1)
     {
        next=new fmt;
        cout<<"Enter name : ";
        cin>>next->name;
        cout<<"Enter Age : ";
        cin>>next->age;
        cout<<"Enter Blood group : ";
        cin>>next->bg;
        next->rchild=NULL;
        next->lchild=NULL;
        insert(root,next);

     }
     
        } while (ch==1);
}
void fmt::insert(fmt *root,fmt *next)
{
 if (root->age > next->age)
    {
        if (root->lchild == NULL)
        {
            c1++;
            c++;
            root->lchild = next;
  cout<<"Inserted successfully";
        }
        else
        {
            insert(root->lchild, next);
        }
    }
    if (root->age < next->age)
    {
        if (root->rchild == NULL)
        {   
            c++;
            c2++;
            root->rchild = next;
            cout<<"Inserted successfully";
        }
        else
        {
            insert(root->rchild, next);
        }
    }

}
void fmt::display(fmt *root)
{
    int top=-1;
    fmt *temp;
    temp=root;
    if(root!=NULL)
    {
        do
        {
             while(temp!=NULL)
             {
                top++;
                st[top]=temp;
                temp=temp->lchild;
             }
             if(top!=-1)
             {
               temp=st[top];
               cout<<"\n"<<temp->name<<"\t"<<temp->age<<"\t"<<temp->bg;
               temp=temp->rchild;
               top--;
             }
        } while (temp!=NULL || top!=-1);
        
    }
    if(c==0)
    {
        cout<<"\nTree is empty";
    }
}
void fmt :: leaf(fmt *next)
{
 int top=-1;
    fmt *temp;
    temp=root;
    if(root!=NULL)
    {
        do
        {
             while(temp!=NULL)
             {
                top++;
                st[top]=temp;
                temp=temp->lchild;
             }
             if(top!=-1)
             {
               temp=st[top];
               if(temp->rchild==NULL && temp->lchild==NULL)
               {
               cout<<"\n"<<temp->name<<"\t"<<temp->age<<"\t"<<temp->bg;
               }
               temp=temp->rchild;
               top--;
             }
        } while (temp!=NULL || top!=-1);
        
    }
    if(c==0)
    {
        cout<<"\nsTree is empty";
    }
}
void fmt::search(fmt *root)
{
    int n,f=0;
    fmt *temp;
    temp=new fmt();
    
    cout<<"Enter Age for search : ";
    cin>>n;
    while(root!=NULL)
    {
        if(root->age > n)
        {
            root=root->lchild;
        }
        else if(root->age < n)
        {
            root=root->rchild;
        }
         else   
       {
        cout<<"Record is found";
        cout<<"\nNAME\tAGE\tBLOODGROUP";
        cout<<"\n"<<root->name<<"\t"<<root->age<<"\t"<<root->bg;
        f++;
        break;
       }
     
 }
   if(f==0)
   {
   cout<<"record not found";
   }
}
void fmt::modify(fmt *root)
{
    int n,f=0;
    fmt *temp;
    temp=new fmt();
    
    cout<<"Enter Age for search : ";
    cin>>n;
    while(root!=NULL)
    {
        if(root->age > n)
        {
            root=root->lchild;
        }
        else if(root->age < n)
        {
            root=root->rchild;
        }
         else   
       {
        cout<<"Record is found";
        cout<<"\nEnter name : ";
        cin>>root->name;
        cout<<"Enter Age : ";
        cin>>root->age;
        cout<<"Enter Blood group : ";
        cin>>root->bg;
        f++;
        break;
       }
     
 }
   if(f==0)
   {
   cout<<"record not found";
   }
}
void fmt:: maximum(fmt *root)
{ 
    while(root->rchild!=NULL)
    {
        root=root->rchild;
    }
 cout<<"\nMaximum age is : "<<root->age;
 }
 void fmt:: minimum(fmt *root)
{ 
    while(root->lchild!=NULL)
    {
        root=root->lchild;
    }
 cout<<"\nMinimum age is : "<<root->age;
 }
 void fmt::total()
 {
    cout<<"\nTotal no of record is : "<<c;
 }
 void fmt::ht()
 {
    if(c1<c2)
    {
        cout<<"\nTotal generation is : "<<c2;
    }
    else
    {
        cout<<"\nTotal generation is : "<<c1;
    }
 }
int main()
{
    int ch;
    fmt f;
    do
    {
        cout<<"\n..........FAMILY TREE...........";
        cout<<"\n1.ACCEPT THE RECORD\n2.DISPLAY THE RECORD\n3.DISPLAY LEAF NODE\n4.SEARCH THE NODE\n5.MODIFY THE RECORD\n6.MAXIMUM\n7.MINIMUM\n8.TOTAL\n9.GENERATION\n10.DELETE\n11.EXIT";
        cout<<"\nEnter your choice : ";
        cin>>ch;
        switch(ch)
        {
            case 1 :
            f.accept();
            break;
            case 2 :
            cout<<"\nNAME\tAGE\tBLOODGROUP";
            f.display(root);
            break;
            case 3 :
            cout<<"\nNAME\tAGE\tBLOODGROUP";
            f.leaf(root);
            break;
            case 4 :
            f.search(root);
            break;
            case 5 :
            f.modify(root);
            break;
            case 6 :
            f.maximum(root);
            break;
            case 7 :
            f.minimum(root);
            break;
            case 8 :
            f.total();
            break;
            case 9 :
            f.ht();
            break;
            case 10 :
           
            f.del(root);
            break;
            case 11 :
            cout<<"Thanks for visiting....!!";
            break;
            default :
            cout<<"Wrong choice";

        }
    } while (ch!=11);
    
}