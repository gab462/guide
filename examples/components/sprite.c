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
  struct sprite_data *sprite = self->data;

  struct component *c = entity_cget (self->entity, POSITION_COMPONENT);
  struct position_data *pos = c->data;

  for (size_t i = 0; i < sprite->h; ++i)
    {
      for (size_t j = 0; j < sprite->w; ++j)
        {
          size_t px = pos->x + j;
          size_t py = pos->y + i;

          if (px < WIDTH && py < HEIGHT)
            canvas[(pos->y + i) * WIDTH + (pos->x + j)] =
              sprite->pixels[i * sprite->w + j];
        }
    }
}

struct component *
sprite_component_new (struct arena *a, struct entity *e,
                      uint32_t *sprite, size_t w, size_t h)
{
  struct component *c =
    component_new (a, SPRITE_COMPONENT, e, update, render);

  struct sprite_data *data = arena_alloc (a, sizeof (struct sprite_data));

  data->pixels = sprite;
  data->w = w;
  data->h = h;

  c->data = data;

  return c;
}
