#ifndef __PLAYER_H__
#define __PLAYER_H__

#include <cstdint>
#include <list>
#include <dirent.h>

#include "../../common/include/socket.h"
#include "../../common/include/protocol.h"
#include "../../common/include/protected_queue.h"
#include "../include/inputReceiver.h"
#include "../include/updateSender.h"
#include "../include/disconnecter.h"

#define MAP_SAVE_ROUTE "../maps/"

class Game;

class Player {
private:
    Protocol protocol;  
    InputReceiver inputReceiver;
    UpdateSender updateSender;
    ProtectedQueue<Update> updates;
public:
    explicit Player(Socket socket);
    void setDisconnecterPtr(Disconnecter* disconecter);
    ~Player();
    void start();   
    void stop();
    void sendChellIdToClient(uint32_t id) const;
    void setInputPtr(ProtectedQueue<Action>* ptr);
    ProtectedQueue<Update>* getUpdatesPtr();
    void pushBackUpdate(Update update);
    void sendGamesList(std::list<Game*>* games);
    void sendMapList();
    uint8_t receiveByte() const;
    uint32_t receiveQuad() const;
    std::string receiveLine() const;
};

#endif
