#include <acknex.h>

void main()
{
	wait(1);
	BMAP* b = bmap_create("tex\\warrior512_3.PCX");
	BMAP* bn = bmap_to_normals(b,30);
	bmap_save(bn,"tex\\warrior512_3_n.bmp");
	wait(-1);
	sys_exit("");
}