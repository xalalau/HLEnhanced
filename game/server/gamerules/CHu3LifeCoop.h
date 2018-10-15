#ifndef GAME_SERVER_GAMERULES_CHU3FLIFECOOP_H
#define GAME_SERVER_GAMERULES_CHU3FLIFECOOP_H

class CBaseEntity;
class CSprite;

//Guardar as informacoes dos players
struct playerCoopWeapons {
	char name[30];
	int currentammo;
	char type1[20];
	int amountammo1;
	char type2[20];
	int amountammo2;
};

struct playerCoopSaveRestore {
	Vector relPos;
	Vector v_angle;
	Vector velocity;
	Vector angles;
	Vector punchangle;
	bool newplayer; // Controle do respawn
	bool changinglevel; // Serve para o hack de acerto das municoes
	bool waitingforchangelevel; // Serve para prender os jogadores numa posicao valida de changelevel
	int weapons; // HUD
	int team;
	float armorvalue;
	bool bInDuck;
	bool flashlight;
	int deadflag;
	int fixangle;
	float health;
	float frags;
	float flFallVelocity;
	char *pName;
	bool godmode;
	bool notarget;
	bool noclip;
	bool respawncommands; // Uso isso para finalizar changelevels ou mortes do jogador
	float notSolidWait; // Tempo minimo que o jogador precisa levar no estado nao solido assim que spawna
	int cam_hu3_crosshair;
	struct playerCoopWeapons keepweapons[64];
};

// Guardar as infos dos jogadores
extern struct playerCoopSaveRestore CoopPlyData[64];

// Nome do landmark em uso
extern char hu3LandmarkName[32];

// Index de um jogador (uso para a troca de nomes. Nao inventar outros usos!)
extern int hu3CoopPlyIndex;
// Novo nome de um jogador
extern char hu3NetNewName[32];
// Se um nome precisa ser alterado ou nao
extern bool hu3ChangeNetName;

// Liga o processamento de trigger_changelevel no think do modo coop
extern bool hu3ChangelevelCheck;

// Pequeno atraso no inicio de func_tracktrains (segundos)
extern int hu3TracktrainDelay;


#endif //GAME_SERVER_GAMERULES_CHU3FLIFECOOP_H
