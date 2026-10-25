package db

import (
	"fmt"
	"lab_1/data_structures"
	"strconv"
)

func Execute(st *Storage, cmd Command, name string, args []string) {
	switch cmd {
	case MCREATE:
		if _, ok := st.Arrays[name]; !ok {
			st.Arrays[name] = data_structures.CreateArray(1)
		}
		fmt.Printf("-> CREATED M %s\n", name)
	case MPUSHBACK:
		st.Arrays[name].PushBack(args[0])
		fmt.Printf("-> %s\n", args[0])
	case MINSERT:
		idx, _ := strconv.Atoi(args[0])
		st.Arrays[name].Insert(idx, args[1])
		fmt.Printf("-> %s\n", args[1])
	case MGET:
		idx, _ := strconv.Atoi(args[0])
		fmt.Printf("-> %s\n", st.Arrays[name].Get(idx))
	case MSET:
		idx, _ := strconv.Atoi(args[0])
		st.Arrays[name].Set(idx, args[1])
		fmt.Printf("-> %s\n", args[1])
	case MREMOVEAT:
		idx, _ := strconv.Atoi(args[0])
		fmt.Printf("-> %s\n", st.Arrays[name].RemoveAt(idx))
	case MLENGTH:
		fmt.Printf("-> %d\n", st.Arrays[name].Length())
	case MREAD:
		st.Arrays[name].Read()

	case FCREATE:
		if _, ok := st.FLists[name]; !ok {
			st.FLists[name] = &data_structures.ForwardList{}
		}
		fmt.Printf("-> CREATED F %s\n", name)
	case FPUSHFRONT:
		st.FLists[name].PushFront(args[0])
		fmt.Printf("-> %s\n", args[0])
	case FPUSHBACK:
		st.FLists[name].PushBack(args[0])
		fmt.Printf("-> %s\n", args[0])
	case FINSERTBEFORE:
		st.FLists[name].InsertBefore(args[0], args[1])
		fmt.Printf("-> %s\n", args[1])
	case FINSERTAFTER:
		st.FLists[name].InsertAfter(args[0], args[1])
		fmt.Printf("-> %s\n", args[1])
	case FPOPFRONT:
		fmt.Printf("-> %s\n", st.FLists[name].PopFront())
	case FPOPBACK:
		fmt.Printf("-> %s\n", st.FLists[name].PopBack())
	case FREMOVEBEFORE:
		fmt.Printf("-> %s\n", st.FLists[name].RemoveBefore(args[0]))
	case FREMOVEAFTER:
		fmt.Printf("-> %s\n", st.FLists[name].RemoveAfter(args[0]))
	case FREMOVE:
		fmt.Printf("-> %s\n", st.FLists[name].Remove(args[0]))
	case FFIND:
		if st.FLists[name].Find(args[0]) {
			fmt.Println("-> TRUE")
		} else {
			fmt.Println("-> FALSE")
		}
	case FREAD:
		st.FLists[name].Read()

	case LCREATE:
		if _, ok := st.LLists[name]; !ok {
			st.LLists[name] = &data_structures.LinkedList{}
		}
		fmt.Printf("-> CREATED L %s\n", name)
	case LPUSHFRONT:
		st.LLists[name].PushFront(args[0])
		fmt.Printf("-> %s\n", args[0])
	case LPUSHBACK:
		st.LLists[name].PushBack(args[0])
		fmt.Printf("-> %s\n", args[0])
	case LINSERTBEFORE:
		st.LLists[name].InsertBefore(args[0], args[1])
		fmt.Printf("-> %s\n", args[1])
	case LINSERTAFTER:
		st.LLists[name].InsertAfter(args[0], args[1])
		fmt.Printf("-> %s\n", args[1])
	case LPOPFRONT:
		fmt.Printf("-> %s\n", st.LLists[name].PopFront())
	case LPOPBACK:
		fmt.Printf("-> %s\n", st.LLists[name].PopBack())
	case LREMOVEBEFORE:
		fmt.Printf("-> %s\n", st.LLists[name].RemoveBefore(args[0]))
	case LREMOVEAFTER:
		fmt.Printf("-> %s\n", st.LLists[name].RemoveAfter(args[0]))
	case LREMOVE:
		fmt.Printf("-> %s\n", st.LLists[name].Remove(args[0]))
	case LFIND:
		if st.LLists[name].Find(args[0]) != nil {
			fmt.Println("-> TRUE")
		} else {
			fmt.Println("-> FALSE")
		}
	case LREAD:
		st.LLists[name].Read()
	case LREADREVERSE:
		st.LLists[name].ReadReverse()

	case QCREATE:
		if _, ok := st.Queues[name]; !ok {
			st.Queues[name] = &data_structures.Queue{}
		}
		fmt.Printf("-> CREATED Q %s\n", name)
	case QPUSH:
		st.Queues[name].Push(args[0])
		fmt.Printf("-> %s\n", args[0])
	case QPOP:
		fmt.Printf("-> %s\n", st.Queues[name].Pop())
	case QREAD:
		st.Queues[name].Read()

	case SCREATE:
		if _, ok := st.Stacks[name]; !ok {
			st.Stacks[name] = &data_structures.Stack{}
		}
		fmt.Printf("-> CREATED S %s\n", name)
	case SPUSH:
		st.Stacks[name].Push(args[0])
		fmt.Printf("-> %s\n", args[0])
	case SPOP:
		fmt.Printf("-> %s\n", st.Stacks[name].Pop())
	case SREAD:
		st.Stacks[name].Read()
	}
}
