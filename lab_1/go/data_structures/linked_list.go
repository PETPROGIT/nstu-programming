package data_structures

type LinkedNode struct {
	Value string
	Next  *LinkedNode
	Prev  *LinkedNode
}

type LinkedList struct {
	Head *LinkedNode
	Tail *LinkedNode
}

func (l *LinkedList) PushFront(value string) {
	newNode := &LinkedNode{Value: value, Next: l.Head}
	if l.Head != nil {
		l.Head.Prev = newNode
	} else {
		l.Tail = newNode
	}
	l.Head = newNode
}

func (l *LinkedList) PushBack(value string) {
	newNode := &LinkedNode{Value: value, Prev: l.Tail}
	if l.Tail != nil {
		l.Tail.Next = newNode
	} else {
		l.Head = newNode
	}
	l.Tail = newNode
}

func (l *LinkedList) Find(value string) *LinkedNode {
	curr := l.Head
	for curr != nil {
		if curr.Value == value {
			return curr
		}
		curr = curr.Next
	}
	return nil
}

func (l *LinkedList) InsertBefore(beforeValue, value string) {
	curr := l.Find(beforeValue)
	if curr == nil {
		return
	}
	if curr == l.Head {
		l.PushFront(value)
		return
	}
	newNode := &LinkedNode{Value: value, Next: curr, Prev: curr.Prev}
	curr.Prev.Next = newNode
	curr.Prev = newNode
}

func (l *LinkedList) InsertAfter(afterValue, value string) {
	curr := l.Find(afterValue)
	if curr == nil {
		return
	}
	if curr == l.Tail {
		l.PushBack(value)
		return
	}
	newNode := &LinkedNode{Value: value, Next: curr.Next, Prev: curr}
	curr.Next.Prev = newNode
	curr.Next = newNode
}

func (l *LinkedList) PopFront() string {
	if l.Head == nil {
		return ""
	}
	val := l.Head.Value
	l.Head = l.Head.Next
	if l.Head != nil {
		l.Head.Prev = nil
	} else {
		l.Tail = nil
	}
	return val
}

func (l *LinkedList) PopBack() string {
	if l.Tail == nil {
		return ""
	}
	val := l.Tail.Value
	l.Tail = l.Tail.Prev
	if l.Tail != nil {
		l.Tail.Next = nil
	} else {
		l.Head = nil
	}
	return val
}

func (l *LinkedList) RemoveBefore(beforeValue string) string {
	curr := l.Find(beforeValue)
	if curr == nil || curr.Prev == nil {
		return ""
	}
	if curr.Prev == l.Head {
		return l.PopFront()
	}
	val := curr.Prev.Value
	curr.Prev.Prev.Next = curr
	curr.Prev = curr.Prev.Prev
	return val
}

func (l *LinkedList) RemoveAfter(afterValue string) string {
	curr := l.Find(afterValue)
	if curr == nil || curr.Next == nil {
		return ""
	}
	if curr.Next == l.Tail {
		return l.PopBack()
	}
	val := curr.Next.Value
	curr.Next = curr.Next.Next
	curr.Next.Prev = curr
	return val
}

func (l *LinkedList) Remove(value string) string {
	curr := l.Find(value)
	if curr == nil {
		return ""
	}
	if curr == l.Head {
		return l.PopFront()
	}
	if curr == l.Tail {
		return l.PopBack()
	}
	val := curr.Value
	curr.Prev.Next = curr.Next
	curr.Next.Prev = curr.Prev
	return val
}

func (l *LinkedList) Read() {
	curr := l.Head
	for curr != nil {
		print(curr.Value, " ")
		curr = curr.Next
	}
	println()
}

func (l *LinkedList) ReadReverse() {
	curr := l.Tail
	for curr != nil {
		print(curr.Value, " ")
		curr = curr.Prev
	}
	println()
}

func (l *LinkedList) Clear() {
	l.Head = nil
	l.Tail = nil
}
