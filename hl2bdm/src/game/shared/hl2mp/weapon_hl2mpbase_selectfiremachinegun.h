//========= Copyright © 1996-2005, Valve Corporation, All rights reserved. ============//
//
// Purpose: 
//
//=============================================================================//

#include "weapon_hl2mpbase.h"

#ifndef BASEHLCOMBATWEAPON_H
#define BASEHLCOMBATWEAPON_H
#ifdef _WIN32
#pragma once
#endif

#if defined( CLIENT_DLL )
	#define CHL2MPSelectFireMachineGun C_HL2MPSelectFireMachineGun
#endif

//=========================================================
// Machine gun base class
//=========================================================
class CHL2MPSelectFireMachineGun : public CWeaponHL2MPBase
{
public:
	DECLARE_CLASS( CHL2MPSelectFireMachineGun, CWeaponHL2MPBase );
	DECLARE_DATADESC();

	CHL2MPSelectFireMachineGun();
	
	DECLARE_NETWORKCLASS(); 
	DECLARE_PREDICTABLE();

	void	PrimaryAttack( void );
	void   	SecondaryAttack( void );    // Firemode implementer

	// Default calls through to m_hOwner, but plasma weapons can override and shoot projectiles here.
	virtual void	ItemPostFrame( void );
	virtual void	FireBullets( const FireBulletsInfo_t &info );
	virtual bool	Deploy( void );

	virtual const Vector &GetBulletSpread( void );

	int				WeaponSoundRealtime( WeaponSound_t shoot_type );

	// utility function
	static void DoMachineGunKick( CBasePlayer *pPlayer, float dampEasy, float maxVerticleKickAngle, float fireDurationTime, float slideLimitTime );

private:
	
	CHL2MPSelectFireMachineGun( const CHL2MPSelectFireMachineGun & );

protected:

	bool m_bFMReady;          // Firemode Ready switch
	bool m_bFMAutomatic;      // Firemode Automatic switch
	int m_nBurstRate;         // Variable burst rate
	int m_nFireMode;          // Firemode value (0 safety,1 single fire,2 burst,3 auto)
	int m_nShotsLeft;         // Firemode remaining shots
	
	int	m_nShotsFired;	// Number of consecutive shots fired
	float m_flNextSoundTime;	// real-time clock of when to make next sound
};

#endif // BASEHLCOMBATWEAPON_H
