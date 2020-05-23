inherit "/std/room";

#include "../domain.h" 

void setup( void ) {

  set_domainname("%^GREEN%^Woodland %^RED%^Critter %^GREEN%^Christmas%^RESET%^");
  set_coords(({ 10, 4 }));
  set_dimensions(({ 12, 16 }));

  set_short( "Woodland" );
  set_long( "This is sprawling woodland, trees can be seen everywhere while critters can be heard in the distance. " );

 set_exits( ([
  "west" : DIR+"/rooms/9_4.c",
  "northwest" : DIR+"/rooms/9_3.c",
  "north" : DIR+"/rooms/10_3.c",
  "northeast" : DIR+"/rooms/11_3.c",
  "east" : DIR+"/rooms/11_4.c"
  ]) );

}

