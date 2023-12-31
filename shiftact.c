/* Navigate to the next/prev tag */
void
shiftview(const Arg *arg)
{
    Arg shifted;
    shifted.ui = selmon->tagset[selmon->seltags];

    if (arg->i > 0)	/* left circular shift */
	shifted.ui = (shifted.ui << arg->i) | (shifted.ui >> (LENGTH(tags) - arg->i));
    else		/* right circular shift */
        shifted.ui = (shifted.ui >> (- arg->i) | shifted.ui << (LENGTH(tags) + arg->i));

    view(&shifted);
}
/* Move the current active window to the next/prev tag and view it. Like following the window */
void
shiftmove(const Arg *arg)
{
    Arg shifted;
    shifted.ui = selmon->tagset[selmon->seltags];

    if (arg->i > 0)	/* left circular shift */
        shifted.ui = ((shifted.ui << arg->i) | (shifted.ui >> (LENGTH(tags) - arg->i)));
    else		/* right circular shift */
        shifted.ui = ((shifted.ui >> (- arg->i) | shifted.ui << (LENGTH(tags) + arg->i)));

    tag(&shifted);
    view(&shifted);
}
