#include "LL.h"
#include <iostream>
using namespace std;
template<class Data>
LL<Data>::LL(){
	// TODO Auto-generated constructor stub
	this->fwdPtr = nullptr;
}
template<class Data>
void LL<Data>::push_front(Data data){
	cout <<"in push front" << endl;
	LLnode * newNode = new LLnode; //creates new node
	LLnode * temp; // creates temporary node pointer
	newNode->theData = data; // stores data in new node
	temp = this->fwdPtr; // sets temporary node pointer to where header points to
	this->fwdPtr = newNode; //sets header to point to new node
	newNode->fwdPtr = temp; // sets new node to point to where the header had pointed to

}
template<class Data>
LLnode* LL<Data>::newNode(Data data){
	LLnode * newNode = new LLnode;
	newNode->theData = data;
	newNode->fwdPtr = nullptr;
	return newNode;
}
template<class Data>
LLnode* LL<Data>::pushBackRecursive(LLnode* head, Data data){
	if(head == nullptr){
		return newNode(data);
	}
	else{
		head->fwdPtr = pushBackRecursive(head->fwdPtr, data);
	}
	return head;
}
template<class Data>
void LL<Data>::push_back(Data data){
	LLnode * temp;
	temp = this->fwdPtr;
	pushBackRecursive(temp, data);
}
template<class Data>
int LL<Data>::listLengthRecursive(LLnode* temp){
	if(temp==nullptr){
		return 0;
	}
	else{
		return 1+listLengthRecursive(temp->fwdPtr);
	}
}
template<class Data>
int LL<Data>::list_length(){
	LLnode * temp;
	temp = this->fwdPtr;

	return listLengthRecursive(temp);

}
template<class Data>
Student LL<Data>::retrieve_front(){
	if(this->fwdPtr == nullptr){
		throw 'A';
	}
	else{
		return this->fwdPtr->theData;
	}
}
template<class Data>
Student LL<Data>::retrieve_back(){
	while(this->fwdPtr->fwdPtr!=nullptr){
		this->fwdPtr = this->fwdPtr->fwdPtr;
	}
	return this->fwdPtr->theData;
}
template<class Data>
void LL<Data>::display_list(){
	LLnode * temp;
	temp = this->fwdPtr;
	int counter = 0;
	if(temp!=nullptr){
		while(temp != nullptr){
			counter++;
			cout << "node " << counter << " address -> " << temp << " Student Name:" << temp->theData.data << " Student ID: " << temp->theData.key << endl;
			temp = temp->fwdPtr;
		}
	}
	else{
		cout << "Empty List" << endl;
	}
}
template<class Data>
void LL<Data>::destroyListRecursive(LLnode * temp){
	if(temp!=nullptr){
		temp = this->fwdPtr->fwdPtr;
		delete this->fwdPtr;
		this->fwdPtr = temp;
		destroyListRecursive(temp);
	}
}
template<class Data>
void LL<Data>::destroy_list(){
	LLnode * temp;
	temp = this->fwdPtr;
	destroyListRecursive(temp);
}
template<class Data>
Data LL<Data>::search_list(int targetKey){
	LLnode* temp;
	temp = this->fwdPtr;
	while(temp!=nullptr){
		if(temp->theData.key == targetKey){
			cout << "Student Found!" << endl;
			return temp->fwdPtr->theData;
		}
		else{
			temp = temp->fwdPtr;
		}

	}
	Student null;
	null.data = "";
	null.key = 0;
	return null;
}
template<class Data>
bool LL<Data>::deleteNodeRecursive(LLnode* temp, LLnode* prevPtr, LLnode* currentPtr, LLnode* nextPtr, int targetKey){
	if(targetKey == temp->theData.key){
		if(prevPtr==nullptr && currentPtr!=nullptr){
			this->fwdPtr = nextPtr;
			delete currentPtr;
			return true;
		}
		else if(prevPtr!=nullptr && nextPtr!=nullptr){
			prevPtr->fwdPtr = nextPtr;
			delete currentPtr;
			return true;
		}
		else if(nextPtr == nullptr && currentPtr != nullptr){
			prevPtr->fwdPtr = nullptr;
			delete currentPtr;

			return true;
		}
		else if(currentPtr == nullptr){
			string temp = "list empty";
			throw temp;
			return false;
		}
	}
	else{
		if(temp->fwdPtr!=nullptr){
			prevPtr = temp;
			currentPtr = temp->fwdPtr;
			nextPtr = temp->fwdPtr->fwdPtr;
			temp = temp->fwdPtr;
			return deleteNodeRecursive(temp, prevPtr, currentPtr, nextPtr, targetKey);
		}
		else{
			return false;
		}
	}
	return false;

}
template<class Data>
bool LL<Data>::delete_node(int targetKey){

	LLnode * temp = this->fwdPtr;
	LLnode * prevPtr = nullptr;
	LLnode * currentPtr = this->fwdPtr;
	LLnode * nextPtr = this->fwdPtr->fwdPtr;

	return deleteNodeRecursive(temp, prevPtr, currentPtr, nextPtr, targetKey);
}
