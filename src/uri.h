/* GST123 - GStreamer based command line media player
 * Copyright (C) 2010 Siddhesh Poyarekar
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General
 * Public License along with this library; if not, write to the
 * Free Software Foundation, Inc., 59 Temple Place, Suite 330,
 * Boston, MA 02111-1307, USA.
 */

#ifndef __URI_H__
#define __URI_H__

#include <glib.h>
#include <string>
#include <stdlib.h>
#include "iostream.h"

namespace Gst123
{

enum
{
  URI_ERROR_UNKNOWN = -1,
  URI_ERROR_INVALID_HOST = -2,
  URI_ERROR_INVALID_HTTP = -3,
  URI_ERROR_INVALID_URI  = -4,
  URI_ERROR_INVALID_PATH = -5
};

class URI
{
  std::string host;
  int port;
  std::string path;
  std::string protocol;
  int status;

  IOStream *stream;

  bool empty_path_allowed();

public:
  URI (const std::string& input);
  ~URI();

  IOStream *get_io_stream();

  std::string strerror (int error);
  std::string read_strerror (int error);

  int open();
};

}

#endif
