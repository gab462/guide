#include "app.h"

struct app *
app_new (struct arena *a, uint32_t *canvas)
{
  struct app *app = arena_alloc (a, sizeof (struct app));

  app->input = input_new (a);
  app->current = NULL;
  app->scenes = list_new (a);
  app->canvas = canvas;

  return app;
}

void
app_sset (struct app *self, int sid)
{
  for (struct list *sl = self->scenes; sl != NULL; sl = sl->tail)
    {
      struct scene *s = sl->head;

      if (s->id == sid)
        {
          self->current = s;
          return;
        }
    }
}

void
app_tick (struct app *self, int dt)
{
  scene_update (self->current, dt, self->input);

  scene_render (self->current, self->canvas);

  input_reset (self->input);
}
