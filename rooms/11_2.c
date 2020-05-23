inherit "/std/room";

#include "../domain.h" 

void setup( void ) {

  set_domainname("%^GREEN%^Woodland %^RED%^Critter %^GREEN%^Christmas%^RESET%^");
  set_coords(({ 11, 2 }));
  set_dimensions(({ 12, 16 }));

  set_short( "Woodland" );
  set_long( "This is sprawling woodland, trees can be seen everywhere while critters can be heard in the distance. " );

 set_exits( ([
  "west" : DIR+"/rooms/10_2.c",
  "northwest" : DIR+"/rooms/10_1.c",
  "north" : DIR+"/rooms/11_1.c",
  "southwest" : DIR+"/rooms/10_3.c",
  "south" : DIR+"/rooms/11_3.c"
  ]) );

}

