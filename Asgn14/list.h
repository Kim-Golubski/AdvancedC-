#ifndef LIST_H
#define LIST_H

#include "ListNode.h"
#include <iostream>

template<typename NODETYPE>
class List
{
public:
	~List()
	{
		if (!isEmpty())
		{
			std::cout << "Destoying nodes ...\n";

			ListNode<NODETYPE>* currentPtr{ firstPtr };
			ListNode<NODETYPE>* tempPtr{ nullptr };

			while (currentPtr != nullptr)
			{
				tempPtr = currentPtr;
				std::cout << tempPtr->data << '\n';
				currentPtr = currentPtr->nextPtr;
				delete tempPtr;
			}
		}

		std::cout << "All nodes detroyed\n\n";
	}

	void insertAtFront(const NODETYPE& value)
	{
		ListNode<NODETYPE>* newPtr{ getNewNode(value) };

		if (isEmpty())
		{
			firstPtr = lastPtr = newPtr;
		}
		else
		{
			newPtr->nextPtr = firstPtr;
			firstPtr = newPtr;
		}
	}

	void insertAtBack(const NODETYPE& value)
	{
		ListNode<NODETYPE>* newPtr{ getNewNode(value) };

		if (isEmpty())
		{
			firstPtr = lastPtr = newPtr;
		}
		else
		{
			lastPtr->nextPtr = newPtr;
			lastPtr = newPtr;
		}
	}

	void insertAtLocation(const NODETYPE& value, int pos)
	{
		ListNode<NODETYPE>* newPtrA{ getNewNode(value) };

		if (pos < 1)
		{
			std::cout << "\nPosition should be >= 1.\n";
		}
		else if (pos == 1)
		{
			newPtrA->nextPtr = firstPtr;
			firstPtr = newPtrA;
		}

		else
		{
			ListNode<NODETYPE>* newPtrB = firstPtr;
			for (int i = 1; i < pos - 1; i++)
			{
				if (newPtrB != NULL)
				{
					newPtrB = newPtrB->nextPtr;
				}
			}
			if (newPtrB != NULL)
			{
				newPtrA->nextPtr = newPtrB->nextPtr;
				newPtrB->nextPtr = newPtrA;
			}
			else
			{
				std::cout << "Position is larger than list length\n";
			}
		}


	}

	bool removeFromFront(NODETYPE& value)
	{
		if (isEmpty())
		{
			return false;
		}
		else
		{
			ListNode<NODETYPE>* tempPtr{ firstPtr };

			if (firstPtr == lastPtr)
			{
				firstPtr = lastPtr = nullptr;
			}
			else
			{
				firstPtr = firstPtr->nextPtr;
			}
			value = tempPtr->data;
			delete tempPtr;
			return true;
		}
	}

	bool removeFromBack(NODETYPE& value)
	{
		if (isEmpty())
		{
			return false;
		}
		else
		{
			ListNode<NODETYPE>* tempPtr{ lastPtr };

			if (firstPtr == lastPtr)
			{
				firstPtr = lastPtr = nullptr;
			}
			else
			{
				ListNode<NODETYPE>* currentPtr{ firstPtr };

				while (currentPtr->nextPtr != lastPtr)
				{
					currentPtr = currentPtr->nextPtr;
				}
				lastPtr = currentPtr;
				currentPtr->nextPtr = nullptr;
			}
			value = tempPtr->data;
			delete tempPtr;
			return true;
		}
	}

	bool removeValue(NODETYPE& value)
	{
		if (isEmpty())
		{
			return false;
		}
		//get count
		ListNode<NODETYPE>* temp = firstPtr;
		ListNode<NODETYPE>* prev = NULL;
		while (temp != NULL)
		{
			if (temp->getData() == value)
			{
				firstPtr = temp->nextPtr;
				return true;
			}
			else
			{
				try
				{
					if (temp->nextPtr == NULL)
						throw "Value does not exist";
					else if (temp->nextPtr->data == value)
					{
						temp->nextPtr = temp->nextPtr->nextPtr;
						return true;
					}
					else
					{
						temp = temp->nextPtr;
					}
				}
				catch (const char* nullPtr)
				{
					std::cout << "Value does not exist\n";
					return false;
				}
			}

		}
		if (temp == NULL)
		{
			return false;
		}
	}

	bool isEmpty() const
	{
		return firstPtr == nullptr;
	}

	void print() const
	{
		if (isEmpty())
		{
			std::cout << "The list is empty \n\n";
			return;
		}

		ListNode<NODETYPE>* currentPtr{ firstPtr };
		std::cout << "The list is: ";
		while (currentPtr != nullptr)
		{
			std::cout << currentPtr->data << ' ';
			currentPtr = currentPtr->nextPtr;
		}

		std::cout << "\n\n";
	}

	int search(int key)
	{
		ListNode<NODETYPE>* currentPtr{ firstPtr };
		int pos{1};
		while (currentPtr != NULL)
		{
			if (currentPtr->data== key)
			{
				return pos;
			}
			else
			{
				currentPtr = currentPtr->nextPtr;
				pos++;
			}
		}
		return -1;
	}

	ListNode<NODETYPE>* middleNode()
	{
		ListNode<NODETYPE>* head = firstPtr;
		ListNode<NODETYPE>* tail = lastPtr;

		ListNode<NODETYPE>* slow = head;
		ListNode<NODETYPE>* fast = head->nextPtr;
		while (fast != tail)
		{
			fast = fast->nextPtr;
			if (fast != tail)
			{
				slow = slow->nextPtr;
				fast = fast->nextPtr;
			}
		}
		return slow;
	}

	ListNode<NODETYPE>* binarySearch(ListNode<NODETYPE>* head, NODETYPE &value)
	{
		ListNode<NODETYPE>* start = head;
		ListNode<NODETYPE>* last = NULL;
		do
		{
			ListNode<NODETYPE> *mid = middleNode();
			if (mid == NULL)
			{
				return NULL;
			}
			if (mid->data == value)
			{
				return mid;
			}
			else if (mid->data < value)
			{
				start = mid->nextPtr;
			}
			else
			{
				last = mid;
			}
		} while ((last == NULL) || (last != start));
		return NULL;
	}

	void selectionSort()
	{
		ListNode<NODETYPE>* temp{ firstPtr };

		while (temp)
		{
			ListNode<NODETYPE>* min = temp;
			ListNode<NODETYPE>* next = temp->nextPtr;

			while (next)
			{
				if (min->data > next->data)
					min = next;
				next = next->nextPtr;
			}
			int x = temp->data;
			temp->data = min->data;
			min->data = x;
			temp = temp->nextPtr;
		}
	}

	void mergeSort(ListNode<NODETYPE>** headRef)
	{
		ListNode<NODETYPE>* head{ *headRef };
		ListNode<NODETYPE>* a;
		ListNode<NODETYPE>* b;
		
		if ((head == NULL) || (head->nextPtr == NULL))
		{
			return;
		}

		splitList(firstPtr , &a, &b);
		mergeSort(&a);
		mergeSort(&b);

		*headRef = sortedMerge(a, b);
	}
	
	ListNode<NODETYPE>* sortedMerge(ListNode<NODETYPE>* a, ListNode<NODETYPE>* b)
	{
		ListNode<NODETYPE>* result = NULL;

		if (a == NULL)
			return(b);
		if (b == NULL)
			return (a);

		if (a->data <= b->data)
		{
			result = a;
			result->nextPtr = sortedMerge(a->nextPtr, b);
		}
		else
		{
			result = b;
			result->nextPtr = sortedMerge(a, b->nextPtr);
		}
		return (result);
	}


	void splitList(ListNode<NODETYPE>* source, ListNode<NODETYPE>** a, ListNode<NODETYPE>** b)
	{
		ListNode<NODETYPE>* slow = source;
		ListNode<NODETYPE>* fast = source->nextPtr;

		while (fast != NULL)
		{
			fast = fast->nextPtr;
			if (fast != NULL)
			{
				slow = slow->nextPtr;
				fast = fast->nextPtr;
			}
		}
		*a = source;
		*b = slow->nextPtr;
		slow->nextPtr = NULL;
	}
	ListNode<NODETYPE>* getFirstNode()
	{
		return firstPtr;
	}
private:
	ListNode<NODETYPE>* firstPtr{ nullptr };
	ListNode<NODETYPE>* lastPtr{ nullptr };
	ListNode<NODETYPE>* nextPtr{ nullptr };

	ListNode<NODETYPE>* getNewNode(const NODETYPE& value)
	{
		return new ListNode<NODETYPE>{ value };
	}
};



#endif
