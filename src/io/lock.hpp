#ifndef TMWA_IO_LOCK_HPP
#define TMWA_IO_LOCK_HPP
//    io/lock.hpp - Output to files with atomic replacement and backups.
//
//    Copyright © 2013 Ben Longbons <b.r.longbons@gmail.com>
//
//    This file is part of The Mana World (Athena server)
//
//    This program is free software: you can redistribute it and/or modify
//    it under the terms of the GNU General Public License as published by
//    the Free Software Foundation, either version 3 of the License, or
//    (at your option) any later version.
//
//    This program is distributed in the hope that it will be useful,
//    but WITHOUT ANY WARRANTY; without even the implied warranty of
//    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//    GNU General Public License for more details.
//
//    You should have received a copy of the GNU General Public License
//    along with this program.  If not, see <http://www.gnu.org/licenses/>.

#include "write.hpp"

#include "../strings/fstring.hpp"


namespace io
{
    class WriteLock : public WriteFile
    {
        FString filename;
        int tmp_suffix;
    public:
        WriteLock(FString filename, bool linebuffered=false);
        ~WriteLock();
        bool close() = delete;
    };
} // namespace io

#endif // TMWA_IO_LOCK_HPP
