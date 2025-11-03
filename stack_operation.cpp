#include<iostream>
#define size 5
using namespace std;
class stack
{
    public:
    int s[5];
    int top,item;
    int pos,item1;
    stack()
    {
        top=-1;
    }

    void push()
    {
        if(top==size-1)
        {
            cout<<"\nStack is full\n";
        }
        else
        {
            top++;
            s[top]=item;
        }
        
    }

    void pop()
    {
        if(top==-1)
        {
            cout<<"\nstack is empty\n";
        }
        else
        {
            cout<<"\n element deleted is:"<<s[top]<<"\n";
            top--;
        }
    }

    void insert()
    {
        if(top==-1)
        {
            cout<<"stack is empty\n";
        }
        else if(top==size-1)
        {
            cout<<"\nstack is full\n";
        }
        else
        
        {
            top++;
            for(int i=top;i>=0;i--)
            {
                if(i>=pos-1)
                {
                    s[i+1]=s[i];
                }
            }
            s[pos-1]=item1;
        }
        
    }

    void display()
    {
        if(top==-1)
        {
          cout<<"stack is empty\n";  
        }
        else
        {
            for(int i=0;i<=top;i++)
            {
                cout<<"\nstack element : "<<i<<" is : "<<s[i]<<"\n";
            }
    }
    }

    void peek()
    {
        cout<<"\ntop element present in stack:"<<s[top]<<"\n";
    }
};

int main()
{
    stack st;
    int choice;
    for(;;)
    {
        cout<<"\n1.Add\n2.delete\n3.insert at position\n4.display\n5.top element\n";
        cout<<"\n enter the chooice : ";
        cin>>choice;
        cout<<"\n";
        switch(choice)
        {
            case 1:
            cout<<"\n Enter the element to be inserted:";
            cin>>st.item;
            st.push();
            break;

            case 2:
            st.pop();
            break;

            case 3:
            st.insert();
            cout<<"\n enter position to be inserted:";
            cin>>st.pos;
            cout<<"\n";
            cout<<"enter the element to be insert:";
            cin>>st.item1;
            cout<<"\n";
            
            break;

            case 4:
            st.display();
            break;

            case 5:
            st.peek();
            break;

            default:exit(0);


        }
    }
    return 0;
}