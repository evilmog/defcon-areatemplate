# Introduction
This file generates NPC's for use with the area generator

```
  --name NAME      npc name
  --label LABEL    npc label
  --level LEVEL    level
  --short SHORT    short desc
  --scolor SCOLOR  short desc color
  --long LONG      long desc
  --lcolor LCOLOR  long desc color
  --gender GENDER  gender
  --race RACE      race
  --aggro AGGRO    sets aggressive
  --id1 ID1        additional id
  --id2 ID2        additional id
  --id3 ID3        additional id
  --id4 ID4        additional id
  --id5 ID5        additional id
  --id6 ID6        additional id
  --obj1 OBJ1      objects to hold
  --obj2 OBJ2      objects to hold
  --obj3 OBJ3      objects to hold
  --obj4 OBJ4      objects to hold
  --obj5 OBJ5      objects to hold
  --obj6 OBJ6      objects to hold
```

## name
name in this case isn't important, its just the filename you use when you add it in your area like `--name bob`

## label
label is what it gets its name set to in the room `--label "big bob"`

## ids
id's are additional short names for the item, like big bob would be big and bob or `--id1 big --id2 bob --id3 bigbob --id4 "big bob"

## race
the npc's race, human, hacker, ant, goblin, etc
`--gender human`


## gender
the npc's gender, male, female, unicorn

`--gender unicorn`

## level
how hard the npc is

`--level 6`

we will relevel your area, also try to keep all npc's around the same level

## aggressive
this makes the mob auto attack

`--aggro 1`

## short
what the npc appears as in the short description such as `--short "Big Bob"

## long
the long description, how the npc appears when you look at it `--long "This is big bob, he will squish you."`

