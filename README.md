# FHL (Five Halves Lib)

FHL is (going to be) an OpenGL and C++11/14 graphics library making easy to combine 2D and 3D elements.  
The main target is 2.5D (hence the name) games and you shouldn't expect FHL as a library for 3D apps.  
  
As for now FHL offers:
* wrapped, into few classes representing 2D or 3D object, OpenGL calls
* easy texture loading thanks to [SOIL](http://lonesock.net/soil.html)
* easy model loading thanks to [Assimp](https://github.com/assimp/assimp) (`fhl::Model` class)
* default GLSL shaders and opportunity to write your own
* [SFML](https://github.com/SFML/SFML)-inspired interfaces (`fhl::Renderable` and `fhl::Transformable`, `fhl::Transformable3D`)
* lights (but note that there's no "scene", every object is (or is not) influenced by particular light independently)
* class representations of 4x4 matrix and vectors and operations on them
* simple collision-detection classes
* time measuring using std's `<chrono>` features (`fhl::Clock`)
* `fhl::ResourceMgr` class enforcing proper resource management
  
In the future there's going to be optional deferred renderer that will be much more efficient in specific situations, but I have to think how to design usage of such.
  
There's still a lot to do and the lib is still rather inefficient.  
  
### Dependencies
* [SOIL](http://lonesock.net/soil.html)
* [Assimp](https://github.com/assimp/assimp)
### Build
* `git clone --recursive https://github.com/Crisspl/FHL.git`
* Generate project with CMake
* Note that you will need Python 2.7 and Internet connection for generating [gl3w](https://github.com/skaslev/gl3w) files (happens automatically on build)
* After first build `gen_gl3w_files` target can be safely removed from build pipeline
### Note
This is the second repository for FHL, which I created because of enormous size of previous repo (it was managed improperly and I wasn't able to filter the big files out from repo history).  
Past development of the lib can be seen on [the previous repository](https://github.com/Crisspl/FHL_old).
