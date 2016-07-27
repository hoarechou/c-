#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <string>

using namespace std;

template <class T>
	struct __list_node{
		struct __list_node<T> *next;
		T data;
};

template <class T>
class List{
	public:

		typedef __list_node<T> list_node;
		typedef list_node* link_type;
		void empty_init();
		List(){empty_init();}
		List(T data);

		void push_back(T data);
		void push_front(T data);
		T back();
		void show();
		void display();
		link_type node;

		void reverse();

};

template <class T>
void List<T>::empty_init(){
	node = new list_node;
	node->next=NULL;
}

template <class T>
List<T>::List(T data)
{
	empty_init();
	push_back(data);
}

template <class T>
void List<T>::reverse(){
	link_type prev = NULL;
	link_type head = node->next;

	while(head!=NULL){
		link_type next = head->next;
		head->next = prev;

		prev= head;
		head=next;
	}
	node->next=prev;

}
template <class T>
void List<T>::push_back(T data)
{
	link_type head = node;
	link_type new_node = new list_node;
	new_node->data = data;

	while(head->next != NULL){
		head = head->next;
	}

	head->next = new_node;

}	
template <class T>
void List<T>::push_front(T data)
{

	link_type head = node;
	link_type new_node = new list_node;
	new_node->data = data;

	new_node->next = head->next;
	head->next = new_node;

}
template <class T>
T List<T>::back()
{
	link_type head = node;

	while(head->next != NULL)
		head = head->next;
 	
	return head->data;
}

template <class T>
void List<T>::show()
{
	link_type head = node;

	while(head->next!= NULL){
		head=head->next;
		cout<<"data:"<<head->data<<endl;
	}	


}
template <class T>
void List<T>::display() {
	link_type list = node;
	while(list->next!=NULL) {
		cout << list->data << " ";
		list = list->next;
	}
	cout << endl;
	cout << endl;
}


#endif
