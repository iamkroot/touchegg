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
#ifndef GESTURE_CONTROLLER_GESTURE_CONTROLLER_H_
#define GESTURE_CONTROLLER_GESTURE_CONTROLLER_H_

#include <memory>

#include "actions/action.h"
#include "gesture-controller/gesture-controller-delegate.h"

class Config;
class Gesture;

/**
 * The GestureController is in charge of receiving events from the outside and
 * dispatching actions according to the user configuration.
 */
class GestureController : public GestureControllerDelegate {
 public:
  explicit GestureController(const Config &config);
  virtual ~GestureController() = default;

  void onGestureBegin(std::unique_ptr<Gesture> gesture) override;
  void onGestureUpdate(std::unique_ptr<Gesture> gesture) override;
  void onGestureEnd(std::unique_ptr<Gesture> gesture) override;

 private:
  const Config &config;
  std::unique_ptr<Action> action;
};

#endif  // GESTURE_CONTROLLER_GESTURE_CONTROLLER_H_
