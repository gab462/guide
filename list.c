#include "app.h"

struct list *
list_new (struct arena *a)
{
  struct list *l = arena_alloc (a, sizeof (struct list));

  l->head = NULL;
  l->tail = NULL;

  return l;
}

void
list_append (struct list *self, void *data, struct arena *a)
{
  if (self->head != NULL && self->tail != NULL)
    {
      list_append (self->tail, data, a);
    }
  else if (self->head == NULL)
    {
      self->head = data;
    }
  else
    {
      self->tail = list_new (a);
      self->tail->head = data;
      self->tail->tail = NULL;
    }
}

/*
void
list_remove (struct list *self, void *data)
{
  for (struct list *l = self; l != NULL; l = l->tail)
    {
      if (l->head == data)
        l->head = NULL;
    }
}
*/
