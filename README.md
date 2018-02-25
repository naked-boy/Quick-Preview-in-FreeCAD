#**Quick-Preview-in-FreeCAD**
##_Introduction_
QuickPreview is a FreeCAD workbench which allows create or display 3D model in a second.

The idea is to render 3D scene directly by OpenGL rather than OpenCascade in order to get the fastest speed. At the same time, geometries in the 3D scene shall be selectable and measurable, but not editable.

However, programming with OpenGL is a very tedious thing. How to simplify and generalize it? It is a critical question.

##_Findings_
- FreeCAD is able to import and show VRML format file in a second. But the geometries are not selectable.
- FreeCAD reads STEP file slowly, but geometries are selectable and measurable.
- FreeCAD reads IGES file slowly, but geometries are selectable and measurable.

- Free software 3D-Tool-Free can read and show stl file fast. It can recognize circles and measure the size of circle, knowing that there is triangle data in stl file. ##_Questions_
How does FreeCAD render a VRML scene?