/* ///////////////////////////////////////////////////////////////////
	Archivo: protected_priority_queue.h
	Descripción:
	[Lucas Alexis Rack]
	[Facultad de Ingeniería]
	[Universidad de Buenos Aires]
   /////////////////////////////////////////////////////////////////// */
#ifndef _PROTECTED_PRORITY_QUEUE_
#define _PROTECTED_PRORITY_QUEUE_

#include <mutex>
#include <queue>

template <class T>
class ProtectedPriorityQueue{
private:
	std::priority_queue<T> queue;
	std::mutex mutex;
public:
	ProtectedPriorityQueue();
	~ProtectedPriorityQueue();
	T top();
	void push(T);
	void pop();
	bool empty();
};

template <class T>
ProtectedPriorityQueue<T>::ProtectedPriorityQueue(){}

template <class T>
ProtectedPriorityQueue<T>::~ProtectedPriorityQueue(){}

template <class T>
T ProtectedPriorityQueue<T>::top(){
	std::unique_lock<std::mutex> lock{mutex};
	return queue.top();
}

template <class T>
void ProtectedPriorityQueue<T>::push(T val){
	std::unique_lock<std::mutex> lock{mutex};
	queue.push(val);	
}

template <class T>
void ProtectedPriorityQueue<T>::pop(){
	std::unique_lock<std::mutex> lock{mutex};
	queue.pop();	
}

template <class T>
bool ProtectedPriorityQueue<T>::empty(){
	std::unique_lock<std::mutex> lock{mutex};
	return queue.empty();
}
#endif
