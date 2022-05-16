/*Linked list
*Code by Luka guraspashvili.
*This program takes users name of choice and stores it in a linked list.
*Then we can display these elements with the next pointers and values.
*I added a search function to search for a name in a linked list;
*Lastly we free all the memory we allocated(tested with valgrind, no memory leaks!) and say thank you!
*may 15th 2022. Thank you!
*/


#include <iostream>

using namespace std;

void get_user_input(string * name)
{
    cout<<"Enter a name you want to store in a linked list and hit (enter) if done type (done) and hit enter or to search in a list type (search):";
    cin>>*name;

}
//linked list node
class node
{
    public:
    string value;
    node * next;
};

//This function searches for a name in a linked list
void search_list(node * head_node)
{
    string * tmp=new string;
    cout<<"Enter a name you want to search and hit enter:";
    cin>>*tmp;
    if(tmp!=NULL)
    {
        for(node * n=head_node;n!=NULL;n=n->next)
        {
            if(head_node->value==*tmp)
            {
                cout<<*tmp<<" is in the list!"<<endl;
                return;
            }    
        }    
    }
    cout<<*tmp<<" not in the list"<<endl;
    delete tmp;
}




//we free memory
void delete_list(node * tmp)
{
    if(tmp==NULL)
    {
        return;
    }
    delete_list(tmp->next);
    delete tmp;
}

//This function will let us print a linked list
void print_list(node * tmp)
{
    if(tmp!=NULL)
    {
        for(node * n=tmp;n!=NULL;n=n->next)
        {
            cout<<n->value<<" "<<n<<"------->";    
        }    
    }
    cout<<""<<endl;
}



int main()
{
    bool noprint=false;
    string * user_input = new string;
    //Head of a linked list
    node * head=NULL;
    // This is how we store values in a list 
    while(true)
    {
        get_user_input(user_input);
        if(*user_input=="done")
        {
            break;
        }
        if(*user_input=="search")
        {
            noprint=false;
            search_list(head);
            break;
        }
        if(head==NULL)
        {
            head = new node;
            head->value=*user_input;
            head->next=NULL;
        }
        else
        {
            node * tmp=new node;
            tmp->value=*user_input;
            tmp->next=head;
            head=tmp;
        }

    }
    if(noprint)
    {
        print_list(head);
    }   
    cout<<"Thank's for running me, see ya!"<<endl;
    //We free the allocated memory for the list
    delete_list(head);
    delete user_input;
}
