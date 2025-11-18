#ifndef LIST_UTILS_HPP
#define LIST_UTILS_HPP

using namespace std;

// node class
// allows variable data type
template <typename T>
class Node {
	public:
		T data;
		Node *next;
		Node(const T &data) : data(data), next(nullptr) {}
};

// linkedlist class
template <typename T>
class Lst {
	private:
		Node<T> *head;
		int size;
	public:
		Lst();
		~Lst();

		void add_front(const T& data);
		void add_back(const T& data);
		void add_at(int n, const T& data);
		void print() const;
		void remove_front();
		void remove_back();
		void clear();
};

#include "lst_utils.tpp"
#endif