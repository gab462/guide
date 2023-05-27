#include "../app.h"
#include <SDL.h>

#define WINDOW_WIDTH (WIDTH * 10)
#define WINDOW_HEIGHT (HEIGHT * 10)

static struct
{
  SDL_Window *window;
  SDL_Renderer *renderer;
  SDL_Texture *texture;
} sdl;

void
setup (void)
{
  sdl.window = SDL_CreateWindow ("Demo",
                                 SDL_WINDOWPOS_UNDEFINED,
                                 SDL_WINDOWPOS_UNDEFINED,
                                 WINDOW_WIDTH, WINDOW_HEIGHT,
                                 SDL_WINDOW_SHOWN);

  sdl.renderer = SDL_CreateRenderer (sdl.window, -1,
                                     SDL_RENDERER_ACCELERATED |
                                     SDL_RENDERER_PRESENTVSYNC);

  sdl.texture = SDL_CreateTexture (sdl.renderer,
                                   SDL_PIXELFORMAT_RGBA32,
                                   SDL_TEXTUREACCESS_STREAMING, WIDTH,
                                   HEIGHT);
}

void
quit (void)
{
  SDL_DestroyTexture (sdl.texture);
  SDL_DestroyRenderer (sdl.renderer);
  SDL_DestroyWindow (sdl.window);

  SDL_Quit ();
}

int
events (struct input *i, bool *gamerunning)
{
  SDL_Event ev;
  char c;

  while (SDL_PollEvent (&ev))
    {
      switch (ev.type)
        {
        case SDL_QUIT:
          *gamerunning = false;
          break;

        case SDL_MOUSEBUTTONDOWN:
          input_mclick (i, ev.button.x / 10, ev.button.y / 10);
          break;

        case SDL_MOUSEBUTTONUP:
          input_mlift (i);
          break;

        case SDL_KEYDOWN:
          c = ev.key.keysym.sym;
          if ('a' <= c && c <= 'z')
            input_kpress (i, c);
          break;

        case SDL_KEYUP:
          c = ev.key.keysym.sym;
          if ('a' <= c && c <= 'z')
            input_krelease (i, c);
          break;
        }
    }

  return SDL_GetTicks ();
}

void
bm2tex (uint32_t *canvas)
{
  void *dst;
  int pitch;

  SDL_LockTexture (sdl.texture, NULL, &dst, &pitch);

  for (size_t y = 0; y < HEIGHT; ++y)
    {
      memcpy ((char *) dst + y * pitch, canvas + y * WIDTH,
              WIDTH * sizeof (uint32_t));
    }

  SDL_UnlockTexture (sdl.texture);
}

void
show (uint32_t *canvas)
{
  bm2tex (canvas);

  SDL_RenderCopy (sdl.renderer, sdl.texture, NULL, NULL);

  SDL_RenderPresent (sdl.renderer);
}
