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
 * along with systemd; If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef libudevmm_device_H
#define libudevmm_device_H

#include <string>
#include <sys/types.h>

namespace udevmm {
class device {
public:
	device(const device& other);
	~device();
	device& operator=(device other);

	const std::string devpath();
	const std::string subsystem();
	const std::string devtype();
	const std::string syspath();
	const std::string sysname();
	const std::string sysnum();
	const std::string devnode();
	const std::string property_value(const std::string& property);
	const std::string driver();
	dev_t devnum();
	const std::string action();
	const std::string sysattr_value(const std::string& sysattr);

	friend class enumerator;
private:
	struct device_private;
	device();
	device(device_private* device_private);
	device_private* _d_ptr;
};
}

#endif
