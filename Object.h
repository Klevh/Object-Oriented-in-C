#ifndef _OOC_BY_KLEVH_
#define _OOC_BY_KLEVH_

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>

#ifdef __GNUC__
#define OBJECT __attribute__((__cleanup__(_delete)))
#else
#error "OOC is GNU-C compatible, recompile it with a GNU compiler"
#endif

struct Class{
  size_t size;
  void * (*ctor)(void * self,va_list args);
  void * (*dtor)(void * self);
  void * (*clon)(const void * self);
};

void * new(const void * type, ...);
void delete(void * self);
void * clone(void * _self);

void _delete(void ** self);

#endif
