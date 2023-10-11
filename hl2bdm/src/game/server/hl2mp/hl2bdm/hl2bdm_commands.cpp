//////////////////////////////
//
// Half-Life 2 Beta Deathmatch
// Engine Commands
//
//////////////////////////////
#include "cbase.h"

void hl2bdm_version_f( void )
{
    Msg("You are currently running:\n");
	Msg("Half-Life 2 Beta Deathmatch Beta 1.0.0\n");
}
 
ConCommand hl2bdm_version( "hl2bdm_version", hl2bdm_version_f, "Game version.");


void hl2bdm_changelog_f( void )
{
    Msg("Beta 1.0.0:\n");
	Msg("\n");
	Msg("- Changed thirdperson from centered to over the shoulder\n");
	Msg("- Added Source Shader Editor.\n");
	Msg("- Changed all weapon models to Matsilagi's models.\n");
	Msg("- OICW now acts like the beta version.\n");
	Msg("- Added HMG1.\n");
	Msg("- Added spectating.\n");
	Msg("- Added team switching to the main menu.\n");
	Msg("- Added 3 new ConVars: 'hl2bdm_version', 'hl2bdm_changelog', and 'hl2bdm_pastversions'\n");
	Msg("- Re-enabled 'cl_righthand' for flipping.\n");
	Msg("- Changed playermodel locations and animations.\n");
	Msg("- Bots now have 'HL2BDMBot01' instead of 'Bot01'\n");
	Msg("- Added Alyxgun.\n");
	Msg("- Updated the UI on the Options > Multiplayer menu.\n");
	Msg("- Removed more MI models. (hopefully)\n");
	Msg("- Improved bot AI.\n");
}
 
ConCommand hl2bdm_changelog( "hl2bdm_changelog", hl2bdm_changelog_f, "Game changelog");


void hl2bdm_pastversions_f( void )
{
	Msg("Stress Test 1.0.1\n");
	Msg("\n");
	Msg("- Removed Missing Information models and skins.\n");
	Msg("\n");
    Msg("Stress Test 1.0.0:\n");
	Msg("\n");
	Msg("- First release\n");
}
 
ConCommand hl2bdm_pastversions( "hl2bdm_pastversions", hl2bdm_pastversions_f, "Game past versions");