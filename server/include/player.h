#ifndef __PLAYER_H__
#define __PLAYER_H__

#include "match.h"
#include "input_receiver.h"
#include "update_sender.h"
#include "./chell/chell.h"
#include "../../common/include/thread.h"
#include "../../common/include/socket.h"
#include "../../common/include/protocol.h"

class Player: public Thread {
public:
    virtual void run() override;
};

#endif
