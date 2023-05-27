// TODO: check dependencies when creating component

enum
{
  POSITION_COMPONENT,
  SPRITE_COMPONENT,
  BUTTON_COMPONENT,
  MOVEMENT_COMPONENT,
};

struct position_data
{
  size_t x;
  size_t y;
};

struct component *position_component_new (struct arena *a,
                                          struct entity *e, size_t x,
                                          size_t y);

struct sprite_data
{
  uint32_t *pixels;
  size_t w;
  size_t h;
};

struct component *sprite_component_new (struct arena *a,
                                        struct entity *e, uint32_t *sprite,
                                        size_t w, size_t h);

struct button_data
{
  void (*callback) (void);
};

struct component *button_component_new (struct arena *a, struct entity *e,
                                        void (*callback) (void));

struct component *movement_component_new (struct arena *a, struct entity *e);
