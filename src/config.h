/* See LICENSE file for copyright and license details. */


/* appearance */
//#ifdef pango.h
  //static const char font[]            = "Terminus 14";
//  static const char font[]            = "Terminus 12";
//#else
  static const char font[]            = "-*-terminus-medium-r-*-*-16-*-*-*-*-*-*-*";
//  static const char font[]            = "Terminus (TTF):size=12:bold=true:antialias=false";
  //static const char dmenufont[]       = "terminus-10";
//  static const char dmenufont[]       = "terminus-10";
  static const char dmenufont[]       = "Terminus (TTF):size=12:antialias=false";
//#endif
//static const char font[]            = "-*-inconsolata--r-*-*-20-*-*-*-*-*-*-*";
//#include <themes/when_destiny_meets_oblivion.h>
#include <themes/parts_unknown.h>
static const unsigned int borderpx  = 2;    /* border pixel of windows */
static const unsigned int gappx     = 18;        /* gap pixel between windows */
static const unsigned int snap      = 32;   /* snap pixel */
static const unsigned int minwsz    = 5;
static const Bool showbar           = True; /* False means no bar */
static const Bool topbar            = True; /* False means bottom bar */

/* tagging */
//static const char *tags[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9" };
#define MAX_TAGNAME_LEN 14		/* excludes TAG_PREPEND */
#define TAG_PREPEND "%1i:"		/* formatted as 2 chars */
#define MAX_TAGLEN 16			/* altogether */
static char tags[][MAX_TAGLEN] = { "1", "2", "3", "4", "5", "6", "7", "8", "9" };
//static char default_tags[][MAX_TAGLEN] = { "1", "2", "3", "4", "5", "6", "7", "8", "9" };

static const Rule rules[] = {
	/* class      instance    title       tags mask     isfloating   monitor */
	{ "Gimp",     NULL,       NULL,       0,            False,       -1 },
	{ "Firefox",  NULL,       NULL,       0,            False,       -1 },
	{ "XTerm",    NULL,       "foo",      0,            True,       -1 },
  { "Msgcompose", NULL,     NULL,       0,            True,       -1 }
};

/* layout(s) */
static const float mfact      = 0.55; /* factor of master area size [0.05..0.95] */
static const float smfact     = 0.00; /* factor of tiled clients [0.00..0.95] */
static const int nmaster      = 1;    /* number of clients in master area */
static const Bool resizehints = True; /* True means respect size hints in tiled resizals */

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "|||",      col },     /* first entry is default */
	{ "[]=",      tile },    
	{ "><>",      NULL },    /* no layout function means floating behavior */
	{ "[M]",      monocle }
};

/* key definitions */
//#define MODKEY Mod1Mask
#define MODKEY Mod4Mask
//#define MODKEY LockMask
// TODO utility to reset tag names and clean up dangling colons?
//	{ MODKEY,                       XK_r,     resettagname,   {.ui = 1 << TAG} }, 
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static const char *dmenucmd[] = { "dmenu_run", "-fn", dmenufont, "-nb", normbgcolor, "-nf", normfgcolor, "-sb", dmenuselbgcolor, "-sf", dmenuselfgcolor, NULL };
static const char *dmenucalc[] = { "xsel -o | dmenu_run -p Calculate: | xargs echo | bc 2>&1 | dmenu -p Answer: | xsel -i", "-fn", dmenufont, "-nb", normbgcolor, "-nf", normfgcolor, "-sb", dmenuselbgcolor, "-sf", dmenuselfgcolor, NULL };
static const char *termcmd[]  = { "/home/patrick/scripts/colorshuffle", NULL };
//static const char *browscmd[]  = { "firefox", "--private-window", NULL };
//static const char *browscmd[]  = { "firefox", NULL };
static const char *browscmd[] = { "/home/patrick/build/surf-git/src/surf/surf", "duckduckgo.com", NULL };
static const char *emailcmd[]  = { "thunderbird", NULL };
static const char *lockcmd[]  = { "xscreensaver-command","-lock", NULL };
static const char *taskcmd[]  = { "/home/patrick/scripts/todo", NULL };
//static const char *resettagcmd[] = { , NULL};

static Key keys[] = {
	/* modifier                     key        function        argument */
	{ MODKEY,                       XK_p,      spawn,          {.v = dmenucmd } },
	{ MODKEY|ShiftMask,             XK_Return, spawn,          {.v = termcmd } },
	{ MODKEY|ShiftMask,             XK_w,      spawn,          {.v = browscmd } },
	{ MODKEY|ShiftMask,             XK_e,      spawn,          {.v = emailcmd } },
	{ MODKEY|ShiftMask,             XK_minus,   spawn,          {.v = lockcmd } },
	{ MODKEY|ShiftMask,             XK_k,      spawn,          {.v = taskcmd } },
	{ MODKEY,                       XK_b,      togglebar,      {0} },
	{ MODKEY,                       XK_j,      focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_k,      focusstack,     {.i = -1 } },
	{ MODKEY,                       XK_i,      incnmaster,     {.i = +1 } },
	{ MODKEY,                       XK_d,      incnmaster,     {.i = -1 } },
	{ MODKEY,                       XK_h,      setmfact,       {.f = -0.05} },
	{ MODKEY,                       XK_l,      setmfact,       {.f = +0.05} },
	{ MODKEY|ShiftMask,             XK_h,      setsmfact,      {.f = +0.05} },
	{ MODKEY|ShiftMask,             XK_l,      setsmfact,      {.f = -0.05} },
	{ MODKEY,                       XK_Return, zoom,           {0} },
	{ MODKEY,                       XK_Tab,    view,           {0} },
	{ MODKEY|ShiftMask,             XK_c,      killclient,     {0} },
	{ MODKEY,                       XK_c,      setlayout,      {.v = &layouts[0]} },
	{ MODKEY,                       XK_t,      setlayout,      {.v = &layouts[1]} },
	{ MODKEY,                       XK_f,      setlayout,      {.v = &layouts[2]} },
	{ MODKEY,                       XK_m,      setlayout,      {.v = &layouts[3]} },
	{ MODKEY,                       XK_space,  setlayout,      {0} },
	{ MODKEY|ShiftMask,             XK_space,  togglefloating, {0} },
	{ MODKEY,                       XK_0,      view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },
	{ MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_period, focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },
	{ MODKEY,                       XK_semicolon, spawn,       {.v = dmenucalc } },
  { MODKEY,                       XK_n,      nametag,        {0} },
	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	TAGKEYS(                        XK_6,                      5)
	TAGKEYS(                        XK_7,                      6)
	TAGKEYS(                        XK_8,                      7)
	TAGKEYS(                        XK_9,                      8)
	{ MODKEY|ShiftMask,             XK_q,      quit,           {0} },
};

/* button definitions */
/* click can be ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};

