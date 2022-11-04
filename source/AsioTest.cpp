/* NetworkManager.cpp
Copyright (c) 2022 by softwarehopper

Endless Sky is free software: you can redistribute it and/or modify it under the
terms of the GNU General Public License as published by the Free Software
Foundation, either version 3 of the License, or (at your option) any later version.

Endless Sky is distributed in the hope that it will be useful, but WITHOUT ANY
WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A
PARTICULAR PURPOSE. See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along with
this program. If not, see <https://www.gnu.org/licenses/>.
*/

#include "AsioTest.h"
#include <stdio.h>
#include <iostream>

#ifdef _WIN32
#define _WIN32_WINNT 0x0A00
#endif

#define ASIO_STANDALONE
#include <asio.hpp>
#include <asio/ts/buffer.hpp>
#include <asio/ts/internet.hpp>

void AsioTest::SendAsioData()
{
    asio::error_code ec;

    // asio's way to preform stuff... unique instance of asio hide platform requirments
    asio::io_context context;

    asio::ip::tcp::endpoint endpoint(asio::ip::make_address("127.0.0.1", ec), 28106);

    asio::ip::tcp::socket socket(context);

    socket.connect(endpoint, ec);

    if (!ec) {
        std::cout << "Connected" << std::endl;
    }
    else if (ec) {
        std::cout << "Failed\n" << ec.message() << std::endl;
    }

    if (socket.is_open()) {
        std::string req = "YO WASSUP DAWG";
        socket.write_some(asio::buffer(req.data(), req.size()), ec);
    }
}