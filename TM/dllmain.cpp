#include "BWAPI.h"
#include "TM.hpp"

TournamentModuleManager tm;

BOOL APIENTRY DllMain(HANDLE hModule, DWORD ul_reason_for_call, LPVOID lpReserved) {
#ifdef BWAPI3
	if (ul_reason_for_call == DLL_PROCESS_ATTACH)
		BWAPI::BWAPI_init();
	return TRUE;
#elif BWAPI4
	return TRUE;
#endif
}

#ifdef BWAPI4
extern "C" __declspec(dllexport) void gameInit(BWAPI::Game *game) {
  BWAPI::BroodwarPtr = game;
}
#endif
extern "C" __declspec(dllexport) BWAPI::AIModule *newTournamentAI(
    BWAPI::Game *game) {
  return tm.bot = new TournamentModuleManager::TournamentBot;
}
extern "C" __declspec(dllexport) BWAPI::TournamentModule *newTournamentModule(
    BWAPI::Game *game) {
  return tm.mod = new TournamentModuleManager::TournamentModule;
}

#ifdef BWAPI3
#endif
