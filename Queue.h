struct Point {
	int x, y;
};

struct Path {
	Point coordinates;
	int value;
	Point trace;
};

struct Node {
	Path key;
	Node* next;
};

struct list {
	Node* head;
	Node* tail;
};

Node* createNode(Path value) {
	Node* p = new Node;
	p->key = value;
	p->next = NULL;
	return p;
}

struct Queue {
	Node* head = NULL;
	Node* tail = NULL;
	bool empty();
	void push(Path value);
	Path front();
	void pop();
};

bool Queue::empty() {
	if (head == NULL) return true;
	return false;
}

void Queue::push(Path value) {
	Node* p = createNode(value);
	if (head == NULL) {
		head = p;
		tail = p;
	}
	else {
		tail->next = p;
		tail = p;
	}
}

Path Queue::front() {
	Path value;
	value = head->key;
	return value;
}

void Queue::pop() {
	if (head == NULL) {
		return;
	}
	Node* p = head;
	head = head->next;
	delete p;
}

struct NodeInt {
	int key;
	NodeInt* next;
};

struct QueueInt {
	NodeInt* head = NULL;
	NodeInt* tail = NULL;
	bool empty();
	void push(int value);
	int front();
	void pop();
};

bool QueueInt::empty() {
	return (head == NULL);
}

void QueueInt::push(int value) {
	NodeInt* p = new NodeInt;
	p->key = value;
	p->next = NULL;
	if (head == NULL) {
		head = p;
		tail = p;
		return;
	}
	tail->next = p;
	tail = p;
}

int QueueInt::front() {
	return head->key;
}

void QueueInt::pop() {
	if (head == NULL) return;
	NodeInt* p = head;
	head = head->next;
	delete p;
}