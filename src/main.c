#define RUN_TESTS 0
#if RUN_TESTS
#include "tests.h"
#else

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "itype.h"
#include "console.h"
#include "tokenparse.h"
#include "departments.h"
#include "gamestate.h"

void PrintManual()
{
  printf("%-15s%-25s%-25s%-25s\n", "department", "example command", "notes", "base delay");
  
  printf("\n%-15s%-25s%-25s%-25s\n", "helm", "rotate clockwise 12", "rotates ship to heading", "1 tick per 15 degrees");
  printf("%-15s%-25s%-25s%-25s\n", "",     "degrees",             "of 12 degrees in the",                "");
  printf("%-15s%-25s%-25s%-25s\n", "",     "",                    "clockwise direction ",                "");

  printf("\n%-15s%-25s%-25s%-25s\n", "sonar", "list contacts", "lists enemies", "1 tick ");

  printf("\n%-15s%-25s%-25s%-25s\n", "weapons", "load", "loads torpedo", "2 ticks");
  printf("\n%-15s%-25s%-25s%-25s\n", "",          "fire", "fires torpedo", "1 tick per 20 meters");


}

void RunSub()
{ 
  char buffer[MAX_BUFFER_LENGTH];
  bool running = true;
  GameState state;
  
  GameState_Init(&state);
    
  while(running)
  {
    GameState_Tick(&state);

    if(Console_DataAvailable())
    {
      Command* cmd = NULL;
      Console_ReadLine(buffer);
      if(!strcmp(buffer, "quit"))
      {
	running = false;
      }
      else if(!strcmp(buffer,"manual") || !strcmp(buffer,"help"))
          PrintManual();
      else if(!strcmp(buffer, "pause"))
      {
	GameState_Pause(&state);
      }
      if((cmd = tokenparse(buffer, state.currentTick)))
      {
	GameState_InsertCommand(&state, cmd);
      }
    }
  }
}



int main(int argc, char** argv)
{
  RunSub();
  return 0;
}

#endif /*RUN_TESTS*/
