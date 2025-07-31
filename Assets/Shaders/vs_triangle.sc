// vs_triangle.sc
$input a_position

#include "common.sh"

void main()
{
    gl_Position = float4(a_position, 1.0);
}
