#include "game.h"

int main(void){
  game_init();
  game_loop();
  game_cleanup();
  
  return 0;
}
