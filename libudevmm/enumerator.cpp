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

#include <algorithm>
#include <libudev.h>

#include <libudevmm/device.hpp>
#include <libudevmm/enumerator.hpp>
#include <libudevmm/enumerator_iterator.hpp>

#include "device_private.hpp"
#include "enumerator_private.hpp"

namespace udevmm {

enumerator::enumerator(const enumerator& other) :
		_d_ptr(new enumerator_private) {
	_d_ptr->_enumerate = other._d_ptr->_enumerate;
	udev_enumerate_ref(_d_ptr->_enumerate);
}

enumerator::enumerator(enumerator_private* d_ptr) :
		_d_ptr(d_ptr) {
}

enumerator::~enumerator() {
	udev_enumerate_unref(_d_ptr->_enumerate);
	delete _d_ptr;
}

void enumerator::add_match(const enumerator::subsystem& query) {
	udev_enumerate_add_match_subsystem(_d_ptr->_enumerate,
			query._subsystem.c_str());
}

void enumerator::add_match(const enumerator::sysattr& query) {
	udev_enumerate_add_match_sysattr(_d_ptr->_enumerate, query._sysattr.c_str(),
			query._value.c_str());
}

void enumerator::add_match(const enumerator::property& query) {
	udev_enumerate_add_match_property(_d_ptr->_enumerate,
			query._property.c_str(), query._value.c_str());
}

void enumerator::add_match(const enumerator::tag& query) {
	udev_enumerate_add_match_tag(_d_ptr->_enumerate, query._tag.c_str());
}

void enumerator::add_match(const enumerator::parent& query) {
	udev_enumerate_add_match_parent(_d_ptr->_enumerate,
			query._parent._d_ptr->_device);
}

void enumerator::add_match(const enumerator::sysname& query) {
	udev_enumerate_add_match_sysname(_d_ptr->_enumerate,
			query._sysname.c_str());
}

enumerator& enumerator::operator=(enumerator other) {
	std::swap(_d_ptr->_enumerate, other._d_ptr->_enumerate);

	return *this;
}

enumerator::iterator enumerator::begin() const {
	udev_enumerate_scan_devices(_d_ptr->_enumerate);
	return enumerator_iterator(*this);
}

enumerator::iterator enumerator::end() const {
	return enumerator_iterator(0);
}
}
