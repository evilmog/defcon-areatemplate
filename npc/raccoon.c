inherit "/std/monster";
#include "../domain.h" 

void setup( void ) {
   set_name("raccoon");
   set_short("A raccoon");
   set_long("A raccoon");
   set_gender("male");
   set_race("raccoon");
   set_hit_skill("combat/unarmed");
   set_skill("combat/unarmed", 80);
   set_skill("combat/defense", 80);
   set_level(4);
}

void monster_died(void) {
  object usr;
  int *wlf;
  int results;
  usr = this_player();
  if (usr->is_completed_quest("Woodland")) {
    return;
  }
  wlf = usr->get_woodland_kills();
  if(!wlf) {
    wlf = (( { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } ));
  }
  if(wlf[12] != 1) {
    wlf[12] = 1;
    results = wlf[0] + wlf[1] + wlf[2] + wlf[3] + wlf[4] + wlf[5] + wlf[6] + wlf[7] + wlf[8] + wlf[9] + wlf[10] + wlf[11] + wlf[12] + wlf[13] + wlf[14] + wlf[15] + wlf[16];
    usr->set_woodland_kills(wlf);
  }
}