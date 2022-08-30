#include <iostream>
using namespace std;

int first_length= 0;

template<typename T>
struct node
{
    T data;
    node* next;
};
template<typename T>
class linked_list
{
private:
    node<T> *head,*tail;
    int length;
public:
    linked_list()
    {
        head = tail = NULL;
        length=0;
    }
    node<T>* gethead()
    {
        return head;
    }
    void set_concate_tail_length()
    {
        length = first_length;
        node<T>* curr= head;
        while(curr->next!=NULL)
            curr= curr->next;
        tail= curr;
    }
    void insert(T n)
    {
        node<T>* newnode= new node<T>;
        newnode->data= n;
        if(length==0)
        {
            head= tail= newnode;
            tail->next=NULL;
        }
        else
        {
            tail->next=newnode;
            newnode->next= NULL;
            tail= newnode;
        }
        length++;
    }
    void insert_first(T n)
    {
        node<T>* newnode= new node<T>;
        newnode->data= n;
        if(length==0)
        {
            head=tail=newnode;
            tail->next=NULL;
        }
        else
        {
            newnode->next=head;
            head= newnode;
        }
        length++;
    }
    void insertPos(T data,int position)
    {
        if(position<0 || position>length)
            cout<<"Insertion out of bound\n";
        else if(position==0)
            insert_first(data);
        else if (position==length)  //check if length  or length-1
            insert(data);
        else
        {
            node<T>* curr= head;
            node<T>* newnode= new node<T>;
            newnode->data= data;
            for(int i=1;i<position;i++)
                curr= curr->next;
            newnode->next = curr->next;
            curr->next= newnode;
            length++;
        }
    }
    void delVal(T value)
    {
        node<T> *curr,*prev;
        if(length==0)
        {
            cout<<"List is empty\n";
        }
        else if(head->data==value)
        {
            curr=head;
            head= head->next;
            delete curr;
            length--;
            if(length==0)
                tail=NULL;
        }
        else
        {
            prev= head;
            curr= head->next;
            while(curr!=NULL)
            {
                if(curr->data==value)
                    break;
                prev= curr,curr= curr->next;
            }
            if(curr==NULL)
                cout<<value<<" Not found\n";
            else
            {
                prev->next= curr->next;
                if(tail==curr)
                    tail=prev;
                delete curr;
                length--;
            }
        }
    }
    void delFirst()
    {
        if(length==0)
            cout<<"List is empty\n";
        else if(length==1)
        {
            delete head;
            head=tail=NULL;
            length--;
        }
        else
        {
            node<T>* curr= head;
            head = head->next;
            delete curr;
            length--;
        }
    }
    void delLast()
    {
        if(length==0)
            cout<<"List is empty\n";
        else if(length==1)
        {
            delete head;
            head=tail=NULL;
            length--;
        }
        else
        {
            node<T>* curr= head;
            while(curr->next!=NULL)
                curr=curr->next;
            tail=curr;
            tail->next=NULL;
            curr=curr->next;
            delete curr;
            length--;
        }
    }
    void deletePos(int position)  // Test it to check the algorithm
    {
        if(position<0 || position>length)
            cout<<"deletion out of bound";
        else if(position==0)
            delFirst();
        else if(position==length)
            delLast();
        else
        {
            node<T>* curr=head;
            for(int i=1;i<position;i++)
                curr=curr->next;
            curr->next= curr->next->next;
            curr= curr->next;
            delete curr;
            length--;
        }
    }
    void static concatenate(node<T>* a,node<T>* b)
    {
        node<T>* first_tail= a;
        while(first_tail->next!=NULL)
        {
            first_tail= first_tail->next;
            first_length++;
        }
        first_tail->next= b;
        while(first_tail->next!=NULL)
        {
            first_tail= first_tail->next;
            first_length++;
        }
        first_length++;
       // set_length_tail(first_length, first_tail);
    }
    void static printLL(node<T>* head)
    {
        node<T>*curr=head;
        while(curr!=NULL)
        {
            cout<<curr->data<<'\t';
            curr=curr->next;
        }
        cout<<endl;
    }
    ~linked_list()
    {
        node<T>* curr= head;
        node<T>* destroy=NULL;
        while(destroy!=NULL)
        {
            destroy= curr;
            curr= curr->next;
            delete destroy;
        }
        curr=NULL;
        delete curr;
        length=0;
        head=tail=NULL;
    }
};

int main()
{
    linked_list<float> list1,list2;
    list1.insert(1);
    list1.insert(2);
    list1.insertPos(3,2);
    list1.insertPos(2.5,2);
    list2.insert(5);
    linked_list<float>::concatenate(list2.gethead(), list1.gethead());
    list2.set_concate_tail_length(); 
    linked_list<float>::printLL(list2.gethead());
    list2.insert(15);
    list2.insert(22);
    list2.insertPos(25, 7);
    list2.delVal(1);
    linked_list<float>::printLL(list2.gethead());
    return 0;
}
