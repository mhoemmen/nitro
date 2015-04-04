/* =========================================================================
 * This file is part of io-c++ 
 * =========================================================================
 * 
 * (C) Copyright 2004 - 2009, General Dynamics - Advanced Information Systems
 *
 * io-c++ is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public 
 * License along with this program; If not, 
 * see <http://www.gnu.org/licenses/>.
 *
 */

#ifndef __IO_FILE_INPUT_STREAM_OS_H__
#define __IO_FILE_INPUT_STREAM_OS_H__

#if !defined(USE_IO_STREAMS)

#include "except/Exception.h"
#include "io/File.h"
#include "io/InputStream.h"
#include "io/SeekableStreams.h"


/*!
 *  \file FileInputStreamOS.h
 *  \brief The InputStream representation of a file using the OS handle
 *  The file contains the representation of an input stream
 *  from a file.  It mimics the Java io package API, with added 
 *  streaming capabilities
 */

namespace io
{

/*!
 *  \class FileInputStreamOS
 *  \brief An InputStream from file
 *
 *  Use this object to create an input stream, where the available()
 *  method is based on the pos in the file, and the streamTo() and read()
 *  are file operations
 */
class FileInputStreamOS : public SeekableInputStream
{
protected:
    io::File mFile;
public:

    //!  Constructor
    FileInputStreamOS()
    {}

    /*!
     *  Alternate Constructor.  Takes an input file and a mode
     *  \param inputFile The file name
     *  \param mode The mode to open the file in
     */
    FileInputStreamOS(const std::string& inputFile)
    {
        // Let this SystemException slide for now
        mFile.create(inputFile,
                     io::File::READ_ONLY,
                     io::File::EXISTING);
    }

    FileInputStreamOS(const io::File& inputFile)
    {
        mFile = inputFile;
    }

    virtual ~FileInputStreamOS()
    {}

    /*!
     * Returns the number of bytes that can be read
     * without blocking by the next caller of a method for this input
     * 
     * \throw except::IOException
     * \return number of bytes which are readable
     * 
     */
    virtual sys::Off_T available();

    /*!
     *  Report whether or not the file is open
     *  \return True if file is open
     */
    virtual bool isOpen()
    {
        return mFile.isOpen();
    }


    /*!
     *  Open the file in the mode provided
     *  \param file The file to open
     *  \param mode The mode
     */
    virtual void create(const std::string& str)
    {
        mFile.create(str,
                     io::File::READ_ONLY,
                     io::File::EXISTING);

    }



    /*!
     *  Go to the offset at the location specified.
     *  \return The number of bytes between off and our origin.
     */
    virtual sys::Off_T seek(sys::Off_T off, Whence whence)
    {
        int from;
        switch (whence)
        {
            case END:
                from = io::File::FROM_END;
                break;

            case START:
                from = io::File::FROM_START;
                break;

            default:
                from = io::File::FROM_CURRENT;
        }
        return mFile.seekTo( off, from );
    }

    /*!
     *  Tell the current offset
     *  \return The byte offset
     */
    virtual sys::Off_T tell()
    {
        return mFile.getCurrentOffset();
    }

    //!  Close the file
    void close()
    {
        mFile.close();
    }

    /*!
     * Read up to len bytes of data from input stream into an array
     * 
     * \param b   Buffer to read into
     * \param len The length to read
     * \throw except::IOException
     * \return  The number of bytes read
     * 
     */
    virtual sys::SSize_T read(sys::byte* b, sys::Size_T len);

};



}
#endif
#endif