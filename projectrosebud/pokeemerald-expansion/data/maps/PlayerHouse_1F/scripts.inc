.set LOCALID_MOM, 1


PlayerHouse_1F_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, PlayerHouse_1F_MomwatchingTV
	.byte 0

PlayerHouse_1F_MomwatchingTV::
	special TurnOnTVScreen
	return 

TextMessageFromMorgan::
	lockall
	msgbox MorgansMessage, MSGBOX_DEFAULT
	delay 30
	setvar HIDE_START_TRIGGER, 1
	msgbox ReplyToMorgan1, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, YouReply1
	release
	end

YouReply1::
	msgbox ConfirmMorgan, MSGBOX_DEFAULT
	setvar REPLYMORGAN, 1
	release
	end

AzuInteract::
	msgbox AzuBeAzuing, MSGBOX_NPC
	end

MomEngrossed::
	msgbox MomWatchingDrama, MSGBOX_NPC
	end

MorgansMessage:
	.string "Your phone buzzes in your pocket!\l"
	.string "You check it quickly. It's from\n"
	.string "your best friend, Morgan.\p"
	.string "Morgan: dnt forget we see prf Talia\n"
	.string "tmrw. Go to bed, nerd :P$"

ReplyToMorgan1:
	.string "Should I reply to his text?$"

MomWatchingDrama:
	.string "Mom's watching a drama show\p"
	.string "She's completely engrossed.$"

ConfirmMorgan:
	.string "You reply: Ya OK$"


AzuBeAzuing:
	.string "Azu! Azu!$"