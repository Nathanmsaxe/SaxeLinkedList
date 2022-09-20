/*
 * LL.h
 *
 *  Created on: Sep 7, 2022
 *      Author: Nathan Saxe
 */

#ifndef LL_H_
#define LL_H_

#include "Student.hpp"

struct LLnode{

	LLnode * fwdPtr;

	Student theData;
};
template<class Data>
class LL {
private:
	LLnode * fwdPtr;
public:
	LL();
	void push_front(Data);
	void push_back(Data);
	LLnode* newNode(Data);
	LLnode* pushBackRecursive(LLnode*, Data);
	int list_length();
	int listLengthRecursive(LLnode*);
	Student retrieve_front();
	Student retrieve_back();
	void display_list();
	void destroy_list();
	void destroyListRecursive(LLnode*);
	Data search_list(int);
	bool deleteNodeRecursive(LLnode*, LLnode*, LLnode*, LLnode*, int);
	bool delete_node(int);
};

#endif /* LL_H_ */
