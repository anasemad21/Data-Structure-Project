#include <iostream>
#include <cstdlib>
using namespace std;
struct copy_date
{
    int day=0;
    int month=0;
    int year=0;
};
struct book_copy
{
    copy_date cpdate;
    bool Aob;
    string borrower;
    copy_date borrow_date;
    int remaining_days;
    book_copy* next;
};
struct book
{
    string book_name;
    int book_isbn;
    int no_of_copies=0;
    int borrow_counter=0;
    book_copy* Front=NULL;
    book* next;
};
class queue_ll : public book
{
public:
    book_copy* Rear;
    queue_ll()
    {
        no_of_copies=0;
    }
    void insert()
    {
        
        
    }
    
};
class linked_list
{
private:
    book* Head;
    book* Tail;
    int length;
public:
    linked_list()
    {
        Head=Tail=NULL;
        length=0;
    }
    void insert()
    {
        string b_name;
        int b_isbn, num_of_copies;
        cout<<"Enter book name: ";
        cin>>b_name;
        cout<<"Enter book ISBN: ";
        cin>>b_isbn;
        cout<<"Enter  number of copies: ";
        cin>>num_of_copies;
        book* new_book= new book;
        new_book->book_name = b_name;
        new_book->book_isbn = b_isbn;
        new_book->no_of_copies += num_of_copies;
        if(length==0)
        {
            Head=Tail=new_book;
            new_book->next= NULL;
        }
        book* listcurr = new book;
        listcurr= Head;
        while(listcurr->next!=NULL)
        {
            if(listcurr->book_name== b_name)
                break;
            listcurr= listcurr->next;
        }
        if(listcurr->next==NULL)
        {
            if(length>0)
            {
                Tail->next= new_book;
                new_book->next= NULL;
                Tail= new_book;
                listcurr=new_book;
            }
            length++;
            
            for(int i=0;i<num_of_copies;i++)
            {
                book_copy* new_copy= new book_copy;
                new_copy->cpdate.day= rand() %30+1;
                new_copy->cpdate.month= rand() %13+1;
                new_copy->cpdate.year= rand() %(2020-2000+1)+2000;
                new_copy->borrow_date.day= 0;
                new_copy->borrow_date.month= 0;
                new_copy->borrow_date.year= 0;
                new_copy->Aob= true;
                new_copy->borrower="";
                new_copy->remaining_days=0;
                if(i==0)
                {
                   listcurr->Front = new_copy;
                   listcurr->Front->next=NULL;
                }
                else
                {
                    book_copy* curr= new book_copy;
                    curr = listcurr->Front;
                    while (curr->next!=NULL)
                        curr=curr->next;
                    curr->next= new_copy;
                    new_copy->next= NULL;
                }
            }
        }
        else
        {
            book_copy* curr1= listcurr->Front;
            while (curr1->next!=NULL)
                curr1=curr1->next;
            for(int i=0;i<num_of_copies;i++)
            {
                book_copy* new_copy= new book_copy;
                new_copy->cpdate.day= rand() %31+1;
                new_copy->cpdate.month= rand() %13+1;
                new_copy->cpdate.year= rand() %(2020-2000+1)+2000;
                new_copy->borrow_date.day= 0;
                new_copy->borrow_date.month= 0;
                new_copy->borrow_date.year= 0;
                new_copy->Aob= true;
                new_copy->borrower="";
                new_copy->remaining_days=0;
                curr1->next= new_copy;
                new_copy->next= NULL;
                curr1= new_copy;
            }
        }
    }
    
    book_copy* delnode(string b_name)
    {
        book* listcurr= Head;
        while(listcurr!=NULL)
        {
            if(listcurr->book_name==b_name)
                break;
            listcurr=listcurr->next;
        }
        book_copy* save= listcurr->Front;
        listcurr->Front= listcurr->Front->next;
        //save->next= NULL;
        return save;
    }
    void insert_1(book_copy* save,string borrower_name,copy_date date)
    {
        save->borrower= borrower_name;
        save->borrow_date= date;
        save->Aob= false;
        save->remaining_days= 15;
        book_copy* temp= save->next;
        save->next=NULL;
        while(temp->next!=NULL)
            temp= temp->next;
        temp->next= save;
    }
    void borrow()
    {
        string name,borrower_name;
        copy_date date;
        cout<<"Enter the name of the book you wish to borrow: ";
        cin>>name;
        cout<<endl<<"Enter your name: ";
        cin>>borrower_name;
        cout<<endl<<"Enter borrowing date(Day/Month/Year): \n";
        cin>>date.day>>date.month>>date.year;
        cout<<endl;
        book* check= Head;
        while(check!=NULL)
        {
            if(check->book_name==name)
                break;
            check=check->next;
        }
        if(check==NULL)
            cout<<"The book is not found.\n";
        else
        {
            if(check->Front->Aob)
            {
                insert_1(delnode(name),borrower_name,date);
                check->borrow_counter++;
            }
            else
                cout<<"Book unavailable now. Please try again later.\n";
        }
    }
    void adding_book_return()
    {
        string b_name,borrower_name;
        cout<<"Enter the name of the book you wish to return: ";
        cin>>b_name;
        cout<<endl<<"Enter Your name: ";
        cin>>borrower_name;
        book* currbook= new book;
        currbook->book_name=b_name;
        book* curr= new book;
        curr= Head;
        book_copy* b_copy= new book_copy;
        b_copy->borrower= borrower_name;
        while(curr!=NULL)
        {
            if(curr->book_name==currbook->book_name)
                break;
            curr= curr->next;
        }
        if(curr==NULL)
        {
            cout<<"The book you have entered does not exist in the Library. Please, check the name and re_enter it\n";
            adding_book_return();
            return;
        }
        else
        {
            currbook= curr;
            b_copy= currbook->Front;
            while(b_copy!=NULL)
            {
                if(b_copy->borrower==borrower_name)
                    break;
                b_copy= b_copy->next;
            }
            if(b_copy==NULL)
            {
                cout<<"You did not borrow this book. (Your name does not match any borrower of the book)";
                return;
            }
            else
            {
                b_copy->borrow_date.day=0;
                b_copy->borrow_date.month=0;
                b_copy->borrow_date.year=0;
                b_copy->remaining_days=0;
                b_copy->Aob=true;
                if(currbook->Front->borrower!="")
                {
                    b_copy->borrower="";
                    book_copy* temp= currbook->Front;
                    currbook->Front=b_copy;
                    b_copy=temp;
                    book_copy* copy= currbook->Front;
                    while(copy->next!=NULL)
                        copy=copy->next;
                    copy->next= b_copy;
                    copy->next->next=NULL;
                    currbook->borrow_counter--;
                }
                else
                {
                    book_copy* check= currbook->Front;
                    while(check!=NULL)
                    {
                        if(check->next->borrower!="")
                        {
                            b_copy->borrower="";
                            book_copy* temp= check->next;
                            check->next=b_copy;
                            b_copy=temp;
                            book_copy* copy= currbook->Front;
                            while(copy->next!=NULL)
                                copy=copy->next;
                            copy->next= b_copy;
                            copy->next->next=NULL;
                            currbook->borrow_counter--;
                            break;
                        }
                        check=check->next;
                    }
                }
            }
        }
        
    }
    void inventory()
    {
        cout<<"Book name"<<'\t'<<"Book ISBN"<<'\t'<<"Number of copies"<<'\t'<<"Number of borrowed books"<<endl<<endl;
        book* curr= Head;
        while(curr!=NULL)
        {
            cout<<" "<<curr->book_name<<"\t\t\t\t"<<curr->book_isbn<<"\t\t\t\t"<<curr->no_of_copies<<"\t\t\t\t"<<curr->borrow_counter<<endl<<endl;
            curr=curr->next;
         }
    }
   void print()
    {
        book* curr= Head;
        while(curr!=NULL)
        {
            cout<<" Book name: "<<curr->book_name<<'\t'<<"Book ISBN: "<<curr->book_isbn<<'\t'<<endl;
            cout<<" Number of copies: "<<curr->no_of_copies<<'\t'<<endl;
            book_copy* queue_copy= curr->Front;
            while(queue_copy!=NULL)
            {
                cout<<" Copy date: "<<queue_copy->cpdate.day<<"\\"<<queue_copy->cpdate.month<<"\\"<<queue_copy->cpdate.year<<'\n';
                cout<<" Avaiblity: "<<queue_copy->Aob<<'\t'<<" Borower name: "<< queue_copy->borrower<<'\n';
                cout<<" Borowering date: "<<queue_copy->borrow_date.day<<"\\"<<queue_copy->borrow_date.month<<"\\"<<queue_copy->borrow_date.year<<'\n';
                cout<<" Remaining days: "<<queue_copy->remaining_days<<endl<<endl;
                queue_copy= queue_copy->next;
            }
        
            cout<<endl;
            curr=curr->next;
         }
    }
};

int main()
{
    linked_list A;
    
    A.insert();
    A.insert();
    A.insert();
    A.borrow();
    A.borrow();
    A.borrow();
    A.inventory();
    A.adding_book_return();
    A.print();
    return 0;
}
