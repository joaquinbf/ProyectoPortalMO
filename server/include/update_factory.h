#ifndef __UPDATE_FACTORY_H__
#define __UPDATE_FACTORY_H__

#include "../../common/include/types.h"
#include "./bodies/body.h"
#include "./bodies/chell/chell.h"


class UpdateFactory {
public:
    Update createUpdate(Body *body) const;
    void fillIdClass(Update &update, const Chell *chell) const;

private:
};

#endif
