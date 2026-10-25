package db

import "fmt"

type Command int

const (
	MCREATE Command = iota
	MPUSHBACK
	MINSERT
	MGET
	MSET
	MREMOVEAT
	MLENGTH
	MREAD

	FCREATE
	FPUSHFRONT
	FPUSHBACK
	FINSERTBEFORE
	FINSERTAFTER
	FPOPFRONT
	FPOPBACK
	FREMOVEBEFORE
	FREMOVEAFTER
	FREMOVE
	FFIND
	FREAD

	LCREATE
	LPUSHFRONT
	LPUSHBACK
	LINSERTBEFORE
	LINSERTAFTER
	LPOPFRONT
	LPOPBACK
	LREMOVEBEFORE
	LREMOVEAFTER
	LREMOVE
	LFIND
	LREAD
	LREADREVERSE

	QCREATE
	QPUSH
	QPOP
	QREAD

	SCREATE
	SPUSH
	SPOP
	SREAD
)

func ParseCommand(s string) Command {
	switch s {
	case "MCREATE":
		return MCREATE
	case "MPUSHBACK":
		return MPUSHBACK
	case "MINSERT":
		return MINSERT
	case "MGET":
		return MGET
	case "MSET":
		return MSET
	case "MREMOVEAT":
		return MREMOVEAT
	case "MLENGTH":
		return MLENGTH
	case "MREAD":
		return MREAD

	case "FCREATE":
		return FCREATE
	case "FPUSHFRONT":
		return FPUSHFRONT
	case "FPUSHBACK":
		return FPUSHBACK
	case "FINSERTBEFORE":
		return FINSERTBEFORE
	case "FINSERTAFTER":
		return FINSERTAFTER
	case "FPOPFRONT":
		return FPOPFRONT
	case "FPOPBACK":
		return FPOPBACK
	case "FREMOVEBEFORE":
		return FREMOVEBEFORE
	case "FREMOVEAFTER":
		return FREMOVEAFTER
	case "FREMOVE":
		return FREMOVE
	case "FFIND":
		return FFIND
	case "FREAD":
		return FREAD

	case "LCREATE":
		return LCREATE
	case "LPUSHFRONT":
		return LPUSHFRONT
	case "LPUSHBACK":
		return LPUSHBACK
	case "LINSERTBEFORE":
		return LINSERTBEFORE
	case "LINSERTAFTER":
		return LINSERTAFTER
	case "LPOPFRONT":
		return LPOPFRONT
	case "LPOPBACK":
		return LPOPBACK
	case "LREMOVEBEFORE":
		return LREMOVEBEFORE
	case "LREMOVEAFTER":
		return LREMOVEAFTER
	case "LREMOVE":
		return LREMOVE
	case "LFIND":
		return LFIND
	case "LREAD":
		return LREAD
	case "LREADREVERSE":
		return LREADREVERSE

	case "QCREATE":
		return QCREATE
	case "QPUSH":
		return QPUSH
	case "QPOP":
		return QPOP
	case "QREAD":
		return QREAD

	case "SCREATE":
		return SCREATE
	case "SPUSH":
		return SPUSH
	case "SPOP":
		return SPOP
	case "SREAD":
		return SREAD
	}
	panic(fmt.Sprintf("unknown command: %s", s))
}
