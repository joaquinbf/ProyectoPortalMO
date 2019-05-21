#ifndef _COMMON_PROTOCOL_H_
#define _COMMON_PROTOCOL_H_

#include <string>

#include "../include/socket.h"
#include "../include/creator.h"
#include "../../common/include/action.h"

class Protocol{
private:
	Socket socket;
public:
	Protocol();
	explicit Protocol(Socket&& socket);
	explicit Protocol(Protocol&&);
	~Protocol();
	Protocol& operator=(Protocol&& other);
	void sendByte(const uint8_t byte) const;
	void sendDoble(const uint16_t byte) const;
	void sendQuad(const uint32_t byte) const;
	void sendLine(const std::string& line) const;
	uint8_t receiveByte() const;
	uint16_t receiveDoble() const;
	uint32_t receiveQuad() const;
	std::string receiveLine() const;
	void sendCreator(const Creator creator) const;
	Creator receiveCreator() const;
	void sendAction(const Action action) const;
	Action receiveAction() const;
};

#endif
