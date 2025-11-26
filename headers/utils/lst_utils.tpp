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
	
	++size;
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
	
	++size;
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
	if (n < 0 || n > size)
		throw out_of_range("Index out of range");

	Node<T> *new_node = new Node<T>(data);

	size++;
	if (n == 0) {
		new_node->next = head;
		head = new_node;
		return;
	}

	Node<T> *cur = head;
	for (int i = 0; i < n - 1; ++i)
		cur = cur->next;
	new_node->next = cur->next;
	cur->next = new_node;
}


// removes the first element
template <typename T>
void Lst<T>::remove_front() {
	if (!head)
		return;

	Node<T> *next = head->next;
	delete head;
	head = next;
	--size;
}

// removes the last element
template <typename T>
void Lst<T>::remove_back() {
	if (!head)
		return;
	if (size == 1)
		return (remove_front());

	Node<T> *prev = head;
	Node<T> *cur = head->next;
	while (cur->next) {
		prev = cur;
		cur = cur->next;
	}
	delete cur;
	prev->next = nullptr;
	--size;
}

// removes the nth element
template <typename T>
void Lst<T>::remove_at(int index) {
	if (!head || index >= size)
		return;
	if (index == 0)
		return (remove_front());
	if (index == size - 1)
		return (remove_back());

	Node<T> *cur = head;
	Node<T> *prev;
	for (int i = 0; i < index; ++i) {
		prev = cur;
		cur = cur->next;
	}
	prev->next = cur->next;
	delete cur;
	--size;
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
	Node<T> *cur = head;
	while (cur) {
		cout << "[" << cur->data << "] -> ";
		cur = cur->next;
	}
	cout << "nullptr" << endl;
}

// gets size of linkedlist
template <typename T>
int Lst<T>::get_size() const {
	return size;
}

// gets data at index
template <typename T>
T Lst<T>::get(int index) const {
	if (index < 0 || index >= size)
		throw out_of_range("Index out of range");
	Node<T> *cur = head;
	for (int i = 0; i < index; ++i)
		cur = cur->next;
	return cur->data;
}

// finds if data exist, returns index of data, -1 if not found
template <typename T>
int Lst<T>::find(const T& data) const {
	Node<T> *cur = head;
	for (int i = 0; i < size; ++i) {
		if (cur->data == data)
			return i;
		cur = cur->next;
	}
	return -1;
}

// finds if data exist
template <typename T>
bool Lst<T>::contains(const T& data) const {
	Node<T> *cur = head;
	for (int i = 0; i < size; ++i) {
		if (cur->data == data)
			return true;
		cur = cur->next;
	}
	return false;
}

// sets data at index
template <typename T>
void Lst<T>::set(int index, const T& data) {
	if (index < 0 || index >= size)
		throw out_of_range("Index out of range");
	Node<T> *cur = head;
	for (int i = 0; i < index; ++i)
		cur = cur->next;
	cur->data = data;
}