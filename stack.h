#ifndef STACK_H
#define STACK_H

#include <iostream>

using namespace std;

template <class T>
class Stack{
	public:
		Stack(int size=100):first(0),end(0){

			items=new T[size];
			this->size = size;
		}
		void push(T value){	
			if(end<size)
				items[end++]=value;
			else
				cout<<"stack is full"<<endl;
		}
		T& pop(){	
			if(first!=end)
				return items[--end];
			else
				cout<<"stack is empty"<<endl;
		}

		void show();
		~Stack(){
			delete [] items;
		}
	private:
		int first;
		int end;
		int size;
		T *items;

};


template <class T>
void Stack<T>::show(){
	int i=0;
	for(i=first;i<end;++i)
		cout<<""<<items[i]<<endl;
}

#endif
