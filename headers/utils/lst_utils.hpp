#ifndef LIST_UTILS_HPP
#define LIST_UTILS_HPP

using namespace std;

template <typename T>
class Node {
	public:
		T data;
		Node *next;
		Node(const T &data) : data(data), next(nullptr) {}
};

template <typename T>
class Lst {
	private:
		Node<T> *head;
	public:
		Lst() : head(nullptr) {}
		~Lst() {
			// clear();
		}

		void add_back(const T& data) {
			Node<T> *new_node = new Node<T>(data);
			
			if (!head) {
				head = new_node;
				return;
			}
			Node<T> *tmp = head;
			while (tmp->next)
				tmp = tmp->next;
			tmp->next = new_node;
		}

		void print() const {
			Node<T> *tmp = head;
			while (tmp) {
				cout << tmp->data << "\n";
				tmp = tmp->next;
			}
			cout << endl;
		}
};

#endif