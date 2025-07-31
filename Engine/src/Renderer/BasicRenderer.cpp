#include "Genesis/Renderer/BasicRenderer.h"
#include <bgfx/bgfx.h>
#include <bgfx/platform.h>

#include "Shaders/vs_triangle.bin.h"
#include "Shaders/fs_triangle.bin.h"


namespace Genesis {
    namespace BasicRenderer {

        static bgfx::VertexLayout s_Layout;
        static bgfx::VertexBufferHandle s_Vbo = BGFX_INVALID_HANDLE;
        static bgfx::ProgramHandle s_Program = BGFX_INVALID_HANDLE;

        struct Vertex {
            float x, y, z;
            uint32_t abgr;
        };

        static const Vertex s_TriangleVertices[] = {
            {  0.0f,  0.5f, 0.0f, 0xff0000ff },
            {  0.5f, -0.5f, 0.0f, 0xff00ff00 },
            { -0.5f, -0.5f, 0.0f, 0xffff0000 },
        };

        extern const uint8_t vs_triangle_bin[];
        extern const uint32_t vs_triangle_bin_len;

        extern const uint8_t fs_triangle_bin[];
        extern const uint32_t fs_triangle_bin_len;

        void Init() {
            // Define layout
            s_Layout.begin()
                .add(bgfx::Attrib::Position, 3, bgfx::AttribType::Float)
                .add(bgfx::Attrib::Color0, 4, bgfx::AttribType::Uint8, true)
                .end();

            // Create vertex buffer
            s_Vbo = bgfx::createVertexBuffer(
                bgfx::makeRef(s_TriangleVertices, sizeof(s_TriangleVertices)),
                s_Layout
            );

            // Load shaders (hardcoded for now, or embed precompiled binary if available)
            s_Program = bgfx::createProgram(
                bgfx::createShader(bgfx::makeRef(vs_triangle_bin, vs_triangle_bin_len)),
                bgfx::createShader(bgfx::makeRef(fs_triangle_bin, fs_triangle_bin_len)),
                true
            );

        }

        void Render() {
            bgfx::setViewClear(0, BGFX_CLEAR_COLOR | BGFX_CLEAR_DEPTH, 0x303030ff, 1.0f, 0);
            bgfx::setViewRect(0, 0, 0, bgfx::BackbufferRatio::Equal);

            bgfx::touch(0);
            bgfx::setVertexBuffer(0, s_Vbo);
            bgfx::submit(0, s_Program);
        }

        void Shutdown() {
            if (bgfx::isValid(s_Vbo)) bgfx::destroy(s_Vbo);
            if (bgfx::isValid(s_Program)) bgfx::destroy(s_Program);
        }

    }
}
