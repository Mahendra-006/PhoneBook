#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;

struct node
{
    string name, number;
    node *next;
};

node *head = NULL, *newnode, *temp;
int len = 0;

void C_node()
{
    newnode = new node;
    cout<<"Enter the Name ";
    cin>>newnode->name;
    cout<<"Enter the Number ";
    cin>>newnode->number;
    newnode->next = NULL;
    if(head==NULL){
        head = temp = newnode;
    }
    else{
        temp->next = newnode;
        temp = newnode;
    }
}

void display ()
{
    if(head==NULL){
        cout<<"\t\tContact list is Empty "<<endl;
    }
    else{
        node *trav = head;
        while (trav != NULL){
            cout<<"\t\tFull Name "<<trav->name<<endl;
            cout<<"\t\tPhone Number "<<trav->number<<endl;
            trav = trav->next;
            len++;
        }
        cout<<"\t\tTotal Contacts In the List = "<<len<<endl;
    }
}

void search_contact ()
{
    node *search_n = head;
    string str;
    int count = 1;
    cout<<"Enter your Desired Contact you want to search";
    cin>>str;
    bool found = false;
    if(head == NULL){
        cout<<"\t\tList is Empty "<<endl;
    }
    else{
        while (search_n != NULL){
            if(str == search_n->name || str == search_n->number)
            {
                cout<<"\t\tFull Name: "<<search_n->name<<endl;
                cout<<"\t\tPhone Number: "<<search_n->number<<endl;
                found = true;
                break;
            }
            search_n = search_n->next;
            count++;
        }
    }
    if(found == true){
        cout<<"\t\tIndex of the contact = "<<count<<endl;
    }
    else{
        cout<<"\t\tDesired Contact Not found "<<endl;
    }
}

void delete_given_pos ()
{
    int pos;
    node *next_node;
    temp = head;
    cout<<"Enter your desired position from where you want to delete the contact.";
    cin>>pos;
    if(head==NULL){
        cout<<"\t\tList is Empty "<<endl;
    }
    else if (pos > len){
        cout<<"\t\tInvalid Position "<<endl;
    }
    else if (pos==0){
        temp = head;
        head = head->next;
        delete temp;
        cout<<"\t\tContact has been Deleted"<<endl;
    }
    else{
        for(int i=1; i<pos; i++){
            temp = temp->next;
        }
        next_node = temp->next;
        temp->next = next_node->next;
        delete next_node;
        cout<<"\t\tContact has been Deleted"<<endl;
    }
}

void menu ()
{
    cout << "Enter 1 to add contact "<<endl;
    cout << "Enter 2 to display all contact "<<endl;
    cout << "Enter 3 to Search Contact "<<endl;
    cout << "Enter 4 to Delete Contact from any Position"<<endl;
    cout << "Enter 5 to Exit PhoneBook"<<endl;
}

int main()
{
    int op;
    while (true)
    {
        menu();
        cin>>op;
        switch (op)
        {
            case 1:
                C_node();
                break;
            case 2:
                len = 0;
                display();
                break;
            case 3:
                search_contact();
                break;
            case 4:
                delete_given_pos();
                break;
            case 5:
                return 0;
            default:
                cout<<"Invalid Option "<<endl;
        }
    }

    return 0;
}