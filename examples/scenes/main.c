#include "../../app.h"
#include "../entities/entities.h"
#include "scenes.h"

struct scene *
main_scene_new (struct arena *a, struct app *app)
{
  struct scene *s = scene_new (a, MAIN_SCENE, app);

  list_append (s->entities, background_entity_new (a, s), a);
  list_append (s->entities, button_entity_new (a, s), a);

  return s;
}
