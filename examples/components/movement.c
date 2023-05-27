#include "../../app.h"
#include "components.h"

static void
update (struct component *self, int dt, struct input *i)
{
  struct component *pc = entity_cget (self->entity, POSITION_COMPONENT);
  struct position_data *pos = pc->data;

  if (input_kheld (i, 'w'))
    pos->y -= dt / 8;
  if (input_kheld (i, 'a'))
    pos->x -= dt / 8;
  if (input_kheld (i, 's'))
    pos->y += dt / 8;
  if (input_kheld (i, 'd'))
    pos->x += dt / 8;
}

static void
render (struct component *self, uint32_t *canvas)
{
  (void) self;
  (void) canvas;
}

struct component *
movement_component_new (struct arena *a, struct entity *e)
{
  struct component *c =
    component_new (a, MOVEMENT_COMPONENT, e, update, render);

  c->data = NULL;

  return c;
}
