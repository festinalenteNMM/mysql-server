/* Copyright (c) 2016 Oracle and/or its affiliates. All rights reserved.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; version 2 of the License.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software Foundation,
   51 Franklin Street, Suite 500, Boston, MA 02110-1335 USA */

#ifndef DD__PARAMETER_INCLUDED
#define DD__PARAMETER_INCLUDED

#include "my_global.h"

#include "dd/types/column.h"         // dd::Column::enum_column_types
#include "dd/types/entity_object.h"  // dd::Entity_object

namespace dd {

///////////////////////////////////////////////////////////////////////////

class Routine;
class Parameter_impl;
class Parameter_type_element;
class Object_type;

///////////////////////////////////////////////////////////////////////////

class Parameter : virtual public Entity_object
{
public:
  static const Object_type &TYPE();
  static const Object_table &OBJECT_TABLE();
  typedef Collection<Parameter_type_element*> Parameter_type_element_collection;
  typedef Parameter_impl Impl;

public:
  virtual ~Parameter()
  { };

public:

  enum enum_parameter_mode
  {
    PM_IN = 1,
    PM_OUT,
    PM_INOUT
  };

public:
  /////////////////////////////////////////////////////////////////////////
  // Is name null?
  /////////////////////////////////////////////////////////////////////////

  virtual void set_name_null(bool is_null) = 0;
  virtual bool is_name_null() const = 0;

  /////////////////////////////////////////////////////////////////////////
  // Routine.
  /////////////////////////////////////////////////////////////////////////

  virtual const Routine &routine() const = 0;

  virtual Routine &routine() = 0;

  /////////////////////////////////////////////////////////////////////////
  // ordinal_position.
  /////////////////////////////////////////////////////////////////////////

  virtual uint ordinal_position() const = 0;

  /////////////////////////////////////////////////////////////////////////
  // mode
  /////////////////////////////////////////////////////////////////////////

  virtual enum_parameter_mode mode() const = 0;
  virtual void set_mode(enum_parameter_mode mode) = 0;
  virtual void set_parameter_mode_null(bool is_null) = 0;
  virtual bool is_parameter_mode_null() const = 0;

  /////////////////////////////////////////////////////////////////////////
  // data type.
  /////////////////////////////////////////////////////////////////////////

  virtual enum_column_types data_type() const = 0;
  virtual void set_data_type(enum_column_types type) = 0;

  /////////////////////////////////////////////////////////////////////////
  // is_zerofill.
  /////////////////////////////////////////////////////////////////////////

  virtual bool is_zerofill() const = 0;
  virtual void set_zerofill(bool zerofill) = 0;

  /////////////////////////////////////////////////////////////////////////
  // is_unsigned.
  /////////////////////////////////////////////////////////////////////////

  virtual bool is_unsigned() const = 0;
  virtual void set_unsigned(bool unsigned_flag) = 0;

  /////////////////////////////////////////////////////////////////////////
  // char_length.
  /////////////////////////////////////////////////////////////////////////

  virtual size_t char_length() const = 0;
  virtual void set_char_length(size_t char_length) = 0;

  /////////////////////////////////////////////////////////////////////////
  // numeric_precision.
  /////////////////////////////////////////////////////////////////////////

  virtual uint numeric_precision() const = 0;
  virtual void set_numeric_precision(uint numeric_precision) = 0;

  /////////////////////////////////////////////////////////////////////////
  // numeric_scale.
  /////////////////////////////////////////////////////////////////////////

  virtual uint numeric_scale() const = 0;
  virtual void set_numeric_scale(uint numeric_scale) = 0;
  virtual void set_numeric_scale_null(bool is_null) = 0;
  virtual bool is_numeric_scale_null() const = 0;

  /////////////////////////////////////////////////////////////////////////
  // datetime_precision.
  /////////////////////////////////////////////////////////////////////////

  virtual uint datetime_precision() const = 0;
  virtual void set_datetime_precision(uint datetime_precision) = 0;

  /////////////////////////////////////////////////////////////////////////
  // collation.
  /////////////////////////////////////////////////////////////////////////

  virtual Object_id collation_id() const = 0;
  virtual void set_collation_id(Object_id collation_id) = 0;

  /////////////////////////////////////////////////////////////////////////
  // Options.
  /////////////////////////////////////////////////////////////////////////

  virtual const Properties &options() const = 0;

  virtual Properties &options() = 0;
  virtual bool set_options_raw(const std::string &options_raw) = 0;

  /////////////////////////////////////////////////////////////////////////
  // Elements.
  /////////////////////////////////////////////////////////////////////////

  virtual Parameter_type_element *add_element() = 0;

  virtual const Parameter_type_element_collection &elements() const = 0;

  virtual size_t elements_count() const = 0;
};

///////////////////////////////////////////////////////////////////////////

}

#endif // DD__PARAMETER_INCLUDED