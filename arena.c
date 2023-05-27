#include "app.h"

struct arena
arena_new (char *memptr, size_t size)
{
  return (struct arena)
  {
    .mem = memptr,
    .size = size
  };
}

void *
arena_alloc (struct arena *self, size_t n)
{
  if (self->next + n > self->size)
    return 0;

  void *mempos = self->mem + self->next;

  self->next += n;

  return mempos;
}

void
arena_free (struct arena *self)
{
  self->next = 0;
}
