#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "itype.h"
#include "pque.h"
#include "torpedo.h"

#define TORPEDO_ARRAY_LENGTH 0xff

typedef struct s_gameState
{
  bool paused;
  u32 currentTick;
  s32 heading;
  u32 ammunition;
  u32 currentTorpedo;
  PQue eventQueue;
  Torpedo* torpedos[TORPEDO_ARRAY_LENGTH];
}GameState;

extern void GameState_GetAmmoCount(u32 ammoType);

extern void GameState_AddAmmoCount(u32 ammoType, s32 offset);

extern void GameState_Init(GameState* state);

extern void GameState_Tick(GameState* state);

extern void GameState_Pause(GameState* state);

extern void GameState_InsertCommand(GameState* state, Command* command);

#endif /*GAMESTATE_H*/
