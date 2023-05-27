enum
{
  BACKGROUND_ENTITY,
  BUTTON_ENTITY
};

struct entity *background_entity_new (struct arena *a, struct scene *s);

struct entity *button_entity_new (struct arena *a, struct scene *s);
