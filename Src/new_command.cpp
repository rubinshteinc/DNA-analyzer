#include "new_command.h"

MetaData* New::exe(std::string seq, std::string name = NULL) {
    MetaData *item = new MetaData(seq, name);
    return item;
}

