/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int minwsz    = 20; 	/* Minimal heigt of a client for smfact */
static const unsigned int borderpx  = 1;        /* border pixel of windows */
static const unsigned int gappx     = 6;        /* gaps between windows */
static const unsigned int snap      = 32;       /* snap pixel */
static const int showbar            = 1;        /* 0 means no bar */
static const char *barlayout        = "tl|s";
static const int topbar             = 1;        /* 0 means bottom bar */
static const char *fonts[]          = { "monospace:size=15" };
static const char dmenufont[]       = "monospace:size=15";
static const char col_gray1[]       = "#222222";
static const char col_gray2[]       = "#444444";
static const char col_gray3[]       = "#bbbbbb";
static const char col_gray4[]       = "#eeeeee";
static const char col_cyan[]        = "#005577";
static const unsigned int baralpha = 0xd0;
static const unsigned int borderalpha = OPAQUE;
static const char *colors[][3]      = {
	/*               fg         bg         border   */
	[SchemeNorm] = { col_gray3, col_gray1, col_gray2 },
	[SchemeSel]  = { col_gray4, col_cyan,  col_cyan  },
};
static const unsigned int alphas[][3]      = {
    /*               fg      bg        border*/
    [SchemeNorm] = { OPAQUE, baralpha, borderalpha },
	[SchemeSel]  = { OPAQUE, baralpha, borderalpha },
};

/* tagging */
static const char *tags[] = { "I", "II", "III", "IV"};
static const char *tagsalt[] = { "1", "2", "3", "4"};
static const int momentaryalttags = 0; /* 1 means alttags will show only when key is held down*/

/* Lockfile */
static char lockfile[] = "/tmp/dwm.lock";

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class      instance    title       tags mask     isfloating   monitor */
	{ "Gimp",     NULL,       NULL,       0,            1,           -1 },
	{ "Firefox",  NULL,       NULL,       1 << 8,       0,           -1 },
};

/* layout(s) */
static const float smfact     = 0.00; /* factor of tiled clients [0.00..0.95] */
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 0;    /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 1; /* 1 will force focus on the fullscreen window */

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[]=",      tile },    /* first entry is default */
	{ "><>",      NULL },    /* no layout function means floating behavior */
	{ "[M]",      monocle },
};

/* key definitions */
#define MODKEY Mod1Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = { "dmenu_run", "-m", dmenumon, "-fn", dmenufont, "-nb", col_gray1, "-nf", col_gray3, "-sb", col_cyan, "-sf", col_gray4, NULL };
static const char *termcmd[]  = { "st", NULL };



static const Key keys[] = {
	/* modifier                     key        function        argument */
{ MODKEY | ShiftMask, XK_o,                    spawn,          SHCMD("sh ~/dev/git/dwm-build/dwm/rec start") },
{ MODKEY | ShiftMask | ControlMask, XK_o,      spawn,          SHCMD("sh ~/dev/git/dwm-build/dwm/rec stop") },
	{ MODKEY,                       XK_p,      spawn,          {.v = dmenucmd } },
	{ MODKEY|ShiftMask,             XK_Return, spawn,          {.v = termcmd } },
	{ MODKEY,                       XK_b,      togglebar,      {0} },
	{ MODKEY|ShiftMask,             XK_j,      rotatestack,    {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_k,      rotatestack,    {.i = -1 } },
	{ MODKEY,                       XK_j,      focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_k,      focusstack,     {.i = -1 } },
	{ MODKEY,                       XK_i,      incnmaster,     {.i = +1 } },
	{ MODKEY,                       XK_d,      incnmaster,     {.i = -1 } },
	{ MODKEY|ControlMask,                       XK_h,      setmfact,       {.f = -0.05} },
	{ MODKEY|ControlMask,                       XK_l,      setmfact,       {.f = +0.05} },
	{ MODKEY|ControlMask,                       XK_Left,      setmfact,       {.f = -0.05} },
	{ MODKEY|ControlMask,                       XK_Right,      setmfact,       {.f = +0.05} },
	{ MODKEY,                       XK_Return, zoom,           {0} },
	{ MODKEY,                       XK_Tab,    view,           {0} },
	{ MODKEY|ShiftMask,             XK_c,      killclient,     {0} },
	{ MODKEY,                       XK_t,      setlayout,      {.v = &layouts[0]} },
	{ MODKEY,                       XK_f,      setlayout,      {.v = &layouts[1]} },
	{ MODKEY,                       XK_m,      setlayout,      {.v = &layouts[2]} },
	{ MODKEY,                       XK_space,  setlayout,      {0} },
	{ MODKEY|ShiftMask,             XK_space,  togglefloating, {0} },
	{ MODKEY,                       XK_agrave, view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_agrave, tag,            {.ui = ~0 } },
	{ MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_semicolon, focusmon,    {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_semicolon, tagmon,      {.i = +1 } },
	TAGKEYS(                        XK_ampersand,              0)
	TAGKEYS(                        XK_eacute,                 1)
	TAGKEYS(                        XK_quotedbl,               2)
	TAGKEYS(                        XK_apostrophe,             3)
	TAGKEYS(                        XK_parenleft,              4)
	TAGKEYS(                        XK_minus,                  5)
	TAGKEYS(                        XK_egrave,                 6)
	TAGKEYS(                        XK_underscore,             7)
	TAGKEYS(                        XK_ccedilla,               8)
	{ MODKEY|ShiftMask,             XK_q,      quit,           {0} },
        
	{ MODKEY | ShiftMask, XK_p, spawn, SHCMD("maim -s | xclip -selection clipboard -t image/png -i") },
        { MODKEY | ShiftMask | ControlMask, XK_p, spawn, SHCMD("maim -s ~/$(date +\"%H:%M\").png") },
	{ MODKEY|ControlMask|ShiftMask, XK_r,      quit,           {1} },
	{ MODKEY|ControlMask,             XK_k,      setsmfact,      {.f = +0.05} },
        { MODKEY|ControlMask,             XK_j,      setsmfact,      {.f = -0.05} },
	{ MODKEY|ControlMask,             XK_Up,      setsmfact,      {.f = +0.05} },
        { MODKEY|ControlMask,             XK_Down,      setsmfact,      {.f = -0.05} },
	{ MODKEY,                       XK_n,      togglealttag,   {0} },

	{ MODKEY | ShiftMask, XK_l, spawn, SHCMD("sh ~/projects/scripts/bookmark.sh -l") },
	{ MODKEY | ShiftMask, XK_b, spawn, SHCMD("sh ~/projects/scripts/bookmark.sh -b") },
	{ MODKEY | ShiftMask, XK_y, spawn, SHCMD("sh ~/projects/scripts/bookmark.sh -c") },
	
	{ MODKEY | ControlMask, XK_l, spawn, SHCMD("st -e lf") },
	{ MODKEY | ControlMask, XK_d, spawn, SHCMD("firefox  https://discord.com/channels/@me/1094069761652035584") },
	{ MODKEY | ControlMask, XK_y, spawn, SHCMD("firefox youtube.com") },
	{ MODKEY | ControlMask, XK_f, spawn, SHCMD("firefox google.com") },
        { MODKEY | ControlMask , XK_b, spawn, SHCMD("zathura ~/crnt/*.pdf") },
        { MODKEY | ControlMask , XK_h, spawn, SHCMD("habit-tracker") },
        { MODKEY | ControlMask , XK_t, spawn, SHCMD("errands") },

};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static const Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};
