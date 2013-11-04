/**
 * The Forgotten Server - a server application for the MMORPG Tibia
 * Copyright (C) 2013  Mark Samman <mark.samman@gmail.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

#ifndef __OTSERV_RSA_H__
#define __OTSERV_RSA_H__

#include <boost/thread/recursive_mutex.hpp>

#include <gmp.h>

class RSA
{
	public:
		RSA();
		~RSA();

		void setKey(const char* p, const char* q);
		bool setKey(const std::string& file);
		void decrypt(char* msg);

		void getPublicKey(char* buffer);

	protected:
		boost::recursive_mutex rsaLock;

		//use only GMP
		mpz_t m_n, m_d;
};

#endif
