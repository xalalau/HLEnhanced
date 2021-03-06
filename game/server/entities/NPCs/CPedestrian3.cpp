// ##############################
// HU3-LIFE PEDESTRE 3
// ##############################

#include "extdll.h"
#include "util.h"
#include "cbase.h"
#include "Monsters.h"
#include "CTalkMonster.h"
#include "Schedule.h"
#include "DefaultAI.h"
#include "animation.h"
#include "entities/CSoundEnt.h"
#include "CScientist.h"
#include "CPedestrian1.h"

#include "CPedestrian3.h"

BEGIN_DATADESC(	CPedestrian3 )
	DEFINE_FIELD( m_painTime, FIELD_TIME ),
	DEFINE_FIELD( m_healTime, FIELD_TIME ),
	DEFINE_FIELD( m_fearTime, FIELD_TIME ),
END_DATADESC()

LINK_ENTITY_TO_CLASS(monster_pedestre_3, CPedestrian3);

//=========================================================
// Spawn
//=========================================================
void CPedestrian3::Spawn(void)
{
	PRECACHE_MODEL("models/pedestre_3.mdl");
	Precache();

	SetModel("models/pedestre_3.mdl");
	SetSize(VEC_HUMAN_HULL_MIN, VEC_HUMAN_HULL_MAX);

	pev->solid = SOLID_SLIDEBOX;
	pev->movetype = MOVETYPE_STEP;
	m_bloodColor = BLOOD_COLOR_RED;
	pev->health = gSkillData.GetScientistHealth();

	pev->view_ofs = Vector(0, 0, 50);// position of the eyes relative to monster's origin.
	m_flFieldOfView = VIEW_FIELD_WIDE; // NOTE: we need a wide field of view so scientists will notice player and say hello
	m_MonsterState = MONSTERSTATE_NONE;

	//	m_flDistTooFar		= 256.0;

	m_afCapability = bits_CAP_HEAR | bits_CAP_TURN_HEAD | bits_CAP_OPEN_DOORS | bits_CAP_AUTO_DOORS | bits_CAP_USE;

	MonsterInit();
	SetUse(&CScientist::FollowerUse);
}