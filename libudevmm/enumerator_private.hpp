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

#ifndef libudevmm_enumerator_private_H
#define libudevmm_enumerator_private_H

#include <libudev.h>

namespace udevmm {
struct enumerator::enumerator_private {
	enumerator_private(::udev* udev) :
			_enumerate(udev_enumerate_new(udev)) {
		if (!_enumerate)
			throw std::bad_alloc();
	}

	~enumerator_private() {
		udev_enumerate_unref(_enumerate);
	}

	enumerator_private(const enumerator_private &other) :
			_enumerate(other._enumerate) {
		udev_enumerate_ref(_enumerate);
	}

	udev_enumerate* _enumerate;
};
}
#endif
