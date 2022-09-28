	function scr_dim_playerstate_free_krus(){
//визначення швидкості руху персонажа (біг, спокійна хотьба)
if(status = STATUS.ACTIVE){
	if (move == 0 ) spd = walkspd;
	else spd = runspd;

	directx = keyr - keyl; 
	directy = keyup - keydown;
	//directxy -= directxy - directx ;
	// змешення швидкості ходьби по діагоналі
	if( directy !=0 && directx !=0 ) spd=spd*0.8; 

	hsp = directx*spd;
	vsp = directy*spd*0.5;
	if instance_exists(obj_pauser){
		hsp = 0;
		vsp = 0;
	}
	x += hsp
	y -= vsp

	//горизонтальна колізія
	if(place_meeting(x + hsp, y, obj_invisiblewall)){
		while(!place_meeting(x+sign(hsp), y, obj_invisiblewall))
			x += sign(hsp);
		hsp = 0;
	}

	//вертикальна колізія
	if(place_meeting(x, y + vsp, obj_invisiblewall)){
		while(!place_meeting(x, y + sign(vsp) , obj_invisiblewall))
			y += sign(vsp);
		vsp = 0;
	}
}

sprit="Krus";

// анімація ходьби по вертикалі відповідно до останнього напрямку руху по горизонталі

if (y!=yprevious && lastmove==0 ) sprite_index = asset_get_index( "spr_dim_" + sprit +"_move_right");
if (y!=yprevious && lastmove==1 ) sprite_index = asset_get_index( "spr_dim_" + sprit + "_move_left");

if (x>xprevious){ sprite_index = asset_get_index("spr_dim_" + sprit +"_move_right");
 lastmove = 0;}
if (keyboard_check(vk_space) and keyr) {sprite_index =asset_get_index ("spr_dim_" + sprit +"_run_right");runspd =8;}
 
if (x<xprevious){ sprite_index = asset_get_index("spr_dim_" + sprit + "_move_left");
if (keyboard_check(vk_space) and keyl) {sprite_index =asset_get_index ("spr_dim_" + sprit +"_run_left");runspd = 8;}	
lastmove = 1;}
if (x==xprevious && y==yprevious && lastmove ==0) sprite_index = asset_get_index("spr_dim_" + sprit + "_stay_r");
if (x==xprevious && y==yprevious && lastmove ==1) sprite_index = asset_get_index("spr_dim_" + sprit + "_stay_l");
// відповідність глибини до вертикальної кординати
//depth = -y;
// відповідність глибини до вертикальної кординати
//depth = -y;
}