#include "../../app.h"
#include "../components/components.h"
#include "entities.h"

static uint32_t sprite[HEIGHT * WIDTH];

static void
fill_sprite (void)
{
  for (size_t i = 0; i < HEIGHT * WIDTH; ++i)
    {
      sprite[i] = 0xFFFF0000;
    }
}

struct entity *
background_entity_new (struct arena *a, struct scene *s)
{
  struct entity *e = entity_new (a, BACKGROUND_ENTITY, s);

  fill_sprite ();

  list_append (e->components, position_component_new (a, e, 0, 0), a);
  list_append (e->components, sprite_component_new (a, e, sprite, WIDTH, HEIGHT), a);

  return e;
}
