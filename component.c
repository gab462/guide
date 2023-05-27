#include "app.h"

struct component *
component_new (struct arena *a,
               int id,
               struct entity *e,
               void (*update) (struct component *self, int dt,
                               struct input *i),
               void (*render) (struct component *self, uint32_t *canvas))
{
  struct component *c = arena_alloc (a, sizeof (struct component));

  c->id = id;
  c->entity = e;
  c->update = update;
  c->render = render;
  c->data = NULL;

  return c;
}

void
component_update (struct component *self, int dt, struct input *i)
{
  self->update (self, dt, i);
}

void
component_render (struct component *self, uint32_t *canvas)
{
  self->render (self, canvas);
}
