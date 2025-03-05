VelvetRoom_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, VelvetRoomCheckFirst
	.byte 0

VelvetRoomCheckFirst::
	goto_if_eq VAR_VELVETROOM_STATE, 1, VelvetRoom_WelcomeBack
	goto_if_eq VAR_VELVETROOM_STATE, 2, VelvetRoom_SacrificeEnable
	release
	end

VelvetRoom_WelcomeBack::
	release
	end

VelvetRoom_SacrificeEnable::
	release
	end
