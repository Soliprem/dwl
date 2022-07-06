/*
 * This file contains patch control flags.
 *
 * In principle you should be able to mix and match any patches
 * you may want. In cases where patches are logically incompatible
 * one patch may take precedence over the other as noted in the
 * relevant descriptions.
 *
 * Although layouts typically come as patches they are differentiated
 * here for grouping purposes.
 */

/* Hide the mouse cursor if it isn't being used after a specified timeout.
 */
#define UNCLUTTER_PATCH 1

/* Hide terminal-emulators when they launch a GUI application.
 */
#define SWALLOW_PATCH 1

/* Always center floating windows.
 */
#define ALWAYSCENTER_PATCH 1

/* Add keybindings for left and right circular shift through tags.
 */
#define SHIFTVIEW_PATCH 1

/* Hide the border when only one window is visible.
 */
#define NOBORDER_PATCH 1
