/**
 * Copyright 2011 - 2020 José Expósito <jose.exposito89@gmail.com>
 *
 * This file is part of Touchégg.
 *
 * Touchégg is free software: you can redistribute it and/or modify it under the
 * terms of the GNU General Public License  as  published by  the  Free Software
 * Foundation,  either version 2 of the License,  or (at your option)  any later
 * version.
 *
 * Touchégg is distributed in the hope that it will be useful,  but  WITHOUT ANY
 * WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR
 * A PARTICULAR PURPOSE.  See the  GNU General Public License  for more details.
 *
 * You should have received a copy of the  GNU General Public License along with
 * Touchégg. If not, see <http://www.gnu.org/licenses/>.
 */
#include "animations/close-window-animation.h"

#include <algorithm>
#include <utility>

CloseWindowAnimation::CloseWindowAnimation(const WindowSystem &windowSystem,
                                           const WindowT &window, Color color,
                                           Color borderColor)
    : Animation(windowSystem, window),
      maxSize(this->windowSystem.getWindowSize(this->window)),
      color(color),
      borderColor(borderColor) {}

void CloseWindowAnimation::render(int percentage) {
  cairo_t *ctx = this->cairoContext;

  // Clear the background
  cairo_set_source_rgba(ctx, 0, 0, 0, 0);
  cairo_set_operator(ctx, CAIRO_OPERATOR_SOURCE);
  cairo_paint(ctx);

  // This animation draws a rectangle inside the window to close with color and
  // a smaller transparent rectangle inside
  double maxAlpha = 0.6;

  // Full-screen colored rectangle
  double alpha = (percentage * maxAlpha) / 100;
  cairo_set_source_rgba(ctx, color.r(), color.g(), color.b(), alpha);
  cairo_rectangle(ctx, maxSize.x, maxSize.y, maxSize.width, maxSize.height);
  cairo_fill(ctx);

  // Calculate the size of the transparent rectangle
  int maxDiff = (5 * std::max(maxSize.width, maxSize.height)) / 100;
  int width = maxSize.width - ((percentage * maxDiff) / 100);
  int height = maxSize.height - ((percentage * maxDiff) / 100);

  cairo_set_line_width(ctx, 2);
  cairo_set_source_rgba(ctx, borderColor.r(), borderColor.g(), borderColor.b(),
                        alpha);
  cairo_rectangle(ctx, maxSize.x + (maxSize.width - width) / 2,
                  maxSize.y + (maxSize.height - height) / 2, width, height);
  cairo_stroke_preserve(ctx);

  cairo_set_source_rgba(ctx, 0, 0, 0, 0);
  cairo_fill(ctx);

  this->windowSystem.flushSurface(this->surface);
}
