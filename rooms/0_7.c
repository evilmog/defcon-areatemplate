inherit "/std/room";

#include "../domain.h" 

void setup( void ) {

  set_domainname("%^GREEN%^Woodland %^RED%^Critter %^GREEN%^Christmas%^RESET%^");
  set_coords(({ 0, 7 }));
  set_dimensions(({ 12, 16 }));

  set_short( "Woodland" );
  set_long( "This is sprawling woodland, trees can be seen everywhere while critters can be heard in the distance. Animal prints can be seen on the ground." );

  add_item("prints", "animal prints, perhaps you should %^MAGENTA%^search%^RESET%^here");  set_objects(
    DIR+"/npc/skunk.c"
  );
 set_exits( ([
  "south" : DIR+"/rooms/0_8.c",
  "southeast" : DIR+"/rooms/1_8.c",
  "north" : DIR+"/rooms/0_6.c"
  ]) );

}

int do_search(void) {
   this_environment()->setup();   write("An animal appears out of the woodwork");   return 1;
}
