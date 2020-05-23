inherit "/std/room";

#include "../domain.h" 

void setup( void ) {

  set_domainname("%^GREEN%^Woodland %^RED%^Critter %^GREEN%^Christmas%^RESET%^");
  set_coords(({ 8, 12 }));
  set_dimensions(({ 12, 16 }));

  set_short( "Woodland" );
  set_long( "This is sprawling woodland, trees can be seen everywhere while critters can be heard in the distance. " );

 set_exits( ([
  "southwest" : DIR+"/rooms/7_13.c",
  "northwest" : DIR+"/rooms/7_11.c",
  "northeast" : DIR+"/rooms/9_11.c"
  ]) );

}

