/*
 * DBC to SQL Converter
 * Copyright (C) 2009  David Vas, Anubisss
 * <http://code.google.com/p/dbctosql/>

 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.

 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef __DBC_H__
#define __DBC_H__

#include <cassert>
#include <cstring>
#include "common/common.h"

#define WDBC_HEADER     0x43424457

class DBCFileLoader
{
    public:
        DBCFileLoader();
        ~DBCFileLoader();

    bool Load(char const *filename);
    class Record
    {
        public:
            float getFloat(size_t field) const
            {
                assert(field < file.fieldCount);
                return *reinterpret_cast<float*>(offset + field * 4);
            }
            void setFloat(size_t field, float newFloat) const
            {
                assert(field < file.fieldCount);
                *reinterpret_cast<float*>(offset + field * 4) = newFloat;
            }
            //!**********************************************
            uint32 getUInt32(size_t field) const
            {
                assert(field < file.fieldCount);
                return *reinterpret_cast<uint32*>(offset + field * 4);
            }
            void setUInt32(size_t field, uint32 newUInt) const
            {
                assert(field < file.fieldCount);
                *reinterpret_cast<uint32*>(offset + field * 4) = newUInt;
            }
            //!**********************************************
            int32 getInt32(size_t field) const
            {
                assert(field < file.fieldCount);
                return *reinterpret_cast<int32*>(offset + field * 4);
            }
            void setInt32(size_t field, int32 newInt) const
            {
                assert(field < file.fieldCount);
                *reinterpret_cast<int32*>(offset + field * 4) = newInt;
            }
            //!**********************************************
            char const* getString(size_t field) const
            {
                assert(field < file.fieldCount);
                size_t stringOffset = getUInt32(field);
                assert(stringOffset < file.stringSize);
                return reinterpret_cast<char*>(file.stringTable + stringOffset);
            }
            void setString(size_t field, char* newString) const
            {
                assert(field < file.fieldCount);
                size_t stringOffset = getUInt32(field);
                assert(stringOffset < file.stringSize);
                *reinterpret_cast<char**>(file.stringTable + stringOffset) = newString;
            }
            //!**********************************************

        private:
            Record(DBCFileLoader &file, unsigned char *offset): file(file), offset(offset){}
            DBCFileLoader &file;
            unsigned char *offset;
            

        friend class DBCFileLoader;
    };

    Record getRecord(size_t id);
    uint32 getNumRows() const { return recordCount; }
    uint32 getNumFields() const { return fieldCount; }
    
    // private:
        uint32 header;
        uint32 recordSize;
        uint32 recordCount;
        uint32 fieldCount;
        uint32 stringSize;
        unsigned char *data;
        unsigned char *stringTable;
};

#endif
