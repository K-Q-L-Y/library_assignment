#ifndef LIST_UTILS_HPP
#define LIST_UTILS_HPP

#include <vector>
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
		Lst(const Lst& other);
		~Lst();
		
		// adding elements
		void add_front(const T& data);
		void add_back(const T& data);
		void add_at(int n, const T& data);
		
		// removing elements
		void remove_front();
		void remove_back();
		void remove_at(int index);
		
		// getter
		int get_size() const;
		T get(int index) const;
		int find(const T& data) const;
		vector<int> find_all(const T& data) const;
		bool contains(const T& data) const;
		
		// setter
		void set(int index, const T& data);
		
		Lst& operator=(const Lst& other);

		void print() const;
		void clear();
};

#include "lst_utils.tpp"
#endif
