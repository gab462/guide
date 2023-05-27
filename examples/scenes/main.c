#include "../../app.h"
#include "../entities/entities.h"
#include "scenes.h"

struct scene *
main_scene_new (struct arena *a, struct app *app)
{
  struct scene *s = scene_new (a, MAIN_SCENE, app);

  scene_eadd (s, background_entity_new (a, s), a);
  scene_eadd (s, button_entity_new (a, s), a);

  return s;
}
