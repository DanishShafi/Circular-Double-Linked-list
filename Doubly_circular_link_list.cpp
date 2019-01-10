#include <iostream>
using namespace std;

struct node{
	int value;
	node *next;
	node *pervious;
};

class Doubly_circular_Link_list
{
	private:
		node *head;
		node *temp;
		node *ptr;
	public:
		Doubly_circular_Link_list()
		{
			head = NULL;
			temp = NULL;
			ptr = NULL;
		}	
		int MakingOfIt()
		{
			cout << "Enter the Value" << endl;
			for(int i =0; i <10; i++)
			{

				if(head == NULL)
				{
					head = new node; 
					cin >> head->value ;
					head->next = head;
					head->pervious = head;
					temp = head;
				}
				else{
					ptr = temp;
					temp -> next = new node ;
					temp = temp -> next;
					temp -> next = head;
					temp -> pervious = ptr;
					cin >> temp -> value;
					head -> pervious = temp;
				}
				

			}
		}

		int insert_at(){
			cout << endl;
			temp = head;
			int key;
			cout << "Enter the Number at which you want to insert" << endl;
			cin >> key;

			do{
				if(key == temp -> value)
				{
					ptr = new node;
					temp->pervious->next = ptr;
					ptr ->pervious = temp ->pervious;
					ptr ->next = temp;
					temp->pervious = ptr;
					cout << temp -> pervious -> next -> value  << endl;
					cout << "Enter the value " << endl;
					cin >> ptr -> value;
					
				}
				temp = temp -> next;
				cout << "There is value of temp " << temp->value << endl;
			}while(temp != head);

		if (key == head -> value ){
					head = ptr;
		}
	}


		int delete_at(){
			cout << endl;
			temp = head;
			int key;
			cout << "Enter the Number which you want to delete" << endl;
			cin >> key;
			do 
			{
				if(key == temp ->value)
				{
					if (key == head -> value ){
						head = head ->next;
					}
					ptr = temp;
					temp = temp -> pervious;
					temp ->next = temp ->next ->next;
					temp ->next ->next ->pervious = temp;
					delete	ptr;
					ptr = NULL;
				}
				temp = temp -> next;
			}
			while(temp != head);
		}


		int Printing_of_Doubly_list()
		{
			temp = head;
			cout << "Enter are required Values" << endl;
			for (int i = 0; i <10; i++)
			{
				cout << temp -> value << " ";	
				temp = temp ->next;
			}


			
		}

		int Memory_free(){
			delete head;
			delete temp;
			delete ptr;
		}

};

int main(){
	Doubly_circular_Link_list D1;
	D1.MakingOfIt();
	D1.Printing_of_Doubly_list();
	D1.delete_at();
	D1.Printing_of_Doubly_list();
	D1.insert_at();
	D1.Printing_of_Doubly_list();
	D1.Memory_free();
}



















