# MinkowskiSum
Minkowski Sum/Difference calculator. Ended up also implementing ear clipping for concave polygons.
The ear clipping is done in the "CreateConcaveShape" function.
I ended up spending more time on the ear clipping for concave polygons than I did on the Minkowski.

I'll probably add buttons later, but until then
Controls:
 * Q - switches between drawing and selecting mode. When drawing a little red dot will follow the cursor
 * Drawing Mode:
  * Left Click - place vertex
  * Space - links the verices in the order they were placed. Note: Theres no testing for non-simple polygons yet, so KISS
 * Selecting Mode:
  * Left Click and Drag - move a shape around
  * Left Click, Hold + Delete/Backspace - delete shape
  * Ctrl + Left Click - marks a shape. If 2 shapes are selected B replaces A and the new shape becomes B
  * Keyboard/Numpad "+" - calculates Minkowski sum (A + B)
  * Keyboard/Numpad "-" - calculates Minkowski difference (A - B)

Requirements:
SFML for rendering.

Refrences:
 * Ear Clipping - Eberly, David. "Triangulation by ear clipping." Geometric Tools (2008). [(link)](https://www.geometrictools.com/Documentation/TriangulationByEarClipping.pdf)
 * Minkowski Sum/Difference - Behar, Evan, and Jyh-Ming Lien. "Fast and robust 2d minkowski sum using reduced convolution." Intelligent Robots and Systems (IROS), 2011 IEEE/RSJ International Conference on. IEEE, 2011.[(link)](http://masc.cs.gmu.edu/wiki/uploads/ReducedConvolution/iros11-mksum2d.pdf)
