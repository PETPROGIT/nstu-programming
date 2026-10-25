package db

import (
	"bufio"
	"lab_1/data_structures"
	"os"
	"strings"
)

func SaveArray(a *data_structures.Array, out *bufio.Writer) {
	for _, v := range a.Data {
		out.WriteByte(' ')
		out.WriteString(v)
	}
}

func SaveForwardList(l *data_structures.ForwardList, out *bufio.Writer) {
	for n := l.Head; n != nil; n = n.Next {
		out.WriteByte(' ')
		out.WriteString(n.Value)
	}
}

func SaveLinkedList(l *data_structures.LinkedList, out *bufio.Writer) {
	for n := l.Head; n != nil; n = n.Next {
		out.WriteByte(' ')
		out.WriteString(n.Value)
	}
}

func SaveQueue(q *data_structures.Queue, out *bufio.Writer) {
	for n := q.Head; n != nil; n = n.Next {
		out.WriteByte(' ')
		out.WriteString(n.Value)
	}
}

func SaveStack(s *data_structures.Stack, out *bufio.Writer) {
	for n := s.Top; n != nil; n = n.Next {
		out.WriteByte(' ')
		out.WriteString(n.Value)
	}
}

func SaveToFile(path string, st *Storage) {
	f, err := os.Create(path)
	if err != nil {
		panic(err)
	}
	defer f.Close()
	w := bufio.NewWriter(f)

	for name, a := range st.Arrays {
		w.WriteString("M ")
		w.WriteString(name)
		SaveArray(a, w)
		w.WriteString("\n")
	}
	for name, l := range st.FLists {
		w.WriteString("F ")
		w.WriteString(name)
		SaveForwardList(l, w)
		w.WriteString("\n")
	}
	for name, l := range st.LLists {
		w.WriteString("L ")
		w.WriteString(name)
		SaveLinkedList(l, w)
		w.WriteString("\n")
	}
	for name, q := range st.Queues {
		w.WriteString("Q ")
		w.WriteString(name)
		SaveQueue(q, w)
		w.WriteString("\n")
	}
	for name, s := range st.Stacks {
		w.WriteString("S ")
		w.WriteString(name)
		SaveStack(s, w)
		w.WriteString("\n")
	}
	w.Flush()
}

func LoadFromFile(path string, st *Storage) {
	f, err := os.Open(path)
	if err != nil {
		return
	}
	defer f.Close()
	sc := bufio.NewScanner(f)
	for sc.Scan() {
		line := sc.Text()
		fields := strings.Fields(line)
		if len(fields) < 2 {
			continue
		}
		typ := fields[0]
		name := fields[1]
		elems := fields[2:]

		switch typ {
		case "M":
			a := data_structures.CreateArray(1)
			for _, x := range elems {
				a.PushBack(x)
			}
			st.Arrays[name] = a
		case "F":
			l := &data_structures.ForwardList{}
			for _, x := range elems {
				l.PushBack(x)
			}
			st.FLists[name] = l
		case "L":
			l := &data_structures.LinkedList{}
			for _, x := range elems {
				l.PushBack(x)
			}
			st.LLists[name] = l
		case "Q":
			q := &data_structures.Queue{}
			for _, x := range elems {
				q.Push(x)
			}
			st.Queues[name] = q
		case "S":
			s := &data_structures.Stack{}
			for i := len(elems) - 1; i >= 0; i-- {
				s.Push(elems[i])
			}
			st.Stacks[name] = s
		}
	}
	if err := sc.Err(); err != nil {
		panic(err)
	}
}
