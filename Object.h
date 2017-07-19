#ifndef _OOC_BY_KLEVH_
#define _OOC_BY_KLEVH_

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>

struct Class{
  size_t size;
  size_t parents;
  void * (*ctor)(void * self,va_list args);
  void * (*dtor)(void * self);
  void * (*clon)(const void * self);
};

void * new(const void * type, ...);
void delete(void * self);
void * clone(void * _self);
void * translate(const void * type, void * self);
void super(void * self, ...);

#endif
