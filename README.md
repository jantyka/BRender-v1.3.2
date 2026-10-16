# Argonaut Blazing Render (BRender)

## deVRace fork

This fork of [dethrace-labs/BRender-v1.3.2](https://github.com/dethrace-labs/BRender-v1.3.2) holds the engine changes needed by [deVRace](https://github.com/jantyka/deVRace), a Linux VR port of Dethrace (Carmageddon). deVRace includes it as a submodule; the changes are on the branch `vr-openxr`, each in its own commit:

- **Render targets per eye**: the OpenGL renderer could only draw to the screen; it can now also draw into hidden render targets backed by framebuffer objects, one per eye (`61f038e`, `60c23ca`).
- **Projection per eye**: a headset gives each eye its own asymmetric field of view; the view to screen transform can now be overridden with it (`0673e6b`, `fcf8fe7`).
- **Querying device values** the VR code needs, such as the OpenGL texture of a render target (`34e17d8`).
- **HUD and menus on the headset's panel**: the 2D overlay can be captured into a render target, which deVRace shows as a panel in the headset (`9a23fb0`, `0b2d53b`).

Without these features being used, BRender behaves as before.

---

This is a fork of the original BRender v1.3.2 open source release at https://github.com/foone/BRender-v1.3.2

Additions:
- CMake support, based on https://github.com/crocguy0688/CrocDE-BRender
- x86 paletted software renderer ported to cross-platform C code
- OpenGL renderer, based on the OpenGL renderer from https://github.com/crocguy0688/CrocDE-BRender
- Virtual framebuffer allowing any windowing backend to be used


## Build
```sh
mkdir build
cd build
cmake -DBRENDER_BUILD_EXAMPLES=on ..
make
```

## Example
Build BRender with examples:

```sh
cmake -DBRENDER_BUILD_EXAMPLES=on ..
```

```sh
./examples/softcube/softcube16
```

## Regenerate generated files if needed
_These are not required unless you are adding new token types or adding/change BRender internal function args_

```sh
gcc -D__CLASSGEN__ -E "core/fw/dev_objs.hpp" > /tmp/dev_objs.tmp
perl make/classgen.pl < /tmp/dev_objs.tmp > core/fw/ddi/dev_objs.cgh
cd core/inc
perl ../../make/tokgen.pl pretok.tok
```

If you change a software renderer primitives config file:
```sh
perl drivers/pentprim/infogen.pl < drivers/pentprim/prim_p8.ifg > drivers/pentprim/prim_p8.c
perl drivers/pentprim/infogen.pl < drivers/pentprim/prim_l8.ifg > drivers/pentprim/prim_l8.c
perl drivers/pentprim/infogen.pl image_suffix=f float_components < drivers/pentprim/prim_t8.ifg > drivers/pentprim/prim_t8f.c
perl drivers/pentprim/infogen.pl image_suffix=x < drivers/pentprim/prim_t8.ifg > drivers/pentprim/prim_t8x.c
```


## License

This is released, as is the original open source release, under the MIT license.
