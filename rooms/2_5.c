inherit "/std/room";

#include "../domain.h" 

void setup( void ) {

  set_domainname("%^GREEN%^Woodland %^RED%^Critter %^GREEN%^Christmas%^RESET%^");
  set_coords(({ 2, 5 }));
  set_dimensions(({ 12, 16 }));

  set_short( "Woodland" );
  set_long( "This is sprawling woodland, trees can be seen everywhere while critters can be heard in the distance. " );

 set_exits( ([
  "southwest" : DIR+"/rooms/1_6.c",
  "northwest" : DIR+"/rooms/1_4.c",
  "northeast" : DIR+"/rooms/3_4.c"
  ]) );

}

