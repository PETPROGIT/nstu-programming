#include "Command.h"

#include <map>

namespace Db {

Command ParseCommand(const std::string& s) {
    static const std::map<std::string, Command> table = {
        {"MCREATE", Command::MCREATE}, {"MPUSHBACK", Command::MPUSHBACK},
        {"MINSERT", Command::MINSERT}, {"MGET", Command::MGET},
        {"MSET", Command::MSET}, {"MREMOVEAT", Command::MREMOVEAT},
        {"MLENGTH", Command::MLENGTH}, {"MREAD", Command::MREAD},

        {"FCREATE", Command::FCREATE}, {"FPUSHFRONT", Command::FPUSHFRONT},
        {"FPUSHBACK", Command::FPUSHBACK},
        {"FINSERTBEFORE", Command::FINSERTBEFORE},
        {"FINSERTAFTER", Command::FINSERTAFTER},
        {"FPOPFRONT", Command::FPOPFRONT}, {"FPOPBACK", Command::FPOPBACK},
        {"FREMOVEBEFORE", Command::FREMOVEBEFORE},
        {"FREMOVEAFTER", Command::FREMOVEAFTER},
        {"FREMOVE", Command::FREMOVE}, {"FFIND", Command::FFIND},
        {"FREAD", Command::FREAD},

        {"LCREATE", Command::LCREATE}, {"LPUSHFRONT", Command::LPUSHFRONT},
        {"LPUSHBACK", Command::LPUSHBACK},
        {"LINSERTBEFORE", Command::LINSERTBEFORE},
        {"LINSERTAFTER", Command::LINSERTAFTER},
        {"LPOPFRONT", Command::LPOPFRONT}, {"LPOPBACK", Command::LPOPBACK},
        {"LREMOVEBEFORE", Command::LREMOVEBEFORE},
        {"LREMOVEAFTER", Command::LREMOVEAFTER},
        {"LREMOVE", Command::LREMOVE}, {"LFIND", Command::LFIND},
        {"LREAD", Command::LREAD}, {"LREADREVERSE", Command::LREADREVERSE},

        {"QCREATE", Command::QCREATE}, {"QPUSH", Command::QPUSH},
        {"QPOP", Command::QPOP}, {"QREAD", Command::QREAD},

        {"SCREATE", Command::SCREATE}, {"SPUSH", Command::SPUSH},
        {"SPOP", Command::SPOP}, {"SREAD", Command::SREAD},

        {"TCREATE", Command::TCREATE}, {"TINSERT", Command::TINSERT},
        {"TREMOVE", Command::TREMOVE}, {"TFIND", Command::TFIND},
        {"TREAD", Command::TREAD},
    };
    return table.at(s);
}

}