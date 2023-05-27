#include "../../app.h"
#include "components.h"

static void
update (struct component *self, int dt, struct input *i)
{
  (void) dt;

  if (!input_mclicked (i))
    return;

  size_t mx = i->mpos[0];
  size_t my = i->mpos[1];

  struct component *pc = entity_cget (self->entity, POSITION_COMPONENT);
  struct position_data *pos = pc->data;

  struct component *sc = entity_cget (self->entity, SPRITE_COMPONENT);
  struct sprite_data *sprite = sc->data;

  bool clicked = pos->x < mx && mx < pos->x + sprite->w
    && pos->y < my && my < pos->y + sprite->h;

  if (clicked)
    {
      struct button_data *button = self->data;
      button->callback ();
    }
}

static void
render (struct component *self, uint32_t *canvas)
{
  (void) self;
  (void) canvas;
}

struct component *
button_component_new (struct arena *a, struct entity *e,
                      void (*callback) (void))
{
  struct component *c =
    component_new (a, BUTTON_COMPONENT, e, update, render);

  struct button_data *data = arena_alloc (a, sizeof (struct button_data));
  data->callback = callback;

  c->data = data;

  return c;
}
