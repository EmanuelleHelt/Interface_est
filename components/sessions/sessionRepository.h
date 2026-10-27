#ifndef SESSIONREPOSITORY_H
#define SESSIONREPOSITORY_H
#include "session.h"

class SessionRepository
{
public:
    bool saveSession(const Session &session);
};

#endif // SESSIONREPOSITORY_H
