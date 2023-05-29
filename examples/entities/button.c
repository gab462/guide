#include "../../app.h"
#include "../components/components.h"
#include "entities.h"
#include <stdio.h>

static uint32_t sprite[25] = {
  0xFF0000FF, 0xFF0000FF, 0xFF0000FF, 0xFF0000FF, 0xFF0000FF,
  0xFF0000FF, 0xFF0000FF, 0xFF0000FF, 0xFF0000FF, 0xFF0000FF,
  0xFF0000FF, 0xFF0000FF, 0xFF0000FF, 0xFF0000FF, 0xFF0000FF,
  0xFF0000FF, 0xFF0000FF, 0xFF0000FF, 0xFF0000FF, 0xFF0000FF,
  0xFF0000FF, 0xFF0000FF, 0xFF0000FF, 0xFF0000FF, 0xFF0000FF,
};

static void
callback (void)
{
  printf ("Clicked!\n");
}

struct entity *
button_entity_new (struct arena *a, struct scene *s)
{
  struct entity *e = entity_new (a, BUTTON_ENTITY, s);

  list_append (e->components, position_component_new (a, e, 0, 0), a);
  list_append (e->components, position_component_new (a, e, 0, 0), a);
  list_append (e->components, sprite_component_new (a, e, sprite, 5, 5), a);
  list_append (e->components, button_component_new (a, e, callback), a);
  list_append (e->components, movement_component_new (a, e), a);

  return e;
}
