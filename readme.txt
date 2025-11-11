//Patnox

RealRTCW mods

MAKE Return To Castle Wolfestein Great Again

Fix 1:

$ git diff 3.1n RealRTCW-v3.1n -- code/game/g_main.c
diff --git a/code/game/g_main.c b/code/game/g_main.c
old mode 100644
new mode 100755
index 9986370..1e241b2
--- a/code/game/g_main.c
+++ b/code/game/g_main.c
@@ -226,7 +226,8 @@ vmCvar_t            sk_ai_dmg_mg42m;
 
 cvarTable_t gameCvarTable[] = {
        // don't override the cheat state set by the system
-       { &g_cheats, "sv_cheats", "", 0, qfalse },
+       ////{ &g_cheats, "sv_cheats", "", 0, qfalse },
+       { &g_cheats, "sv_cheats", "1", CVAR_CHEAT, 0, qfalse },
 
        // noset vars
        { NULL, "gamename", GAMEVERSION, CVAR_SERVERINFO | CVAR_ROM, 0, qfalse  },
        
Fix 2:

$ git diff 3.1n RealRTCW-v3.1n -- code/server/sv_ccmds.c
diff --git a/code/server/sv_ccmds.c b/code/server/sv_ccmds.c
old mode 100644
new mode 100755
index eb4c45d..a424e7b
--- a/code/server/sv_ccmds.c
+++ b/code/server/sv_ccmds.c
@@ -302,11 +302,14 @@ static void SV_Map_f( void ) {
        // if the level was started with "map <levelname>", then
        // cheats will not be allowed.  If started with "devmap <levelname>"
        // then cheats will be allowed
+       /**
        if ( cheat ) {
                Cvar_Set( "sv_cheats", "1" );
        } else {
                Cvar_Set( "sv_cheats", "0" );
        }
+       **/
+       Cvar_Set( "sv_cheats", "1" );
 
 }



