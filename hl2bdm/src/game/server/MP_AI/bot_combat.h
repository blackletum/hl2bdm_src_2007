//******************************************************************
// Multiplayer AI for Source engine by R_Yell - rebel.y3ll@gmail.com
//******************************************************************

#include "cbase.h"
#include "player.h"
#include "hl2mp_player.h"
#include "in_buttons.h"
#include "movehelper_server.h"
#include "gameinterface.h"
#include "hl2mp_gamerules.h"
#include "bot_main.h"


bool AcquireEnemy( CSDKBot *pBot )
{
	float minDist = FLT_MAX;
	bool Success = false;

	for ( int i = 1; i <= gpGlobals->maxClients; i++ )
	{
		CHL2MP_Player *pPlayer = ToHL2MPPlayer( UTIL_PlayerByIndex( i ) );

		if ( pPlayer && pPlayer != NULL && pPlayer->IsAlive())
		{
			float dist = (pBot->GetLocalOrigin() - pPlayer->GetLocalOrigin()).Length();

			if( dist < minDist )
			{
				minDist = dist;
				//If the player is not on my team, find him.
				if ( HL2MPRules()->IsTeamplay() == true)
				{
					if (pPlayer->GetPlayerModelType() == PLAYER_SOUNDS_METROPOLICE || pPlayer->GetPlayerModelType() == PLAYER_SOUNDS_COMBINESOLDIER && pBot->GetPlayerModelType() == PLAYER_SOUNDS_CITIZEN )
					{
						pBot->hEnemy.Set(pPlayer);
						Success = true;
					}
					else if (pPlayer->GetPlayerModelType() == PLAYER_SOUNDS_CITIZEN && pBot->GetPlayerModelType() == PLAYER_SOUNDS_METROPOLICE || pBot->GetPlayerModelType() == PLAYER_SOUNDS_COMBINESOLDIER )
					{
						pBot->hEnemy.Set(pPlayer);
						Success = true;

					}
				}
				else
				{
					pBot->hEnemy.Set(pPlayer);
					Success = true;
				}
			}
		}
	}

	return Success;
}

void BotAttack( CSDKBot *pBot, CUserCmd &cmd )
{

	// EXCEPTIONS
	if( !pBot->m_bEnemyOnSights || !pBot->m_bInRangeToAttack || pBot->m_flNextBotAttack > gpGlobals->curtime )
		return;
	
	//Coming soon: Gravity Gun code.
	//for ( int i = 1; i <= gpGlobals->maxClients; i++ )
	//{
		//CHL2MP_Player *pPlayer = ToHL2MPPlayer( UTIL_PlayerByIndex( i ) );
	//}

	//Attack.
	cmd.buttons |= IN_ATTACK;
	pBot->m_flNextBotAttack = gpGlobals->curtime + 0.75f;

}


