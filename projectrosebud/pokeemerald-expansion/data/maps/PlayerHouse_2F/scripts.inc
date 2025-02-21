.set OBJ_EVENT_GFX_SPECIES(ZORUA), 1

PlayerHouse_2F_MapScripts::
	.byte 0

EventStartSleep::
	lockall
	msgbox TimeToSleep, MSGBOX_DEFAULT
	fadescreen FADE_TO_BLACK
	delay 30
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	msgbox SleepyCallZorua, MSGBOX_DEFAULT
	addobject OBJ_EVENT_GFX_SPECIES(ZORUA)
	setobjectxy OBJ_EVENT_GFX_SPECIES(ZORUA), 7,6
	turnobject OBJ_EVENT_GFX_SPECIES(ZORUA), DIR_NORTH
	fadescreen FADE_FROM_BLACK
	delay 30
	msgbox ZoruaLaugh, MSGBOX_DEFAULT
