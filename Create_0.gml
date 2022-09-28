mask_index = sprite_index;
walkspd = 4;
runspd  = 15;
collisionSpeed = 4;
lastmove = 0;

//налаштування перемикання між персонажами 
playernum = 1;
status = STATUS.ACTIVE
enum STATUS{
ACTIVE,
PASSIVE,
}

/*sound = snd_rivalstation;
audio_play_sound(sound,1,1);*/

state=PLAYERSTATE.FREE;
hitByAttack = ds_list_create();
enum PLAYERSTATE{
FREE,
}

//Частина 1 системи слідкування за героєм
array_size = 15; 
for(var i = array_size-1; i >= 0; i--){
	posX[i] = x; 
	posY[i] = y;		
}

//inventory
global.inv = ds_list_create();
