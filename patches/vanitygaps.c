void defaultgaps(const Arg *arg) {
	setgaps(gappoh, gappov, gappih, gappiv);
}

void incgaps(const Arg *arg) {
	setgaps(
		selmon->gappoh + arg->i,
		selmon->gappov + arg->i,
		selmon->gappih + arg->i,
		selmon->gappiv + arg->i);
}

void incigaps(const Arg *arg) {
	setgaps(
		selmon->gappoh,
		selmon->gappov,
		selmon->gappih + arg->i,
		selmon->gappiv + arg->i);
}

void incihgaps(const Arg *arg) {
	setgaps(
		selmon->gappoh,
		selmon->gappov,
		selmon->gappih + arg->i,
		selmon->gappiv);
}

void incivgaps(const Arg *arg) {
	setgaps(
		selmon->gappoh,
		selmon->gappov,
		selmon->gappih,
		selmon->gappiv + arg->i);
}

void incogaps(const Arg *arg) {
	setgaps(
		selmon->gappoh + arg->i,
		selmon->gappov + arg->i,
		selmon->gappih,
		selmon->gappiv);
}

void incohgaps(const Arg *arg) {
	setgaps(
		selmon->gappoh + arg->i,
		selmon->gappov,
		selmon->gappih,
		selmon->gappiv);
}

void incovgaps(const Arg *arg) {
	setgaps(
		selmon->gappoh,
		selmon->gappov + arg->i,
		selmon->gappih,
		selmon->gappiv);
}

void setgaps(int oh, int ov, int ih, int iv) {
	selmon->gappoh = MAX(oh, 0);
	selmon->gappov = MAX(ov, 0);
	selmon->gappih = MAX(ih, 0);
	selmon->gappiv = MAX(iv, 0);
	arrange(selmon);
}

void togglegaps(const Arg *arg) {
	enablegaps = !enablegaps;
	arrange(selmon);
}
