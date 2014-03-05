/* This file is part of libudevmm
 *
 * Copyright 2014 Hein-Pieter van Braam <hp@tmm.cx>
 *
 * libudevmm is free software; you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation; either version 2.1 of the License, or
 * (at your option) any later version.
 *
 * libudevmm is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with libudevmm; If not, see <http://www.gnu.org/licenses/>.
 */

#include <new>
#include <libudev.h>
#include <libudevmm/enumerator.hpp>
#include <libudevmm/udev.hpp>

#include "enumerator_private.hpp"
#include "udev_private.hpp"

namespace udevmm {

udev::udev() :
		_d_ptr(new udev_private) {
}

udev::udev(const udev &other) :
		_d_ptr(other._d_ptr) {
}

udev::~udev() {
	delete _d_ptr;
}

enumerator udev::new_enumerator() {
	return enumerator(new enumerator::enumerator_private(_d_ptr->_udev));
}

}
