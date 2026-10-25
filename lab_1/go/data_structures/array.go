package data_structures

type Array struct {
	Data     []string
	Capacity int
}

func CreateArray(capacity int) *Array {
	return &Array{
		Data:     make([]string, 0, capacity),
		Capacity: capacity,
	}
}

func (a *Array) PushBack(value string) {
	a.Data = append(a.Data, value)
	if len(a.Data) > a.Capacity {
		a.Capacity = len(a.Data)
	}
}

func (a *Array) Insert(index int, value string) {
	a.Data = append(a.Data, "")
	copy(a.Data[index+1:], a.Data[index:])
	a.Data[index] = value
}

func (a *Array) Get(index int) string {
	return a.Data[index]
}

func (a *Array) Set(index int, value string) {
	a.Data[index] = value
}

func (a *Array) RemoveAt(index int) string {
	removed := a.Data[index]
	a.Data = append(a.Data[:index], a.Data[index+1:]...)
	return removed
}

func (a *Array) Length() int {
	return len(a.Data)
}

func (a *Array) Read() {
	for _, v := range a.Data {
		print(v, " ")
	}
	println()
}

func (a *Array) Clear() {
	a.Data = nil
	a.Capacity = 0
}
