#pragma once

#include <stdbool.h>

#include "nvim/decoration_defs.h"  // IWYU pragma: keep
#include "nvim/macros_defs.h"
#include "nvim/types_defs.h"  // IWYU pragma: keep

void decor_providers_invoke_win_buf(win_T *wp, buf_T *buf, linenr_T topline, linenr_T botline);

#include "decoration_provider.h.generated.h"
