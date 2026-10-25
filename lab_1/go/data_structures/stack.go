package data_structures

type StackNode struct {
	Value string
	Next  *StackNode
}

type Stack struct {
	Top *StackNode
}

func (s *Stack) Push(value string) {
	s.Top = &StackNode{Value: value, Next: s.Top}
}

func (s *Stack) Pop() string {
	if s.Top == nil {
		return ""
	}
	val := s.Top.Value
	s.Top = s.Top.Next
	return val
}

func (s *Stack) Read() {
	curr := s.Top
	for curr != nil {
		print(curr.Value, " ")
		curr = curr.Next
	}
	println()
}

func (s *Stack) Clear() {
	s.Top = nil
}
