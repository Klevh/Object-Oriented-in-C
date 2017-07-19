#include "Object.h"
	
/* Class implementation */
void * new(const void * type, ...){
  const struct Class * class = type;
  void * p = calloc(1, class->size);
	
  *(const struct Class **)p=class;
	
  if(class->ctor){
    va_list l;
    va_start(l, type);
		
    p = class->ctor(p, l);
    va_end(l);
  }
	
  return p;
}

void delete(void *self){
  const struct Class ** cp = self;
	
  if(self && *cp && (*cp)->dtor){
    self=(*cp)->dtor(self);
  }
	
  free(self);
}

void * clone(void *_self){
  const struct Class **cp = _self;
  void * p = calloc(1,(*cp)->size);
	
  *(const struct Class **)p=*cp;
	
  if(_self && *cp && (*cp)->clon){
    p=(*cp)->clon(_self);
  }

  return p;
}
/* ------------ */
