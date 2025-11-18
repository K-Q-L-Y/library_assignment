template <typename T>
Lst<T>::Lst() : head(nullptr), size(0) {}

template <typename T>
Lst<T>::~Lst() {
	cout << "Deleting linkedlist... ";
	clear();
	cout << "ok" << endl;
}

// adds node at first element
template <typename T>
void Lst<T>::add_front(const T& data) {
	Node<T> *new_node = new Node<T>(data);
	
	size++;
	if (!head) {
		head = new_node;
		return;
	}
	Node<T> *tmp = head;
	head = new_node;
	head->next = tmp;
}

// adds node at last element
template <typename T>
void Lst<T>::add_back(const T& data) {
	Node<T> *new_node = new Node<T>(data);
	
	size++;
	if (!head) {
		head = new_node;
		return;
	}
	Node<T> *tmp = head;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new_node;
}

// adds node at nth element
template <typename T>
void Lst<T>::add_at(int n, const T& data) {
	if (n < 0 || n > size) {
		throw (out_of_range("Index out of range"));
		return;
	}
	Node<T> *new_node = new Node<T>(data);

	size++;
	if (n == 0) {
		new_node->next = head;
		head = new_node;
		return;
	}
	Node<T> *tmp = head;
	for (int i = 0; i < n - 1; ++i)
		tmp = tmp->next;
	new_node->next = tmp->next;
	tmp->next = new_node;
}


// removes the first element
template <typename T>
void Lst<T>::remove_front() {
	if (!head) return;
	Node<T> *next = head->next;
	delete head;
	head = next;
	size--;
}

// removes the last element
template <typename T>
void Lst<T>::remove_back() {
	if (!head) return;
	Node<T> *tmp = head;
	while (tmp->next->next)
	tmp = tmp->next;
	delete tmp->next;
	tmp->next = nullptr;
	size--;
}

// removes the nth element
template <typename T>
void Lst<T>::remove_at(int n) {
	if (!head || n >= size) return;
	if (n == 0) return (remove_front());
	if (n == size - 1) return (remove_back());

	Node<T> *tmp = head;

	while (--n)
		tmp = tmp->next;
	Node<T> *next = tmp->next->next;
	delete tmp->next;
	tmp->next = next;
}

// clears the linkedlist
// frees allocated memory
template <typename T>
void Lst<T>::clear() {
	Node<T> *cur = head;
	while (cur) {
		Node<T> *next = cur->next;
		delete cur;
		cur = next;
	}
	head = nullptr;
	size = 0;
}

// prints the linkedlist
template <typename T>
void Lst<T>::print() const {
	Node<T> *tmp = head;
	while (tmp) {
		cout << tmp->data << "\n";
		tmp = tmp->next;
	}
}