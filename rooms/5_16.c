inherit "/std/room";
#include "../domain.h"

void setup(void) {

   add_area("required");

   set_domainname("%^GREEN%^Woodland %^RED%^Critter %^GREEN%^Christmas%^RESET%^");
   set_coords(({ 0, 0 }));
   set_dimensions(({ 1, 1 }));
   set_mapstart(({ 0, 0} ));

   set_short("A large open field");
   set_long("You are in a large open field.");
   set_exits(([
     "north" : "/domains/woodland/rooms/5_15",
     "south" : "/domains/newbie/rooms/tree"
   ]));
   set_objects(
    DIR+"/obj/sign.c"
  );
}

