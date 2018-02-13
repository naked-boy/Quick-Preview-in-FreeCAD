/***************************************************************************
 *   Copyright (c) YEAR YOUR NAME         <Your e-mail address>            *
 *                                                                         *
 *   This file is part of the FreeCAD CAx development system.              *
 *                                                                         *
 *   This library is free software; you can redistribute it and/or         *
 *   modify it under the terms of the GNU Library General Public           *
 *   License as published by the Free Software Foundation; either          *
 *   version 2 of the License, or (at your option) any later version.      *
 *                                                                         *
 *   This library  is distributed in the hope that it will be useful,      *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU Library General Public License for more details.                  *
 *                                                                         *
 *   You should have received a copy of the GNU Library General Public     *
 *   License along with this library; see the file COPYING.LIB. If not,    *
 *   write to the Free Software Foundation, Inc., 59 Temple Place,         *
 *   Suite 330, Boston, MA  02111-1307, USA                                *
 *                                                                         *
 ***************************************************************************/


#include "PreCompiled.h"
#ifndef _PreComp_
#include <Python.h>
#endif

#include <Base/Console.h>
#include <Base/PyObjectBase.h>

#include <CXX/Extensions.hxx>
#include <CXX/Objects.hxx>


namespace QuickPreview {
class Module : public Py::ExtensionModule<Module>
{
public:
    Module() : Py::ExtensionModule<Module>("QuickPreview")
    {
		add_varargs_method("sayHello", &Module::sayHello
			);
		initialize("This module is the QuickPreview module."); // register with Python
    }

    virtual ~Module() {}

private:
	Py::Object sayHello(const Py::Tuple& args)
	{
		Base::Console().Message("Hello, World!");
		return Py::None();
	}
};

PyObject* initModule()
{
    return (new Module)->module().ptr();
}


} // namespace QuickPreview


/* Python entry */
PyMOD_INIT_FUNC(QuickPreview)
{
    // ADD YOUR CODE HERE
    //
    //
    PyObject* mod = QuickPreview::initModule();
    Base::Console().Log("Loading QuickPreview module... done\n");
    PyMOD_Return(mod);
}
