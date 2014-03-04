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

#include <libudevmm/enumerator.hpp>
#include <libudevmm/device.hpp>

namespace udevmm {
//TODO Make this a complete input_iterator
class enumerator_iterator {
public:
	typedef enumerator_iterator self_type;
	typedef device value_type;

	~enumerator_iterator();
	bool operator==(const self_type& rhs) const;
	bool operator!=(const self_type& rhs) const;
	value_type operator*();
	self_type& operator++();

	friend class udevmm::enumerator;
private:
	struct enumerator_iterator_private;
	enumerator_iterator();
	//enumerator_iterator(const enumerator& enumerator);
	enumerator_iterator_private* _d_ptr;
};
}

#endif
