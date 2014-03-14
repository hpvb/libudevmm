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

#include <libudev.h>
#include <libudevmm/device.hpp>

#include "device_private.hpp"

namespace udevmm {

device::device(const device& other) :
		_d_ptr(other._d_ptr) {
}

device::device(const udevmm::syspath& syspath) :
		_d_ptr(new device_private(syspath)) {

}

device::~device() {
	delete _d_ptr;
}

device& device::operator=(device other) {
	std::swap(_d_ptr->_device, other._d_ptr->_device);

	return *this;
}

const std::string device::devpath() {
	const char* value = udev_device_get_devpath(_d_ptr->_device);
	if (value)
		return std::string(value);
	return std::string();
}

const std::string device::subsystem() {
	const char* value = udev_device_get_subsystem(_d_ptr->_device);
	if (value)
		return std::string(value);
	return std::string();
}

const std::string device::devtype() {
	const char* value = udev_device_get_devtype(_d_ptr->_device);
	if (value)
		return std::string(value);
	return std::string();
}

const std::string device::syspath() {
	const char* value = udev_device_get_syspath(_d_ptr->_device);
	if (value)
		return std::string(value);
	return std::string();
}

const std::string device::sysname() {
	const char* value = udev_device_get_sysname(_d_ptr->_device);
	if (value)
		return std::string(value);
	return std::string();
}

const std::string device::sysnum() {
	const char* value = udev_device_get_sysnum(_d_ptr->_device);
	if (value)
		return std::string(value);
	return std::string();
}

const std::string device::devnode() {
	const char* value = udev_device_get_devnode(_d_ptr->_device);
	if (value)
		return std::string(value);
	return std::string();
}

const std::string device::property_value(const std::string& property) {
	const char* value = udev_device_get_property_value(_d_ptr->_device,
			property.c_str());
	if (value)
		return std::string(value);
	return std::string();
}

const std::string device::driver() {
	const char* value = udev_device_get_driver(_d_ptr->_device);
	if (value)
		return std::string(value);
	return std::string();
}

dev_t device::devnum() {
	return udev_device_get_devnum(_d_ptr->_device);
}

const std::string device::action() {
	const char* value = udev_device_get_action(_d_ptr->_device);
	if (value)
		return std::string(value);
	return std::string();
}

const std::string device::sysattr_value(const std::string& sysattr) {
	const char* value = udev_device_get_sysattr_value(_d_ptr->_device,
			sysattr.c_str());
	if (value)
		return std::string(value);
	return std::string();
}
}
