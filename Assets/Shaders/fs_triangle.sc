#include "common.sh"

void main(float4 gl_FragCoord : SV_POSITION, out float4 bgfx_FragData0 : SV_TARGET0)
{ 
    float4 bgfx_VoidFrag = vec4_splat(0.0);
    bgfx_FragData0 = float4(1.0, 0.0, 0.0, 1.0);
}
