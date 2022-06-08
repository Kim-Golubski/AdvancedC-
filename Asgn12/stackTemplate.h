#ifndef STACKTEMPLATE_H
#define STACKTEMPLATE_H

#include <vector>
#include <iostream>
template<typename T>
class Stack
{
public:
	void push(const T& pushValue)
	{
		vector.push_back(pushValue);
	}
	const T pop()
	{
		const T front = top();
		
		vector.erase(vector.begin());
			
		return front;
	}
	const T& top()
	{
		return vector.front();
	}
	void clear()
	{
		vector.clear();
	}
	bool isEmpty() const
	{
		return vector.empty();
	}

private:
	std::vector<T> vector;
};
#endif // !STACKTEMPLATE_H
