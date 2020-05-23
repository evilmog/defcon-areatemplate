inherit "/std/room";

#include "../domain.h" 

void setup( void ) {

  set_domainname("%^GREEN%^Woodland %^RED%^Critter %^GREEN%^Christmas%^RESET%^");
  set_coords(({ 0, 9 }));
  set_dimensions(({ 12, 16 }));

  set_short( "Woodland" );
  set_long( "This is sprawling woodland, trees can be seen everywhere while critters can be heard in the distance. Animal prints can be seen on the ground." );

  add_item("prints", "animal prints, perhaps you should %^MAGENTA%^search%^RESET%^here");  set_objects(
    DIR+"/npc/chipmunk.c"
  );
 set_exits( ([
  "southeast" : DIR+"/rooms/1_10.c",
  "north" : DIR+"/rooms/0_8.c"
  ]) );

}

int do_search(void) {
   this_environment()->setup();   write("An animal appears out of the woodwork");   return 1;
}
