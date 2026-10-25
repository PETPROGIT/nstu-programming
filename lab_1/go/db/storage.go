package db

import "lab_1/data_structures"

type Storage struct {
	Arrays map[string]*data_structures.Array
	FLists map[string]*data_structures.ForwardList
	LLists map[string]*data_structures.LinkedList
	Queues map[string]*data_structures.Queue
	Stacks map[string]*data_structures.Stack
}

func NewStorage() *Storage {
	return &Storage{
		Arrays: make(map[string]*data_structures.Array),
		FLists: make(map[string]*data_structures.ForwardList),
		LLists: make(map[string]*data_structures.LinkedList),
		Queues: make(map[string]*data_structures.Queue),
		Stacks: make(map[string]*data_structures.Stack),
	}
}

func (s *Storage) ClearStorage() {
	for _, a := range s.Arrays {
		a.Clear()
	}
	for _, f := range s.FLists {
		f.Clear()
	}
	for _, l := range s.LLists {
		l.Clear()
	}
	for _, q := range s.Queues {
		q.Clear()
	}
	for _, st := range s.Stacks {
		st.Clear()
	}
}
