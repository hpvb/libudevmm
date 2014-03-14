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

#ifndef libudevmm_raii_udev_H
#define libudevmm_raii_udev_H

#include <libudev.h>

namespace udevmm {
namespace raii {
struct udev {
	udev() :
			ptr(udev_new()) {
		if (!ptr)
			throw std::bad_alloc();
	}

	udev(const udev &other) {
		udev_ref(ptr);
		ptr = other.ptr;
	}

	~udev() {
		udev_unref(ptr);
	}

	::udev* ptr;
};
}
}
#endif
