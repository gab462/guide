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

  entity_cadd (e, position_component_new (a, e, 0, 0), a);
  entity_cadd (e, sprite_component_new (a, e, sprite, 5, 5), a);
  entity_cadd (e, button_component_new (a, e, callback), a);
  entity_cadd (e, movement_component_new (a, e), a);
  
  return e;
}
