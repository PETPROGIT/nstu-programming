package main

import (
	"fmt"
	"os"
	"strings"

	"lab_1/db"
)

func main() {
	var file, query string
	args := os.Args[1:]
	for i := 0; i < len(args); i++ {
		if args[i] == "--file" && i+1 < len(args) {
			file = args[i+1]
			i++
		} else if args[i] == "--query" && i+1 < len(args) {
			query = args[i+1]
			i++
		}
	}

	tokens := strings.Fields(query)
	if len(tokens) < 2 {
		fmt.Println("invalid query")
		return
	}
	cmdStr := tokens[0]
	name := tokens[1]
	var qArgs []string
	if len(tokens) > 2 {
		qArgs = tokens[2:]
	}

	cmd := db.ParseCommand(cmdStr)
	st := db.NewStorage()
	db.LoadFromFile(file, st)
	db.Execute(st, cmd, name, qArgs)
	db.SaveToFile(file, st)
	st.ClearStorage()
}
