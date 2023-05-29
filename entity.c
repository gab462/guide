#include "app.h"

struct entity *
entity_new (struct arena *a, int id, struct scene *s)
{
  struct entity *e = arena_alloc (a, sizeof (struct entity));

  e->id = id;
  e->scene = s;
  e->components = list_new (a);

  return e;
}

struct component *
entity_cget (struct entity *self, int cid)
{
  for (struct list *cl = self->components; cl != NULL; cl = cl->tail)
    {
      struct component *c = cl->head;

      if (c->id == cid)
        return c;
    }

  return NULL;
}

void
entity_update (struct entity *self, int dt, struct input *i)
{
  for (struct list *cl = self->components; cl != NULL; cl = cl->tail)
    {
      component_update (cl->head, dt, i);
    }
}

void
entity_render (struct entity *self, uint32_t *canvas)
{
  for (struct list *cl = self->components; cl != NULL; cl = cl->tail)
    {
      component_render (cl->head, canvas);
    }
}
