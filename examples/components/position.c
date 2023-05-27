#include "../../app.h"
#include "components.h"

static void
update (struct component *self, int dt, struct input *i)
{
  (void) self;
  (void) dt;
  (void) i;
}

static void
render (struct component *self, uint32_t *canvas)
{
  (void) self;
  (void) canvas;
}

struct component *
position_component_new (struct arena *a, struct entity *e, size_t x, size_t y)
{
  struct component *c =
    component_new (a, POSITION_COMPONENT, e, update, render);

  struct position_data *data = arena_alloc (a, sizeof (struct position_data));

  data->x = x;
  data->y = y;

  c->data = data;

  return c;
}
