#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>

#define WIDTH 80
#define HEIGHT 60

struct arena
{
  char *mem;
  size_t size;
  size_t next;
};

struct list
{
  void *head;
  struct list *tail;
};

struct input
{
  uint32_t kpressedmask;
  uint32_t kheldmask;
  bool mclicked;
  bool mheld;
  size_t mx;
  size_t my;
};

struct component
{
  int id;
  void *data;
  struct entity *entity;
  void (*update) (struct component *self, int dt, struct input *i);
  void (*render) (struct component *self, uint32_t *canvas);
};

struct entity
{
  int id;
  struct list *components;
  struct scene *scene;
};

struct scene
{
  int id;
  struct list *entities;
  struct app *app;
};

struct app
{
  struct input *input;
  struct list *scenes;
  struct scene *current;
  uint32_t *canvas;
};

struct arena arena_new (char *memptr, size_t size);
void *arena_alloc (struct arena *self, size_t n);
void arena_free (struct arena *self);

struct list *list_new (struct arena *a);
void list_append (struct list *self, void *data, struct arena *a);
void list_remove (struct list *self, void *data);

struct input *input_new (struct arena *a);
void input_kpress (struct input *self, char c);
void input_krelease (struct input *self, char c);
bool input_kpressed (struct input *self, char c);
bool input_kheld (struct input *self, char c);
void input_mclick (struct input *self, size_t x, size_t y);
void input_mlift (struct input *self);
bool input_mclicked (struct input *self);
bool input_mheld (struct input *self);
void input_reset (struct input *self);

struct component *component_new (struct arena *a,
                                 int id,
                                 struct entity *e,
                                 void (*update) (struct component *self,
                                                 int dt, struct input *i),
                                 void (*render) (struct component *self,
                                                 uint32_t *canvas));
void component_update (struct component *self, int dt, struct input *i);
void component_render (struct component *self, uint32_t *canvas);

struct entity *entity_new (struct arena *a, int id, struct scene *s);
void entity_cadd (struct entity *self, struct component *c, struct arena *a);
void entity_crm (struct entity *self, struct component *c);
struct component *entity_cget (struct entity *self, int cid);
void entity_update (struct entity *self, int dt, struct input *i);
void entity_render (struct entity *self, uint32_t *canvas);

struct scene *scene_new (struct arena *a, int id, struct app *app);
void scene_eadd (struct scene *self, struct entity *c, struct arena *a);
void scene_erm (struct scene *self, struct entity *c);
struct entity *scene_eget (struct scene *self, int eid);
void scene_update (struct scene *self, int dt, struct input *i);
void scene_render (struct scene *self, uint32_t *canvas);

struct app *app_new (struct arena *a, uint32_t *canvas);
void app_sadd (struct app *self, struct scene *s, struct arena *a);
void app_sset (struct app *self, int sid);
void app_tick (struct app *self, int dt);
