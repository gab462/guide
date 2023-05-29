#include "app.h"

struct scene *
scene_new (struct arena *a, int id, struct app *app)
{
  struct scene *s = arena_alloc (a, sizeof (struct scene));

  s->id = id;
  s->app = app;
  s->entities = list_new (a);

  return s;
}

struct entity *
scene_eget (struct scene *self, int eid)
{
  for (struct list *el = self->entities; el != NULL; el = el->tail)
    {
      struct entity *e = el->head;

      if (e->id == eid)
        return e;
    }

  return NULL;
}

void
scene_update (struct scene *self, int dt, struct input *i)
{
  for (struct list *el = self->entities; el != NULL; el = el->tail)
    {
      entity_update (el->head, dt, i);
    }
}

void
scene_render (struct scene *self, uint32_t *canvas)
{
  for (struct list *el = self->entities; el != NULL; el = el->tail)
    {
      entity_render (el->head, canvas);
    }
}
