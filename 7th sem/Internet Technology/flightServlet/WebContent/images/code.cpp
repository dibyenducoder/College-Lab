#include<iostream>
#include<stdlib.h>
using namespace std;
class book{
    public:
int bookid;
int sno;
string title;
string author;

};
class node{
public:
int data;
int sno;
string tie;
string aname;
node*next;
};
class student:book{
public :
int c=0;
int memberid;
char *name;
char*email;

void bookstore(node*head,int bkid,int sno,string tile,string authorname)
{
    node*temp=head;
    temp=new node();
    if(head==NULL)
    {
        
        head->data=bkid;
        head->sno=sno;
        head->tie=tile;
        head->aname=authorname;
        temp=head;
        temp=temp->next;
        cout<<"data entered\n";
    }
    else{
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->data=bkid;
        temp->sno=sno;
        temp->tie=tile;
        temp->aname=authorname;
        temp=temp->next;
        cout<<"OK entered\n";
        
    }
}
void bookissue(node*head,int bkid)
{
    node*temp=head;
    node*prev=NULL;
    temp=new node();
    prev =new node();
    while(temp!=NULL)
    {
        if(temp->data==bkid)
        {
            cout<<"book available and issued\n";
            prev->next=temp->next;
            return;
        }
        prev=temp;
        temp=temp->next;
    }
    cout<<"book not avaliable\n";
}
void bookreturn(int bkid,int sno,char*t,node*head)
{
    node*temp=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->data=bkid;
    temp->sno=sno;
    temp->tie=t;
   // temp->aname=
    cout<<"book returned\n";
}
void display(node*head)
{
node*temp=head;
temp=new node();
while(temp!=NULL)
{
    cout<<temp->data<<" "<<temp->sno<<" "<<temp->tie<<" "<<temp->aname<<"\n";
    temp=temp->next;
}
cout<<"done\n";
}
};

int main()
{
    student s;
    int i=0;
    node*head=NULL;
    head=new node();
while(1){
    cout<<"enter your choice\n";
    int ch;
    cin>>ch;
    switch(ch)
    {
        case 0: cout<<"Thank you\n";
        exit(0);
        break;
        case 2: cout<<"display:\n";
        s.display(head);
        break;
        case 1:cout<<"book store\n";
        int bkid,sno;
        string tile;string authorname;
        tile=new char[100];
        authorname=new char[100];
        cout<<"enter book id  serialno.  title  and  author name respectively\n";
        cin>>bkid>>sno;
        cin.ignore();
        getline(cin,tile);
        cin.ignore();
        getline(cin,authorname);
        s.bookstore(head,bkid,sno,tile,authorname);
        break;
        
    }
}
}