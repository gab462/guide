#include "app.h"

struct input *
input_new (struct arena *a)
{
  struct input *i = arena_alloc (a, sizeof (struct input));

  i->mclicked = 0;
  i->mheld = 0;
  i->kpressedmask = 0;
  i->kheldmask = 0;

  return i;
}

void
input_kpress (struct input *self, char c)
{
  if (c >= 'a' && c <= 'z')
    {
      self->kpressedmask |= 1 << (c - 'a');
      self->kheldmask |= 1 << (c - 'a');
    }
}

void
input_krelease (struct input *self, char c)
{
  if (c >= 'a' && c <= 'z')
    self->kheldmask &= ~(1 << (c - 'a'));
}

bool
input_kpressed (struct input *self, char c)
{
  return self->kpressedmask & (1 << (c - 'a'));
}

bool
input_kheld (struct input *self, char c)
{
  return (self->kheldmask & (1 << (c - 'a')));
}

void
input_mclick (struct input *self, size_t x, size_t y)
{
  self->mclicked = 1;
  self->mheld = 1;
  self->mpos[0] = x;
  self->mpos[1] = y;
}

void
input_mlift (struct input *self)
{
  self->mheld = 0;
}

bool
input_mclicked (struct input *self)
{
  return self->mclicked;
}

bool
input_mheld (struct input *self)
{
  return self->mheld;
}

void
input_reset (struct input *self)
{
  self->mclicked = 0;
  self->kpressedmask = 0;
}
