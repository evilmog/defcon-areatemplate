# room.py
This creates a room, it takes a number of arguments

```
usage: room.py [-h] --name NAME --short SHORT [--scolor SCOLOR] --long LONG
               [--lcolor LCOLOR] [--area AREA] [--north NORTH]
               [--anorth ANORTH] [--south SOUTH] [--asouth ASOUTH]
               [--east EAST] [--aeast AEAST] [--west WEST] [--awest AWEST]
               [--northeast NORTHEAST] [--anortheast ANORTHEAST]
               [--northwest NORTHWEST] [--anorthwest ANORTHWEST]
               [--southeast SOUTHEAST] [--asoutheast ASOUTHEAST]
               [--southwest SOUTHWEST] [--asouthwest ASOUTHWEST] [--up UP]
               [--aup AUP] [--down DOWN] [--adown ADOWN] [--hnorth HNORTH]
               [--hsouth HSOUTH] [--heast HEAST] [--hwest HWEST]
               [--hnortheast HNORTHEAST] [--hnorthwest HNORTHWEST]
               [--hsoutheast HSOUTHEAST] [--hsouthwest HSOUTHWEST] [--hup HUP]
               [--hdown HDOWN] [--panel PANEL] [--vent VENT] [--pipe PIPE]
               [--hole HOLE] [--pushwall PUSHWALL] [--item1 ITEM1]
               [--item1desc ITEM1DESC] [--item2 ITEM2] [--item2desc ITEM2DESC]
               [--item3 ITEM3] [--item3desc ITEM3DESC] [--item4 ITEM4]
               [--item4desc ITEM4DESC] [--obj1 OBJ1] [--obj2 OBJ2]
               [--obj3 OBJ3] [--obj4 OBJ4] [--obj5 OBJ5] [--obj6 OBJ6]
               [--mon1 MON1] [--mon2 MON2] [--mon3 MON3] [--mon4 MON4]
               [--mon5 MON5] [--mon6 MON6] [--mon7 MON7] [--mon8 MON8]
               [--mon9 MON9] [--mon10 MON10] [--mon11 MON11] [--mon12 MON12]
               [--door DOOR] [--doorkey DOORKEY] [--doorlocked DOORLOCKED]
```

## name
The name of the room is special, its how the exit calculations work. All rooms
live on an X, Y, Z co-ordinate system. The spacing between co-ordinates is 10, so
1 unit north is 10 co-ordinates north. The names look like `x0y0z0` or `x10y-30z-20`

to set the name use the --name flag such as `--name x0y0z0`

## area
This determines how the room is split up, the typical directory structure looks like this:
```
/domains/woodland
/domains/woodland/npc
/domains/woodland/obj
/domains/woodland/rooms/AREA_NAME/
```

area here would replace AREA_NAME, area is specified with the `--area` flag

all exits by default stay within the same area, to change areas with an exit use the following flags:
```
               [--northeast NORTHEAST] [--anortheast ANORTHEAST]
               [--northwest NORTHWEST] [--anorthwest ANORTHWEST]
               [--southeast SOUTHEAST] [--asoutheast ASOUTHEAST]
               [--southwest SOUTHWEST] [--asouthwest ASOUTHWEST] [--up UP]
               [--aup AUP] [--down DOWN] [--adown ADOWN]
```

such as `--aup north`

## COLOURS
You can specify the following colours:

* short description `--scolor SCOLOR`
* long description `--lcolor LCOLOR`

SCOLOR or LCOLOR can be any of the following:
```
CYAN
GREEN
GREY
HBLUE
HCYAN
HGREEN
HMAGENTA
HRED
HWHITE
MAGENTA
ORANGE
RED
WHITE
YELLOW
```

To make color codes in a description use `%^` to wrap the COLOR token such as `%^CYAN%^Hello%^RESET%^`

## short
`--short` is the short description that shows up when you look at a room, its the 1 liner that appears at the top

```
A large open field

You are in a large open field.  To the north you see a large dead tree with some
sort of sign on it. If you go down you will enter a strange world. To advance
levels find human resources in the domes.
```
A large open field would be the short description

to set the short description use `--short "A large open field"`

## long
`--long` is the long description that shows up when you lok at a room, it can be multi line.  Use `\n` to represent a line break.

Enclode the long description in quotes such as this: `--long "This is a room's long description.\n\nThis is a new paragraph."`

## Exits
The following options can build visibile or invisible exits

```
[--north NORTH]
               [--anorth ANORTH] [--south SOUTH] [--asouth ASOUTH]
               [--east EAST] [--aeast AEAST] [--west WEST] [--awest AWEST]
               [--northeast NORTHEAST] [--anortheast ANORTHEAST]
               [--northwest NORTHWEST] [--anorthwest ANORTHWEST]
               [--southeast SOUTHEAST] [--asoutheast ASOUTHEAST]
               [--southwest SOUTHWEST] [--asouthwest ASOUTHWEST] [--up UP]
               [--aup AUP] [--down DOWN] [--adown ADOWN] [--hnorth HNORTH]
               [--hsouth HSOUTH] [--heast HEAST] [--hwest HWEST]
               [--hnortheast HNORTHEAST] [--hnorthwest HNORTHWEST]
               [--hsoutheast HSOUTHEAST] [--hsouthwest HSOUTHWEST] [--hup HUP]
               [--hdown HDOWN] [--panel PANEL] [--vent VENT] [--pipe PIPE]
               [--hole HOLE] [--pushwall PUSHWALL]
```

Exits are split into 2 types, automatic and manual, automatic exits are the major cardinal exits like north, south, east, west, up, down, etc. To use them
type use the exit argument and the number of units you want to travel and it will do the calculations. such as `--north 1` or `--south 20`.  Manual exits require a path such as vent or panel like this `--panel "DIR+/rooms/evil/x130y120z0.c", you will need to correct the source as I haven't fixed the code for this yet, so please note it during submission.

## Items
items in this case aren't things you can pick up, they are instead things you can look at like the item on a desk

```
[--item1 ITEM1]
               [--item1desc ITEM1DESC] [--item2 ITEM2] [--item2desc ITEM2DESC]
               [--item3 ITEM3] [--item3desc ITEM3DESC] [--item4 ITEM4]
               [--item4desc ITEM4DESC]
```

You need to specify 2 things, the item to look at and its description, so for a desk you would use
```
--item1 desk --item1desc "This is a large wooden desk."
```

## Objects
Objects are things you can pick up, potions etc

```
[--obj1 OBJ1] [--obj2 OBJ2]
               [--obj3 OBJ3] [--obj4 OBJ4] [--obj5 OBJ5] [--obj6 OBJ6]
```

I honestly can't remember if the code is set for relative or complete paths, you'll figure it out

## monsters/npc's
```
[--mon1 MON1] [--mon2 MON2] [--mon3 MON3] [--mon4 MON4]
               [--mon5 MON5] [--mon6 MON6] [--mon7 MON7] [--mon8 MON8]
               [--mon9 MON9] [--mon10 MON10] [--mon11 MON11] [--mon12 MON12]
```

specify the monster you want to clone from your /npc's directory, uses relative links

## doors
```
[--door DOOR] [--doorkey DOORKEY] [--doorlocked DOORLOCKED]
```
--door triggers the block action that activates a door, specify `--door 1` to enable door functionality

--doorkey specifies the door key code, which is basicallt the object that needs to be present to open the door, example `--doorkey skeletonkey`

--doorlocked actually locks sets the door as locked, LOCK_D is setup in case you want to remotely lock a door, contact @evil_mog for information on that platform, to use set `--doorlocked 1`

## lights
if you want to trigger lights contact evilmog
