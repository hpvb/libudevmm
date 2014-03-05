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

#ifndef libudevmm_device_private_H
#define libudevmm_device_private_H

#include <libudevmm/device.hpp>

namespace udevmm {
struct device::device_private {
	device_private(udev_device* dev) :
			_device(dev) {
	}

	device_private(const device_private &other) :
			_device(other._device) {
		udev_device_ref(_device);
	}

	~device_private() {
		udev_device_unref(_device);
	}

	udev_device* _device;
};
}
#endif
