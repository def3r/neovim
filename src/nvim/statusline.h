#pragma once

#include <stddef.h>

#include "nvim/highlight_defs.h"
#include "nvim/macros_defs.h"
#include "nvim/option_defs.h"  // IWYU pragma: keep
#include "nvim/statusline_defs.h"  // IWYU pragma: keep
#include "nvim/types_defs.h"  // IWYU pragma: keep

/// Array defining what should be done when tabline is clicked
EXTERN StlClickDefinition *tab_page_click_defs INIT( = NULL);
/// Size of the tab_page_click_defs array
EXTERN size_t tab_page_click_defs_size INIT( = 0);

int build_stl_str_hl(win_T *wp, char *out, size_t outlen, char *fmt, OptIndex opt_idx,
					 int opt_scope, schar_T fillchar, int maxwidth, stl_hlrec_t **hltab,
					 size_t *hltab_len, StlClickRecord **tabtab, statuscol_T *stcp);

#include "statusline.h.generated.h"
