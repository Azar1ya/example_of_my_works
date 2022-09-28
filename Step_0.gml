
//якщо магазин відкритий, гравець нерухомий
if (global.shop) exit;

//система зміни статусу гравця
if(keyboard_check(ord("1"))) status = STATUS.ACTIVE;
if(keyboard_check(ord("2"))) status = STATUS.PASSIVE;

switch(status){
	case STATUS.ACTIVE : scr_play_player()   ; break;
	case STATUS.PASSIVE: scr_passive_player(); break;
}


 switch(state){
 case	PLAYERSTATE.FREE	 : scr_dim_playerstate_free_ytopurok();    break;
 } 


if (x!= xprevious or y!= yprevious){
	for(var i = array_size-1; i > 0; i--){
		posX[i] = posX[i-1];
		posY[i] = posY[i-1];
	}

	posX[0] = x;
	posY[0] = y;
}