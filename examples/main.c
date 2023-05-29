#include "../app.h"
#include "scenes/scenes.h"

#define MEMSIZE (1024)

extern void setup (void);
extern void quit (void);
extern int events (struct input *i, bool *gamerunning);
extern void show (uint32_t *canvas);

int
main (void)
{
  char mem[MEMSIZE] = {0};
  uint32_t canvas[HEIGHT * WIDTH] = {0};

  struct arena arena = arena_new (mem, MEMSIZE);

  struct app *app = app_new (&arena, canvas);
  app_sadd (app, main_scene_new (&arena, app), &arena);
  app_sset (app, MAIN_SCENE);

  bool gamerunning = true;
  int previous_ts = 0;

  setup ();

  while (gamerunning)
    {
      int timestamp = events (app->input, &gamerunning);
      int dt = timestamp - previous_ts;

      app_tick (app, dt);

      show (canvas);

      previous_ts = timestamp;
    }

  quit ();

  return 0;
}
