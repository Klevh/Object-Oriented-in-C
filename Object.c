#include "Object.h"
	
/* Class implementation */
void * new(const void * type, ...){
  const struct Class * class = type;
  void * p = calloc(1, class->size);
	
  *(const struct Class **)p=class;
	
  if(class->ctor){
    va_list l;
    va_start(l, type);
		
    p = class->ctor(p, &l);
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

void * translate(const void * type, void * self){
  size_t                size,
                        i;
  const struct Class ** cl    = self,
                      * c,
                      * typ   = type;
  int                   found = 0;
  void                * res   = NULL;
	
  if(type && self){
    c=*cl;
    if(c){
      size = c->size;
      i = 0;
      do{
	found = (c->size == typ->size) && (c->ctor == typ->ctor) && (c->dtor == typ->dtor) && (c->parents == typ->parents) && (c->clon == typ->clon);
	if(!found){
	  i+=c->size;
	  c=(const struct Class *)((char *)c + c->size);
	}
      }while(!found && size > i);
      if(i<size){
	res = (void *)c;
      }
    }
  }
	
  return res;
}

void super(void * self, ...){
  va_list      l;
  const void * arg;
	
  if(self){
    va_start(l,self);
    arg=va_arg(l,const void *);
    self = (void *)((char *)self + sizeof(const struct Class *));
    while(arg){
      *(const struct Class **)self = (const struct Class *)arg;
      self = (void *)((char *)self + (*(const struct Class **)self)->size);
      arg=va_arg(l,const void *);
    }
  }
}
/* ------------ */
