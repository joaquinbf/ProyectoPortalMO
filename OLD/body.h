#ifndef __BODY_H__
#define __BODY_H__

#include <cstdint>
#include "../../common/include/update.h"
#include "../../common/include/types.h"


class Body {
protected:
    static uint32_t body_number;

public:
    virtual Update getCreateUpdate() = 0;
    virtual Update getUpdate() = 0;
};

#endif
