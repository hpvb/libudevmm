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

#include "raii/udev.hpp"

namespace udevmm {
struct device::device_private {
	device_private(udev_device* dev) :
			_device(dev) {
	}

	device_private(const udevmm::syspath& syspath) :
			_device(
					udev_device_new_from_syspath(_udev.ptr,
							syspath.get_c_str())) {
	}

	device_private(const char type, const udevmm::devnum& devnum) :
			_device(
					udev_device_new_from_devnum(_udev.ptr, type,
							devnum.get_devnum())) {
	}

	device_private(const udevmm::subsystem& subsystem,
			const udevmm::sysname& sysname) :
			_device(
					udev_device_new_from_subsystem_sysname(_udev.ptr,
							subsystem.get_c_str(), sysname.get_c_str())) {
	}

	device_private(const udevmm::device_id& device_id) :
			_device(
					udev_device_new_from_device_id(_udev.ptr,
							const_cast<char*>(device_id.get_c_str()))) {

	}

	device_private(const device_private &other) {
		udev_device_ref(_device);
		_device = other._device;
	}

	~device_private() {
		udev_device_unref(_device);
	}

	raii::udev _udev;
	udev_device* _device;
};
}
#endif
