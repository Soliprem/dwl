pid_t getparentprocess(pid_t p) {
	unsigned int v = 0;

	FILE *f;
	char buf[256];
	snprintf(buf, sizeof(buf) - 1, "/proc/%u/stat", (unsigned)p);

	if (!(f = fopen(buf, "r")))
		return 0;

	fscanf(f, "%*u %*s %*c %u", &v);
	fclose(f);

	return (pid_t)v;
}

int isdescprocess(pid_t p, pid_t c) {
	while (p != c && c != 0)
		c = getparentprocess(c);

	return (int)c;
}

Client *
termforwin(Client *w) {
	Client *c;

	if (!w->pid || w->isterminal || w->noswallow)
		return NULL;

	wl_list_for_each(c, &clients, link) if (c->isterminal && !c->swallowing && c->pid && isdescprocess(c->pid, w->pid)) return c;

	return NULL;
}

void swallow(Client *c, Client *w) {
	c->bw = w->bw;
	c->isfloating = w->isfloating;
	c->isurgent = w->isurgent;
	c->isfullscreen = w->isfullscreen;
	resize(c, w->geom.x, w->geom.y, w->geom.width, w->geom.height, 0);
	wl_list_insert(&w->link, &c->link);
	wl_list_insert(&w->flink, &c->flink);
	wlr_scene_node_set_enabled(w->scene, 0);
	wlr_scene_node_set_enabled(c->scene, 1);
}
