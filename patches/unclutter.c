void handlecursoractivity() {
	wl_event_source_timer_update(hide_source, cursor_timeout * 1000);
	if (cursor_hidden) {
		wlr_xcursor_manager_set_cursor_image(cursor_mgr, "left_ptr", cursor);
		cursor_hidden = false;
	}
}

int hidecursor(void *data) {
	wlr_cursor_set_image(cursor, NULL, 0, 0, 0, 0, 0, 0);
	wlr_seat_pointer_notify_clear_focus(seat);
	cursor_hidden = true;
	return 1;
}
