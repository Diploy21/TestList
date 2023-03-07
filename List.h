#pragma once


template <typename T>
class List 
{
public:
	List();
	~List();
	void push_back(T data);
	int GetSize() { return Size; };
	T& operator[](const int index);
	void pop_front();
	void clear();
	void push_front(T data);
	void insert(T data, int index);
	void removeAt(int index);

private:

	template <typename T>
	class Node
	{
	public:
		Node* pNext;
		T data;

		Node(T data = T(), Node* pNext = nullptr)
		{
			this->data = data;
			this->pNext = pNext;
		}
	};

	int Size;
	Node<T> *head;
};


template <typename T>
List<T>::List()
{
	Size = 0;
	head = nullptr;
}

template <typename T>
List<T>::~List()
{
	clear();
}

template <typename T>
void List<T>::push_back(T data)
{
	if (head == nullptr)
	{
		head = new Node<T>(data);
	}
	else
	{
		Node<T>* temp = this->head;

		while (temp->pNext != nullptr)
		{
			temp = temp->pNext;
		}
		temp->pNext = new Node<T>(data);
	}
	Size++;
}

template <typename T>
T & List<T>::operator[](const int index)
{
	int counter = 0;
	Node<T>* temp = this->head;
	while (temp != nullptr)
	{
		if (counter == index)
		{
			return temp->data;
		}
		temp = temp->pNext;
		counter++;
	}
}

template<typename T>
void List<T>::pop_front()
{
	Node<T>* temp = head;
	head = head->pNext;
	delete temp;
	Size--;
}

template<typename T>
inline void List<T>::clear()
{
	while (Size)
	{
		pop_front();
	}
}

template<typename T>
inline void List<T>::push_front(T data)
{
	head = new Node<T>(data, head);
	Size++;
}

template<typename T>
inline void List<T>::insert(T data, int index)
{
	if (!index)
	{
		push_front(data);
	}
	else
	{
		Node<T>* prev = this->head;
		for (int i = 0; i < index - 1; i++)
		{
			prev = prev->pNext;
		}
	
		prev->pNext = new Node<T>(data, prev->pNext);
	}
	Size++;
}

template<typename T>
inline void List<T>::removeAt(int index)
{
	if (!index)
	{
		pop_front();
	}
	else
	{
		Node<T>* prev = this->head;
		for (int i = 0; i < index - 1; i++)
		{
			prev = prev->pNext;
		}

		Node<T>* pDelete = prev->pNext;
		prev->pNext = pDelete->pNext;
		
		delete pDelete;
	}
	Size--;
}

int menu();
void logic(List<int>&, int&, bool&);
void output(List<int>& ls);
void ListMenu();

