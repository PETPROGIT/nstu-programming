package data_structures

type QueueNode struct {
	Value string
	Next  *QueueNode
}

type Queue struct {
	Head *QueueNode
	Tail *QueueNode
}

func (q *Queue) Push(value string) {
	newNode := &QueueNode{Value: value}
	if q.Tail == nil {
		q.Head = newNode
		q.Tail = newNode
	} else {
		q.Tail.Next = newNode
		q.Tail = newNode
	}
}

func (q *Queue) Pop() string {
	if q.Head == nil {
		return ""
	}
	val := q.Head.Value
	q.Head = q.Head.Next
	if q.Head == nil {
		q.Tail = nil
	}
	return val
}

func (q *Queue) Read() {
	curr := q.Head
	for curr != nil {
		print(curr.Value, " ")
		curr = curr.Next
	}
	println()
}

func (q *Queue) Clear() {
	q.Head = nil
	q.Tail = nil
}
