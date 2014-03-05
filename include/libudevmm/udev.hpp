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

#ifndef libudevmm_udev_H
#define libudevmm_udev_H

namespace udevmm {
class enumerator;

class udev {
public:
	udev();
	udev(const udev &other);
	~udev();

	enumerator new_enumerator();
	struct udev_private;
private:
	udev_private* _d_ptr;
};
}

#endif
