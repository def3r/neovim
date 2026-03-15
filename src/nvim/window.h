#pragma once

#include <stdbool.h>

#include "nvim/buffer_defs.h"  // IWYU pragma: keep
#include "nvim/ex_cmds_defs.h"  // IWYU pragma: keep
#include "nvim/garray_defs.h"  // IWYU pragma: keep
#include "nvim/macros_defs.h"
#include "nvim/option_defs.h"  // IWYU pragma: keep
#include "nvim/types_defs.h"  // IWYU pragma: keep

/// arguments for win_split()
enum {
  WSP_ROOM     = 0x01,   ///< require enough room
  WSP_VERT     = 0x02,   ///< split/equalize vertically
  WSP_HOR      = 0x04,   ///< equalize horizontally
  WSP_TOP      = 0x08,   ///< window at top-left of shell
  WSP_BOT      = 0x10,   ///< window at bottom-right of shell
  WSP_HELP     = 0x20,   ///< creating the help window
  WSP_BELOW    = 0x40,   ///< put new window below/right
  WSP_ABOVE    = 0x80,   ///< put new window above/left
  WSP_NEWLOC   = 0x100,  ///< don't copy location list
  WSP_NOENTER  = 0x200,  ///< don't enter the new window
  WSP_QUICKFIX = 0x400,  ///< creating the quickfix window
};

enum {
  MIN_COLUMNS = 12,   ///< minimal columns for screen
  MIN_LINES   = 2,    ///< minimal lines for screen
  STATUS_HEIGHT = 1,  ///< height of a status line under a window
};

enum {
  /// Lowest number used for window ID. Cannot have this many windows per tab.
  LOWEST_WIN_ID = 1000,
};

bool win_has_segments(const win_T *wp);
linenr_T win_segment_total_lnum(const win_T *wp);
linenr_T win_cursor_abs_lnum(const win_T *wp);
linenr_T win_visual_abs_lnum(const win_T *wp);
bool win_resolve_segment_lnum(const win_T *wp, linenr_T lnum, buf_T **buf, linenr_T *buf_lnum,
                              size_t *seg_idx);
bool win_multibuf_set_buffer_for_lnum(win_T *wp, linenr_T lnum, linenr_T *buf_lnum,
                                      size_t *seg_idx);
bool win_multibuf_set_cursor_pos(win_T *wp, linenr_T lnum);
void win_set_visual_cursor(win_T *wp);
void win_clear_segments(win_T *wp);

EXTERN int tabpage_move_disallowed INIT( = 0);  ///< moving tabpages around disallowed

#include "window.h.generated.h"
