#include "../Object.h"

/* Coord class */
struct Coord{
  const void * class;
  int x;
  int y;
};

void * Coord_ctor(void * _self, va_list ap);
int getX(void * self);
int getY(void * self);

static const struct Class _Coord = {
  sizeof(struct Coord),
  Coord_ctor, NULL,NULL
};
const void * Coord = &_Coord;
/* ------------- */
	
/* Class Coord3D (inherit from Coord) */
struct Coord3D{
  struct Coord coord;
  int z;
};

void * Coord3D_ctor(void * _self, va_list ap);
int getZ(void * self);

static const struct Class _Coord3D = {
  sizeof(struct Coord3D),
  Coord3D_ctor, NULL,NULL
};
const void * Coord3D=&_Coord3D;
/* ------------- */

int main()
{
  void * coord = new(Coord,0,3);
  void * coord3D = new(Coord3D,0,2,5);
	
  printf("2D : %d %d\n",getX(coord),getY(coord));
  printf("3D : %d %d %d\n",getX(coord3D),getY(coord3D),getZ(coord3D));
	
  delete(coord);
  delete(coord3D);
	
  return 0;
}

/* Coord3D implementation */
void * Coord3D_ctor(void * _self, va_list ap){
  struct Coord3D * self = _self;
  self=Coord_ctor(_self,ap);
  self->z=va_arg(ap,int);
  return (void *)self;
}

int getZ(void * self){
  struct Coord3D * c = self;
  return c->z;
}

/* Coord implementation */
void * Coord_ctor(void * _self, va_list ap){
  struct Coord * self=_self;
  self->x=va_arg(ap,int);
  self->y=va_arg(ap,int);
  return (void *) self;
}

int getX(void * self){
  struct Coord * c = self;
  return c->x;
}

int getY(void * self){
  struct Coord * c = self;
  return c->y;
}
/* -------------- */
