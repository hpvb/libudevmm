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

#ifndef libudevmm_udev_private_H
#define libudevmm_udev_private_H

#include <libudev.h>
#include <libudevmm/udev.hpp>

namespace udevmm {
struct udev::udev_private {
	udev_private() :
			_udev(udev_new()) {
		if (!_udev)
			throw std::bad_alloc();
	}

	~udev_private() {
		udev_unref(_udev);
	}

	udev_private(const udev_private &other) :
			_udev(other._udev) {
		udev_ref(_udev);
	}

	::udev* _udev;
};
}
#endif
