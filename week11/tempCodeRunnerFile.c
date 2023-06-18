void addq(Element e) {
	queue_pointer new = (queue_pointer)malloc(sizeof(queue));
	new->item = e;
	new->link = NULL;

	if (is_queue_empty())
		front = rear = new;
	else {
		rear->link = new;
		rear = new;
	}
}

Element deleteq() {
	if (is_queue_empty()) {
		printf("queue is empty \n");
		return '\0';
	}
	queue_pointer tmp = front;
	Element item = front->item;
	front = front->link;
	free(tmp);
	return item;
}