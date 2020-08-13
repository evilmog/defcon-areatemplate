# Introduction
Welcome to the DEFCON MUD Writeup, this will cover the trials and tribulations of building the Evil Mog mud for DEFCON 2020.

# Background
The MUD officially started sometime in 2018. A MUD or Multi User Dungeon is a text based game running on a telnet server. This
particular one happens to be built using a language called LPC using DGD (Dworkins Game Driver) and the Gurbalib.

The original LPMUD's based on MudOS and lpmud 2.4.5 has a clause that stipulated that they not be used for commercial use. Current
MUD's such as LDMUD, MudOS, and FluffOS all have this restriction. Back in the 90's a clean room implementation was created called DGD
which later was used as the underlying technology behind Yahoo chat rooms. DGD was always free for non commercial use but in 2010 the
fork which allows commercial use was open sourced.

LPMUD's are split into a driver and a mudlib. The driver is basically the LPC Interpreter and the mudlib implements all of the game logic
including rooms, players, objects, basically everything is an LPC file. Where DGD comes in handy is the entire game can be recompiled while
the game is running. The only problem with stock DGD is the telnet server in it is fairly limited in that it doesn't support telnet option
negotiations.

I contacted Felix the author of DGD and he suggested instead moving the telnet server to the mudlib abd bypassing the driver entirely. As
I didn't have the skill for this I paid Felix to port the drivers telnet server to LPC for me so I could implement things like GMCP.

Telnet sub option negotiations are negotiated over RFC 854/855, this includes GMCP. So I spent a few months pouring over specification
documents such as <https://tintin.mudhalla.net/protocols/gmcp/> in order to add on enhancements.  GMCP allows for out of band communication
with a mud client in a way that is hidden from the user. Now GMCP doesn't really define data to send and mudlet doesn't really care as long
as it matches up to the lua scripts which allows for some fun shenanigans later.

In order to reduce attack surface only 5 or 6 GMCP commands were actually implemented, all other details were sent as a 'push' to prevent
weird things from happening.

# Coding
The interesting thing about this game is that about 60% of it was copied from Coremud.org run by David Shay. Now when I say copied
I don't mean I copied the source code. I wrote a python tool to generate LPC, logged onto the game and copied room descriptions into
shell scripts which called the python tool and generated LPC.

A room would look like this:
```
python room_p.py --name x0y0z0 --area city --short "Central Hub" --long "This is an example room long description" --mon1 evilmog --sw 1 --ne 1
```

This would automatically place a room file x0y0z0.c with exits going sw to x-10y-10z0 and ne to x10y10z0 with a monster named evilmog.

The nice part about building this way is 90% of the code is boiler plate and customization could be done after the fact. Also if a foundational
change was made to the mud library, auto regenerating the game would take all of 5 minutes.

Other areas such as labyrinth, woodland, and dungeon were generated with random room descriptions and monster placement, this allowed a mud
of 1200+ rooms to be created or copied by a single person over the course of 2 years.

# Cheats
The initial concept for the game was that there is no such thing as cheating, bots and anything would be approved, however certain exploits
were discovered that were rapidly closed.

Fixed exploits:

* path traversal and LFI vulnerability discovered in baseline Gurbalib by David Byrne
* negative money, you could drop more money than you had, your inventory would go negative but your sock could pick it up
* some shops paid you money when you purchased things

These exploits were semi intentional

Unfixed exploits:

* telportation bug - use set start_room to set your start location to the wizard potion room, pickup potion, hit reset, stock up and teleport around as the wizard potion returns you to your start_room without recall penalties
* lockpick bypass - some doors were vulnerable to lockpicks and quests could be bypassed
* unbalanced gameplay - use a normal player to get level 20 gear and give to a fed, basically once you have 2 or 3 level 20 armour and a pair of level 20 swords, all mobs die instantly

GMCP Cheats:

* Evil.Mog.Authenticate [insert string here] - this used to give you full admin, removed prior to defcon
* External.cheat.ariana.deathproof - grants death proof
* External.cheat.ariana.rearm - resets the death counter
* External.cheat.ariana.heal - heals you to full health

There were a few other cheat codes that activated the cheat console, those have been removed as the cheatconsole is
unlocked now.

# Trolling
The game initially reset you to level 1 on death but for defcon we decided to up the ante and make it so if you died 3 times we deleted your character.

This is a troll because level up until defcon didn't really matter, what mattered were stats. By adding the 3 lives limit it gave the appearance of being hard but still having bypasses.

The sword of 1000 truths was another troll, the code basically looks like this:
```
#include "../domain.h"

inherit "/std/weapon";

void set_sword_skill(string s) {
   if (!is_standard_weapon_skill(s)) {
      s = "small";
   }
   set_weapon_skill("combat/edge/" + s);
}

void setup(void) {
   set_id("sword of 1000 truths");
   add_id("sword");
   add_id("1000");
   set_adj("1000");
   set_short("A sword of 1000 truths");
   set_long("This is the fabled sword of 1000 truths, it can destroy anything, you can power it up with '%^MAGENTA%^powerup%^RESET%^' Be warned this sword has a 20% chance of killing you when you power it up. Type %^MAGENTA%^recycle%^RESET%^ to recycle me.");
   set_gettable(1);

   set_min_damage(1);
   set_max_damage(1);
   set_hit_bonus(1);

   add_action("do_recycle", "recycle");
   add_action("do_powerup", "powerup");
   set_wield_type("single");
   set_weapon_actions(({
      "slash", "slice", "dice", "cut", "gash", "stab", "poke", "gouge"
      }));
   set_sword_skill("small");

   set_value(100000000);
   set_size(2);
   set_weight(600);

}

int do_powerup(string arg) {
  int powerup;
  powerup = random(5);
  if (query_admin(this_player())) {
    write("Holy hell you are lucky, your sword powered up");
    this_object()->set_min_damage(1000);
    this_object()->set_max_damage(2000);
    this_object()->set_hit_bonus(1000);
    return 1;
  }

  if (powerup == 1) {
    write("shit I guess you died");
    this_player()->die();
    return 1;
  }

  if (powerup == 2) {
    write("Your sword has sortof powered up");
    this_object()->set_min_damage(1);
    this_object()->set_max_damage(1000);
    this_object()->set_hit_bonus(10);
    return 1;
  }
  if (powerup == 3) {
    write("shit I guess you died");
    this_player()->die();
    return 1;
  }
  if (powerup == 4) {
    write("Your sword is mostly useless, but atleast you aren't dead, retry?");
    this_object()->set_min_damage(1);
    this_object()->set_max_damage(1);
    this_object()->set_hit_bonus(0);
    return 1;
  }
  if (powerup == 5) {
    write("Its a normal sword.....");
    this_object()->set_min_damage(1);
    this_object()->set_max_damage(20);
    this_object()->set_hit_bonus(0);
    return 1;
  }
  do_powerup("");
  return 1;
}

int destroy_me(string args) {
  this_object()->destruct();
  return 1;
}
```

As you can see its not the most useful sword, but even the normal sword mode was pretty useful.

# Quests
There are a bunch of writeups on the MUD already, I made sure people had to research the mud to beat the quests. This added
an OSINT level challenge, for example I released the location of the lockpicks needed to break into the store room for the
Evil Quest during an iron sysadmin podcast.

# Future
This wasn't a complete writeup, I'll add to it as I go, that being said the defcon MUD will be online for a while as I get it
ready for next year.