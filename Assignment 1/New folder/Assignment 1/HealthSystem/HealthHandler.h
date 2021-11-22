#pragma once
#include "Room.h"

typedef struct HealthHandler {
    list_t* rooms;
}HealthHandler;

typedef struct HealthHandler* healthHandler_t;

healthHandler_t healthHandler_create();
void healthHandler_destroy(healthHandler_t self);
void healthHandler_addRoom(healthHandler_t self, room_t room);
void healthHandler_showBuildingHealth(healthHandler_t self);