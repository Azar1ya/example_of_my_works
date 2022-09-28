// Script assets have changed for v2.3.0 see
// https://help.yoyogames.com/hc/en-us/articles/360005277377 for more information
function scr_passive_player(){
event_inherited();
move     =  keyboard_check(vk_space);
keyr     =  keyboard_check(ord("D")) && place_free(x + collisionSpeed,y);
keyl     =  keyboard_check(ord("A")) && place_free(x - collisionSpeed,y);
keyup    =  keyboard_check(ord("W")) && place_free(x,y - collisionSpeed);
keydown  =  keyboard_check(ord("S")) && place_free(x,y + collisionSpeed);
key_room_go = keyboard_check(ord("E"))

//унаслідування координат гравця


if (playernum == 2) {
	//walk
	if (move == 0) mp_linear_step_object(obj_dim_player1.posX[10], obj_dim_player1.posY[10], 5, obj_woi_invisible_wall);
	//run
	if (move == 1) mp_linear_step_object(obj_dim_player1.posX[10], obj_dim_player1.posY[10], 10, obj_woi_invisible_wall);
	//teleport
	if (distance_to_object(obj_dim_player1) > 100)
	{
		x = obj_dim_player1.posX[10]
		y = obj_dim_player1.posY[10]
	}
	}
else if(playernum == 1){
	//walk
	if (move == 0) mp_linear_step_object(obj_dim_player2.posX[10], obj_dim_player2.posY[10], 5, obj_woi_invisible_wall);
	//run
	if (move == 1) mp_linear_step_object(obj_dim_player2.posX[10], obj_dim_player2.posY[10], 10, obj_woi_invisible_wall);
	//teleport
	if (distance_to_object(obj_dim_player2) > 100)
	{
		x = obj_dim_player2.posX[10]
		y = obj_dim_player2.posY[10]
	}
}

}
