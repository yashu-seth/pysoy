/*
    PySoy - soy.widgets.Canvas Type
    Copyright (C) 2006,2007,2008,2009,2010,2011,2012 Copyleft Games Group

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU Affero General Public License as published
    by the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU Affero General Public License for more details.

    You should have received a copy of the GNU Affero General Public License
    along with this program; if not, see http://www.gnu.org/licenses
*/

#include "pysoy2.h"
#define SELF PySoy_widgets_Canvas_Object*


static char
tp_doc[] = "soy.widgets.Canvas Type\n"
"\n"
"    Renders a :class:`~soy.textures.Texture`.\n"
"\n"
"    Since :class:`~soy.textures.Texture` can be any sort of bitmap including\n"
"    text, images, and video, adding a :class:`~soy.widgets.Canvas` to a\n"
"    :class:`~soy.widgets.Window` behind a :class:`~soy.widgets.Projector`\n"
"    allows for a background to the rendered :class:`~soy.scenes.Scene`.\n"
"\n"
"    Adding a :class:`~soy.widgets.Canvas` in a :class:`~soy.widgets.Window`\n"
"    after a :class:`~soy.widgets.Projector` can also be used to create an\n"
"    overlay display, such as text or an image.\n"
"\n"
"    :class:`~soy.widgets.Canvas` and widgets packed into nested \n"
"    :class:`~soy.widgets.Container` classes can create numerous effects \n";


static SELF
tp_new (PyTypeObject* type, PyObject* args, PyObject* kwds) {
    SELF self;
    PySoy_widgets_Container_Object* parent;
    PySoy_textures_Texture_Object* texture;
    static char* kw[] = {"parent", "texture", NULL};

    // Parse arguments
    if (!PyArg_ParseTupleAndKeywords(args, kwds, "O!|O!", kw,
                                     &PySoy_widgets_Container_Type, &parent,
                                     &PySoy_textures_Texture_Type, &texture))
        return NULL;

    // inherit base type
    self = (SELF) PyType_GenericNew(type, args, kwds);
    if (!self)
      return NULL;

    // new gobject
    self->g = soy_widgets_canvas_new(parent->g, texture->g);

    return self;
}


static PyObject*
tp_repr (SELF self) {
    PyObject* ret;

    // TODO this should report additional debug information such as size

    ret = PyUnicode_FromString("<Canvas>");

    // return string
    return ret;
}


///////////////////////////////////////////////////////////////////////////////
// Properties

PYSOY_PROP_OBJECT_DELETABLE(widgets, canvas, texture, textures_Texture)
static char
texture_doc[] = {
"\n"
"    This is the current :class:`~soy.textures.Texture` to be rendered on\n"
"    the :class:`~soy.widgets.Canvas`.  Deleting this disables this Canvas.\n"
"\n"
"    This property be changed at any time.\n"
};


///////////////////////////////////////////////////////////////////////////////
// Type structs

static PyGetSetDef tp_getset[] = {
    PYSOY_PROPSTRUCT(texture),
    {NULL},                                                // sentinel
};


PyTypeObject PySoy_widgets_Canvas_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    "soy.widgets.Canvas",                                  // tp_name
    sizeof(PySoy_widgets_Canvas_Object),                   // tp_basicsize
    0,                                                     // tp_itemsize
    0,                                                     // tp_dealloc
    0,                                                     // tp_print
    (getattrfunc) 0,                                       // tp_getattr
    (setattrfunc) 0,                                       // tp_setattr
    0,                                                     // tp_compare
    (reprfunc) tp_repr,                                    // tp_repr
    0,                                                     // tp_as_number
    0,                                                     // tp_as_sequence
    0,                                                     // tp_as_mapping
    0,                                                     // tp_hash
    0,                                                     // tp_call
    0,                                                     // tp_str
    (getattrofunc) 0,                                      // tp_getattro
    (setattrofunc) 0,                                      // tp_setattro
    0,                                                     // tp_as_buffer
    Py_TPFLAGS_DEFAULT | Py_TPFLAGS_BASETYPE,              // tp_flags
    tp_doc,                                                // tp_doc
    0,                                                     // tp_traverse
    0,                                                     // tp_clear
    0,                                                     // tp_richcompare
    0,                                                     // tp_weaklistoffset
    0,                                                     // tp_iter
    0,                                                     // tp_iternext
    0,                                                     // tp_methods
    0,                                                     // tp_members
    tp_getset,                                             // tp_getset
    &PySoy_widgets_Widget_Type,                            // tp_base
    0,                                                     // tp_dict
    0,                                                     // tp_descr_get
    0,                                                     // tp_descr_set
    0,                                                     // tp_dictoffset
    0,                                                     // tp_init
    0,                                                     // tp_alloc
    (newfunc) tp_new,                                      // tp_new
    0,                                                     // tp_free
    0,                                                     // tp_is_gc
};
