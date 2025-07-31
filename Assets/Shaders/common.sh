// common.sh
#ifdef __HLSL__
    #define vec4_splat(x) float4(x, x, x, x)
#else
    #define vec4_splat(x) vec4(x, x, x, x)
#endif