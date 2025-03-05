

PlayerHouse_2F_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, HideTheZorua
	.byte 0

EventStartSleep::
	lockall
	setvar VAR_NIGHTTIME_ROOM, 1
	msgbox TimeToSleep, MSGBOX_DEFAULT
	fadescreen FADE_TO_BLACK
	clearflag FLAG_TEMP_7
	delay 30
	setweather WEATHER_SHADE
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	msgbox SleepyCallZorua, MSGBOX_DEFAULT
	fadescreen FADE_FROM_BLACK
	delay 30
	playmoncry SPECIES_ZORUA, 0
	msgbox ZoruaLaugh, MSGBOX_DEFAULT
	applymovement OBJ_EVENT_GFX_SPECIES(ZORUA), ZoruaWalkComp
	waitmovement 0
	applymovement OBJ_EVENT_GFX_SPECIES(ZORUA), ZoruaTransform
	waitmovement 0
	setflag FLAG_TEMP_7
	clearflag FLAG_TEMP_5
	applymovement OBJ_EVENT_GFX_RED, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	applymovement OBJ_EVENT_GFX_RED, Common_Movement_WalkInPlaceFasterUp
	msgbox ZoruaTyping, MSGBOX_DEFAULT
	applymovement OBJ_EVENT_GFX_RED, ZoruaToWindow
	applymovement OBJ_EVENT_GFX_RED, ZoruaTransform
	setflag FLAG_TEMP_5
	clearflag FLAG_TEMP_6
	removeobject OBJ_EVENT_GFX_RED
	waitmovement 30
	playmoncry SPECIES_ZORUA, 0
	msgbox ZoruaLaugh, MSGBOX_AUTOCLOSE
	applymovement OBJ_EVENT_GFX_PIKACHU, ZoruaJumpWindow
	removeobject OBJ_EVENT_GFX_PIKACHU
	msgbox PokemonJumpedWindow, MSGBOX_DEFAULT
	setflag FLAG_TEMP_6
	releaseall
	end

TriggerNighttime::
	lockall
	msgbox DontLeaveRoom, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, ThisWalksRight
	releaseall
	end

ComputerActivate::
	lockall
	goto_if_eq VAR_NIGHTTIME_ROOM, 1, WarpToVelvetRoom
	msgbox Computer, MSGBOX_SIGN
	releaseall
	end

WarpToVelvetRoom::
	msgbox ZoruaGoodLuck, MSGBOX_DEFAULT
	releaseall
	warpteleport MAP_VELVET_ROOM, 10, 13
	waitstate
	end

Computer:
	.string "It's your computer. You have no reason\n"
	.string "to use this right now.$"

TimeToSleep:
	.string "Got a big day tomorrow. Time to rest.$"

DontLeaveRoom:
	.string "It's the middle of night. Why leave?$"
	
SleepyCallZorua:
	.string "Snore...\p"
	.string "Snore...\p"
	.string "SNORE...\p"
	.string "...Strange, you feel something on your\n"
	.string "chest!$"

ZoruaLaugh:
	.string "Zohohoho!$"

ZoruaTyping:
	.string "It sounds like Zorua typed something!$"

PokemonJumpedWindow:
	.string "The pokemon jumped out the window!!$"

ZoruaGoodLuck:
	.string "The screen reads GOOD LUCK...\p"
	.string "Wait, what's happening??$"

ThisWalksRight:
	walk_right
	step_end

ZoruaWalkComp:
	applymovement OBJ_EVENT_GFX_ZORUA, Movement_JumpRight
	walk_right
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

ZoruaTransform::
	face_left
	face_down
	face_right
	face_up
	face_left
	face_down
	face_right
	face_up
	face_left
	face_down
	face_right
	face_up
	step_end

ZoruaToWindow:
	walk_left
	walk_left
	walk_left
	step_end

ZoruaJumpWindow:
	walk_fast_up
	applymovement OBJ_EVENT_GFX_PIKACHU, Movement_JumpUp
	step_end

