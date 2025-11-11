//Patnox

# RealRTCW mods

MAKE Return To Castle Wolfestein Great Again

## Fix 1:

$ git diff 5.2 RealRTCW-v5.2 -- code/game/g_main.c
diff --git a/code/game/g_main.c b/code/game/g_main.c
index cb3d122..d74c9a5 100644
--- a/code/game/g_main.c
+++ b/code/game/g_main.c
@@ -182,8 +182,9 @@ vmCvar_t g_playerSurvivalClass;
 vmCvar_t g_mapname;
 
 cvarTable_t gameCvarTable[] = {
-       // don't override the cheat state set by the system
-       { &g_cheats, "sv_cheats", "", 0, qfalse },
+       // PATNOX - ENABLE CHEATS
+       //// { &g_cheats, "sv_cheats", "", 0, qfalse },
+       { &g_cheats, "sv_cheats", "1", CVAR_CHEAT, 0, qfalse },
 
        // noset vars
        { NULL, "gamename", GAMEVERSION, CVAR_SERVERINFO | CVAR_ROM, 0, qfalse  },
        
        
## Fix 2:

$ git diff 5.2 RealRTCW-v5.2 -- code/server/sv_ccmds.c
diff --git a/code/server/sv_ccmds.c b/code/server/sv_ccmds.c
index 4bc9088..b5a442f 100644
--- a/code/server/sv_ccmds.c
+++ b/code/server/sv_ccmds.c
@@ -330,11 +330,15 @@ static void SV_Map_f( void ) {
        // if the level was started with "map <levelname>", then
        // cheats will not be allowed.  If started with "devmap <levelname>"
        // then cheats will be allowed
+       // PATNOX - ENABLE CHEATS
+       /** 
        if ( cheat ) {
                Cvar_Set( "sv_cheats", "1" );
        } else {
                Cvar_Set( "sv_cheats", "0" );
        }
+       */
+       Cvar_Set( "sv_cheats", "1" );
 
 }

## Fix 3:

$ git diff 5.2 RealRTCW-v5.2 -- code/client/cl_main.c
diff --git a/code/client/cl_main.c b/code/client/cl_main.c
index ee923ee..131924c 100644
--- a/code/client/cl_main.c
+++ b/code/client/cl_main.c
@@ -1470,10 +1470,11 @@ void CL_Disconnect( qboolean showMainMenu ) {
        clc.state = CA_DISCONNECTED;
 
        // allow cheats locally
-#ifndef WOLF_SP_DEMO
+       // PATNOX - ENABLE CHEATS
+//// #ifndef WOLF_SP_DEMO
        // except for demo
-       Cvar_Set( "sv_cheats", "0" );
-#endif
+       Cvar_Set( "sv_cheats", "1" );
+//// #endif
 
        // not connected to a pure server anymore
        cl_connectedToPureServer = qfalse;

## Fix 4:

$ git diff 5.2 RealRTCW-v5.2 -- code/qcommon/cvar.c
diff --git a/code/qcommon/cvar.c b/code/qcommon/cvar.c
index 8860156..956ab95 100644
--- a/code/qcommon/cvar.c
+++ b/code/qcommon/cvar.c
@@ -1418,7 +1418,8 @@ void Cvar_Init( void )
        Com_Memset(cvar_indexes, '\0', sizeof(cvar_indexes));
        Com_Memset(hashTable, '\0', sizeof(hashTable));
 
-       cvar_cheats = Cvar_Get( "sv_cheats", "0", CVAR_ROM | CVAR_SYSTEMINFO );
+       // PATNOX - ENABLE CHEATS
+       cvar_cheats = Cvar_Get( "sv_cheats", "1", CVAR_ROM | CVAR_SYSTEMINFO );
 
        Cmd_AddCommand ("print", Cvar_Print_f);
        Cmd_AddCommand( "toggle", Cvar_Toggle_f );

## Fix 5:

$ git diff 5.2 RealRTCW-v5.2 -- sdk/rtcw-bspc-custom/src/cgame/cg_info.c
diff --git a/sdk/rtcw-bspc-custom/src/cgame/cg_info.c b/sdk/rtcw-bspc-custom/src/cgame/cg_info.c
index 5f45326..b7a12b1 100644
--- a/sdk/rtcw-bspc-custom/src/cgame/cg_info.c
+++ b/sdk/rtcw-bspc-custom/src/cgame/cg_info.c
@@ -601,12 +601,13 @@ void CG_DrawInformation( void ) {
        }
 
        // cheats warning
-       s = Info_ValueForKey( sysInfo, "sv_cheats" );
-       if ( s[0] == '1' ) {
-               UI_DrawProportionalString( 320, y, "CHEATS ARE ENABLED",
-                                                                  UI_CENTER | UI_SMALLFONT | UI_DROPSHADOW, colorWhite );
-               y += PROP_HEIGHT;
-       }
+       // PATNOX - ENABLE CHEATS
+       // s = Info_ValueForKey( sysInfo, "sv_cheats" );
+       // if ( s[0] == '1' ) {
+       //      UI_DrawProportionalString( 320, y, "CHEATS ARE ENABLED",
+       //                                                         UI_CENTER | UI_SMALLFONT | UI_DROPSHADOW, colorWhite );
+       //      y += PROP_HEIGHT;
+       // }
 
        // game type
        switch ( cgs.gametype ) {

## Fix 6:

$ git diff 5.2 RealRTCW-v5.2 -- sdk/rtcw-bspc-custom/src/client/cl_main.c
diff --git a/sdk/rtcw-bspc-custom/src/client/cl_main.c b/sdk/rtcw-bspc-custom/src/client/cl_main.c
index 20abecb..8d0f183 100644
--- a/sdk/rtcw-bspc-custom/src/client/cl_main.c
+++ b/sdk/rtcw-bspc-custom/src/client/cl_main.c
@@ -761,11 +761,12 @@ void CL_Disconnect( qboolean showMainMenu ) {
 
        cls.state = CA_DISCONNECTED;
 
+       // PATNOX - ENABLE CHEATS
        // allow cheats locally
-#ifndef WOLF_SP_DEMO
+////#ifndef WOLF_SP_DEMO
        // except for demo
        Cvar_Set( "sv_cheats", "1" );
-#endif
+////#endif
 
        // not connected to a pure server anymore
        cl_connectedToPureServer = qfalse;

## Fix 7:

$ git diff 5.2 RealRTCW-v5.2 -- sdk/rtcw-bspc-custom/src/game/g_main.c
diff --git a/sdk/rtcw-bspc-custom/src/game/g_main.c b/sdk/rtcw-bspc-custom/src/game/g_main.c
index d0eda0a..e79f942 100644
--- a/sdk/rtcw-bspc-custom/src/game/g_main.c
+++ b/sdk/rtcw-bspc-custom/src/game/g_main.c
@@ -141,8 +141,9 @@ vmCvar_t g_soldierChargeTime;
 vmCvar_t g_playerStart;         // set when the player enters the game
 
 cvarTable_t gameCvarTable[] = {
-       // don't override the cheat state set by the system
-       { &g_cheats, "sv_cheats", "", 0, qfalse },
+       // PATNOX - ENABLE CHEATS
+       //// { &g_cheats, "sv_cheats", "", 0, qfalse },
+       { &g_cheats, "sv_cheats", "1", CVAR_CHEAT, 0, qfalse },
 
        // noset vars
        { NULL, "gamename", GAMEVERSION, CVAR_SERVERINFO | CVAR_ROM, 0, qfalse  },

## Fix 8:

$ git diff 5.2 RealRTCW-v5.2 -- sdk/rtcw-bspc-custom/src/qcommon/cvar.c
diff --git a/sdk/rtcw-bspc-custom/src/qcommon/cvar.c b/sdk/rtcw-bspc-custom/src/qcommon/cvar.c
index 1a3745a..bd276d8 100644
--- a/sdk/rtcw-bspc-custom/src/qcommon/cvar.c
+++ b/sdk/rtcw-bspc-custom/src/qcommon/cvar.c
@@ -895,7 +895,7 @@ Reads in all archived cvars
 ============
 */
 void Cvar_Init( void ) {
-       cvar_cheats = Cvar_Get( "sv_cheats", "0", CVAR_ROM | CVAR_SYSTEMINFO );
+       cvar_cheats = Cvar_Get( "sv_cheats", "1", CVAR_ROM | CVAR_SYSTEMINFO );
 
        Cmd_AddCommand( "toggle", Cvar_Toggle_f );
        Cmd_AddCommand( "set", Cvar_Set_f );

## Fix 9:

$ git diff 5.2 RealRTCW-v5.2 -- sdk/rtcw-bspc-custom/src/server/sv_ccmds.c
diff --git a/sdk/rtcw-bspc-custom/src/server/sv_ccmds.c b/sdk/rtcw-bspc-custom/src/server/sv_ccmds.c
index 4d9274a..92449a7 100644
--- a/sdk/rtcw-bspc-custom/src/server/sv_ccmds.c
+++ b/sdk/rtcw-bspc-custom/src/server/sv_ccmds.c
@@ -285,11 +285,14 @@ static void SV_Map_f( void ) {
        // if the level was started with "map <levelname>", then
        // cheats will not be allowed.  If started with "devmap <levelname>"
        // then cheats will be allowed
+       /**
        if ( cheat ) {
                Cvar_Set( "sv_cheats", "1" );
        } else {
                Cvar_Set( "sv_cheats", "0" );
        }
+       */
+       Cvar_Set( "sv_cheats", "1" );
 
 }

## Fix 10:

$ git diff 5.2 RealRTCW-v5.2 -- sdk/rtcw-bspc-custom/src/server/sv_init.c
diff --git a/sdk/rtcw-bspc-custom/src/server/sv_init.c b/sdk/rtcw-bspc-custom/src/server/sv_init.c
index cdb1477..a1ac9bf 100644
--- a/sdk/rtcw-bspc-custom/src/server/sv_init.c
+++ b/sdk/rtcw-bspc-custom/src/server/sv_init.c
@@ -917,7 +917,7 @@ void SV_Init( void ) {
        sv_allowAnonymous = Cvar_Get( "sv_allowAnonymous", "0", CVAR_SERVERINFO );
 
        // systeminfo
-       Cvar_Get( "sv_cheats", "0", CVAR_SYSTEMINFO | CVAR_ROM );
+       Cvar_Get( "sv_cheats", "1", CVAR_SYSTEMINFO | CVAR_ROM );
        sv_serverid = Cvar_Get( "sv_serverid", "0", CVAR_SYSTEMINFO | CVAR_ROM );
 //----(SA) VERY VERY TEMPORARY!!!!!!!!!!!
 //----(SA) this is so Activision can test milestones with

# BUILD
$ make BUILD_STANDALONE=1 STEAM=0
