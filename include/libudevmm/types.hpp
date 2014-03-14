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

#ifndef libudevmm_types_H
#define libudevmm_types_H

#include <string>
#include <sys/types.h>

namespace udevmm {
class subsystem {
public:
	subsystem(const std::string& subsystem) :
			_subsystem(subsystem) {
	}

	const char* get_c_str() const {
		return _subsystem.c_str();
	}
private:
	std::string _subsystem;
};

class syspath {
public:
	syspath(const std::string& syspath) :
			_syspath(syspath) {
	}

	const char* get_c_str() const {
		return _syspath.c_str();
	}
private:
	std::string _syspath;
};

class device_id {
public:
	device_id(const std::string& device_id) :
			_device_id(device_id) {
	}

	const char* get_c_str() const {
		return _device_id.c_str();
	}
private:
	std::string _device_id;
};

class sysattr {
public:
	sysattr(const std::string& sysattr, const std::string& value) :
			_sysattr(sysattr), _value(value) {
	}
private:
	std::string _sysattr;
	std::string _value;
};

class property {
public:
	property(const std::string& property, const std::string& value) :
			_property(property), _value(value) {
	}
private:
	std::string _property;
	std::string _value;
};

class tag {
public:
	tag(const std::string& tag) :
			_tag(tag) {
	}
private:
	std::string _tag;
};

class sysname {
public:
	sysname(const std::string& sysname) :
			_sysname(sysname) {
	}

	const char* get_c_str() const {
		return _sysname.c_str();
	}
private:
	std::string _sysname;
};

class devnum {
public:
	devnum(const dev_t devnum) :
			_devnum(devnum) {
	}

	dev_t get_devnum() const {
		return _devnum;
	}
private:
	dev_t _devnum;
};
}

#endif
