static struct wl_event_source *hide_source;
static bool cursor_hidden = false;

static void handlecursoractivity();
static int hidecursor(void *data);
