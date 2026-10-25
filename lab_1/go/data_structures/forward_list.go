package data_structures

type ForwardNode struct {
	Value string
	Next  *ForwardNode
}

type ForwardList struct {
	Head *ForwardNode
}

func (l *ForwardList) PushFront(value string) {
	l.Head = &ForwardNode{Value: value, Next: l.Head}
}

func (l *ForwardList) PushBack(value string) {
	newNode := &ForwardNode{Value: value}
	if l.Head == nil {
		l.Head = newNode
		return
	}
	curr := l.Head
	for curr.Next != nil {
		curr = curr.Next
	}
	curr.Next = newNode
}

func (l *ForwardList) InsertBefore(beforeValue, value string) {
	if l.Head == nil {
		return
	}
	if l.Head.Value == beforeValue {
		l.PushFront(value)
		return
	}
	curr := l.Head
	for curr.Next != nil {
		if curr.Next.Value == beforeValue {
			curr.Next = &ForwardNode{Value: value, Next: curr.Next}
			return
		}
		curr = curr.Next
	}
}

func (l *ForwardList) InsertAfter(afterValue, value string) {
	curr := l.Head
	for curr != nil {
		if curr.Value == afterValue {
			curr.Next = &ForwardNode{Value: value, Next: curr.Next}
			return
		}
		curr = curr.Next
	}
}

func (l *ForwardList) PopFront() string {
	if l.Head == nil {
		return ""
	}
	val := l.Head.Value
	l.Head = l.Head.Next
	return val
}

func (l *ForwardList) PopBack() string {
	if l.Head == nil {
		return ""
	}
	if l.Head.Next == nil {
		val := l.Head.Value
		l.Head = nil
		return val
	}
	curr := l.Head
	for curr.Next.Next != nil {
		curr = curr.Next
	}
	val := curr.Next.Value
	curr.Next = nil
	return val
}

func (l *ForwardList) RemoveBefore(beforeValue string) string {
	if l.Head == nil || l.Head.Next == nil {
		return ""
	}
	if l.Head.Next.Value == beforeValue {
		return l.PopFront()
	}
	curr := l.Head
	for curr.Next != nil && curr.Next.Next != nil {
		if curr.Next.Next.Value == beforeValue {
			val := curr.Next.Value
			curr.Next = curr.Next.Next
			return val
		}
		curr = curr.Next
	}
	return ""
}

func (l *ForwardList) RemoveAfter(afterValue string) string {
	curr := l.Head
	for curr != nil {
		if curr.Value == afterValue {
			if curr.Next != nil {
				val := curr.Next.Value
				curr.Next = curr.Next.Next
				return val
			}
			return ""
		}
		curr = curr.Next
	}
	return ""
}

func (l *ForwardList) Remove(value string) string {
	if l.Head == nil {
		return ""
	}
	if l.Head.Value == value {
		return l.PopFront()
	}
	curr := l.Head
	for curr.Next != nil {
		if curr.Next.Value == value {
			val := curr.Next.Value
			curr.Next = curr.Next.Next
			return val
		}
		curr = curr.Next
	}
	return ""
}

func (l *ForwardList) Find(value string) bool {
	curr := l.Head
	for curr != nil {
		if curr.Value == value {
			return true
		}
		curr = curr.Next
	}
	return false
}

func (l *ForwardList) Read() {
	curr := l.Head
	for curr != nil {
		print(curr.Value, " ")
		curr = curr.Next
	}
	println()
}

func (l *ForwardList) Clear() {
	l.Head = nil
}
