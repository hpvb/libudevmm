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

#ifndef libudevmm_enumerator_iterator_H
#define libudevmm_enumerator_iterator_H

#include <libudev.h>

#include <libudevmm/enumerator_iterator.hpp>

namespace udevmm {
struct enumerator_iterator::enumerator_iterator_private {
	udev_enumerate* _enumerate;
	udev_list_entry* _head;
	udev_list_entry* _current;
};

enumerator_iterator::enumerator_iterator(const enumerator& enumerator) :
		_d_ptr(new enumerator_iterator_private) {
	_d_ptr->_enumerate = enumerator._d_ptr->_enumerate;
	udev_enumerate_ref(_d_ptr->_enumerate);
	_d_ptr->_head = udev_enumerate_get_list_entry(_d_ptr->_enumerate);
	_d_ptr->_current = _d_ptr->_head;
}

enumerator_iterator::~enumerator_iterator() {
	udev_enumerate_unref(_d_ptr->_enumerate);
	delete _d_ptr;
}

bool enumerator_iterator::operator==(const self_type& rhs) const {
	return _d_ptr->_current == rhs._d_ptr->_current;
}

bool enumerator_iterator::operator!=(const self_type& rhs) const {
	return _d_ptr->_current != rhs._d_ptr->_current;
}

enumerator_iterator::value_type enumerator_iterator::operator*() {
	const char* syspath = udev_list_entry_get_name(_d_ptr->_current);
	udev_device* dev = udev_device_new_from_syspath(
			udev_enumerate_get_udev(_d_ptr->_enumerate), syspath);

	return device(dev);
}

enumerator_iterator::self_type& enumerator_iterator::operator++() {
	_d_ptr->_current = udev_list_entry_get_next(_d_ptr->_current);
	return *this;
}

}

#endif
