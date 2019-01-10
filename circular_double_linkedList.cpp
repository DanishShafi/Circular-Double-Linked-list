#include<iostream>
using namespace std;
/*

	Insertion front
	Insertion center
	Search
	Deletion front
	Dleletion center

*/
struct node{
	int info;
	node *temp;
	node *next;
	node *prev;
};

class Linked_List
{
	private:
		node *head, *temp, *ptr, *ptr1;;
	public:
		Linked_List()
		{
			head = NULL;
			temp = NULL;
		}
		
		int insert_front(int x)
		{
			if(head==NULL)
			{
				head=new node();
				head->info=x;
				head->next=head->prev=head;
				return 0;
			}
				ptr=head;
				while(ptr->next!=head)
				{
					ptr=ptr->next;
				}
				temp=new node();
				temp->info=x;
				temp->next=head;
				temp->prev=head->prev;
				temp->next->prev=temp;
				head=temp;
				ptr->next=head;
				
		}
		
		int search(int x)
		{
			temp=head;
			while(temp->next!=head)
			{
				if(temp->info==x)
				{
					cout<<"found value = "<< x <<endl;
				}
				temp=temp->next;
			}
		}
		
		int insert_middle(int x, int key)
		{
			temp=head;
			while(temp->next!=head)
			{
				if(temp->info==key)
				{
					temp->next=ptr1;
					ptr=new node();
					ptr->info=x;
					temp->next=ptr;
					ptr->prev=temp;
					ptr1->prev=ptr;
					ptr->next=ptr1;
				}
				temp=temp->next;
			}
		}
		void print()
		{
			temp=head;
			while(temp->next != head)
			{
				cout<<temp->info<<" ";
				temp=temp->next;
			}
			cout<<endl;
		}
		
		
};

int main(){
	
	Linked_List l;
	l.insert_front(1);
	l.insert_front(2);
	l.insert_front(3);
	l.insert_front(5);
	l.insert_front(6);
	l.print();
	
	l.search(6);
	
	l.insert_middle(4,5);
	l.print();
	return 0;
}

