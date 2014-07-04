#include "DSGM.h"

DSGM_Input DSGM_newpress, DSGM_held, DSGM_release;
touchPosition DSGM_stylus;

void DSGM_UpdateInput(void) {
	scanKeys();
	
	int newpress = keysDown();
	int held = keysHeld();
	int release = keysUp();
	
	touchRead(&DSGM_stylus);
	
	#define MAP_KEY(DSGMKey, libndsKey)\
	DSGM_newpress.DSGMKey = (newpress & libndsKey);\
	DSGM_held.DSGMKey = (held & libndsKey);\
	DSGM_release.DSGMKey = (release & libndsKey)
	
	MAP_KEY(A,		KEY_A);
	MAP_KEY(B,		KEY_B);
	MAP_KEY(Select,	KEY_SELECT);
	MAP_KEY(Start,	KEY_START);
	MAP_KEY(Right,	KEY_RIGHT);
	MAP_KEY(Left,	KEY_LEFT);
	MAP_KEY(Up,		KEY_UP);
	MAP_KEY(Down,	KEY_DOWN);
	MAP_KEY(R,		KEY_R);
	MAP_KEY(L,		KEY_L);
	MAP_KEY(X,		KEY_X);
	MAP_KEY(Y,		KEY_Y);
	MAP_KEY(Touch,	KEY_TOUCH);
	MAP_KEY(Lid,	KEY_LID);
	
	#undef MAP_KEY
}
