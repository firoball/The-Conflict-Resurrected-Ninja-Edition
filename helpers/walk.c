#include <default.c>
#include <mtlfx.c>

VECTOR vecPos;
ANGLE vecAng;
var cnt;

void printpos()
{
	var h =file_open_append("pos.txt");
	file_var_write(h, integer(cnt));
	file_str_write(h, ") pos ");
	file_var_write(h, integer(vecPos.x));
	file_var_write(h, integer(vecPos.y));
	file_var_write(h, integer(vecPos.z));
	file_str_write(h, "\t ang ");
	file_var_write(h, integer(vecAng.pan));
	file_var_write(h, integer(vecAng.tilt));
	file_var_write(h, integer(vecAng.roll));
	file_str_write(h, "\n\r");
	file_close(h);
	cnt++;
	beep();
}

void main()
{
	VECTOR vecFrom;
	VECTOR vecTo;
	var vTemp;
	d3d_antialias=9;
	//mouse_mode = 2;
	//on_mouse_left = printpos;
	wait(1);
	level_load("h.wmb");
	while(1)
	{ 
		wait(1);
		mouse_pos.x = mouse_cursor.x;    
		mouse_pos.y = mouse_cursor.y;

		vec_set(&vecTo, &mouse_dir3d);
		vec_scale(&vecTo, 3000);
		vec_add(&vecTo, &mouse_pos3d);
		vec_set(&vecFrom, &mouse_pos3d);
		if(c_trace (&vecFrom, &vecTo, vTemp)!=0)
		{
			DEBUG_VAR(hit->x,23);
			DEBUG_VAR(hit->y,43);
			DEBUG_VAR(hit->z,63);
			DEBUG_VAR(hit->nx,103);
			DEBUG_VAR(hit->ny,123);
			DEBUG_VAR(hit->nz,143);
			vec_to_angle(&vecAng, hit->nx);
			vecAng.roll=0;
			ang_rotate(&vecAng,vector(0,-90,0));
			DEBUG_VAR(vecAng.pan,183);
			DEBUG_VAR(vecAng.tilt,203);
			DEBUG_VAR(vecAng.roll,223);
			vec_set(&vecPos, hit->x);
		}
	}
}