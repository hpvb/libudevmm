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

#ifndef libudevmm_enumerator_H
#define libudevmm_enumerator_H

#include <libudevmm/device.hpp>
#include <libudevmm/enumerator_iterator.hpp>

namespace udevmm {
class enumerator_iterator;

class enumerator {
public:
	typedef enumerator_iterator iterator;
	typedef udevmm::device value_type;

	class subsystem {
		friend class enumerator;
	public:
		subsystem(const std::string& subsystem) :
				_subsystem(subsystem) {
		}
	private:
		std::string _subsystem;
	};

	class sysattr {
		friend class enumerator;
	public:
		sysattr(const std::string& sysattr, const std::string& value) :
				_sysattr(sysattr), _value(value) {
		}
	private:
		std::string _sysattr;
		std::string _value;
	};

	class property {
		friend class enumerator;
	public:
		property(const std::string& property, const std::string& value) :
				_property(property), _value(value) {
		}
	private:
		std::string _property;
		std::string _value;
	};

	class tag {
		friend class enumerator;
	public:
		tag(const std::string& tag) :
				_tag(tag) {
		}
	private:
		std::string _tag;
	};

	class parent {
		friend class enumerator;
	public:
		parent(const udevmm::device& parent) :
				_parent(parent) {
		}
	private:
		udevmm::device _parent;
	};

	class sysname {
		friend class enumerator;
	public:
		sysname(const std::string& sysname) :
				_sysname(sysname) {
		}
	private:
		std::string _sysname;
	};

	enumerator(const enumerator& other);

	void add_match(const enumerator::subsystem& query);
	void add_match(const enumerator::sysattr& query);
	void add_match(const enumerator::property& query);
	void add_match(const enumerator::tag& query);
	void add_match(const enumerator::parent& query);
	void add_match(const enumerator::sysname& query);
	~enumerator();
	enumerator& operator=(enumerator other);

	iterator begin() const;
	iterator end() const;

	friend class enumerator_iterator;
private:
	struct enumerator_private;
	enumerator(enumerator_private* enumerator_private);

	enumerator_private* _d_ptr;
};
}
#endif
