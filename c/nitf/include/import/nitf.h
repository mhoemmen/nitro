/* =========================================================================
 * This file is part of NITRO
 * =========================================================================
 * 
 * (C) Copyright 2004 - 2008, General Dynamics - Advanced Information Systems
 *
 * NITRO is free software; you can redistribute it and/or modify
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
 * License along with this program; if not, If not, 
 * see <http://www.gnu.org/licenses/>.
 *
 */

#ifndef __IMPORT_NITF_H__
#define __IMPORT_NITF_H__

#include "nitf/BandInfo.h"
#include "nitf/BandSource.h"
#include "nitf/ComponentInfo.h"
#include "nitf/Debug.h"
#include "nitf/DEReader.h"
#include "nitf/DESegment.h"
#include "nitf/DESubheader.h"
#include "nitf/DLL.h"
#include "nitf/DefaultTRE.h"
#include "nitf/DefaultUserSegment.h"
#include "nitf/Directory.h"
#include "nitf/DownSampler.h"
#include "nitf/Error.h"
#include "nitf/Extensions.h"
#include "nitf/Field.h"
#include "nitf/FieldWarning.h"
#include "nitf/FileHeader.h"
#include "nitf/FileSecurity.h"
#include "nitf/GraphicSegment.h"
#include "nitf/GraphicSubheader.h"
#include "nitf/HashTable.h"
#include "nitf/IOHandle.h"
#include "nitf/ImageIO.h"
#include "nitf/ImageReader.h"
#include "nitf/ImageSegment.h"
#include "nitf/ImageSource.h"
#include "nitf/ImageSubheader.h"
#include "nitf/ImageWriter.h"
#include "nitf/IntStack.h"
#include "nitf/LabelSegment.h"
#include "nitf/LabelSubheader.h"
#include "nitf/List.h"
#include "nitf/LookupTable.h"
#include "nitf/Pair.h"
#include "nitf/ParseInfo.h"
#include "nitf/PluginIdentifier.h"
#include "nitf/PluginRegistry.h"
#include "nitf/RESegment.h"
#include "nitf/RESubheader.h"
#include "nitf/RowSource.h"
#include "nitf/Reader.h"
#include "nitf/Record.h"
#include "nitf/SegmentReader.h"
#include "nitf/SegmentSource.h"
#include "nitf/SubWindow.h"
#include "nitf/Sync.h"
#include "nitf/System.h"
#include "nitf/TRE.h"
#include "nitf/TREUtils.h"
#include "nitf/TextSegment.h"
#include "nitf/TextSubheader.h"
#include "nitf/UserSegment.h"
#include "nitf/Validation.h"
#include "nitf/Writer.h"

#endif
