#ifndef SC_COMPAT_H
#define SC_COMPAT_H

#include "config.h"

//#include <libavcodec/version.h>
//#include <libavformat/version.h>
//#include <libavutil/version.h>
#include <SDL2/SDL_version.h>

# define PRIu64_ PRIu64
# define SC_PRIsizet "zu"

#if SDL_VERSION_ATLEAST(2, 0, 6)
// <https://github.com/libsdl-org/SDL/commit/d7a318de563125e5bb465b1000d6bc9576fbc6fc>
# define SCRCPY_SDL_HAS_HINT_TOUCH_MOUSE_EVENTS
#endif

#if SDL_VERSION_ATLEAST(2, 0, 8)
// <https://hg.libsdl.org/SDL/rev/dfde5d3f9781>
# define SCRCPY_SDL_HAS_HINT_VIDEO_X11_NET_WM_BYPASS_COMPOSITOR
#endif

#if SDL_VERSION_ATLEAST(2, 0, 16)
# define SCRCPY_SDL_HAS_THREAD_PRIORITY_TIME_CRITICAL
#endif

#ifndef HAVE_STRDUP
char *strdup(const char *s);
#endif

#ifndef HAVE_ASPRINTF
int asprintf(char **strp, const char *fmt, ...);
#endif

#ifndef HAVE_VASPRINTF
int vasprintf(char **strp, const char *fmt, va_list ap);
#endif

#ifndef HAVE_NRAND48
long nrand48(unsigned short xsubi[3]);
#endif

#ifndef HAVE_JRAND48
long jrand48(unsigned short xsubi[3]);
#endif

#ifndef HAVE_REALLOCARRAY
void *reallocarray(void *ptr, size_t nmemb, size_t size);
#endif

#endif
